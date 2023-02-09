# version 450 core

layout (location = 0) in vec3 v_position;
layout (location = 1) in vec3 v_color;

out vec3 vertex_color;

void main(){
	gl_Position = vec4(v_position.x, v_position.y, v_position.z, 1.0);
	vertex_color = v_color;
}
