#ifndef REDHEADDUCK_H
#define REDHEADDUCK_H

#include "Duck.h"
#include "Fly/FlyWithWings.h"
#include "Quack/QuackBehavior.h"
#include "Dance/DanceMinuet.h"
#include <memory>

class RedheadDuck : public Duck
{
public:
	RedheadDuck()
		: Duck(FlyWithWings(), QuackBehavior(), DanceMinuet())
	{
	}

	void Display() const override
	{
		std::cout << "I'm redhead duck\n";
	}
};

#endif
