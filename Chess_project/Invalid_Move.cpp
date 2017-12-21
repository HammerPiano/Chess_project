#include "Invalid_Move.h"

Invalid_Move::Invalid_Move(std::string msg) : std::exception(msg.c_str())
{

}