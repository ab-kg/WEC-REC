cmake_minimum_required(VERSION 3.6...3.31)
project(WECGL LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------- Vendor Settings ----------------
set(GLFW_LIBRARY_TYPE "STATIC")
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_INSTALL OFF)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build Assimp as static library" FORCE)
set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "Disable Assimp tests" FORCE)
set(ASSIMP_INSTALL OFF CACHE BOOL "Disable Assimp install target" FORCE)

# ---------------- Add Vendor Libraries ----------------
add_subdirectory(vendors/glm)
add_subdirectory(vendors/glfw)
add_subdirectory(vendors/assimp)

# ---------------- WECGL Library ----------------
file(GLOB LIB_SOURCES src/*.cpp src/*.c)
file(GLOB LIB_HEADERS src/*.h src/*.hpp)
file(GLOB VENDOR_SOURCE_FILES vendors/glad/src/glad.c)

add_library(WECGL_LIB STATIC
    ${LIB_SOURCES}
    ${LIB_HEADERS}
    ${VENDOR_SOURCE_FILES}
)

# Include directories for the library
target_include_directories(WECGL_LIB PUBLIC
    src
    vendors/glm
    vendors/glfw/include
    vendors/glad/include
    vendors/assimp/include
)

# Link vendor libraries into the library
target_link_libraries(WECGL_LIB PUBLIC
    glm::glm
    glfw
    assimp
)

# ---------------- Task1 Executable ----------------
add_executable(Task1 tasks/Task1/Task1.cpp)
target_link_libraries(Task1 PRIVATE WECGL_LIB)

# Copy shaders and assets for Task1
file(GLOB TASK1_SHADERS tasks/Task1/shaders/*.glsl)
file(COPY ${TASK1_SHADERS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/shaders)
file(GLOB TASK1_ASSETS tasks/Task1/assets/*)
file(COPY ${TASK1_ASSETS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/assets)

# ---------------- Task2 Executable ----------------
add_executable(Task2 tasks/Task2/Task2.cpp)
target_link_libraries(Task2 PRIVATE WECGL_LIB)

# Copy shaders and assets for Task2
file(GLOB TASK2_SHADERS tasks/Task2/shaders/*.glsl)
file(COPY ${TASK2_SHADERS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/shaders)
file(GLOB TASK2_ASSETS tasks/Task2/assets/*)
file(COPY ${TASK2_ASSETS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/assets)

# ---------------- Task3 Executable ----------------
add_executable(Task3 tasks/Task3/Task3.cpp)
target_link_libraries(Task3 PRIVATE WECGL_LIB)

# Copy shaders and assets for Task3
file(GLOB TASK3_SHADERS tasks/Task3/shaders/*.glsl)
file(COPY ${TASK3_SHADERS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/shaders)
file(GLOB TASK3_ASSETS tasks/Task3/assets/*)
file(COPY ${TASK3_ASSETS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/assets)




