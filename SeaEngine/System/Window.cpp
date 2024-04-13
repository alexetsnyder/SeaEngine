#include "Window.h"

#include "Logging/ErrorLog.h"

#include <glad/glad.h>

namespace SeaEngine::Sys
{
	Window::Window(const char* title, int width, int height)
		: isFullScreen_{ false }, width_{ width }, height_{ height }
	{
		initSDL();
		createWindow(title);
		setUpOpenGLContext();
		loadGLAD();
		setOpenGLOptions();
	}

	Window::~Window()
	{
		SDL_DestroyWindow(window_);
		SDL_Quit();
	}

	int Window::pollEvent(SDL_Event* event)
	{
		return SDL_PollEvent(event);
	}

	void Window::ClearBuffer()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::SwapBuffer()
	{
		SDL_GL_SwapWindow(window_);
	}

	void Window::resizeWindow(int width, int height)
	{
		width_ = width;
		height_ = height;
		glViewport(0, 0, width_, height_);
	}

	void Window::toggleFullScreen()
	{
		isFullScreen_ = !isFullScreen_;
		if (isFullScreen_)
		{
			SDL_SetWindowFullscreen(window_, SDL_WINDOW_FULLSCREEN_DESKTOP);
			updateWindowSize();
		}
		else
		{
			SDL_SetWindowFullscreen(window_, 0);
			updateWindowSize();
		}
	}

	void Window::initSDL()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			ErrorLog::log("SDL_Init(SDL_INIT_EVERYTHIG)", SDL_GetError());
			//return EXIT_FAILURE;
		}
	}

	void Window::createWindow(const char* title)
	{
		window_ = SDL_CreateWindow(title,
								   SDL_WINDOWPOS_CENTERED,
								   SDL_WINDOWPOS_CENTERED,
								   width_,
								   height_,
								   SDL_WINDOW_OPENGL |
								   SDL_WINDOW_RESIZABLE);

		if (window_ == nullptr)
		{
			ErrorLog::log("SDL_CreateWindow(...)", SDL_GetError());
			//return EXIT_FAILURE;
		}
	}

	void Window::setUpOpenGLContext()
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		if (SDL_GL_CreateContext(window_) == nullptr)
		{
			ErrorLog::log("SDL_GL_CreateContext(window)", SDL_GetError());
			//return EXIT_FAILURE;
		}
	}

	void Window::loadGLAD()
	{
		if (!gladLoadGLLoader(static_cast<GLADloadproc>(SDL_GL_GetProcAddress)))
		{
			ErrorLog::log("gladLoadGLLoader(GLADloadproc)", "GLAD load failed.");
			//return EXIT_FAILURE;
		}
	}

	void Window::setOpenGLOptions()
	{
		glViewport(0, 0, width_, height_);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	}

	void Window::updateWindowSize()
	{
		SDL_GetWindowSize(window_, &width_, &height_);
		glViewport(0, 0, width_, height_);
	}
}
