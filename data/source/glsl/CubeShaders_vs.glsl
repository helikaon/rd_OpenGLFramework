#version 400

uniform mat4 matWVP;

in vec3 position;
in vec3 Color;

out vec3 color;

void main()
{
	color = Color;
	gl_Position = matWVP * vec4(position, 1.0);
}	