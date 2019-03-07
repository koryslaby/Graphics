file(REMOVE_RECURSE
  "libGL.pdb"
  "libGL.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/GL.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
