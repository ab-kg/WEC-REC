// Window & 2D Polygon Rendering

#include "callbacks.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <array>

#include "Shader.h"
#include "hexagon.h"


int main() {

    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }
    GLFWwindow* window = glfwCreateWindow(1000, 1000, "OpenGL Window", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }

    std::string path1 = "C:/CS/WEC/WECGL/src/shaders/vert.glsl";
    std::string path2 = "C:/CS/WEC/WECGL/src/shaders/frag.glsl";

    Shader* hexagonShader = Shader::FromGLSLTextFiles(path1, path2);

    glViewport(250, 250, 500, 500);


    int triangles = 8  ;
    int numberofindicesForOpenGL = 8 * 3  ;
    auto vertices = makeVertices<8>(0.0, 0.0, 1);

    unsigned int VBO2, VAO2;
    glGenVertexArrays(1, &VAO2);
    glGenBuffers(1, &VBO2);

    glBindVertexArray(VAO2);
    glBindBuffer(GL_ARRAY_BUFFER, VBO2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * triangles * 9 , vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while (!glfwWindowShouldClose(window))
    {
        //processInput(window);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        hexagonShader->use();
        processInput(window);

        glBindVertexArray(VAO2);
        glDrawArrays(GL_TRIANGLES, 0, numberofindicesForOpenGL);

        // Render commands here
        // Swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}


