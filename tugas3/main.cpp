#include "GLFW/glfw3.h"
#include "cube.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <string>

using namespace std;

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

static void drawCube(Cube cube){
        
    if(cube.getCode().substr(0,1)=="1"){
        //front yellow
        glColor3f(   1.0,  1.0, 0.5 ); 
    }
    else{
        glColor3f(   0.0,  0.0, 0.0 );
    }
    glBegin(GL_POLYGON);  
    glVertex3f( cube.getX()+ 0.5f, cube.getY()- 0.5f, cube.getZ() -0.5f ); 
    glVertex3f( cube.getX()+ 0.5f, cube.getY()+ 0.5f, cube.getZ() -0.5f ); 
    glVertex3f( cube.getX()- 0.5f, cube.getY()+ 0.5f, cube.getZ() -0.5f );
    glVertex3f( cube.getX()- 0.5f, cube.getY()- 0.5f, cube.getZ() -0.5f );
    glEnd(); 
    
    if(cube.getCode().substr(1,1)=="1"){
        //left green
        glColor3f(   0.0,  0.7,  0.3 );
    }
    else{
        glColor3f(   0.0,  0.0, 0.0 );
    }
    glBegin(GL_POLYGON);
    glVertex3f( cube.getX()- 0.5, cube.getY()- 0.5,  cube.getZ() +0.5 );
    glVertex3f( cube.getX()- 0.5, cube.getY()+ 0.5,  cube.getZ() +0.5 );
    glVertex3f( cube.getX()- 0.5, cube.getY()+ 0.5, cube.getZ() -0.5 );
    glVertex3f( cube.getX()- 0.5, cube.getY()- 0.5, cube.getZ() -0.5 );
    glEnd();
    
    if(cube.getCode().substr(2,1)=="1"){
        // right red
        glColor3f(  1.0,  0.3,  0.3 );
    }
    else{
        glColor3f(   0.0,  0.0, 0.0 );
    }
    glBegin(GL_POLYGON);
    glVertex3f( cube.getX()+ 0.5, cube.getY()- 0.5, cube.getZ() -0.5 );
    glVertex3f( cube.getX()+ 0.5, cube.getY()+ 0.5, cube.getZ() -0.5 );
    glVertex3f( cube.getX()+ 0.5, cube.getY()+ 0.5,  cube.getZ() +0.5 );
    glVertex3f( cube.getX()+ 0.5, cube.getY()- 0.5,  cube.getZ() +0.5 );
    glEnd();
    
    if(cube.getCode().substr(3,1)=="1"){
        //top blue
        glColor3f( 0.0, 0.3, 0.7 ); 
    }
    else{
        glColor3f(   0.0,  0.0, 0.0 );
    }
    glBegin(GL_POLYGON);
    glVertex3f( cube.getX()+ 0.5, cube.getY()+ 0.5, cube.getZ() + 0.5 );
    glVertex3f( cube.getX()+ 0.5, cube.getY()+ 0.5, cube.getZ() -0.5 );
    glVertex3f( cube.getX()- 0.5, cube.getY()+ 0.5, cube.getZ() -0.5 );
    glVertex3f( cube.getX()- 0.5, cube.getY()+ 0.5, cube.getZ() + 0.5 );
    glEnd();
    
    if(cube.getCode().substr(4,1)=="1"){
        //bottom orange
        glColor3f(   1.0,  0.5,  0.0 );
    }
    else{
        glColor3f(   0.0,  0.0, 0.0 );
    }
    glBegin(GL_POLYGON);
    glVertex3f( cube.getX()+ 0.5, cube.getY()- 0.5, cube.getZ() -0.5 );
    glVertex3f( cube.getX()+ 0.5, cube.getY()- 0.5, cube.getZ() + 0.5 );
    glVertex3f( cube.getX()- 0.5, cube.getY()- 0.5, cube.getZ() + 0.5 );
    glVertex3f( cube.getX()- 0.5, cube.getY()- 0.5, cube.getZ() -0.5 );
    glEnd();
    
    if(cube.getCode().substr(5,1)=="1"){
        //back white
        glColor3f(   1.0,  1.0,  1.0 );
    }
    else{
        glColor3f(   0.0,  0.0, 0.0 );
    }
    glBegin(GL_POLYGON);
    glVertex3f( cube.getX()+ 0.5, cube.getY()- 0.5, cube.getZ() +0.5 );
    glVertex3f( cube.getX()+ 0.5, cube.getY()+ 0.5, cube.getZ() +0.5 );
    glVertex3f( cube.getX()- 0.5, cube.getY()+ 0.5, cube.getZ() +0.5 );
    glVertex3f( cube.getX()- 0.5, cube.getY()- 0.5, cube.getZ() +0.5 );
    glEnd();
}

int rotate_x = -45;
int rotate_y = 45;
float dis = 1.2;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
      if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

      //  Right arrow - increase rotation by 5 degree
      if (key == GLFW_KEY_D && action == GLFW_PRESS){
        
      }
}

int main(void)
{
    GLFWwindow* window;
    vector<Cube> Rubik;
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

    //dari kiri atas ke kanan
    Rubik.push_back(Cube("110100",-dis,dis,-dis));
    Rubik.push_back(Cube("100100",0,dis,-dis));
    Rubik.push_back(Cube("101100",dis,dis,-dis));
    //dari kiri tengah ke kanan
    Rubik.push_back(Cube("110000",-dis,0,-dis));
    Rubik.push_back(Cube("100000",0,0,-dis));
    Rubik.push_back(Cube("101000",dis,0,-dis));
    //dari kiri bawah ke kanan
    Rubik.push_back(Cube("110010",-dis,-dis,-dis));
    Rubik.push_back(Cube("100010",0,-dis,-dis));
    Rubik.push_back(Cube("101010",dis,-dis,-dis));

    Rubik.push_back(Cube("010100",-dis,dis,0));
    Rubik.push_back(Cube("000100",0,dis,0));
    Rubik.push_back(Cube("001100",dis,dis,0));
    Rubik.push_back(Cube("010000",-dis,0,0));
    Rubik.push_back(Cube("000000",0,0,0));
    Rubik.push_back(Cube("001000",dis,0,0));
    Rubik.push_back(Cube("010010",-dis,-dis,0));
    Rubik.push_back(Cube("000010",0,-dis,0));
    Rubik.push_back(Cube("001010",dis,-dis,0));
    Rubik.push_back(Cube("010101",-dis,dis,dis));
    Rubik.push_back(Cube("000101",0,dis,dis));
    Rubik.push_back(Cube("001101",dis,dis,dis));
    Rubik.push_back(Cube("010001",-dis,0,dis));
    Rubik.push_back(Cube("000001",0,0,dis));
    Rubik.push_back(Cube("001001",dis,0,dis));
    Rubik.push_back(Cube("010011",-dis,-dis,dis));
    Rubik.push_back(Cube("001011",dis,-dis,dis));
    Rubik.push_back(Cube("000011",0,-dis,dis));

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

        for(int i = 0;i<Rubik.size();i++){
            //glLoadIdentity();
            //glRotatef( rotate_x, 1.0, 0.0, 0.0 );
            drawCube(Rubik.at(i));
        }

        glFlush();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}