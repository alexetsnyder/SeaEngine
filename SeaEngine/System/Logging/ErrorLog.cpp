#include "ErrorLog.h"

#include <iostream>

namespace SeaEngine::Sys
{
	void ErrorLog::log(std::string_view caller, std::string_view errorMsg)
	{
		std::cerr << "Error::" << caller;
		if (errorMsg != "" && errorMsg != "\n")
		{
			std::cerr << "::" << errorMsg;
		}
		std::cerr << std::endl;
	}
}