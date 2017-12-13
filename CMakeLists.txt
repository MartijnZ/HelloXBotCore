cmake_minimum_required(VERSION 2.8.12)

# [MZ]: Why do we set these?
if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 OLD)
    cmake_policy(SET CMP0005 NEW)
    cmake_policy(SET CMP0017 NEW)
endif(COMMAND cmake_policy)

# Project name:
project(HelloXBotCore)

# Add cmake dir and include custom macros
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
include(MacroOptionalBuild)
include(MacroYCMInstallLibrary)

# Select compiler, C++11
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-std=c++11" COMPILER_SUPPORTS_CXX11)
check_cxx_compiler_flag("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

# find first YCM in order to have ${YCM_MODULE_PATH} defined for 3rd party software like Eigen3
#find_package(YCM REQUIRED) # [mz] Didn't provide Eigen3, I had to include manually!
#find_package(XBotCore REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(XCM REQUIRED)
#find_package(ADVR_ROS QUIET)
#find_package(catkin QUIET COMPONENTS roscpp geometry_msgs)

include_directories(include
           ${EIGEN3_INCLUDE_DIRS}
           ${XCM_INCLUDE_DIRS}
           #           ${XBotCoreThread_INCLUDE_DIRS}
           )

# For library:
add_library(${PROJECT_NAME} SHARED src/HelloXBotCore.cpp)

target_link_libraries(${PROJECT_NAME}
                    ${XCM_LIBRARIES})

# For installation
ycm_library_install(${PROJECT_NAME} 1 0 0)


