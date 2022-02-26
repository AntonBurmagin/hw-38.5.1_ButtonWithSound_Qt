# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\button_with_sound_effect_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\button_with_sound_effect_autogen.dir\\ParseCache.txt"
  "button_with_sound_effect_autogen"
  )
endif()
