#ifndef FLYWITHWINGS_H
#define FLYWITHWINGS_H

#include "IFlyBehavior.h"
#include <iostream>

class FlyWithWings : public IFlyBehavior
{
public:
	void Fly() override
	{
		std::cout << "I'm flying with wings!!\n";
		std::cout << "My count of flights: " << ++m_flightCount << "\n";
	}

	bool CanFly() override {
		return true;
	}

	int GetFlightCount() override
	{
		return m_flightCount;
	}

private:
	int m_flightCount = 0;
};

#endif
