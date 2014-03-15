cmake_minimum_required(VERSION 2.8)

project(test)

set(
  CMAKE_MODULE_PATH
  "${CMAKE_SOURCE_DIR}/cmake_modules"
  "/usr/local/share/SFML/cmake/Modules/"
  ${CMAKE_MODULE_PATH}
  )

find_package(SFML 2.1 COMPONENTS system window graphics audio REQUIRED)

#find_package(GLUT)
#find_package(OpenGL)

set(ALL_LIBS ${SFML_LIBRARIES} ${OPENGL_LIBRARIES})

include_directories(
  include
)

file(
  GLOB_RECURSE
  TETRIS_SOURCES
  src/*.cpp
  )

file(
  GLOB_RECURSE
  TETRIS_HEADERS
  include/*.hpp
  include/*.hh
  include/*.h
  )

set(
  EXECUTABLE_OUTPUT_PATH
  ./
)

add_executable(test ${TETRIS_SOURCES} ${TETRIS_HEADERS})

target_link_libraries(test ${ALL_LIBS})

#file(COPY ${PROJECT_SOURCE_DIR}/assets/maps DESTINATION ${PROJECT_BINARY_DIR}/server)
