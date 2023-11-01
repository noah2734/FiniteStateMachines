# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/FiniteStateMachinesApp_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/FiniteStateMachinesApp_autogen.dir/ParseCache.txt"
  "FiniteStateMachinesApp_autogen"
  )
endif()
