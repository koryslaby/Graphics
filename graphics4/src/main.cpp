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
#include "Cube.h"
#include "Plain.h"
#include "camera.h"
 
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void collisionDetection(glm::vec3 *array, int size, glm::vec3 scale);
void collisionDetection(glm::vec3 *array, int size, glm::vec3 *scale);
bool objCollisionDetection(glm::vec3 pos, glm::vec3 scale, glm::vec3 groundPos, glm::vec3 groundScale );

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

glm::vec3 coral(1.0f, 0.5f, 0.31f);
glm::vec3 lightPos(0.0f, 1.0f, -25.0f);
glm::vec3 bouncingBlock(0.0f, 8.0f, -20.0f);
glm::vec3 cubeScale(10.0, 15.0, 10.0);

float gravity = -.15;
float lightSpeed = .1;

Camera camera(cameraPos);
float blowBack = 5;
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

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

    glm::vec3 planeNormal(0.0f, 1.0f, 0.0f);

    //creating a window and giving it a name

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH-1, SCR_HEIGHT, "My Screen", glfwGetPrimaryMonitor(), NULL);

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

    Shader lightShader("shader.vs", "lightshader.fs");

    Shader objectShader("Object.vs", "Object.fs");


    glm::mat4 projection = glm::mat4(1.0f);
    glm::mat4 model = glm::mat4 (1.0f);
    projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);

    Cube cubes;
    Plain plain;

    int buildings = 8;
    int plains = 5;

    while(!glfwWindowShouldClose(window))
    {
    	float currentFrame = glfwGetTime();
    	deltaTime = currentFrame - lastFrame;
    	lastFrame = currentFrame;

        glm::mat4 view = camera.GetViewMatrix();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        processInput(window);
        objectShader.use();

        //glm::mat4 model = glm::mat4 (1.0f);
        float angle = 20.0f;

        objectShader.setMat4("projection", projection);
        objectShader.setMat4("view", view);
        objectShader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
        objectShader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);
        objectShader.setVec3("lightPos", lightPos);

        glEnable(GL_DEPTH_TEST);


        objectShader.setVec3("objectColor", coral);

        plain.bindVertices();

        float savNum = 1.0f;
        for (int j = 0; j < plains; ++j) {
            collisionDetection(floorPositions, plains, floorScale);
            model = glm::mat4 (1.0f);
            model = glm::translate(model, floorPositions[j]);
            model = glm::scale(model, floorScale[j]);
            if(j > 2){
                savNum = savNum;
                angle = 1.57;
                model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 0.0f, savNum));
            }
            objectShader.setMat4("model", model);
            glDrawArrays(GL_TRIANGLES, 0, 6);
        }

        cubes.bindVertices();

        for (int i = 0; i < buildings; ++i) {

            collisionDetection(buildingPositions, buildings, cubeScale);


            model = glm::mat4 (1.0f);
            model = glm::translate(model, buildingPositions[i] );
            model = glm::scale(model, cubeScale);

            objectShader.setMat4("model", model);
            glDrawArrays(GL_TRIANGLES, 0, 36);

        }


        model = glm::mat4 (1.0f);
        if(!objCollisionDetection(bouncingBlock, glm::vec3(2.0, 2.0, 2.0), floorPositions[2], floorScale[2])){
            bouncingBlock.y += gravity * -gravity;
        } else {
          //  bouncingBlock.y += gravity + (1 - deltaTime);
        }

        model = glm::translate(model, bouncingBlock );
        model = glm::scale(model, glm::vec3(2.0, 2.0, 2.0));


        objectShader.setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        lightShader.use();

        lightShader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);
        lightShader.setMat4("projection", projection);
        lightShader.setMat4("view", view);

        lightPos.z += lightSpeed;
        if(lightPos.z > 20){
            lightSpeed = -.1;
        }
        if(lightPos.z < -35.1){
            lightSpeed = .1;
        }

        model = glm::mat4 (1.0f);
        model = glm::translate(model, lightPos );
        model = glm::scale(model, glm::vec3(1.0, 1.0, 1.0));
        lightShader.setMat4("model", model);
        cubes.bindVertices();
        glDrawArrays(GL_TRIANGLES, 0, 36);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

bool objCollisionDetection(glm::vec3 pos, glm::vec3 scale, glm::vec3 groundPos, glm::vec3 groundScale ){
    glm::vec3 buildPos = pos;
    int MaxX = buildPos[0] + (scale[0]/2);
    int MinX = buildPos[0] - (scale[0]/2);
    int MaxY = buildPos[1] + (scale[1]/2);
    int MinY = buildPos[1] - (scale[1]/2);
    int MaxZ = buildPos[2] + (scale[2]/2);
    int MinZ = buildPos[2] - (scale[2]/2);

    int gMaxX = groundPos[0] + (groundScale[0]/2);
    int gMinX = groundPos[0] - (groundScale[0]/2);
    int gMaxY = groundPos[1] + (groundScale[1]/2);
    int gMinY = groundPos[1] - (groundScale[1]/2);
    int gMaxZ = groundPos[2] + (groundScale[2]/2);
    int gMinZ = groundPos[2] - (groundScale[2]/2);

    if((MinX  <= gMaxX && MaxX >= gMinX) && (MinY <= gMaxY
    && MaxY >= gMinY) && (MinZ <= gMaxZ && MaxZ >= gMinZ)){
        return true;
    }
    return false;
}


void collisionDetection(glm::vec3 *array, int size, glm::vec3 scale){
    glm::vec3 lastMousePos = camera.Position;
    for(int i = 0; i < size; i++){
        glm::vec3 buildPos = array[i];
        int MaxX = buildPos[0] + (scale[0]/2);
        int MinX = buildPos[0] - (scale[0]/2);
        int MaxY = buildPos[1] + (scale[1]/2);
        int MinY = buildPos[1] - (scale[1]/2);
        int MaxZ = buildPos[2] + (scale[2]/2);
        int MinZ = buildPos[2] - (scale[2]/2);

        if((camera.Position.x  >= MinX && camera.Position.x <= MaxX) && (camera.Position.y <= MaxY
        && camera.Position.y >= MinY) && (camera.Position.z >= MinZ && camera.Position.z <= MaxZ)){
            cout << "the mouse is colliding" << endl;
            camera.colliding(true, blowBack);
        }
    }
}

void collisionDetection(glm::vec3 *array, int size, glm::vec3 *scale){
    for(int i = 0; i < size; i++){
        glm::vec3 buildPos = array[i];
        glm::vec3 scaleSize = scale[i];
        int MaxX = buildPos[0] + (scaleSize[0]/2);
        int MinX = buildPos[0] - (scaleSize[0]/2);
        int MaxY = buildPos[1] + (scaleSize[1]/2);
        int MinY = buildPos[1] - (scaleSize[1]/2);
        int MaxZ = buildPos[2] + (scaleSize[2]/2);
        int MinZ = buildPos[2] - (scaleSize[2]/2);

        if((camera.Position.x  >= MinX && camera.Position.x <= MaxX) && (camera.Position.y <= MaxY
        && camera.Position.y >= MinY) && (camera.Position.z >= MinZ && camera.Position.z <= MaxZ)){
            cout << "the mouse is colliding" << endl;
            camera.colliding(true, blowBack);
        }
    }
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

//is called when the window is resized.
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}
