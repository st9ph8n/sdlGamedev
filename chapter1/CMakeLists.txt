project(chapter1)
add_executable(chapter1 src/main.cpp)
target_link_libraries(chapter1 ${SDL2_LIBRARY}) #SDL2_LIBRARY found in FINDSDL2.cmake
install(TARGETS chapter1 RUNTIME DESTINATION ${BIN_DIR}) 