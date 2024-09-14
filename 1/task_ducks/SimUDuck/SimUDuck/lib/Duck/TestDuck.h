#ifndef TESTDUCK_H
#define TESTDUCK_H

#include "Duck.h"
#include "Fly/FlyWithWings.h"
#include "Quack/QuackBehavior.h"
#include "Dance/DanceWaltz.h"

class TestDuck : public Duck
{
public:
	TestDuck()
		: Duck(FlyWithWings(), QuackBehavior(), DanceWaltz())
	{
	}

	void Display() const override
	{
		std::cout << "I'm test duck\n";
	}
};

#endif

