#ifndef FLYWITHWINGS_H
#define FLYWITHWINGS_H

#include <iostream>

std::function<std::optional<std::function<int()>>()> FlyWithWings()
{
	int flightCount = 0;
	return [flightCount]() mutable {
		return [flightCount]() mutable {
			std::cout << "I'm flying with wings, count: " << flightCount++ << std::endl;
			return flightCount;
			};
		};
}


#endif
