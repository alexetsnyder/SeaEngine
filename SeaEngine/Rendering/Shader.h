#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <vector>

namespace SeaEngine
{
	class Shader
	{
		public:
			Shader();
			~Shader();
			Shader(const Shader&) = delete;

			bool setVertexShader(const std::string& shaderPath);

			bool setFragmentShader(const std::string& shaderPath);

			bool compile();

			bool link();

			void use() const;

			void setUniform(const std::string& name, const glm::mat4& matrix) const;
			void setUniform(const std::string& name, const glm::vec3& vector) const;

		private:
			bool setShader(const std::string shaderPath, int glShader);
			std::string readFile(const std::string& filePath);
			bool compile(GLuint shader, std::vector<char>& infoLog);

			GLuint programID_;
			GLuint vertexID_;
			GLuint fragmentID_;
	};
}
