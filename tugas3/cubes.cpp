#include "GLFW/glfw3.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string>

using namespace std;

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

static void drawCube(string code, float x, float y, float z){
        
    if(code.substr(0,1)=="1"){
        //front yellow
        glColor3f(   1.0,  1.0, 0.5 ); 
    }
    else{
        glColor3f(   0.0,  0.0, 0.0 );
    }
    glBegin(GL_POLYGON);  
    glVertex3f( x + 0.5f, y - 0.5f, z-0.5f ); 
    glVertex3f( x + 0.5f, y + 0.5f, z-0.5f ); 
    glVertex3f( x - 0.5f, y + 0.5f, z-0.5f );
    glVertex3f( x - 0.5f, y - 0.5f, z-0.5f );
    glEnd(); 
    
    if(code.substr(1,1)=="1"){
        //left green
        glColor3f(   0.0,  0.7,  0.3 );
    }
    else{
        glColor3f(   0.0,  0.0, 0.0 );
    }
    glBegin(GL_POLYGON);
    glVertex3f( x - 0.5, y - 0.5,  z+0.5 );
    glVertex3f( x - 0.5, y + 0.5,  z+0.5 );
    glVertex3f( x - 0.5, y + 0.5, z-0.5 );
    glVertex3f( x - 0.5, y - 0.5, z-0.5 );
    glEnd();
    
    if(code.substr(2,1)=="1"){
        // right red
        glColor3f(  1.0,  0.3,  0.3 );
    }
    else{
        glColor3f(   0.0,  0.0, 0.0 );
    }
    glBegin(GL_POLYGON);
    glVertex3f( x + 0.5, y - 0.5, z-0.5 );
    glVertex3f( x + 0.5, y + 0.5, z-0.5 );
    glVertex3f( x + 0.5, y + 0.5,  z+0.5 );
    glVertex3f( x + 0.5, y - 0.5,  z+0.5 );
    glEnd();
    
    if(code.substr(3,1)=="1"){
        //top blue
        glColor3f( 0.0, 0.3, 0.7 ); 
    }
    else{
        glColor3f(   0.0,  0.0, 0.0 );
    }
    glBegin(GL_POLYGON);
    glVertex3f( x + 0.5, y + 0.5, z+ 0.5 );
    glVertex3f( x + 0.5, y + 0.5, z-0.5 );
    glVertex3f( x - 0.5, y + 0.5, z-0.5 );
    glVertex3f( x - 0.5, y + 0.5, z+ 0.5 );
    glEnd();
    
    if(code.substr(4,1)=="1"){
        //bottom orange
        glColor3f(   1.0,  0.5,  0.0 );
    }
    else{
        glColor3f(   0.0,  0.0, 0.0 );
    }
    glBegin(GL_POLYGON);
    glVertex3f( x + 0.5, y - 0.5, z-0.5 );
    glVertex3f( x + 0.5, y - 0.5, z+ 0.5 );
    glVertex3f( x - 0.5, y - 0.5, z+ 0.5 );
    glVertex3f( x - 0.5, y - 0.5, z-0.5 );
    glEnd();
    
    if(code.substr(5,1)=="1"){
        //back white
        glColor3f(   1.0,  1.0,  1.0 );
    }
    else{
        glColor3f(   0.0,  0.0, 0.0 );
    }
    glBegin(GL_POLYGON);
    glVertex3f( x + 0.5, y - 0.5, z+0.5 );
    glVertex3f( x + 0.5, y + 0.5, z+0.5 );
    glVertex3f( x - 0.5, y + 0.5, z+0.5 );
    glVertex3f( x - 0.5, y - 0.5, z+0.5 );
    glEnd();
}

int rotate_x = -45;
int rotate_y = 45;
float dis = 1.2;

int rotate1 = 0;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
      if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

      //  Right arrow - increase rotation by 5 degree
      if (key == GLFW_KEY_D && action == GLFW_PRESS){
        rotate_x += 180;
        rotate_x = rotate_x % 360;
      }
        
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

        glScalef(0.1,0.1,0.1);


        drawCube("000000",0,0,0);
        drawCube("010000",-dis,0,0);
        drawCube("001000",dis,0,0);

        drawCube("000010",0,-dis,0);
        drawCube("010010",-dis,-dis,0);
        drawCube("001010",dis,-dis,0);

        drawCube("000100",0,dis,0);
        drawCube("010100",-dis,dis,0);
        drawCube("001100",dis,dis,0);

        drawCube("100000",0,0,-dis);
        drawCube("110000",-dis,0,-dis);
        drawCube("101000",dis,0,-dis);

        drawCube("100010",0,-dis,-dis);
        drawCube("110010",-dis,-dis,-dis);
        drawCube("101010",dis,-dis,-dis);

        drawCube("100100",0,dis,-dis);
        drawCube("110100",-dis,dis,-dis);
        drawCube("101100",dis,dis,-dis);

        drawCube("000001",0,0,dis);
        drawCube("010001",-dis,0,dis);
        drawCube("001001",dis,0,dis);

        drawCube("000011",0,-dis,dis);
        drawCube("010011",-dis,-dis,dis);
        drawCube("001011",dis,-dis,dis);

        drawCube("000101",0,dis,dis);
        drawCube("010101",-dis,dis,dis);
        drawCube("001101",dis,dis,dis);

        glFlush();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}