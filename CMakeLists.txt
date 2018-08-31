cmake_minimum_required(VERSION 3.11)

set(as_subproject "SomeLib" "OtherLib")

macro(find_package)
  if(NOT "${ARGV0}" IN_LIST as_subproject)
    _find_package(${ARGV})
  endif()
endmacro()

add_subdirectory(SomeLib)
add_subdirectory(MyApp)
add_subdirectory(OtherLib)
