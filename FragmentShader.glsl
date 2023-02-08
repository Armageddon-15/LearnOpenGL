# version 450 core
out vec4 FragColor;

uniform float color;

void main(){
	FragColor = vec4(1.0, color, 0.5, 1.0);
}
