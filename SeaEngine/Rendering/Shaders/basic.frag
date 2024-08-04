#version 460 core
out vec4 FragmentColor;

in vec2 TextureCoordinate;

uniform sampler2D texture0;

void main()
{
	FragmentColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
}
