#version 330 core

in vec3 vBC;
in vec3 f_col;
in vec3 e_col;

out vec4 color;

void main() {
	if (vBC.x < 0.025) {
		color = vec4(e_col, 1.0);
	} 

	else if (vBC.y < 0.025) {
		color = vec4(e_col, 1.0);
	}

	else if (vBC.z < 0.025) {
		color = vec4(e_col, 1.0);
	}

	else {
		color = vec4(f_col, 1.0);
	}
}