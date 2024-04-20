#pragma once

#include <stdexcept>
#include <string>

namespace SeaEngine
{
	class InitException : public std::runtime_error
	{
		public:
			InitException(const std::string& error)
				: std::runtime_error{ error }
			{

			}
	};
}