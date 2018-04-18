cmake_minimum_required(VERSION 3.4.1)
project(ServerDemo)
set(EXECUTABLE_OUTPUT_PATH  "${CMAKE_CURRENT_SOURCE_DIR}/${ANDROID_ABI}")

include_directories(
    platform/include
    server
)
link_directories(platform/libs/${ANDROID_ABI})

aux_source_directory(./ _SRC_MAIN)
aux_source_directory(server _SRC_SERVER)
list(APPEND _SRC_MAIN ${_SRC_SERVER})
add_executable( ${PROJECT_NAME}
             ${_SRC_MAIN} )

target_link_libraries( ${PROJECT_NAME}
                       c cutils binder utils log )