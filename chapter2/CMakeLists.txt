
project(chapter2)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})



add_library(
    texturelib SHARED
   ../include/TextureManager.hpp
   ../include/TextureManager.cpp
)

add_library(
    gameobjlib SHARED 
    ../include/gameobject.hpp
    ../include/gameobject.cpp
)


add_library(
    sdlgamelib SHARED
    # ../include/gameobject.hpp
    # ../include/loadParam.hpp
    ../include/sdlgameobj.hpp
    ../include/sdlgameobj.cpp
)

add_library(
    playerlib SHARED
    ../include/player.hpp
    ../include/player.cpp
)

add_library(
    enemylib SHARED 
    ../include/enemy.hpp
    ../include/enemy.cpp
)

add_library( 
    gamelib SHARED

   ../include/game.hpp
   ../include/game.cpp
   )



target_link_libraries(texturelib SDL2_image)



 
target_link_libraries(gamelib playerlib enemylib texturelib sdlgamelib)


add_executable(chapter2 src/main.cpp)

target_link_libraries(chapter2 ${SDL2_LIBRARY} gamelib ${SDL2_INCLUDE_DIR} )

install(TARGETS chapter2 RUNTIME DESTINATION ${BIN_DIR})