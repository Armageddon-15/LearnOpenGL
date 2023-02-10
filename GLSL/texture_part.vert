# version 450 core

layout (location = 0) in vec3 v_position;
layout (location = 1) in vec3 v_color;
layout (location = 2) in vec2 v_uv0;

out vec3 vertex_position;
out vec3 vertex_color;
out vec2 vertex_uv0;

void main(){
	gl_Position = vec4(v_position, 1.0);
	vertex_position = v_position;
	vertex_color = v_color;
	vertex_uv0 = v_uv0;
}
