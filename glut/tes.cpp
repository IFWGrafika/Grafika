#include <GL/GLUT.h>
#include <GL/GLU.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <vector>

#include "cube.h"

using namespace std;

vector < vector < vector < Cube > > > Rubik;
int rotate_x = -45;
int rotate_y = 45;
float dis = 0.21;
bool debug = true;
float ratio;
float cube_size = 0.1f;
void render(void);
int rubik_size = 3;

void keyboard(unsigned char c, int x, int y);
 
void mouse(int button, int state, int x, int y);

GLuint LoadTexture( const char * filename )
{
	GLuint texture;
	int width, height;
	unsigned char * data;
	FILE * file;
	file = fopen( filename, "rb" );

	if ( file == NULL ) return 0;
	// printf("halo");
	width = 128;
	height = 128;
	data = (unsigned char *)malloc( width * height * 3 );
	//int size = fseek(file,);
	fread( data, width * height * 3, 1, file );
	fclose( file );

	for(int i = 0; i < width * height ; ++i)
	{
	   int index = i*3;
	   unsigned char B,R;
	   B = data[index];
	   R = data[index+2];

	   data[index] = R;
	   data[index+2] = B;

	}

	glGenTextures( 1, &texture );
	glBindTexture( GL_TEXTURE_2D, texture );
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );


	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
	gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
	// glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, data);
	free( data );

	return texture;
}


static void drawCube(Cube cube){   
	GLuint texture;
 	texture= LoadTexture( "dark_purple.bmp" );

    // if(cube.getCode().substr(0,1)=="1" ||debug){
    //     //front yellow
    //     glColor3f(   1.0,  1.0, 0.5 ); 
    // }
    // else{
    //     glColor3f(   0.0,  0.0, 0.0 );
    // }
    glEnable(GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, texture);
    glBegin(GL_POLYGON);  
    glTexCoord2f(1, 0);glVertex3f( cube.getX()+ cube_size, cube.getY()- cube_size, cube.getZ() - cube_size  ); 
    glTexCoord2f(0, 0);glVertex3f( cube.getX()+ cube_size, cube.getY()+ cube_size, cube.getZ() - cube_size ); 
    glTexCoord2f(0, 1);glVertex3f( cube.getX()- cube_size, cube.getY()+ cube_size, cube.getZ() - cube_size );
    glTexCoord2f(0, 0);glVertex3f( cube.getX()- cube_size, cube.getY()- cube_size, cube.getZ() - cube_size );
    glEnd(); 
    
    // if(cube.getCode().substr(1,1)=="1" ||debug){
    //     //left green
    //     glColor3f(   0.0,  0.7,  0.3 );
    // }
    // else{
    //     glColor3f(   0.0,  0.0, 0.0 );
    // }

    texture= LoadTexture( "purple.bmp" );
    glEnable(GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, texture);
    glBegin(GL_POLYGON);
    glTexCoord2f(1, 0);glVertex3f( cube.getX()- cube_size, cube.getY()- cube_size,  cube.getZ() +cube_size );
    glTexCoord2f(0, 0);glVertex3f( cube.getX()- cube_size, cube.getY()+ cube_size,  cube.getZ() +cube_size );
    glTexCoord2f(0, 1);glVertex3f( cube.getX()- cube_size, cube.getY()+ cube_size, cube.getZ() -cube_size );
    glTexCoord2f(0, 0);glVertex3f( cube.getX()- cube_size, cube.getY()- cube_size, cube.getZ() -cube_size );
    glEnd();
    
    // if(cube.getCode().substr(2,1)=="1" ||debug){
    //     // right red
    //     glColor3f(  1.0,  0.3,  0.3 );
    // }
    // else{
    //     glColor3f(   0.0,  0.0, 0.0 );
    // }

    texture= LoadTexture( "green.bmp" );
	glEnable(GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, texture);
    glBegin(GL_POLYGON);
    glTexCoord2f(0, 0);glVertex3f( cube.getX()+ cube_size, cube.getY()- cube_size, cube.getZ() -cube_size );
    glTexCoord2f(1, 1);glVertex3f( cube.getX()+ cube_size, cube.getY()+ cube_size, cube.getZ() -cube_size );
    glTexCoord2f(1, 1);glVertex3f( cube.getX()+ cube_size, cube.getY()+ cube_size,  cube.getZ() +cube_size );
    glTexCoord2f(0, 0);glVertex3f( cube.getX()+ cube_size, cube.getY()- cube_size,  cube.getZ() +cube_size );
    glEnd();
    
    // if(cube.getCode().substr(3,1)=="1" ||debug){
    //     //top blue
    //     glColor3f( 0.0, 0.3, 0.7 ); 
    // }
    // else{
    //     glColor3f(   0.0,  0.0, 0.0 );
    // }
    texture= LoadTexture( "blue.bmp" );
    glEnable(GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, texture);
    glBegin(GL_POLYGON);
    glTexCoord2f(1, 0);glVertex3f( cube.getX()+ cube_size, cube.getY()+ cube_size, cube.getZ() + cube_size );
    glTexCoord2f(0, 1);glVertex3f( cube.getX()+ cube_size, cube.getY()+ cube_size, cube.getZ() -cube_size );
    glTexCoord2f(0, 0);glVertex3f( cube.getX()- cube_size, cube.getY()+ cube_size, cube.getZ() -cube_size );
    glTexCoord2f(1, 1);glVertex3f( cube.getX()- cube_size, cube.getY()+ cube_size, cube.getZ() + cube_size );
    glEnd();
    
    // if(cube.getCode().substr(4,1)=="1" ||debug){
    //     //bottom orange
    //     glColor3f(1.0,  0.5,  0.0);
    // }
    // else{
    //     glColor3f(0.0,  0.0, 0.0);
    // }
    texture= LoadTexture( "dark_blue.bmp" );
    glEnable(GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, texture);
    glBegin(GL_POLYGON);
    glTexCoord2f(1, 0);glVertex3f( cube.getX()+ cube_size, cube.getY()- cube_size, cube.getZ() -cube_size );
    glTexCoord2f(0, 0);glVertex3f( cube.getX()+ cube_size, cube.getY()- cube_size, cube.getZ() + cube_size );
    glTexCoord2f(0, 1);glVertex3f( cube.getX()- cube_size, cube.getY()- cube_size, cube.getZ() + cube_size );
    glTexCoord2f(1, 1);glVertex3f( cube.getX()- cube_size, cube.getY()- cube_size, cube.getZ() -cube_size );
    glEnd();
    
    // if(cube.getCode().substr(5,1)=="1" ||debug){
    //     glColor3f(1.0, 1.0, 1.0);
    // }
    // else{
    //     glColor3f(0.0, 0.0, 0.0);
    // }
    texture= LoadTexture( "red.bmp" );
    glEnable(GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, texture);
    glBegin(GL_POLYGON);
    glTexCoord2f(1, 0);glVertex3f( cube.getX()+ cube_size, cube.getY()- cube_size, cube.getZ() +cube_size );
    glTexCoord2f(0, 0);glVertex3f( cube.getX()+ cube_size, cube.getY()+ cube_size, cube.getZ() +cube_size );
    glTexCoord2f(0, 1);glVertex3f( cube.getX()- cube_size, cube.getY()+ cube_size, cube.getZ() +cube_size );
    glTexCoord2f(1, 1);glVertex3f( cube.getX()- cube_size, cube.getY()- cube_size, cube.getZ() +cube_size );
    glEnd();
}

