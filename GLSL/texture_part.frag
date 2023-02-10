# version 450 core

uniform float time;
uniform sampler2D base_color;
uniform sampler2D add_layer;

in vec3 vertex_position;
in vec3 vertex_color;
in vec2 vertex_uv0;

out vec4 FragColor;

void main(){
	vec2 uv0 = 2*vertex_uv0;
	FragColor = mix(texture(base_color, uv0), texture(add_layer, uv0), 0.5);
}