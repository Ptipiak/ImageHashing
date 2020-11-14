message("Build the software")
# Path to the differents directories
set(INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/sources)
set(LIBRARIES_DIR ${CMAKE_CURRENT_LIST_DIR}/libraries)

add_library(hasher
	${SOURCE_DIR}/
	${SOURCE_DIR}/core/Core.cpp
	${SOURCE_DIR}/core/Log.cpp
	${SOURCE_DIR}/application/Application.cpp
)

find_package(spdlog
	CONFIG
)

target_include_directories(hasher
	PUBLIC
	${INCLUDE_DIR}/
	${INCLUDE_DIR}/core
	${INCLUDE_DIR}/application
)

target_link_libraries(hasher
	PUBLIC
	spdlog::spdlog
)

set_target_properties(hasher
	PROPERTIES 
	LINKER_LANGUAGE CXX
)
