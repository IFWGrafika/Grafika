#ifndef cube_h
#define cube_h
#include <string>
#include "property.h"

using namespace std;

class Cube{
	public:
		Cube();
		Cube(string _code, float _x, float _y, float _z);
		~Cube();

		string getCode();

		Property getProperty();
		void setProperty(Property _prop);
		float getX();
		float getY();
		float getZ();
		int getRotateX();
		int getRotateY();
		int getRotateZ();

		void setRotateX(int _x);
		void setRotateY(int _y);
		void setRotateZ(int _z);

	private:
		float x;
		float y;
		float z;

		Property prop;
};

#endif