#include "cube.h"

Cube::Cube(){
	code = "000000";
    x = 0;
    y = 0;
    z = 0;
    rotate_x = 0;
    rotate_y = 0;
}

Cube::Cube(string _code, float _x, float _y, float _z){
    code = _code;
    x = _x;
    y = _y;
    z = _z;
    rotate_x = 0;
    rotate_y = 0;
}

Cube::~Cube(){

}

string Cube::getCode(){
    return code;
}

float Cube::getX(){
    return x;
}

float Cube::getY(){
    return y;
}
float Cube::getZ(){
    return z;
}

int Cube::getRotateX(){
    return rotate_x;
}
int Cube::getRotateY(){
    return rotate_y;
}
void Cube::setRotateX(int _x){
    rotate_x = _x;
}
void Cube::setRotateY(int _y){
    rotate_y = _y;
}