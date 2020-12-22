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

add_subdirectory(${LIBRARIES_DIR}/cli11
	${BUILD_DIR}/software/cli11/
)

add_subdirectory(${LIBRARIES_DIR}/spdlog
	${BUILD_DIR}/software/spdlog/
)

add_subdirectory(${LIBRARIES_DIR}/opencv
	${BUILD_DIR}/software/opencv/
)

set(OpenCV_DIR ${BUILD_DIR}/opencv/)

set(BUILD_LIST
	"core",
	"imgproc",
	"imgcodes",
	"highgui"
)

find_package(OpenCV 
	REQUIRED
	HINTS
	${BUILD_DIR}
)

target_include_directories(hasher
	PUBLIC
	${INCLUDE_DIR}/
	${INCLUDE_DIR}/core
	${INCLUDE_DIR}/application
	${INCLUDE_DIR}/algorythm
	${OpenCV_INCLUDE_DIRS}
	${OpenCV_INCLUDE_DIR}
)


MESSAGE("Libs to be linked:"
	${OpenCV_LIBS}
)

target_link_libraries(hasher
	PUBLIC
	spdlog::spdlog
	CLI11::CLI11
	${OpenCV_LIBS}
)

set_target_properties(hasher
	PROPERTIES 
	LINKER_LANGUAGE CXX
)
