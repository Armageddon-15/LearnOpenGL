#include "Texture.h"

Texture::Texture() {
    stbi_set_flip_vertically_on_load(true);
	glGenTextures(1, &id);
	width = 0;
	height = 0;
	n_ch = 0;
}

Texture::Texture(const char* filename) {
    stbi_set_flip_vertically_on_load(true);
	glGenTextures(1, &id);
	setTexture(filename);
}

void Texture::setTexture(const char* filename) {
	glBindTexture(GL_TEXTURE_2D, id);
	GLubyte* temp_data = stbi_load(filename, &width, &height, &n_ch, 0);
	if (temp_data) {
		data = std::vector<GLubyte>(temp_data, temp_data + (width * height * n_ch));
		int color_ch = n_ch == 4 ? GL_RGBA : (n_ch == 1 ? GL_RED : GL_RGB);
		glTexImage2D(GL_TEXTURE_2D, 0, color_ch, width, height, 0, color_ch, GL_UNSIGNED_BYTE, data.data());
		glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(temp_data);
	} else {
		throw "Failed to load image";
	}
}

void Texture::setTextureParameter(GLenum pname, GLint param) {
	glTexParameteri(GL_TEXTURE_2D, pname, param);
}

void Texture::setTextureParameter(GLenum pname, GLfloat param) {
	glTexParameterf(GL_TEXTURE_2D, pname, param);
}

void Texture::setTextureParameter(GLenum pname, const GLint* param) {
	glTexParameteriv(GL_TEXTURE_2D, pname, param);
}

void Texture::setTextureParameter(GLenum pname, const GLfloat* param) {
	glTexParameterfv(GL_TEXTURE_2D, pname, param);
}

void Texture::active() {
	glActiveTexture(GL_TEXTURE0 + id - 1);
	glBindTexture(GL_TEXTURE_2D, id);
}
