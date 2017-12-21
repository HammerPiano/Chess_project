#pragma once
#include <iostream>
#include <exception>
class Invalid_Move : public std::exception
{
	Invalid_Move(std::string msg);
};