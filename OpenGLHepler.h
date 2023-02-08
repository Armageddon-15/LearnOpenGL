#ifndef OPENGLHELPER
#define OPENGLHELPER

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace OpenglHelper {

	inline GLint maxVertexAttribute() {
		int n_attrib;
		glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &n_attrib);
		return n_attrib;
	}

}

#endif // !OPENGLHELPER
