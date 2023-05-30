
cmake_minimum_required (VERSION 3.12)

project ("EtinanEngine")

set(app_root_dir ${CMAKE_CURRENT_SOURCE_DIR})
set(engine_root_dir ${CMAKE_CURRENT_SOURCE_DIR}/engine)
set(vendor_root_dir ${CMAKE_CURRENT_SOURCE_DIR}/vendor)

add_subdirectory ("engine")
add_subdirectory ("vendor")


