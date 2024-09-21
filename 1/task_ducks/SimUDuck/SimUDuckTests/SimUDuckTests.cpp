#define CATCH_CONFIG_MAIN

#include "../../../../../catch.hpp"
#include "../SimUDuck/lib/Duck/Duck.h"
#include "../SimUDuck/lib/DuckFunctions.h"
#include "../SimUDuck/lib/Duck/MallardDuck.h"
#include "../SimUDuck/lib/Duck/DecoyDuck.h"
#include "../SimUDuck/lib/Duck/RubberDuck.h"
#include "../SimUDuck/lib/Duck/RedheadDuck.h"
#include "../SimUDuck/lib/Duck/ModelDuck.h"

using namespace std;

TEST_CASE("Test with mallard duck. It always flies")
{
	std::stringstream buffer;
	std::streambuf* prev_buf = std::cout.rdbuf(buffer.rdbuf());
	
	MallardDuck mallardDuck;
	PlayWithDuck(mallardDuck);
	PlayWithDuck(mallardDuck);

	std::cout.rdbuf(prev_buf);
	CHECK(buffer.str() == "I'm mallard duck\n"
		"Quack Quack!!!\n"
		"I'm flying with wings!!\n"
		"My count of flights: 1\n"
		"I'm dancing waltz!\n\n"
		"I'm mallard duck\n"
		"Quack Quack!!!\n"
		"I'm flying with wings!!\n"
		"My count of flights: 2\n"
		"Quack Quack!!!\n"
		"I'm dancing waltz!\n\n"
	);
}

//
//TEST_CASE("Get prime numbers with negative upper bound")
//{
//	MallardDuck mallardDuck;
//	PlayWithDuck(mallardDuck);
//	PlayWithDuck(mallardDuck);
//	PlayWithDuck(mallardDuck);
//	PlayWithDuck(mallardDuck);
//
//	RedheadDuck redheadDuck;
//	PlayWithDuck(redheadDuck);
//	PlayWithDuck(redheadDuck);
//
//	RubberDuck rubberDuck;
//	PlayWithDuck(rubberDuck);
//	PlayWithDuck(rubberDuck);
//
//	DecoyDuck decoyDuck;
//	PlayWithDuck(decoyDuck);
//	PlayWithDuck(decoyDuck);
//
//	ModelDuck modelDuck;
//	PlayWithDuck(modelDuck);
//	PlayWithDuck(modelDuck);
//
//	modelDuck.SetFlyBehavior(std::make_unique<FlyWithWings>());
//	PlayWithDuck(modelDuck);
//}
