cmake_minimum_required(VERSION 3.11)
project(SomeLib VERSION 0.1.0 LANGUAGES CXX)

add_library(SomeLib)
add_library(Imerso::SomeLib ALIAS SomeLib)

target_sources(SomeLib
  PRIVATE
    src/Foo.cpp
    src/Bar.cpp
)

target_include_directories(SomeLib
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

install(TARGETS SomeLib EXPORT SomeLibTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

install(EXPORT SomeLibTargets
  FILE "SomeLibTargets.cmake"
  NAMESPACE Imerso::
  DESTINATION lib/cmake/SomeLib
)

install(DIRECTORY include/ DESTINATION include)

include(CMakePackageConfigHelpers)

write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/SomeLibConfigVersion.cmake"
  VERSION ${SomeLib_VERSION}
  COMPATIBILITY SameMajorVersion
)

install(FILES "SomeLibConfig.cmake" "${CMAKE_CURRENT_BINARY_DIR}/SomeLibConfigVersion.cmake"
  DESTINATION "lib/cmake/SomeLib"
)
