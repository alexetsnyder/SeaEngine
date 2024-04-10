#pragma once

#include <string_view>

namespace SeaEngine::Sys
{
	class ErrorLog
	{
		public:
			static void log(std::string_view caller, std::string_view errorMsg);

		private:
	};
}
