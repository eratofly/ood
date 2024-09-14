#ifndef DANCEWALTZ_H
#define DANCEWALTZ_H

#include <iostream>

std::function<void()> DanceWaltz()
{
	std::cout << "I'm dancing waltz!\n";
	return [] () {};
}

#endif
