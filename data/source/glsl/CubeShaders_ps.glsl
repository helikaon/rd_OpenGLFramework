#version 400

uniform vec3 triangleColor;

in vec3 color;

out vec4 outColor;

void main()
{
	outColor = vec4(triangleColor * color, 1.0);
}