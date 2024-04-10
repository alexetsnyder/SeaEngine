#pragma once

#include <glad/glad.h>

#include <string>
#include <vector>

namespace SeaEngine
{
	class Shader
	{
		public:
			Shader();
			~Shader();

			bool setVertexShader(const std::string& shaderPath);

			bool setFragmentShader(const std::string& shaderPath);

			bool compile();

			bool link();

			void use() const;

		private:
			bool setShader(const std::string shaderPath, int glShader);
			std::string readFile(const std::string& filePath);
			bool compile(GLuint shader, std::vector<GLchar>& infoLog);

			GLuint programID_;
			GLuint vertexID_;
			GLuint fragmentID_;
	};
}
