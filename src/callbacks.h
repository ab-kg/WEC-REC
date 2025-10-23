#ifndef GLOBALS_H
#define GLOBALS_H

#include "Camera.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);
void takeScreenShot(const char* filename, GLFWwindow* window);

// Window size
extern const unsigned int SCR_WIDTH;
extern const unsigned int SCR_HEIGHT;

// Camera
extern Camera camera;
extern float lastX;
extern float lastY;
extern bool firstMouse;

// Timing
extern float deltaTime;
extern float lastFrame;

extern int count; 

extern bool isFullscreen ;
extern int windowedX , windowedY ;
extern int windowedWidth , windowedHeight ;

#endif


