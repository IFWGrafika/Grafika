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

bool debug = true;
int rotate_x = -45;
int rotate_y = 45;
float dis = 1.2;

static void drawCube(Cube cube){
        
    if(cube.getCode().substr(0,1)=="1" ||debug){
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
    
    if(cube.getCode().substr(1,1)=="1" ||debug){
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
    
    if(cube.getCode().substr(2,1)=="1" ||debug){
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
    
    if(cube.getCode().substr(3,1)=="1" ||debug){
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
    
    if(cube.getCode().substr(4,1)=="1" ||debug){
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
    
    if(cube.getCode().substr(5,1)=="1" ||debug){
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

static vector<Cube> Rubik;

static void swapProp(int i,int j){
    Property temp = Rubik.at(i).getProperty();
    Rubik.at(i).setProperty(Rubik.at(j).getProperty());
    Rubik.at(j).setProperty(temp);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
      if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

      if (key == GLFW_KEY_S && action == GLFW_PRESS){

        Rubik.at(1).setRotateX((Rubik.at(1).getRotateX()-90)%360);
        Rubik.at(4).setRotateX((Rubik.at(4).getRotateX()-90)%360);
        Rubik.at(7).setRotateX((Rubik.at(7).getRotateX()-90)%360);
        Rubik.at(10).setRotateX((Rubik.at(10).getRotateX()-90)%360);
        Rubik.at(13).setRotateX((Rubik.at(13).getRotateX()-90)%360);
        Rubik.at(16).setRotateX((Rubik.at(16).getRotateX()-90)%360);
        Rubik.at(19).setRotateX((Rubik.at(19).getRotateX()-90)%360);
        Rubik.at(22).setRotateX((Rubik.at(22).getRotateX()-90)%360);
        Rubik.at(25).setRotateX((Rubik.at(25).getRotateX()-90)%360);

        //bagian pinggir
        swapProp(1,7);
        swapProp(1,25);
        swapProp(1,19);

        //bagian tengah
        swapProp(4,16);
        swapProp(4,22);
        swapProp(4,10);
      }

      else if (key == GLFW_KEY_E && action == GLFW_PRESS){

        Rubik.at(0).setRotateY((Rubik.at(0).getRotateY()+90)%360);
        Rubik.at(1).setRotateY((Rubik.at(1).getRotateY()+90)%360);
        Rubik.at(2).setRotateY((Rubik.at(2).getRotateY()+90)%360);
        Rubik.at(9).setRotateY((Rubik.at(9).getRotateY()+90)%360);
        Rubik.at(10).setRotateY((Rubik.at(10).getRotateY()+90)%360);
        Rubik.at(11).setRotateY((Rubik.at(11).getRotateY()+90)%360);
        Rubik.at(18).setRotateY((Rubik.at(18).getRotateY()+90)%360);
        Rubik.at(19).setRotateY((Rubik.at(19).getRotateY()+90)%360);
        Rubik.at(20).setRotateY((Rubik.at(20).getRotateY()+90)%360);

        //bagian pinggir
        swapProp(0,2);
        swapProp(0,20);
        swapProp(0,18);

        //bagian tengah
        swapProp(1,11);
        swapProp(1,19);
        swapProp(1,9);
      }

      else if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
        rotate_y += 90;
     
      //  Left arrow - decrease rotation by 5 degree
      else if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
        rotate_y -= 90;
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

    //0
    Rubik.push_back(Cube("110100",-dis,dis,-dis));
    //1
    Rubik.push_back(Cube("100100",0,dis,-dis));
    //2
    Rubik.push_back(Cube("101100",dis,dis,-dis));
    //3
    Rubik.push_back(Cube("110000",-dis,0,-dis));
    //4
    Rubik.push_back(Cube("100000",0,0,-dis));
    //5
    Rubik.push_back(Cube("101000",dis,0,-dis));
    //6
    Rubik.push_back(Cube("110010",-dis,-dis,-dis));
    //7
    Rubik.push_back(Cube("100010",0,-dis,-dis));
    //8
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
    Rubik.push_back(Cube("000011",0,-dis,dis));
    Rubik.push_back(Cube("001011",dis,-dis,dis));

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);  
        
        // glScalef(0.1,0.1,0.1);
        // glRotatef(rotate_x,1.0,0.0,0.0);
        // glRotatef(rotate_y,0.0,1.0,0.0);
        
        for(int i = 0;i<Rubik.size();i++){
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
            glMatrixMode(GL_MODELVIEW);
            glPushMatrix();

            glRotatef(rotate_x,1.0,0.0,0.0);
            glRotatef(rotate_y,0.0,1.0,0.0);
            
            glTranslatef(Rubik.at(i).getX(),0,0);
            glRotatef((float)Rubik.at(i).getRotateX(), 1.0, 0.0, 0.0 );
            glTranslatef(-Rubik.at(i).getX(),0,0);

            glTranslatef(0,Rubik.at(i).getY(),0);
            glRotatef((float)Rubik.at(i).getRotateY(), 0.0, 1.0, 0.0 );
            glTranslatef(0,-Rubik.at(i).getY(),0);

            glTranslatef(0,0,Rubik.at(i).getZ());
            glRotatef((float)Rubik.at(i).getRotateZ(), 0.0, 0.0, 1.0 );
            glTranslatef(0,0,-Rubik.at(i).getZ());

            glScalef(0.1,0.1,0.1);
            
            drawCube(Rubik.at(i));
            glPopMatrix();
            glLoadIdentity();
        
            // glLoadIdentity();
        }

        glFlush();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}