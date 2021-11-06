#sets up the minimum version of cmake
cmake_minimum_required(VERSION 3.9) # personally I'd set this version as low as required; you don't have to require the cutting edge version

#how the project will be called
project (projectz)

#set the C++ standard to be used
set (CMAKE_CXX_STANDARD 20)

#set source files
set (SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

add_executable (projectz ${SOURCE_FILES})

#look for SFML and add it
find_package (SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
if(SFML_FOUND)
  # include_directories(${SFML_INCLUDE_DIR})
  # include_directories(${CMAKE_CURRENT_SOURCE_DIR}/SFML/include)
  target_link_libraries(projectz sfml-graphics sfml-audio)
endif()
