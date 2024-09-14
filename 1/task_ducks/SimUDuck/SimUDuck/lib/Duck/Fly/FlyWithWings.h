#ifndef FLYWITHWINGS_H
#define FLYWITHWINGS_H

#include <iostream>

std::function<int()> FlyWithWings()
{
	int flightCount = 0;
	return [flightCount]() mutable {
		std::cout << "I'm flying with wings, cout: " << ++flightCount << std::endl;
		return flightCount;
	};
}

#endif
