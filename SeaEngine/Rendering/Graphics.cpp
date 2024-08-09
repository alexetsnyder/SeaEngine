#include "Graphics.h"

#include "System/Exceptions/InitException.h"
#include "System/Logging/ErrorLog.h"

#include <glad/glad.h>
#include <SFML/Window.hpp>

namespace SeaEngine
{
	Graphics::Graphics(int width, int height)
		: width_{ width }, height_{ height }
	{
		initGlad();
		setOpenGLOptions();
	}

	void Graphics::setSize(int width, int height)
	{
		width_ = width;
		height_ = height;
	}

	void Graphics::clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Graphics::initGlad()
	{
		if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(sf::Context::getFunction)))
		{
			Sys::ErrorLog::log("gladLoadGLLoader(GLADloadproc)", "GLAD load failed.");
			throw Sys::InitException{ "Initializing GLAD failed." };
		}
	}

	void Graphics::setOpenGLOptions()
	{
		glViewport(0, 0, width_, height_);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glEnable(GL_DEPTH_TEST);
		//glEnable(GL_CULL_FACE);
	}
}