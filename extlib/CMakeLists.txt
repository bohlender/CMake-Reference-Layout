# gtest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "Builds the googletest subproject" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "Builds the googlemock subproject")
cmake_policy(SET CMP0048 NEW)
add_subdirectory(googletest)