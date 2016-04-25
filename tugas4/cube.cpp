#include "cube.h"

Cube::Cube(){
    x = 0;
    y = 0;
    z = 0;
    prop = Property("111111");
}

Cube::Cube(string _code, float _x, float _y, float _z){
    prop = Property(_code);
    x = _x;
    y = _y;
    z = _z;
}

Cube::~Cube(){

}

string Cube::getCode(){
    return prop.getCode();
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

vector<Rotation> Cube::getRotation(){
    return rotationList;
}

void Cube::addRotation(Rotation r){
    return rotationList.push_back(r);
}
