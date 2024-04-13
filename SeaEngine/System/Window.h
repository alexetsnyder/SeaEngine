#pragma once

#include <SDL/SDL.h>

namespace SeaEngine::Sys
{
	class Window
	{
		public:
			Window(const char* title, int width, int height);
			~Window();

			int width() const { return width_; }
			int height() const { return height_; }

			int pollEvent(SDL_Event* event);
			void ClearBuffer();
			void SwapBuffer();
			void resizeWindow(int width, int height);
			void toggleFullScreen();

		private:
			void initSDL();
			void createWindow(const char* title);
			void setUpOpenGLContext();
			void loadGLAD();
			void setOpenGLOptions();
			void updateWindowSize();

			bool isFullScreen_;
			int width_;
			int height_;
			SDL_Window* window_;
	};
}
