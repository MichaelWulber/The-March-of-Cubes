#version 430 core

layout ( location = 0 ) in vec3 position;
layout ( location = 1 ) in vec3 barycentric;

out vec3 vBC;

uniform mat4 MVP;


void main() {
	vBC = barycentric;
	gl_Position = MVP * vec4(position, 1.0);
}