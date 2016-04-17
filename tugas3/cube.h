#ifndef cube_h
#define cube_h
#include <string>

using namespace std;

class Cube{
	public:
		Cube();
		Cube(string _code, float _x, float _y, float _z);
		~Cube();

		string getCode();
		float getX();
		float getY();
		float getZ();

		int getRotateX();
		int getRotateY();
		void setRotateX(int _x);
		void setRotateY(int _y);

	private:
		string code;
		float x;
		float y;
		float z;

		int rotate_x;
		int rotate_y;
};

#endif