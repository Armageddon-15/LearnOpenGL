#include "ShaderProgram.h"

ShaderProgram::ShaderProgram() {
	initShaderProgram();
}

GLuint ShaderProgram::getShaderProgramId() {
	return id;
}

void ShaderProgram::initShaderProgram() {
	id = glCreateProgram();
}

void ShaderProgram::setVertexShader(const char* filename) {
	setShader(GL_VERTEX_SHADER, filename);
}

void ShaderProgram::setFragmentShader(const char* filename) {
	setShader(GL_FRAGMENT_SHADER, filename);
}

Shader* ShaderProgram::setShader(GLenum type, const char* filename) {
	Shader* shader = new Shader(type , filename);
	if (shader->checkShaderState()) {
		glAttachShader(id, shader->id);
	}
	shader->deleteShader();
	return shader;
}

void ShaderProgram::attachShader(Shader& shader) {
	glAttachShader(id, shader.id);
}

void ShaderProgram::setUniform(const char* name, int value) {
	glUniform1i(glGetUniformLocation(id, name), value);
}

void ShaderProgram::setUniform(const char* name, double value) {
	glUniform1d(glGetUniformLocation(id, name), value);
}

void ShaderProgram::setUniform(const char* name, float value) {
	glUniform1f(glGetUniformLocation(id, name), value);

}

void ShaderProgram::linkProgram() {
	glLinkProgram(id);
}

void ShaderProgram::useProgram() {
	glUseProgram(id);
}
