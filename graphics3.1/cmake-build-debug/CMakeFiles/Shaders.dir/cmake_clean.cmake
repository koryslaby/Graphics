file(REMOVE_RECURSE
  "libShaders.pdb"
  "libShaders.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/Shaders.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
