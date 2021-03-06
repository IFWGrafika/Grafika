#include "GLFW/glfw3.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;

typedef struct Point{
	double x;
	double y;
} Point;

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void drawTriangle(vector< Point > trianglePoint){
	for(int i=0; i<trianglePoint.size()-1; i++){
		glBegin(GL_POINTS);
		glVertex2f(trianglePoint[i].x, trianglePoint[i].y);
		glEnd(); 
		glBegin(GL_POINTS);
		glVertex2f(trianglePoint[i+1].x, trianglePoint[i+1].y);
		glEnd(); 
	}
	glBegin(GL_LINES);
	glVertex2f(trianglePoint[trianglePoint.size()-1].x, trianglePoint[trianglePoint.size()-1].y);
	glVertex2f(trianglePoint[0].x, trianglePoint[0].y);
	glEnd();
	
}

void drawSierpinski(vector< vector < Point > > list, int n)
{
	if(n==0){
		//do-nothings
	} else {
		vector< vector < Point > > new_list;
		vector < Point > trianglePoint;
		vector < Point > trianglePoint2;
		Point p;
		for(int i=0; i<list.size();i++){
			trianglePoint.clear();
			for(int j=0; j<list[i].size()-1;j++){
				p.x = (list[i][j].x + list[i][j+1].x)/2;
				p.y = (list[i][j].y + list[i][j+1].y)/2;
				trianglePoint.push_back(p);
			}
			p.x = (list[i][list[i].size()-1].x + list[i][0].x)/2;
			p.y = (list[i][list[i].size()-1].y + list[i][0].y)/2;
			trianglePoint.push_back(p);
			//new_list.push_back(trianglePoint);
			drawTriangle(trianglePoint);
			for(int k=1; k<list[i].size();k++){
				trianglePoint2.clear();
				p = trianglePoint[k-1];
				trianglePoint2.push_back(p);
				p = trianglePoint[k];
				trianglePoint2.push_back(p);
				p = list[i][k];
				trianglePoint2.push_back(p);
				new_list.push_back(trianglePoint2);
			}
			trianglePoint2.clear();
			p = trianglePoint[list[i].size()-1];
			trianglePoint2.push_back(p);
			p = trianglePoint[0];
			trianglePoint2.push_back(p);
			p = list[i][0];
			trianglePoint2.push_back(p);
			new_list.push_back(trianglePoint2);
		}
		drawSierpinski(new_list, n-1);
	}
	
}

int main(int argc, char *argv[])
{
	if(argc<2){
		return 0;
	}
	
	int loop = atoi(argv[1]);
	
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
		
		//int loop = 7;
		vector< vector < Point > > list;
		vector< Point > trianglePoint;
		Point p;
		p.x = -0.6f;
		p.y = -0.4f;
		trianglePoint.push_back(p);
		p.x = 0.f;
		p.y = 0.6f;
		trianglePoint.push_back(p);
		p.x = 0.6f;
		p.y = -0.4f;
		trianglePoint.push_back(p);
		list.push_back(trianglePoint);
		drawTriangle(trianglePoint);
		drawSierpinski(list,loop);  
   
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}