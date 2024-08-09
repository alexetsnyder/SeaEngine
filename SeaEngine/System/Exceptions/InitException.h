#pragma once

#include <stdexcept>
#include <string>

namespace SeaEngine::Sys
{
	class InitException : public std::runtime_error
	{
		public:
			InitException(const std::string& errorMsg)
				: std::runtime_error{ errorMsg }
			{

			}
	};
}
