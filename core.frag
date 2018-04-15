#version 330 core

in vec3 vBC;
in vec3 f_col;
in vec3 e_col;
in vec3 surf_norm;

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
		vec3 lightDir = vec3(10.0, 10.0, 10.0); 
		float diff = max(dot(norm, lightDir), 0.0);
		vec3 diffuse = diff * vec3(1.0, 1.0, 1.0);
		color = vec4(diffuse * f_col, 1.0);
	}
}