#version 430 core

in vec3 vBC;

out vec4 color;

void main() {
	if (vBC.x < 0.05) {
		color = vec4(1.0, 1.0, 0.0, 1.0);
	} 

	else if (vBC.y < 0.05) {
		color = vec4(1.0, 1.0, 0.0, 1.0);
	}

	else if (vBC.z < 0.05) {
		color = vec4(1.0, 1.0, 0.0, 1.0);
	}

	else {
		color = vec4(0.5, 0., 1.0, 1.0);
	}
}