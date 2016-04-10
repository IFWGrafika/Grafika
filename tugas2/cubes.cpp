#include "GLFW/glfw3.h"
#include <stdlib.h>
#include <stdio.h>

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

double rotate_x = 0;
double rotate_y = 0;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
      if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

      //  Right arrow - increase rotation by 5 degree
      if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
        rotate_y += 5;
     
      //  Left arrow - decrease rotation by 5 degree
      else if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
        rotate_y -= 5;
     
      else if (key == GLFW_KEY_UP && action == GLFW_PRESS)
        rotate_x += 5;
     
      else if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) 
        rotate_x -= 5;
}

int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Cubes", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glRotatef( rotate_x, 1.0, 0.0, 0.0 );
        glRotatef( rotate_y, 0.0, 1.0, 0.0 );

        glBegin(GL_POLYGON);
        //sky blue
        glColor3f( 0.0, 1.0, 1.0 );     
        glVertex3f(  0.5, -0.5, -0.5 ); 
        glVertex3f(  0.5,  0.5, -0.5 ); 
        glVertex3f( -0.5,  0.5, -0.5 );
        glVertex3f( -0.5, -0.5, -0.5 );
        glEnd();
		
        glBegin(GL_POLYGON);
        //white
        glColor3f(   1.0,  1.0, 1.0 );
        glVertex3f(  0.5, -0.5, 0.5 );
        glVertex3f(  0.5,  0.5, 0.5 );
        glVertex3f( -0.5,  0.5, 0.5 );
        glVertex3f( -0.5, -0.5, 0.5 );
        glEnd();
         
        glBegin(GL_POLYGON);
        //purple
        glColor3f(  1.0,  0.0,  1.0 );
        glVertex3f( 0.5, -0.5, -0.5 );
        glVertex3f( 0.5,  0.5, -0.5 );
        glVertex3f( 0.5,  0.5,  0.5 );
        glVertex3f( 0.5, -0.5,  0.5 );
        glEnd();
         
        glBegin(GL_POLYGON);
        //green
        glColor3f(   0.0,  1.0,  0.0 );
        glVertex3f( -0.5, -0.5,  0.5 );
        glVertex3f( -0.5,  0.5,  0.5 );
        glVertex3f( -0.5,  0.5, -0.5 );
        glVertex3f( -0.5, -0.5, -0.5 );
        glEnd();
         
        glBegin(GL_POLYGON);
        //blue
        glColor3f(   0.0,  0.0,  1.0 );
        glVertex3f(  0.5,  0.5,  0.5 );
        glVertex3f(  0.5,  0.5, -0.5 );
        glVertex3f( -0.5,  0.5, -0.5 );
        glVertex3f( -0.5,  0.5,  0.5 );
        glEnd();
         
        glBegin(GL_POLYGON);
        //red
        glColor3f(   1.0,  0.0,  0.0 );
        glVertex3f(  0.5, -0.5, -0.5 );
        glVertex3f(  0.5, -0.5,  0.5 );
        glVertex3f( -0.5, -0.5,  0.5 );
        glVertex3f( -0.5, -0.5, -0.5 );
        glEnd();
		
        glFlush();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}