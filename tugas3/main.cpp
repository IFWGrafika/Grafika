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
float dis = 0.12;
static vector<Cube> Rubik;

static void drawCube(Cube cube){
        
    if(cube.getCode().substr(0,1)=="1" ||debug){
        //front yellow
        glColor3f(   1.0,  1.0, 0.5 ); 
    }
    else{
        glColor3f(   0.0,  0.0, 0.0 );
    }
    glBegin(GL_POLYGON);  
    glVertex3f(  0.5f, - 0.5f, -0.5f ); 
    glVertex3f(  0.5f,  0.5f, -0.5f ); 
    glVertex3f( - 0.5f,  0.5f, -0.5f );
    glVertex3f( - 0.5f, - 0.5f, -0.5f );
    glEnd(); 
    
    if(cube.getCode().substr(1,1)=="1" ||debug){
        //left green
        glColor3f(   0.0,  0.7,  0.3 );
    }
    else{
        glColor3f(   0.0,  0.0, 0.0 );
    }
    glBegin(GL_POLYGON);
    glVertex3f( - 0.5, - 0.5,  0.5 );
    glVertex3f( - 0.5,  0.5,  0.5 );
    glVertex3f( - 0.5,  0.5, -0.5 );
    glVertex3f( - 0.5, - 0.5, -0.5 );
    glEnd();
    
    if(cube.getCode().substr(2,1)=="1" ||debug){
        // right red
        glColor3f(  1.0,  0.3,  0.3 );
    }
    else{
        glColor3f(   0.0,  0.0, 0.0 );
    }
    glBegin(GL_POLYGON);
    glVertex3f(  0.5, - 0.5, -0.5 );
    glVertex3f(  0.5,  0.5, -0.5 );
    glVertex3f(  0.5,  0.5,  0.5 );
    glVertex3f(  0.5, - 0.5,  0.5 );
    glEnd();
    
    if(cube.getCode().substr(3,1)=="1" ||debug){
        //top blue
        glColor3f( 0.0, 0.3, 0.7 ); 
    }
    else{
        glColor3f(   0.0,  0.0, 0.0 );
    }
    glBegin(GL_POLYGON);
    glVertex3f(  0.5,  0.5,  0.5 );
    glVertex3f(  0.5,  0.5, -0.5 );
    glVertex3f( - 0.5,  0.5, -0.5 );
    glVertex3f( - 0.5,  0.5,  0.5 );
    glEnd();
    
    if(cube.getCode().substr(4,1)=="1" ||debug){
        //bottom orange
        glColor3f(   1.0,  0.5,  0.0 );
    }
    else{
        glColor3f(   0.0,  0.0, 0.0 );
    }
    glBegin(GL_POLYGON);
    glVertex3f(  0.5, - 0.5, -0.5 );
    glVertex3f(  0.5, - 0.5,  0.5 );
    glVertex3f( - 0.5, - 0.5,  0.5 );
    glVertex3f( - 0.5, - 0.5, -0.5 );
    glEnd();
    
    if(cube.getCode().substr(5,1)=="1" ||debug){
        //back white
        glColor3f(   1.0,  1.0,  1.0 );
    }
    else{
        glColor3f(   0.0,  0.0, 0.0 );
    }
    glBegin(GL_POLYGON);
    glVertex3f(  0.5, - 0.5, 0.5 );
    glVertex3f(  0.5,  0.5, 0.5 );
    glVertex3f( - 0.5,  0.5, 0.5 );
    glVertex3f( - 0.5, - 0.5, 0.5 );
    glEnd();
}

