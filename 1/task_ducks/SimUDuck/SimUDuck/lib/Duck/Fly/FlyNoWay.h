#ifndef FLYNOWAY_H
#define FLYNOWAY_H

#include "IFlyBehavior.h"

class FlyNoWay : public IFlyBehavior
{
public:
	void Fly() override {}

	bool IsDuckCanFly() override {
		return false;
	}
	
	int GetFlightCount() override {
		return 0;
	}
};

#endif
