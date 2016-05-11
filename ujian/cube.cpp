#include "cube.h"

Cube::Cube(){
	id = -1;
    x = 0;
    y = 0;
    z = 0;
    prop = Property("111111");
}

Cube::Cube(string _code, int _id, float _x, float _y, float _z){
    prop = Property(_code);
	id = _id;
    x = _x;
    y = _y;
    z = _z;
}

/*Cube& Cube::operator=(Cube cube){
	prop = cube.prop;
	x = cube.x;
	y = cube.y;
	z = cube.z;
	return *this;
}*/

Cube::~Cube(){

}

string Cube::getCode(){
    return prop.getCode();
}

int Cube::getID(){
	return id;
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

void Cube::setX(float _x){
	x = _x;
}

void Cube::setY(float _y){
	y = _y;
}

void Cube::setZ(float _z){
	z = _z;
}

int Cube::getRotateX(){
    return prop.getRotateX();
}
int Cube::getRotateY(){
    return prop.getRotateY();
}
int Cube::getRotateZ(){
    return prop.getRotateZ();
}

void Cube::setRotateX(int _x){
    prop.setRotateX(_x);
}
void Cube::setRotateY(int _y){
    prop.setRotateY(_y);
}

void Cube::setRotateZ(int _z){
    prop.setRotateZ(_z);
}

Property Cube::getProperty(){
    return prop;
}

void Cube::setProperty(Property _prop){
    prop = _prop;
}

