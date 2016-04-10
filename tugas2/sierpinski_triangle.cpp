#include "GLFW/glfw3.h"
#include <stdlib.h>
#include <stdio.h>
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void drawSierpinski(float x1, float y1, float x2, float y2, float x3, float y3)
{
    
    glBegin(GL_LINES);
    glVertex2f(-0.6f, -0.4f);
    glVertex2f(0.6f, -0.4f);      
    glEnd();     

    glBegin(GL_LINES);
    glVertex2f(-0.6f, -0.4f);
    glVertex2f(0.f, 0.6f);     
    glEnd();   

    glBegin(GL_LINES);
    glVertex2f(0.f, 0.6f); 
    glVertex2f(0.6f, -0.4f);      
    glEnd();     
    
    /*
   subTriangle
    (
      1,
      (x1 + x2) / 2,
      (y1 + y2) / 2,
      (x1 + x3) / 2,
      (y1 + y3) / 2,
      (x2 + x3) / 2,
      (y2 + y3) / 2 
    );*/
}

int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Triangle Gradation", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
		
		drawSierpinski(-0.6f,-0.4f,0.6f,-0.4f,0.f,0.6f);  
   
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}