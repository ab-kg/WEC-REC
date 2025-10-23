// 3D MODEL RENDERING 
// WITH CAMERA


#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Model.h"
#include "Camera.h"
#include "Shader.h"
#include <iostream>
#include "callbacks.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main()
{   

    for (int i = 0; i < 50; i++)
    {
        std::cout << "Rendering is on the way from the different dimension , WAIT UP !";
    }

    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // tell stb_image.h to flip loaded texture's on the y-axis (before loading model).
    stbi_set_flip_vertically_on_load(true);

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile shaders
    // -------------------------


    std::string path1 = "C:/CS/WEC/WECGL/src/shaders/modelvert.glsl";
    std::string path2 = "C:/CS/WEC/WECGL/src/shaders/modelfrag.glsl";

    path1 = "shaders/modelvert.glsl";
    path2 = "shaders/modelfrag.glsl";

    Shader* ourShader = Shader::FromGLSLTextFiles(path1, path2);

    // load models
    // -----------
    string path = "C:/CS/WEC/WECGL/src/assets/backpack/backpack.obj";
    path = "C:/CS/WEC/WECGL/src/assets/carr/car.obj";
    path = "C:/CS/WEC/WECGL/src/assets/backpack/backpack.obj";
    path = "C:/CS/WEC/WECGL/src/assets/carr/car.obj";
    path = "assets/carr/car.obj";

    Model ourModel(path);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
    ourShader->use();
    ourShader->setMat4("model", model);


    const int N = 7;        // Number of cubes
    const float radius = 5.0f;
    std::vector<glm::vec3> cubePositions;

    for (int i = 0; i < N; ++i) {
        float theta = 2.0f * glm::pi<float>() * i / N;
        float x = radius * cos(theta);
        float z = radius * sin(theta);
        cubePositions.push_back(glm::vec3(x, 0.0f, z));
    }


    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        // --------------------
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);

        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ourShader->use();

        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        ourShader->setMat4("projection", projection);

        // cam/view transformation
        glm::mat4 view = camera.GetViewMatrix();
        ourShader->setMat4("view", view);

        for (int i = 0; i < 7; i++)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);
            ourShader->use();
            ourShader->setMat4("model", model);
            ourModel.Draw(ourShader);
        }

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

