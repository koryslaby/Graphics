/*
#include <iostream>
#include "../../LearnOpenGL/includes/glad/glad.h"
#include <GLFW/glfw3.h>

#include "../../LearnOpenGL/includes/glm/glm.hpp"
#include "../../LearnOpenGL/includes/glm/gtc/matrix_transform.hpp"
#include "../../LearnOpenGL/includes/glm/gtc/type_ptr.hpp"

#include "../../shader.h"
#include "Shape.h"
*/

 #include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>

#include "shader.h"
#include "Shape.h"
#include "Cube.h"
#include "Plain.h"
 
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

bool firstMouse = true;
float yaw = -90.0f;
float pitch = 0.0f;
float lastX = 800.0f / 2.0;
float lastY = 600.0 / 2.0;
float fov = 45.0f;

int main(int argc, char const *argv[])
{
    //initualizing glfw and telling it what version we are using.
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

    Cube cube("cube");
    Cube light("cube");
    Plain ground("plain");


    glm::vec3 cubPositions[] = {
            glm::vec3(0.0f, -30.0f, -20.0f),
            glm::vec3(2.0f, -2.0f, -15.0f),
            glm::vec3(-1.5f, -2.2f, -2.5f),
            glm::vec3(-1.8f, -2.0f, -12.3f),
            glm::vec3(2.4f, -0.4f, -3.5f),
            glm::vec3(-1.7f, 3.0f, -7.5f),
            glm::vec3(1.3f, -2.0f, -2.5f),
            glm::vec3(1.5f, 2.0f, -2.5f),
            glm::vec3(1.5f, 0.2f, -1.5f),
            glm::vec3(-2.3f, 1.0f, -1.5f),
    };

    glm::vec3 buildingPositions[] = {
            glm::vec3(15.0f, -2.5f, -35.0f),
            glm::vec3(-15.0f, -2.5f, -35.0f),
            glm::vec3(15.0f, -2.5f, -20.0f),
            glm::vec3(-15.0f, -2.5f, -20.0f),
            glm::vec3(15.0f, -2.5f, -5.0f),
            glm::vec3(-15.0f, -2.5f, -5.0f),
            glm::vec3(15.0f, -2.5f, 10.0f),
            glm::vec3(-15.0f, -2.5f, 10.0f),
            glm::vec3(15.0f, -2.5f, 25.0f),
            glm::vec3(-15.0f, -2.5f, 25.0f)
    };

    glm::vec3 floorPositions[] = {
            glm::vec3(-15.0f, -30.0f, -10.0f),
            glm::vec3(15.0f, -30.0f, -10.0f),
            glm::vec3(0.0f, -30.5f, -10.0f),
            glm::vec3(5.0f, -30.54f, -10.0f),
            glm::vec3(-5.0f, -30.54f, -10.0f)
    };

    glm::vec3 floorScale[] = {
            glm::vec3(20.0, 40.0, 60.0),
            glm::vec3(20.0, 40.0, 60.0),
            glm::vec3(10.0, 40.0, 60.0),
            glm::vec3(0.01, 40.0, 60.0),
            glm::vec3(0.01, 40.0, 60.0)
    };


    //creating a window and giving it a name

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH-1, SCR_HEIGHT, "My Screen", nullptr, nullptr);
    glfwPollEvents();
    glfwSetWindowSize(window, SCR_WIDTH, SCR_HEIGHT);
    if ( window == NULL)
    {
        cout << "failed to create GLFWwindow" << endl;
        glfwTerminate();
        return -1;
    }
    //seting window to current and pasing it to frambuffer_size_callback
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    //checking to see if GLAD has been loaded.

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }

    Shader myShader("shader.vs", "shader.fs");
    Shader lightShader("shader.vs", "lightshader.fs");


    cube.cubeBufferCreate();
    light.cubeBufferCreate();
    ground.plainBufferCreate();



    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

    int buildings = 8;
    int plains = 5;

    while(!glfwWindowShouldClose(window))
    {
    	float currentFrame = glfwGetTime();
    	deltaTime = currentFrame - lastFrame;
    	lastFrame = currentFrame;

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        processInput(window);
        myShader.use();


        glm::mat4 model = glm::mat4 (1.0f);
        float angle = 20.0f;

        myShader.setMat4("projection", projection);

        glEnable(GL_DEPTH_TEST);

        //generating the ground
        ground.plainBindBuffer();

        int flip = -1;
        float savNum = 1.0f;
        for (int j = 0; j < plains; ++j) {
            model = glm::mat4 (1.0f);
            model = glm::translate(model, floorPositions[j]);
            angle = 0.0f;
            model = glm::scale(model, floorScale[j]);
            if(j > 2){
                savNum = savNum * flip;
                angle = 1.57;
                model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 0.0f, savNum));
            }
            myShader.setMat4("model", model);
            glDrawArrays(GL_TRIANGLES, 0, 6);
            model = glm::mat4 (1.0f);
        }

        //generating the buildings
        cube.cubeBindBuffer();

        for (int i = 0; i < buildings; ++i) {
            model = glm::mat4 (1.0f);
            model = glm::translate(model, buildingPositions[i] );
            model = glm::scale(model, glm::vec3(10.0, 15.0, 10.0));
            myShader.setMat4("model", model);
            glDrawArrays(GL_TRIANGLES, 0, 36);

        }







        glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        myShader.setMat4("view", view);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    ground.clearBuffer();

    glfwTerminate();
    return 0;
}


void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    float cameraSpeed = 2.5 * deltaTime;
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
    	cameraPos += cameraSpeed * cameraFront;
    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
    	cameraPos -= cameraSpeed * cameraFront;
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
    	cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
    	
    	cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    }

}

//is called when the window is resized.
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if(firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.05f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;
	pitch += yoffset;
	yaw += xoffset;
	if(pitch > 89.0f)
	{
		pitch = 89.0f;
	}
	if (pitch < -89.0f)
	{
		pitch = -89.0f;
	}
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(front);
}
