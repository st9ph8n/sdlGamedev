project(chapter2)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

add_library( 
    gamelib SHARED

   ../include/game.hpp
   ../include/game.cpp
   )

add_library(
    texturelib SHARED
../include/TextureManager.hpp
   ../include/TextureManager.cpp
)


target_link_libraries(texturelib SDL2_image)

add_executable(chapter2 src/main.cpp)

target_link_libraries(chapter2 ${SDL2_LIBRARY}  gamelib texturelib ${SDL2_INCLUDE_DIR})

install(TARGETS chapter2 RUNTIME DESTINATION ${BIN_DIR})