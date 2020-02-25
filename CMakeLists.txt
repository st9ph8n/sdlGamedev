
cmake_minimum_required(VERSION 3.14.0)
project(sdlGamedev VERSION 1.0.0)

# Use our modified  FindSDL2* modules

# rule of thumb,
# SET: set(<variable> <value> [[CACHE <type> <docstring> [FORCE]] | PARENT_SCOPE]) ...cmake_module_path bind to sdlproject


# append to project, cmake module path to find sdl2 modules

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${sdlGamedev_SOURCE_DIR}/cmake")

#set an install dir (BIN_DIR) to reference for installing our executatbles.
set(BIN_DIR ${sdlGamedev_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Bump up warning levels appropriately for clang, gcc & msvc and build in debug mode
# Also set debug/optimization flags depending on the build type
# IDE users choose this when selecting the build mode in their IDE
if (MSVC)
	if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
endif()

#look up SDL2 and add the include directory to our include path
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(include)

#look in the the lesson0 subdirectory to find its CMakeLists.txt so we can build the executable
#add_subdirectory(chapter1)
add_subdirectory(chapter2)


