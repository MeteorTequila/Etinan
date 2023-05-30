# glfw
option(GLFW_BUILD_EXAMPLES "" OFF)
option(GLFW_BUILD_TESTS "" OFF)
option(GLFW_BUILD_DOCS "" OFF)
option(GLFW_INSTALL "" OFF)
add_subdirectory(glfw)

# glad
set(glad_include_dir "${CMAKE_CURRENT_SOURCE_DIR}/glad/include")
set(glad_src_dir "${CMAKE_CURRENT_SOURCE_DIR}/glad/src")
file(GLOB_RECURSE glad_headers "${CMAKE_CURRENT_SOURCE_DIR}/glad/*.h")
file(GLOB_RECURSE glad_sources "${CMAKE_CURRENT_SOURCE_DIR}/glad/*.c")
add_library(glad STATIC ${glad_headers} ${glad_sources})
target_include_directories(glad PUBLIC ${glad_include_dir} ${glad_src_dir})

# OpenGL
find_package(OpenGL REQUIRED)

# imgui
set(imgui_root_dir "${CMAKE_CURRENT_SOURCE_DIR}/imgui")
file(GLOB imgui_sources "${imgui_root_dir}/*.cpp")
file(
	GLOB 
	imgui_impl 
	"${imgui_root_dir}/backends/imgui_impl_glfw.cpp"
	"${imgui_root_dir}/backends/imgui_impl_glfw.h"
	"${imgui_root_dir}/backends/imgui_impl_opengl3.cpp"
	"${imgui_root_dir}/backends/imgui_impl_opengl3.h"
	)
add_library(imgui STATIC ${imgui_sources} ${imgui_impl})
target_include_directories(imgui PUBLIC ${imgui_root_dir} ${OPENGL_INCLUDE_DIR})
target_link_libraries(imgui PUBLIC glfw ${OPENGL_LIBRARIES})