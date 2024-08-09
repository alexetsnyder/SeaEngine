#pragma once

namespace SeaEngine
{
	class Graphics
	{
		public:
			Graphics(int width, int height);

			void setSize(int width, int height);

			void clear();

		private:
			void initGlad();
			void setOpenGLOptions();

			int width_;
			int height_;
	};
}
