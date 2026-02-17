# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\appqueenss_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appqueenss_autogen.dir\\ParseCache.txt"
  "appqueenss_autogen"
  )
endif()
