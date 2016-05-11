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
vector < vector < vector < Cube > > > Rubik2;
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

	// AMBIENT
	GLfloat light_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	
	// DIFFUSE
	GLfloat cyan[] = {.0f, .8f, .8f, 1.f};
	glMaterialfv(GL_FRONT, GL_DIFFUSE, cyan);
	GLfloat light_diffuse[] = { 0.0, 0.5, 0.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_diffuse);

	// SPECULAR
	GLfloat red[] = {.2f, .0f, .0f, 1.f};
	glMaterialfv(GL_FRONT, GL_SPECULAR, red);
	GLfloat light_specular[] = { 0.2, 2.0, 0.3, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_specular);

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

    texture= LoadTexture( "ben.bmp" );
	glEnable(GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, texture);
    glBegin(GL_POLYGON);
    glTexCoord2f(0, 0);glVertex3f( cube.getX()+ cube_size, cube.getY()- cube_size, cube.getZ() -cube_size );
    glTexCoord2f(1, 0);glVertex3f( cube.getX()+ cube_size, cube.getY()+ cube_size, cube.getZ() -cube_size );
    glTexCoord2f(1, 1);glVertex3f( cube.getX()+ cube_size, cube.getY()+ cube_size,  cube.getZ() +cube_size );
    glTexCoord2f(0, 1);glVertex3f( cube.getX()+ cube_size, cube.getY()- cube_size,  cube.getZ() +cube_size );
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
		Row.push_back(Cube("110100",0,-dis,dis,-dis));
		Row.push_back(Cube("100100",1,0,dis,-dis));
		Row.push_back(Cube("101100",2,dis,dis,-dis));
		Side.push_back(Row);
		Row.clear();
		//dari kiri tengah ke kanan
		Row.push_back(Cube("110000",3,-dis,0,-dis));
		Row.push_back(Cube("100000",4,0,0,-dis));
		Row.push_back(Cube("101000",5,dis,0,-dis));
		Side.push_back(Row);
		Row.clear();
		//dari kiri bawah ke kanan
		Row.push_back(Cube("110010",6,-dis,-dis,-dis));
		Row.push_back(Cube("100010",7,0,-dis,-dis));
		Row.push_back(Cube("101010",8,dis,-dis,-dis));
		Side.push_back(Row);
		Row.clear();
		Rubik.push_back(Side);
		Side.clear();

		Row.push_back(Cube("010100",9,-dis,dis,0));
		Row.push_back(Cube("000100",10,0,dis,0));
		Row.push_back(Cube("001100",11,dis,dis,0));
		Side.push_back(Row);
		Row.clear();

		Row.push_back(Cube("010000",12,-dis,0,0));
		Row.push_back(Cube("000000",13,0,0,0));
		Row.push_back(Cube("001000",14,dis,0,0));
		Side.push_back(Row);
		Row.clear();

		Row.push_back(Cube("010010",15,-dis,-dis,0));
		Row.push_back(Cube("000010",16,0,-dis,0));
		Row.push_back(Cube("001010",17,dis,-dis,0));
		Side.push_back(Row);
		Row.clear();
		Rubik.push_back(Side);
		Side.clear();

		Row.push_back(Cube("010101",18,-dis,dis,dis));
		Row.push_back(Cube("000101",19,0,dis,dis));
		Row.push_back(Cube("001101",20,dis,dis,dis));
		Side.push_back(Row);
		Row.clear();

		Row.push_back(Cube("010001",21,-dis,0,dis));
		Row.push_back(Cube("000001",22,0,0,dis));
		Row.push_back(Cube("001001",23,dis,0,dis));
		Side.push_back(Row);
		Row.clear();

		Row.push_back(Cube("010011",24,-dis,-dis,dis));
		Row.push_back(Cube("000011",25,0,-dis,dis));
		Row.push_back(Cube("001011",26,dis,-dis,dis));
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

void printRubik(vector < vector < vector < Cube > > > Rubik){
	for(int i = 0; i < Rubik.size(); i++) {
		for(int j = 0; j < Rubik[i].size(); j++) {
			for(int k = 0; k<Rubik[i][j].size(); k++){
				printf("%d %f %f %f\n",Rubik[i][j][k].getID(),Rubik[i][j][k].getX(),Rubik[i][j][k].getY(),Rubik[i][j][k].getZ());
			}
			printf("\n");
		}
	}
	printf("\n\n");
}

