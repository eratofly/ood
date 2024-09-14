#ifndef FLYNOWAY_H
#define FLYNOWAY_H

#include "IFlyBehavior.h"

std::function<int()> FlyNoWay()
{
	return [] () {
		return 0;
	};
}
#endif
