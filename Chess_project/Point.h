#pragma once
#include <iostream>

class Point {
public:
	
	Point(char x, char y);
	Point(std::string coordinates);
	~Point();
	char getX();
	char getY();

	void SetXY(char x, char y);
	void setXY(std::string coordinates);
private:
	char _x;
	char _y;

};