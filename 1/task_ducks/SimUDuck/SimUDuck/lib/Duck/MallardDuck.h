#ifndef MALLARDDUCK_H
#define MALLARDDUCK_H

#include "Duck.h"
#include "Fly/FlyWithWings.h"
#include "Quack/QuackBehavior.h"
#include "Dance/DanceWaltz.h"

class MallardDuck : public Duck
{
public:
	MallardDuck()
		: Duck(FlyWithWings(), QuackBehavior(), DanceWaltz())
	{
	}

	void Display() const override
	{
		std::cout << "I'm mallard duck\n";
	}
};

#endif
