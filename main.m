#include "stdafx.h"

int main()
{

    GameEngine *engine = new GameEngine();
	while (engine->IsRunning())
	{
		engine->Run();
        //std::cout << "Engine is running...";
	}
	return 0;
}
