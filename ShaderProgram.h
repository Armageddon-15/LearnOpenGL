#ifndef SHADERPROGRAM
#define SHADERPROGRAM

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "toolFunctions.h"
#include "Shader.h"

class ShaderProgram
{
public:
	GLuint id;
	ShaderProgram();

private:


public:
	GLuint getShaderProgramId();
	void initShaderProgram();

	void setVertexShader(const char* filename);
	void setFragmentShader(const char* filename);
	Shader* setShader(GLenum type, const char* filename);
	void attachShader(Shader& shader);

	void setUniform(const char* name, int value);
	void setUniform(const char* name, double value);
	void setUniform(const char* name, float value);


	void linkProgram();
	void useProgram();

	bool checkState();
	
};


#endif // !SHADERPROGRAM

