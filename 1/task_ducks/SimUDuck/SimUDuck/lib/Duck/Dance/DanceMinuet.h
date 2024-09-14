#ifndef DANCEMINUET_H
#define DANCEMINUET_H

#include <iostream>

std::function<void()> DanceMinuet()
{
	std::cout << "I'm dancing minuet!\n";
	return [] () {};
}

#endif