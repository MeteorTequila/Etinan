
cmake_minimum_required (VERSION 3.12)

project ("EtinanEngine")

set(CMAKE_CXX_STANDARD 17)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
message("CMAKE_CXX_COMPILER_ID： ${CMAKE_CXX_COMPILER_ID}")
else()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wformat")
endif()

set(app_root_dir ${CMAKE_CURRENT_SOURCE_DIR})
set(engine_root_dir ${CMAKE_CURRENT_SOURCE_DIR}/engine)
set(vendor_root_dir ${CMAKE_CURRENT_SOURCE_DIR}/vendor)

add_subdirectory ("engine")
add_subdirectory ("vendor")


