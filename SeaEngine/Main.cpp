#include "Exceptions/InitException.h"
#include "Game.h"
#include "System/Logging/ErrorLog.h"

#include <cstdlib>

constexpr int screenWidth{ 1024 };
constexpr int screenHeight{ 768 };

int main(int argc, char** argv)
{
	try
	{
		SeaEngine::Game game{ "SeaEngine", screenWidth, screenHeight };
		game.run();
	}
	catch (const SeaEngine::InitException& exception)
	{
		SeaEngine::Sys::ErrorLog::log("main", exception.what());
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
