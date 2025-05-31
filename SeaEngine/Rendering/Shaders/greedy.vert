#version 460 core
layout (location = 0) in vec3 vertex;
layout (location = 1) in vec2 textureCoordinate;

out vec2 TextureCoordinate;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(vertex, 1.0f);
	TextureCoordinate = textureCoordinate;
}
