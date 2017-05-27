project(myapplication VERSION 0.1 LANGUAGES CXX)

# Let target be called "myapp"
set(TARGET_NAME myapp)

# Specify the sources this target consists of
add_executable(${TARGET_NAME}
        src/main.cpp)

# Define the libraries this project depends upon
target_link_libraries(${TARGET_NAME}
        mylib)