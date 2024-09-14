#ifndef QUACKBEHAVIOR_H
#define QUACKBEHAVIOR_H

#include <iostream>

std::function<void()> QuackBehavior()
{
	std::cout << "Quack Quack!!!" << std::endl;
	return []() {};
}

#endif
