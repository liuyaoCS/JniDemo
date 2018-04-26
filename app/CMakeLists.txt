cmake_minimum_required(VERSION 3.4.1)
project(jni_demo)


include_directories(
   test
)

aux_source_directory(src/main/cpp  _SRC_MAIN)
aux_source_directory(src/main/cpp/test _SRC_TEST)
list(APPEND _SRC_MAIN ${_SRC_TEST})

add_library( ${PROJECT_NAME}
            SHARED
            ${_SRC_MAIN} )

target_link_libraries( ${PROJECT_NAME}
                      log )