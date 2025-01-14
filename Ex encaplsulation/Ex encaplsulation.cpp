#include "Vector2.h"
#include "BreakableObject.h"
#include "StaticObject.h"
#include "Mob.h"
#include "Player.h"
#include "World.h"

int main()
{
#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif

	/*StaticObject* staticObject = new StaticObject(Vector2(10, 10));

	BreakableObject* breakableObject = new BreakableObject(Vector2(10, 10), 50);

	Mob* mob = new Mob(Vector2(10, 10), 50, Vector2(2,0), 3);

	Player* player = new Player(Vector2(10, 10), 50, Vector2(2, 0), 3);*/

	World* world = new World();

	world->Init();

	while (!world->IsWin())
	{
		world->Step();
	}

	return 0;
}
