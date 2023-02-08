# version 450 core

uniform float time;

in vec3 vertex_color;

out vec4 FragColor;

void main(){
	FragColor = vec4(vertex_color, 1.0) * (sin(time)*0.5+0.5);
}
