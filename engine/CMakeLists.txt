
cmake_minimum_required (VERSION 3.12)


file(GLOB_RECURSE engine_head_files "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
file(GLOB_RECURSE engine_source_files "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")



add_executable (${PROJECT_NAME} ${engine_head_files} ${engine_source_files})

target_compile_definitions(
	${PROJECT_NAME}
	PRIVATE
	"GLFW_INCLUDE_NONE"
)

target_include_directories(
	${PROJECT_NAME}
	PRIVATE
	${engine_root_dir}
	${vendor_root_dir}/imgui
	${vendor_root_dir}/glm

)

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
	glfw
	glad
	imgui
	assimp
)
