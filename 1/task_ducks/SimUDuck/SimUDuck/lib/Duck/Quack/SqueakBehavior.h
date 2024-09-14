#ifndef SQUEAKBEHAVIOR_H
#define SQUEAKBEHAVIOR_H

#include <iostream>

std::function<void()> SqueakBehavior()
{
	std::cout << "Squeek!!!" << std::endl;
	return []() {};
}

#endif
