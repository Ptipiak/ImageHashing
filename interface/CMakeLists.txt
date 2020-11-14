message("Build the interface")
# Path to the differents directories
set(INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/sources)
set(LIBRARIES_DIR ${CMAKE_CURRENT_LIST_DIR}/libraries)

add_executable(interface)

target_include_directories(interface
	PUBLIC
	${INCLUDE_DIR}/
	${INCLUDE_DIR}/entrypoint
)

set_target_properties(interface
	PROPERTIES
	LINKER_LANGUAGE CXX
	ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/archive
	LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

target_link_libraries(interface
	hasher
)

target_sources(interface 
	PUBLIC 
	${SOURCE_DIR}/entrypoint/Entrypoint.cpp
)