void initRubik (vector < vector < vector < Cube > > > *newRubik) {
	for (int i=0; i<3; i++) {
		vector < vector < Cube > > Side;
		for (int j=0; j<3; j++) {
			vector < Cube > Row;
			for (int k=0; k<3; k++) {
				Cube cube;
				Row.push_back(cube);
			}
			//printf("pushed %d %d",i,j);
			Side.push_back(Row);
			//Row.clear();
		}
		(*newRubik).push_back(Side);
		Side.clear();
	}
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
	vector < vector < vector < Cube > > > newRubik;
	initRubik(&newRubik);
	printf("%d",newRubik[0].size());
	int x,y,z;
	for(int i = 0; i < newRubik.size(); i++) {
		for(int j = 0; j < newRubik[i].size(); j++) {
			for(int k = 0; k < newRubik[i][j].size(); k++){
				if (k==row) {
					x = rubik_size - 1 - j;
					y = i;
					z = row;
					newRubik[i][j][k] = Rubik[x][y][z];
					printf("swap %d with %d ",Rubik[i][j][k].getID(),Rubik[x][y][z].getID());
					float posY = newRubik[i][j][k].getY();
					float posZ = newRubik[i][j][k].getZ();
					printf("%f %f\n",posY,posZ);
					if ( (posY > 0 && posZ < 0) || (posY < 0 && posZ > 0) ) {
						newRubik[i][j][k].setY(-posY);
					} else if ( (posY < 0 && posZ < 0) || (posY > 0 && posZ > 0) ) {
						newRubik[i][j][k].setZ(-posZ);
					} else if (posY == 0 && posZ!=0) {
						newRubik[i][j][k].setY(posZ);
						newRubik[i][j][k].setZ(posY);
					} else if (posZ == 0 && posY!=0) {
						newRubik[i][j][k].setY(posZ);
						newRubik[i][j][k].setZ(-posY);
					}
				} else {
					newRubik[i][j][k]=Rubik[i][j][k];
				}
			}
		} 
	}
	Rubik = newRubik;
	// printRubik(Rubik);
}

