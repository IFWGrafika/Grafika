#include "rotation.h"

Rotation::Rotation(){
    code = 'x';
    angle = 0; 
}

Rotation::Rotation(char _code, int _angle){
    code = _code;
    angle = _angle;
}

Rotation::~Rotation(){

}

int Rotation::getAngle(){
    return angle;
}

char Rotation::getCode(){
    return code;
}
