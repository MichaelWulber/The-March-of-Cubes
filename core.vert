#version 330 core

layout ( location = 0 ) in vec3 position;
layout ( location = 1 ) in vec3 barycentric;
layout ( location = 2 ) in vec3 f_color;
layout ( location = 3 ) in vec3 e_color;
layout ( location = 4 ) in vec3 normal;

out vec3 vBC;
out vec3 f_col;
out vec3 e_col;
out vec4 surf_norm;

uniform mat4 MVP;
uniform mat4 model;

void main() {
	vBC = barycentric;
	f_col = f_color;
	e_col = e_color;
	surf_norm = model * vec4(normal, 1.0);
	gl_Position = MVP * vec4(position, 1.0);
}