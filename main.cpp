#include <iostream>

#define GLEW_STATIC
#include <Gl/glew.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "Shader.h"
#include "LookUpTable.h"

const GLint WIDTH = 1200, HEIGHT = 1200;
int screenWidth, screenHeight;

int main() {
	glfwInit();

	// set the version of openGL to 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// use the modern stuff
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "setupGL", nullptr, nullptr);

	// ensures pixels coordinates are mapped to the screen correctly (accounts for pixel density)
	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	if (nullptr == window) {
		std::cout << "Failed to create GLFW window" << std::endl;
		return EXIT_FAILURE;
	}

	// set the current context to the window we just created
	glfwMakeContextCurrent(window);

	// use modern approach to obtain function pointers
	glewExperimental = GL_TRUE;

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialize GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	glViewport(0, 0, screenWidth, screenHeight);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	Shader ourShader("core.vert", "core.frag");

	// Create Cube Vertices
	GLfloat vertices[] = {
		// ABC
		-0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,	0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 1.0f,
		// ACD
		-0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 1.0f,
		// BFG
		 0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 1.0f,
		// BGC
		 0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 1.0f,
		// FEH
		 0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 1.0f,
		// FHG
		 0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 1.0f,
		// EAD
		-0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,	0.0f, 1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 1.0f,
		// EDH
		-0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 1.0f,
		// DCG
		-0.5f,  0.5f,  0.5f,	1.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 1.0f,
		// DGH
		-0.5f,  0.5f,  0.5f,	1.0f, 0.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 1.0f,
		// EFB
		-0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 1.0f,
		// EBA
		-0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,	0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 1.0f
	};

	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	// bind vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	glm::mat4 projection;
	projection = glm::perspective(glm::radians(45.0f), (GLfloat)(screenWidth) / (GLfloat)(screenHeight), 0.1f, 1000.0f);

	// GAME LOOP
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		ourShader.use();

		// set up MVP matrix
		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::lookAt(
			glm::vec3(4, 3, 3), // Camera is at (4,3,3), in World Space
			glm::vec3(0, 0, 0), // and looks at the origin
			glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
			);
		glm::mat4 MVP = projection * view * model;

		GLint MVPLoc = glGetUniformLocation(ourShader.Program, "MVP");
		glUniformMatrix4fv(MVPLoc, 1, GL_FALSE, glm::value_ptr(MVP));

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glfwTerminate();

	return EXIT_SUCCESS;
}

bool isInsideSphere(GLfloat x, GLfloat y, GLfloat z, GLfloat radius) {
	return (x * x + y * y + z * z < radius);
}

GLfloat* genSphereMesh() {
	GLfloat minX, minY, minZ = 1.0f;
	GLfloat maxX, maxY, maxZ = -1.0f;
	GLfloat x, y, z, a = 0.0f;

	const GLfloat radius = 0.5f;
	const GLint dim = 100; // number of vertices on bounding box edge
	bool vertices[dim][dim][dim];

	for (GLint i = 0; i < dim; ++i) {
		for (GLint j = 0; j < dim; ++j) {
			for (GLint k = 0; k < dim; ++k) {
				a = ((GLfloat)i / (GLfloat)dim);
				x = maxX * a + minX * (1.0f - a);
				y = maxY * a + minY * (1.0f - a);
				z = maxZ * a + minZ * (1.0f - a);
				vertices[i][j][k] = isInsideSphere(x, y, z, radius);
			}
		}
	}

	// ...
	
	GLfloat mesh[] = {0.0f};
	return mesh;
}

int edgeListIndex(const bool arr[8] ){
	int index = 0;
	for (int i = 0; i < 8; ++i){
		index += i * pow(2, i);
	}
	return index;
}
