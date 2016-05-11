#ifndef cube_h
#define cube_h
#include <string>
#include "property.h"

using namespace std;

class Cube{
	public:
		Cube();
		Cube(string _code, int _id, float _x, float _y, float _z);
		Cube(const Cube& other) : prop(other.prop), id(other.id ), x(other.x), y(other.y), z(other.z) {}
		~Cube();
		//Cube& operator=(Cube cube);

		string getCode();

		Property getProperty();
		void setProperty(Property _prop);
		int getID();
		float getX();
		float getY();
		float getZ();
		int getRotateX();
		int getRotateY();
		int getRotateZ();

		void setID(int _id);
		void setX(float _x);
		void setY(float _y);
		void setZ(float _z);
		void setRotateX(int _x);
		void setRotateY(int _y);
		void setRotateZ(int _z);
		

	private:
		int id;
		float x;
		float y;
		float z;

		Property prop;
};

#endif