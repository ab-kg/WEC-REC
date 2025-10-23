#include "callbacks.h"
#include <iostream>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// Window size
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// Camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// Timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;
int count = 0; 

bool isFullscreen = false;
int windowedX = 100, windowedY = 100;
int windowedWidth = 1280, windowedHeight = 720;


void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);



    static bool fKeyPressed = false;
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS && !fKeyPressed)
    {
        fKeyPressed = true; // avoid repeating toggle while holding the key

        if (!isFullscreen)
        {
            // Save current window position & size
            glfwGetWindowPos(window, &windowedX, &windowedY);
            glfwGetWindowSize(window, &windowedWidth, &windowedHeight);

            // Get primary monitor and its resolution
            GLFWmonitor* monitor = glfwGetPrimaryMonitor();
            const GLFWvidmode* mode = glfwGetVideoMode(monitor);

            glfwSetWindowMonitor(window, monitor, 0, 0,
                mode->width, mode->height, mode->refreshRate);
            isFullscreen = true;
        }
        else
        {
            // Go back to windowed mode
            glfwSetWindowMonitor(window, NULL, windowedX, windowedY,
                windowedWidth, windowedHeight, 0);
            isFullscreen = false;
        }
    }

    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_RELEASE)
        fKeyPressed = false;



    //int add = 3.0f;
    //int sub = -3.0f;

    //if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
    //{
    //    camera.ProcessMouseClick(sub);
    //}
    //if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
    //{
    //    camera.ProcessMouseClick(add);
    //}
     

    if (glfwGetKey(window, GLFW_KEY_F1) == GLFW_PRESS)
    {
        std::string firstname = "screenshots/"; 
        std::string imagename = firstname +  std::to_string(count++) + ".png";

        std::cout << "filename is " << imagename << std::endl;
        takeScreenShot(imagename.c_str() , window);
    }


    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        camera.ProcessKeyboard(UP, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        camera.ProcessKeyboard(DOWN, deltaTime);
}


void takeScreenShot(const char* filename, GLFWwindow* window)
{
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    std::vector<unsigned char> pixels(width * height * 3);

    glReadBuffer(GL_BACK);
    glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels.data());

    // Flip vertically
    for (int y = 0; y < height / 2; y++)
        for (int x = 0; x < width * 3; x++)
            std::swap(pixels[y * width * 3 + x], pixels[(height - 1 - y) * width * 3 + x]);

    stbi_write_png(filename, width, height, 3, pixels.data(), width * 3);
}



// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}

