#version 460 core
out vec4 FragmentColor;

in vec2 TextureCoordinate;

uniform sampler2D texture0;

void main()
{
	FragmentColor = texture(texture0, TextureCoordinate);
}
