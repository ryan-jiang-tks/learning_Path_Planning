cmake_minimum_required(VERSION 3.10)

project(MyPlanner)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)

set(CMAKE_PREFIX_PATH "F:/clib/vcpkg/installed/x64-windows/share")
set(CMAKE_TOOLCHAIN_FILE "F:/clib/vcpkg/scripts/buildsystems/vcpkg.cmake")
# Find OMPL
# find_package(Eigen REQUIRED)
include(F:/clib/vcpkg/scripts/buildsystems/vcpkg.cmake)
find_package(Eigen3 REQUIRED)
find_package(ompl REQUIRED)

set(OMPL_LIBRARIES "F:/clib/vcpkg/installed/x64-windows/debug/lib/ompl.lib")


include_directories(

  ${OMPL_INCLUDE_DIRS} # Add OMPL include directories
  ${EIGEN3_INCLUDE_DIRS}
  include
)
message("DCMAKE_BUILD_TYPE: ${DCMAKE_BUILD_TYPE}")
message("CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message("ompl libraries: ${OMPL_LIBRARIES}")
message("toolchain: ${CMAKE_TOOLCHAIN_FILE}")

# Link your executable to OMPL
add_executable(MyPlanner src/test.cpp)
target_link_libraries(MyPlanner 
${OMPL_LIBRARIES})