static void swapProp(int i,int j){
    // Property temp = Rubik.at(i).getProperty();
    // Rubik.at(i).setProperty(Rubik.at(j).getProperty());
    // Rubik.at(j).setProperty(temp);

    Cube temp = Rubik.at(i);
    Rubik.at(i) = Rubik.at(j);
    Rubik.at(j) = temp;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
      if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

      if (key == GLFW_KEY_S && action == GLFW_PRESS){

        // //bagian pinggir
        swapProp(1,13);swapProp(13,7);
        swapProp(7,13);swapProp(13,25);
        swapProp(25,13);swapProp(13,19);
        swapProp(19,13);swapProp(13,1);

        //bagian tengah
        swapProp(4,13);swapProp(13,16);
        swapProp(16,13);swapProp(13,22);
        swapProp(22,13);swapProp(13,10);
        swapProp(10,13);swapProp(13,4);

        // Rubik.at(1).setRotateX((Rubik.at(1).getRotateX()-90)%360);
        // Rubik.at(4).setRotateX((Rubik.at(4).getRotateX()-90)%360);
        // Rubik.at(7).setRotateX((Rubik.at(7).getRotateX()-90)%360);
        // Rubik.at(10).setRotateX((Rubik.at(10).getRotateX()-90)%360);
        // Rubik.at(13).setRotateX((Rubik.at(13).getRotateX()-90)%360);
        // Rubik.at(16).setRotateX((Rubik.at(16).getRotateX()-90)%360);
        // Rubik.at(19).setRotateX((Rubik.at(19).getRotateX()-90)%360);
        // Rubik.at(22).setRotateX((Rubik.at(22).getRotateX()-90)%360);
        // Rubik.at(25).setRotateX((Rubik.at(25).getRotateX()-90)%360);

        Rubik.at(1).addRotation(Rotation('x',-90));
        Rubik.at(4).addRotation(Rotation('x',-90));
        Rubik.at(7).addRotation(Rotation('x',-90));
        Rubik.at(10).addRotation(Rotation('x',-90));
        Rubik.at(13).addRotation(Rotation('x',-90));
        Rubik.at(16).addRotation(Rotation('x',-90));
        Rubik.at(19).addRotation(Rotation('x',-90));
        Rubik.at(22).addRotation(Rotation('x',-90));
        Rubik.at(25).addRotation(Rotation('x',-90));

        
      }

      else if (key == GLFW_KEY_E && action == GLFW_PRESS){

        //bagian pinggir
        swapProp(0,13);swapProp(13,2);
        swapProp(2,13);swapProp(13,20);
        swapProp(20,13);swapProp(13,18);
        swapProp(18,13);swapProp(13,0);

        //bagian tengah
        swapProp(1,13);swapProp(13,11);
        swapProp(11,13);swapProp(13,19);
        swapProp(19,13);swapProp(13,9);
        swapProp(9,13);swapProp(13,1);
        // Rubik.at(0).setRotateY((Rubik.at(0).getRotateY()-90)%360);
        // Rubik.at(1).setRotateY((Rubik.at(1).getRotateY()-90)%360);
        // Rubik.at(2).setRotateY((Rubik.at(2).getRotateY()-90)%360);
        // Rubik.at(9).setRotateY((Rubik.at(9).getRotateY()-90)%360);
        // Rubik.at(10).setRotateY((Rubik.at(10).getRotateY()-90)%360);
        // Rubik.at(11).setRotateY((Rubik.at(11).getRotateY()-90)%360);
        // Rubik.at(18).setRotateY((Rubik.at(18).getRotateY()-90)%360);
        // Rubik.at(19).setRotateY((Rubik.at(19).getRotateY()-90)%360);
        // Rubik.at(20).setRotateY((Rubik.at(20).getRotateY()-90)%360);

        Rubik.at(0).addRotation(Rotation('y',-90));
        Rubik.at(1).addRotation(Rotation('y',-90));
        Rubik.at(2).addRotation(Rotation('y',-90));
        Rubik.at(9).addRotation(Rotation('y',-90));
        Rubik.at(10).addRotation(Rotation('y',-90));
        Rubik.at(11).addRotation(Rotation('y',-90));
        Rubik.at(18).addRotation(Rotation('y',-90));
        Rubik.at(19).addRotation(Rotation('y',-90));
        Rubik.at(20).addRotation(Rotation('y',-90));


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
        
        for(int i = 0;i<Rubik.size();i++){
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
            glMatrixMode(GL_MODELVIEW);
            glPushMatrix();

            glRotatef(rotate_x,1.0,0.0,0.0);
            glRotatef(rotate_y,0.0,1.0,0.0);

            glTranslatef(Rubik.at(i).getX(),Rubik.at(i).getY(),Rubik.at(i).getZ());

            for(int j = Rubik.at(i).getRotation().size()-1;j>=0;j--){
                switch(Rubik.at(i).getRotation().at(j).getCode()){
                    case 'x':
                        glRotatef(Rubik.at(i).getRotation().at(j).getAngle(), 1.0, 0.0, 0.0 );
                        break;
                    case 'y':
                        glRotatef(Rubik.at(i).getRotation().at(j).getAngle(), 0.0, 1.0, 0.0 );
                        break;
                    case 'z':
                        glRotatef(Rubik.at(i).getRotation().at(j).getAngle(), 0.0, 0.0, 1.0 );
                        break;
                }
            }

            // glTranslatef(Rubik.at(i).getX(),Rubik.at(i).getY(),Rubik.at(i).getZ());

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