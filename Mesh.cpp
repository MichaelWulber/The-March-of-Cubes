#include "Mesh.h"

Mesh::Mesh() : vPositions(0, 0.f), vFaceColors(0, 0.f), vEdgeColors(0, 0.f), faceColor(3, 0.f), edgeColor(3, 0.f), vBuffer(0, 0.f) {}

Mesh::Mesh(GLfloat fR, GLfloat fG, GLfloat fB, GLfloat eR, GLfloat eG, GLfloat eB) : vPositions(0, 0.f), vFaceColors(0, 0.f), vEdgeColors(0, 0.f), faceColor(3, 0.f), edgeColor(3, 0.f), vBuffer(0, 0.f) {
	this->faceColor[0] = fR;
	this->faceColor[1] = fG;
	this->faceColor[2] = fB;

	this->edgeColor[0] = eR;
	this->edgeColor[1] = eG;
	this->edgeColor[2] = eB;
}

Mesh::Mesh(const Mesh &mesh) {
	this->vPositions = mesh.vPositions;
	this->vFaceColors = mesh.vFaceColors;
	this->vEdgeColors = mesh.vEdgeColors;
	this->faceColor = mesh.faceColor;
	this->edgeColor = mesh.edgeColor;
	this->vBuffer = mesh.vBuffer;
}

void Mesh::setVPositions(std::vector<GLfloat> vPos) {
	this->vPositions = vPos;
}

void Mesh::addTriangle(std::vector<GLfloat> vPos) {
	vPositions.insert(vPositions.end(), vPos.begin(), vPos.end());
}

void Mesh::genBuffer() {
	std::vector<GLfloat> buffer(vPositions.size() * 4, 0.0f);
	std::vector<GLfloat> vBC;
	vBC = genVBC();

	int count = 0;
	for (int i = 0; i < vPositions.size() * 4; i += 12) {
		// vertex position
		buffer[i] = vPositions[count];
		buffer[i + 1] = vPositions[count + 1];
		buffer[i + 2] = vPositions[count + 2];

		// barycentric value
		buffer[i + 3] = vBC[count];
		buffer[i + 4] = vBC[count + 1];
		buffer[i + 5] = vBC[count + 2];

		// vertex rgb
		buffer[i + 6] = this->faceColor[0];
		buffer[i + 7] = this->faceColor[1];
		buffer[i + 8] = this->faceColor[2];

		// edge rgb
		buffer[i + 9] = this->edgeColor[0];
		buffer[i + 10] = this->edgeColor[1];
		buffer[i + 11] = this->edgeColor[2];
		
		count += 3;
	}
	this->vBuffer = buffer;
}

void Mesh::bindBuffer() {
	glBufferData(GL_ARRAY_BUFFER, vBuffer.size() * sizeof(GLfloat), &vBuffer[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(GLfloat), (GLvoid *)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(GLfloat), (GLvoid *)(9 * sizeof(GLfloat)));
	glEnableVertexAttribArray(3);

	glBindVertexArray(0);
}

std::vector<GLfloat> Mesh::genVBC() {
	std::vector<GLfloat> vBC(vPositions.size(), 0.0f);
	for (int i = 0; i < vPositions.size(); i += 9) {
		vBC[i] = 1.0f;
		vBC[i + 1] = 0.0f;
		vBC[i + 2] = 0.0f;

		vBC[i + 3] = 0.0f;
		vBC[i + 4] = 1.0f;
		vBC[i + 5] = 0.0f;

		vBC[i + 6] = 0.0f;
		vBC[i + 7] = 0.0f;
		vBC[i + 8] = 1.0f;
	}
	return vBC;
}

std::vector<GLfloat> Mesh::getVBuffer() {
	return this->vBuffer;
}

void Mesh::reset() {

}