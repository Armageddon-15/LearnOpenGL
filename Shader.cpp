#include "Shader.h"

Shader::Shader(GLenum type) {
	setShaderType(type);
}

Shader::Shader(GLenum type, const char* filename) {
	setShaderType(type);
	setShaderFile(filename);
	compileShader();
}

void Shader::setShaderType(GLenum type) {
	id = glCreateShader(type);
}

void Shader::setShaderFile(const char* filename) {
	std::string code = readFile(filename);
	glShaderSource(id, 1, StringHelper(code), NULL);
}

void Shader::compileShader() {
	glCompileShader(id);
}

void Shader::deleteShader() {
	glDeleteShader(id);
}

bool Shader::checkState() {
	int success;
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);
	if (success) {
		return true;
	}

	char log[512];
	glGetShaderInfoLog(id, 512, NULL, log);
	std::cout << log << "\n";
	return false;
}