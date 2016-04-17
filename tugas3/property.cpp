#include "cube.h"

Property::Property(){
	code = "111111";
    rotate_x = 0;
    rotate_y = 0;
}

Property::Property(string _code){
    code = _code;
    rotate_x = 0;
    rotate_y = 0;
}

Property::~Property(){

}

string Property::getCode(){
    return code;
}

int Property::getRotateX(){
    return rotate_x;
}
int Property::getRotateY(){
    return rotate_y;
}
void Property::setRotateX(int _x){
    rotate_x = _x;
}
void Property::setRotateY(int _y){
    rotate_y = _y;
}