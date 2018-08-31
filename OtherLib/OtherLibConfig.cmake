include(CMakeFindDependencyMacro)
find_dependency(SomeLib 0.1.0 REQUIRED)

include("${CMAKE_CURRENT_LIST_DIR}/OtherLibTargets.cmake")