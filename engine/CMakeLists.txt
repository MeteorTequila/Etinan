
cmake_minimum_required (VERSION 3.12)


file(GLOB_RECURSE engine_head_files "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
file(GLOB_RECURSE engine_source_files "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")



# 将源代码添加到此项目的可执行文件。
add_executable (${PROJECT_NAME} ${engine_head_files} ${engine_source_files})

