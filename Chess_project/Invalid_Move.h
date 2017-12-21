#pragma once
#include <iostream>
#include <exception>
class Invalid_Move : public std::exception
{
public:
	Invalid_Move(std::string msg);
};