file(REMOVE_RECURSE
  "libGLAD.pdb"
  "libGLAD.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/GLAD.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
