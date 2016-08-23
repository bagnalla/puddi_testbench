include_directories(${puddi_testbench_SOURCE_DIR}/puddi/include ${puddi_testbench_SOURCE_DIR}/include)

add_executable(puddi_testbench main.cc)

target_link_libraries(puddi_testbench puddi gomp GLEW GL SDL2 png jpeg z SDL2_image assimp)
