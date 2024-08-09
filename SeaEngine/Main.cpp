#include "Engine.h"
#include "System/Exceptions/InitException.h"
#include "System/Logging/ErrorLog.h"
#include <cstdlib>

constexpr int DefaultWindowWidth{ 800 };
constexpr int DefaultWindowHeight{ 600 };

int main(int argc, char** argv)
{
	try
	{
		sf::ContextSettings context{ 24, 0, 0, 4, 6 };
		SeaEngine::Engine engine{ context, DefaultWindowWidth, DefaultWindowHeight };
		engine.run();
	}
	catch (const SeaEngine::Sys::InitException& exception)
	{
		SeaEngine::Sys::ErrorLog::log("main", exception.what());
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
