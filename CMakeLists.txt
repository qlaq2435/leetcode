cmake_minimum_required(VERSION 3.0.0)
project (hello)

# //CONFIG::
# 若不适用clang的话，可以将这段注释删去。
# windows上clang的功能可以通过插件提供，如果一定要使用clang
# 需要根据使用msvc还是mingw指定target 参数，不指定的话在windows上默认是使用msvc
# clang使用msvc:
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -target x86_64-w64-windows-mdvc")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++17 -target x86_64-w64-windows-msvc")
# 或
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++17")
# clang使用mingw:
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -target x86_64-w64-windows-gnu")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++17 -target x86_64-w64-windows-gnu")
# 不使用clang的话，使用下面的设置即可:
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

# 使用c++17标准
set(CMAKE_CXX_STANDARD 17)


include(CTest)
enable_testing()
include_directories(include/hello) 


aux_source_directory(${PROJECT_SOURCE_DIR}/src  src_dirs)
list(APPEND src_dirs ${PROJECT_SOURCE_DIR}/src/hello/hello.cpp)


# 编译条件判断
if(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -O0")
    message("Debug mode:${CMAKE_C_FLAGS_DEBUG}")
    add_executable(debug ${src_dirs})

elseif(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Release"))
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wall -O3")
    message("Release mode:${CMAKE_C_FLAGS_RELEASE}")
    add_executable(release ${src_dirs})
else()
    message("no_specified:${CMAKE_BUILD_TYPE}")
    message("no_specified:${CMAKE_C_FLAGS_RELEASE}")
    add_executable(no_specified ${src_dirs})
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)
