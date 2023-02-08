#ifndef SHADER
#define SHADER

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "toolFunctions.h"

class Shader
{
public:
	GLuint id;
	GLenum type;
	std::string filename;

	Shader(GLenum type);
	Shader(GLenum type, const char* filename);

public:
	void setShaderFile(const char* filename);
	void compileShader();
	void deleteShader();

	bool checkState();

private:
	void setShaderType(GLenum type);

};

#endif // !SHADER

