#pragma once
#include <iostream>

class Point {
public:
	
	char getX();
	char getY();

	void SetXY(char x, char y);
	void setXY(std::string coordinates);
private:
	char _x;
	char _y;

};