#ifndef TESTDANCE_H
#define TESTDANCE_H

#include "IDanceBehavior.h"
#include <iostream>

class TestDance : public IDanceBehavior
{
public:
	void Dance() override
	{
		std::cout << "I'm dancing waltz!\n";
	}
private:
	int m_danceCount = 0;
};

#endif