int main(int argc, char** argv) {

        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
        glutInitWindowPosition(100, 100);
        glutInitWindowSize(640, 640);
        glutCreateWindow("Simple GLUT Application");
		
        int width, height;
        ratio = width / (float) height;
        
		
        glutDisplayFunc(render);       
        glutKeyboardFunc(keyboard);
        glutMouseFunc(mouse);
		
		//dari kiri atas ke kanan
		vector < vector < Cube > > Side;
		vector < Cube > Row;
		Row.push_back(Cube("110100",-dis,dis,-dis));
		Row.push_back(Cube("100100",0,dis,-dis));
		Row.push_back(Cube("101100",dis,dis,-dis));
		Side.push_back(Row);
		Row.clear();
		//dari kiri tengah ke kanan
		Row.push_back(Cube("110000",-dis,0,-dis));
		Row.push_back(Cube("100000",0,0,-dis));
		Row.push_back(Cube("101000",dis,0,-dis));
		Side.push_back(Row);
		Row.clear();
		//dari kiri bawah ke kanan
		Row.push_back(Cube("110010",-dis,-dis,-dis));
		Row.push_back(Cube("100010",0,-dis,-dis));
		Row.push_back(Cube("101010",dis,-dis,-dis));
		Side.push_back(Row);
		Row.clear();
		Rubik.push_back(Side);
		Side.clear();

		Row.push_back(Cube("010100",-dis,dis,0));
		Row.push_back(Cube("000100",0,dis,0));
		Row.push_back(Cube("001100",dis,dis,0));
		Side.push_back(Row);
		Row.clear();

		Row.push_back(Cube("010000",-dis,0,0));
		Row.push_back(Cube("000000",0,0,0));
		Row.push_back(Cube("001000",dis,0,0));
		Side.push_back(Row);
		Row.clear();

		Row.push_back(Cube("010010",-dis,-dis,0));
		Row.push_back(Cube("000010",0,-dis,0));
		Row.push_back(Cube("001010",dis,-dis,0));
		Side.push_back(Row);
		Row.clear();
		Rubik.push_back(Side);
		Side.clear();

		Row.push_back(Cube("010101",-dis,dis,dis));
		Row.push_back(Cube("000101",0,dis,dis));
		Row.push_back(Cube("001101",dis,dis,dis));
		Side.push_back(Row);
		Row.clear();

		Row.push_back(Cube("010001",-dis,0,dis));
		Row.push_back(Cube("000001",0,0,dis));
		Row.push_back(Cube("001001",dis,0,dis));
		Side.push_back(Row);
		Row.clear();

		Row.push_back(Cube("010011",-dis,-dis,dis));
		Row.push_back(Cube("000011",0,-dis,dis));
		Row.push_back(Cube("001011",dis,-dis,dis));
		Side.push_back(Row);
		Row.clear();
		Rubik.push_back(Side);
		Side.clear();

		/*for(int i = 0;i<Rubik.size();i++){
			for(int j = 0;j<Rubik[i].size();j++){
				for(int k = 0;k<Rubik[i][j].size();k++){
					if(j==0){
						int new_rotateY = (Rubik[i][j][k].getRotateY() + 1) % 4;
						Rubik[i][j][k].setRotateY(new_rotateY);
					}
				}
			}
		}*/
        glutMainLoop();
}

