#include <functional>
#include "../SimUDuck/lib/Duck/MallardDuck.h"
#include "../SimUDuck/lib/DuckFunctions.h"
#include "../SimUDuck/lib/Duck/RedheadDuck.h"
#include "../SimUDuck/lib/Duck/RubberDuck.h"
#include "../SimUDuck/lib/Duck/DecoyDuck.h"
#include "../SimUDuck/lib/Duck/ModelDuck.h"
#include "../SimUDuck/lib/Duck/TestDuck.h"

int main()
{
	MallardDuck mallardDuck;
	PlayWithDuck(mallardDuck);
	PlayWithDuck(mallardDuck);
	PlayWithDuck(mallardDuck);

	RedheadDuck redheadDuck;
	PlayWithDuck(redheadDuck);
	PlayWithDuck(redheadDuck);

	RubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);
	PlayWithDuck(rubberDuck);

	DecoyDuck decoyDuck;
	PlayWithDuck(decoyDuck);
	PlayWithDuck(decoyDuck);

	ModelDuck modelDuck;
	PlayWithDuck(modelDuck);
	PlayWithDuck(modelDuck);

	TestDuck testDuck;
	PlayWithDuck(testDuck);
	PlayWithDuck(testDuck);

	modelDuck.SetFlyBehavior(FlyWithWings());
	PlayWithDuck(modelDuck);

	return EXIT_SUCCESS;
}

