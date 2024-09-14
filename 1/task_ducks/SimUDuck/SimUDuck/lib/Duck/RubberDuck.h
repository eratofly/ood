#ifndef RUBBERDUCK_H
#define RUBBERDUCK_H

#include "Duck.h"
#include "Fly/FlyNoWay.h"
#include "Quack/SqueakBehavior.h"
#include "Dance/DanceNoWay.h"
#include <iostream>

class RubberDuck : public Duck
{
public:
	RubberDuck()
		: Duck(FlyNoWay(), SqueakBehavior(), DanceNoWay())
	{
	}

	void Display() const override
	{
		std::cout << "I'm rubber duck\n";
	}
};

#endif
