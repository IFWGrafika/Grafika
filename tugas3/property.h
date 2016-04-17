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
		void setRotateX(int _x);
		void setRotateY(int _y);

	private:
		string code;
		int rotate_x;
		int rotate_y;
};

#endif