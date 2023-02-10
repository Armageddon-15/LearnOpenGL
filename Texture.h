#ifndef TEXTURE
#define TEXTURE

#include <vector>
#include <stdexcept>

#include "OpenGLHepler.h"
#include "stb_image.h"

class Texture
{
public:
	GLuint id;
	int width, height, n_ch;
	std::vector<GLubyte> data;
	Texture();
	Texture(const char* filename);

public:
	void setTexture(const char* filename);
	void setTextureParameter(GLenum pname, GLint param);
	void setTextureParameter(GLenum pname, GLfloat param);
	void setTextureParameter(GLenum pname, const GLint* param);
	void setTextureParameter(GLenum pname, const GLfloat* param);


private:

};

#endif // !TEXTURE
