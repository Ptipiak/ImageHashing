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
	${SOURCE_DIR}/algorythm/Phash.cpp
)

find_package(spdlog
	REQUIRED
)

find_package(ImageMagick
	COMPONENTS
	Magick++
)

target_include_directories(hasher
	PUBLIC
	${INCLUDE_DIR}/
	${INCLUDE_DIR}/core
	${INCLUDE_DIR}/application
	${INCLUDE_DIR}/algorythm
	${ImageMagick_INCLUDE_DIRS}
)

target_link_libraries(hasher
	PUBLIC
	spdlog::spdlog
	${ImageMagick_LIBRARIES}
)

set_target_properties(hasher
	PROPERTIES 
	LINKER_LANGUAGE CXX
)
