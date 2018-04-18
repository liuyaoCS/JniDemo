cmake_minimum_required(VERSION 3.4.1)
project(jni_demo)

include_directories(src/main/cpp)
find_library( log-lib
              log )

add_library( ${PROJECT_NAME}
             SHARED
             src/main/cpp/main.cpp )

target_link_libraries( ${PROJECT_NAME}
                       ${log-lib} )