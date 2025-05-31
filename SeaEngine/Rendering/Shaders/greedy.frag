#version 460 core
out vec4 FragmentColor;

in vec2 TextureCoordinate;

uniform vec2 atlasTilePosition;
uniform vec2 atlasTileSize;
uniform sampler2D texture0;

void main()
{
	vec2 dx = dFdx(TextureCoordinate);
	vec2 dy = dFdy(TextureCoordinate);
	vec2 coord = atlasTilePosition + atlasTileSize * fract(TextureCoordinate);
	FragmentColor = textureGrad(texture0, coord, dx, dy);
}
