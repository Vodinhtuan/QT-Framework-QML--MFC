# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\apphelloWorldQtQml_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\apphelloWorldQtQml_autogen.dir\\ParseCache.txt"
  "apphelloWorldQtQml_autogen"
  )
endif()
