#include "Texture.h"

Texture::Texture() {
	glGenTextures(1, &id);
}

Texture::Texture(const char* filename) {
	glGenTextures(1, &id);
	setTexture(filename);
}

void Texture::setTexture(const char* filename) {
	GLubyte* temp_data = stbi_load(filename, &width, &height, &n_ch, 0);
	if (temp_data) {
		data = std::vector<GLubyte>(temp_data, temp_data + (width * height * n_ch));
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data.data());
		glGenerateMipmap(GL_TEXTURE_2D);
	} else {
		throw "Failed to load image";
	}
}
