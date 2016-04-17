#ifndef rotation_h
#define rotation_h

using namespace std;

class Rotation{
	public:
		Rotation();
		Rotation(char _code, int _angle);
		~Rotation();

		int getAngle();
		char getCode();

	private:
		int angle;
		char code;
};

#endif