void rotateX(int row, int direction){
	for(int i = 0; i < Rubik.size(); i++) {
		for(int j = 0; j < Rubik[i].size(); j++) {
			for(int k = 0; k<Rubik[i][j].size(); k++){
				if(k==row){
					int new_rotateX = (Rubik[i][j][k].getRotateX() + direction) % 4;
					Rubik[i][j][k].setRotateX(new_rotateX);
				}
			}
		}
	}
	vector < vector < vector < Cube > > > newRubik = Rubik;
	for(int i = 0; i < newRubik.size(); i++) {
		for(int j = 0; j < newRubik[i].size(); j++) {
			for(int k = 0; k < newRubik[i][j].size(); k++){
				if(k==row){
					int x = rubik_size - 1 - j;
					int y = i;
					int z = row;
					newRubik[i][j][k]=Rubik[x][y][z];
				}
			}
		}
	}
	Rubik = newRubik;
}

void rotateY(int row, int direction){
	for(int i = 0; i < Rubik.size(); i++) {
		for(int j = 0; j < Rubik[i].size(); j++) {
			if(j==row){
				for(int k = 0; k<Rubik[i][j].size(); k++){
					int new_rotateY = (Rubik[i][j][k].getRotateY() + direction) % 4;
					Rubik[i][j][k].setRotateY(new_rotateY);
				}
			}
		}
	}
	vector < vector < vector < Cube > > > newRubik = Rubik;
	for(int i = 0; i < newRubik.size(); i++) {
		for(int j = 0; j < newRubik[i].size(); j++) {
			if(j==row){
				for(int k = 0; k<newRubik[i][j].size(); k++){
					int x = rubik_size - 1 - k;
					int y = row;
					int z = i;
					newRubik[i][j][k]=Rubik[x][y][z];
				}
			}
		}
	}
	Rubik = newRubik;
}

void rotateZ(int row, int direction){
	for(int i = 0; i < Rubik.size(); i++) {
		if(i==row){
			for(int j = 0; j < Rubik[i].size(); j++) {
				for(int k = 0; k < Rubik[i][j].size(); k++){
					int new_rotateZ = (Rubik[i][j][k].getRotateZ() + direction) % 4;
					Rubik[i][j][k].setRotateZ(new_rotateZ);
				}
			}
		}
	}
	vector < vector < vector < Cube > > > newRubik = Rubik;
	for(int i = 0; i < newRubik.size(); i++) {
		if(i==row){
			for(int j = 0; j < newRubik[i].size(); j++) {
				for(int k = 0; k < newRubik[i][j].size(); k++){
					int x = row;
					int y = rubik_size - 1 - k;
					int z = j;
					newRubik[i][j][k]=Rubik[x][y][z];
				}
			}
		}
	}
	Rubik = newRubik;
	


}

void keyboard(unsigned char c, int x, int y) {
	if (c == 27) {
		exit(0);
	} else if(c == 113){//q
		rotateY(0,1);
		render();
	} else if(c == 101){//e
		rotateX(0,1);
		render();
	} else if(c == 116){//t
		rotateZ(0,1);
		render();
	}
}
 
void mouse(int button, int state, int x, int y) {
	if (button == GLUT_RIGHT_BUTTON) {
			exit(0);
	}
}

void rotateView(){
	gluLookAt(0, 0, 0,
           1, 1, 1,
           0, 1, 0);

}
 
void render(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	rotateView();
	for(int i = 0;i<Rubik.size();i++){
		for(int j = 0;j<Rubik[i].size();j++){
			for(int k = 0;k<Rubik[i][j].size();k++){
				glPushMatrix();
				
				//Rotate x
				for(int x_r=0; x_r<Rubik[i][j][k].getRotateX(); x_r++)
					glRotatef( -90, 1.0, 0.0, 0.0);
				
				//Rotate y
				for(int y_r=0; y_r<Rubik[i][j][k].getRotateY(); y_r++)
					glRotatef( -90, 0.0, 1.0, 0.0);
				
				//Rotate z
				for(int z_r=0; z_r<Rubik[i][j][k].getRotateZ(); z_r++)
					glRotatef( -90, 0.0, 0.0, 1.0);
				
				drawCube(Rubik[i][j][k]);
				glPopMatrix();

			}
		}
	}
	
	glFlush();
	glutSwapBuffers();
	
}