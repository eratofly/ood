#ifndef FLYNOWAY_H
#define FLYNOWAY_H

#include "IFlyBehavior.h"
#include <optional>


std::function<std::optional<std::function<int()>>()> FlyNoWay()
{
	return []() {
		return std::nullopt;
		};
}

#endif
