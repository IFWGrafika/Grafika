#ifndef property_h
#define property_h
#include <string>

using namespace std;

class Property{
	public:
		Property();
		Property(string _code);
		~Property();

		string getCode();
		int getRotateX();
		int getRotateY();
		int getRotateZ();
		void setRotateX(int _x);
		void setRotateY(int _y);
		void setRotateZ(int _z);

	private:
		string code;
		int rotate_x;
		int rotate_y;
		int rotate_z;
};

#endif