void rotateY(int row, int direction){
	for(int i = 0; i < Rubik.size(); i++) {
		for(int j = 0; j < Rubik[i].size(); j++) {
			if(j==row){
				for(int k = 0; k<Rubik[i][j].size(); k++){
					printf("ID yg dirotate %d",Rubik[i][j][k].getID());
					int new_rotateY = (Rubik[i][j][k].getRotateY() + direction) % 4;
					Rubik[i][j][k].setRotateY(new_rotateY);
				}
			}
		}
	}
	vector < vector < vector < Cube > > > newRubik;
	initRubik(&newRubik);
	for(int i = 0; i < newRubik.size(); i++) {
		for(int j = 0; j < newRubik[i].size(); j++) {
			if (j==row) {
				for(int k = 0; k<newRubik[i][j].size(); k++){
					int x = rubik_size - 1 - k;
					int y = row;
					int z = i;
					printf("swap %d with %d\n",Rubik[i][j][k].getID(),Rubik[x][y][z].getID());
					newRubik[i][j][k] = Rubik[x][y][z];
					float posX = newRubik[i][j][k].getX();
					float posZ = newRubik[i][j][k].getZ();
					if ( (posX < 0 && posZ < 0) || (posX > 0 && posZ > 0) ) {
						newRubik[i][j][k].setX(-posX);
					} else if ( (posX > 0 && posZ < 0) || (posX < 0 && posZ > 0) ){
						newRubik[i][j][k].setZ(-posZ);
					} else if (posZ == 0 && posX!=0) {
						newRubik[i][j][k].setX(posZ);
						newRubik[i][j][k].setZ(posX);
					} else if (posX == 0 && posZ!=0) {
						newRubik[i][j][k].setX(-posZ);
						newRubik[i][j][k].setZ(posX);
					}
				}
			} else {
				for(int k = 0; k<newRubik[i][j].size(); k++){
					newRubik[i][j][k] = Rubik[i][j][k];
				}
			}
		}
	}
	Rubik = newRubik;
	printf("Rubik stlh update");
	// printRubik(Rubik);
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
	vector < vector < vector < Cube > > > newRubik;
	initRubik(&newRubik);
	for(int i = 0; i < newRubik.size(); i++) {
		if(i==row){
			for(int j = 0; j < newRubik[i].size(); j++) {
				for(int k = 0; k < newRubik[i][j].size(); k++){
					int x = row;
					int y = rubik_size - 1 - k;
					int z = j;
					printf("swap %d with %d\n",Rubik[i][j][k].getID(),Rubik[x][y][z].getID());
					newRubik[i][j][k] = Rubik[x][y][z];
					float posX = newRubik[i][j][k].getX();
					float posY = newRubik[i][j][k].getY();
					printf("%f %f\n",posX,posY);
					if ( (posX < 0 && posY > 0) || (posX > 0 && posY < 0) ) {
						newRubik[i][j][k].setX(-posX);
					} else if ( (posX > 0 && posY > 0) || (posX < 0 && posY < 0) ){
						newRubik[i][j][k].setY(-posY);
					} else if (posX == 0 && posY!=0) {
						newRubik[i][j][k].setX(posY);
						newRubik[i][j][k].setY(posX);
					} else if (posY == 0 && posX!=0) {
						newRubik[i][j][k].setX(posY);
						newRubik[i][j][k].setY(-posX);
					}
				}
			}
		} else {
			for(int j = 0; j < newRubik[i].size(); j++) {
				for(int k = 0; k < newRubik[i][j].size(); k++){
					newRubik[i][j][k] = Rubik[i][j][k];
				}
			}
		}
	}
	Rubik = newRubik;
	// printRubik(Rubik);
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
	//printRubik();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glLoadIdentity();
	rotateView();

	for(int i = 0;i<Rubik.size();i++){
		for(int j = 0;j<Rubik[i].size();j++){
			for(int k = 0;k<Rubik[i][j].size();k++){
				//Rotate x
				glPushMatrix();
				/*for(int x_r=0; x_r<Rubik[i][j][k].getRotateX(); x_r++)
					glRotatef( -90, 1.0, 0.0, 0.0);*/
				glPopMatrix();
				
				//Rotate y
				glPushMatrix();
				/*for(int y_r=0; y_r<Rubik[i][j][k].getRotateY(); y_r++)
					glRotatef( -90, 0.0, 1.0, 0.0);*/
				glPopMatrix();
				
				//Rotate z
				glPushMatrix();
				/*for(int z_r=0; z_r<Rubik[i][j][k].getRotateZ(); z_r++)
					glRotatef( -90, 0.0, 0.0, 1.0);*/
				glPopMatrix();
				
				glPushMatrix();
				glTranslatef(Rubik[i][j][k].getX(), Rubik[i][j][k].getY(), Rubik[i][j][k].getZ());
				//Rotate x
				for(int x_r=0; x_r<Rubik[i][j][k].getRotateX(); x_r++)
					glRotatef( -90, 1.0, 0.0, 0.0);
				//Rotate y
				for(int y_r=0; y_r<Rubik[i][j][k].getRotateY(); y_r++)
					glRotatef( -90, 0.0, 1.0, 0.0);
				//Rotate z
				for(int z_r=0; z_r<Rubik[i][j][k].getRotateZ(); z_r++)
					glRotatef( -90, 0.0, 0.0, 1.0);
				glTranslatef(-1*Rubik[i][j][k].getX(), -1*Rubik[i][j][k].getY(), -1*Rubik[i][j][k].getZ());
				//if((i==0 && j==0 && k==0) || (i==0 && j==0 && k==1))

				drawCube(Rubik[i][j][k]);
				
				glPopMatrix();

			}
		}
	}
	
	/*drawCube(Rubik[0][0][0]);
	drawCube(Rubik[0][0][1]);
	drawCube(Rubik[0][0][2]);
	drawCube(Rubik[0][1][0]);*/
	glFlush();
	glutSwapBuffers();
	
	
}