project(mylibrary VERSION 0.1 LANGUAGES CXX)

# Let target be called "mylib"
set(TARGET_NAME mylib)
# Let export be called "MyLibraryConfig"
set(EXPORT_NAME MyLibraryConfig)
# Let target for tests be caled "testmylib"
set(TEST_TARGET_NAME testmylib)

# Specify the sources this target consists of
add_library(${TARGET_NAME}
        src/MyLib.cpp)

# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
target_include_directories(${TARGET_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE src)

# If we have compiler requirements for this library, list them
# here
target_compile_features(${TARGET_NAME}
        PUBLIC cxx_auto_type
        PRIVATE cxx_variadic_templates)

# Depend on a library that we defined in the top-level file
target_link_libraries(${TARGET_NAME}
        boost
        #MyOtherLibrary
        )

# 'make install' to the correct locations (provided by GNUInstallDirs).
install(TARGETS ${TARGET_NAME} EXPORT ${EXPORT_NAME}
        ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})  # This is for Windows
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# This makes the project importable from the install directory
# Put config file in per-project dir (name MUST match), can also
# just go into 'cmake'.
install(EXPORT ${EXPORT_NAME} DESTINATION share/MyLibrary/cmake)

# This makes the project importable from the build directory
export(TARGETS ${TARGET_NAME} FILE ${EXPORT_NAME}.cmake)

# Every library has unit tests, of course
add_executable(${TEST_TARGET_NAME}
        test/testlib.cpp)

target_link_libraries(${TEST_TARGET_NAME} ${TARGET_NAME} gtest_main)

add_test(${TEST_TARGET_NAME} ${TEST_TARGET_NAME})