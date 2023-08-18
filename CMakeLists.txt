cmake_minimum_required(VERSION 3.12)
set(PROJECT_NAME graph)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS_RELEASE "-O3")

file(GLOB INC_FILES CONFIGURE_DEPENDS "src/*.h")
file(GLOB SRC_FILES CONFIGURE_DEPENDS "src/*.cpp")

# Boost
find_package(Boost REQUIRED graph)

# Unittests
add_subdirectory(test)

add_executable(${PROJECT_NAME} ${INC_FILES} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} Boost::boost Boost::graph)