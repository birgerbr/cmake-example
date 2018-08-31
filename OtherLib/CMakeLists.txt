cmake_minimum_required(VERSION 3.11)
project(OtherLib VERSION 0.1.0 LANGUAGES CXX)

find_package(SomeLib 0.1.0 REQUIRED)

add_library(OtherLib)
add_library(Imerso::OtherLib ALIAS OtherLib)

target_link_libraries(OtherLib PUBLIC Imerso::SomeLib)

target_sources(OtherLib
  PRIVATE
    src/Foo.cpp
)

target_include_directories(OtherLib
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

install(TARGETS OtherLib EXPORT OtherLibTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

install(EXPORT OtherLibTargets
  FILE "OtherLibTargets.cmake"
  NAMESPACE Imerso::
  DESTINATION lib/cmake/OtherLib
)

install(DIRECTORY include/ DESTINATION include)

include(CMakePackageConfigHelpers)

write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/OtherLibConfigVersion.cmake"
  VERSION ${OtherLib_VERSION}
  COMPATIBILITY SameMajorVersion
)

install(FILES "OtherLibConfig.cmake" "${CMAKE_CURRENT_BINARY_DIR}/OtherLibConfigVersion.cmake"
  DESTINATION "lib/cmake/OtherLib"
)

