cmake_minimum_required(VERSION 3.11)
project(MyApp VERSION 0.1.0 LANGUAGES CXX)

find_package(Eigen3 3.3.0 REQUIRED)
find_package(OtherLib 0.1.0 REQUIRED)

add_executable(MyApp)

target_link_libraries(MyApp PUBLIC Eigen3::Eigen)
target_link_libraries(MyApp PUBLIC Imerso::OtherLib)

target_sources(MyApp
  PRIVATE
    src/main.cpp
)

target_include_directories(MyApp
  PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

install(TARGETS MyApp EXPORT MyAppTargets
  RUNTIME DESTINATION bin
)
