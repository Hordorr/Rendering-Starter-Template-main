#version 410

layout(location = 0) in vec2 in_position;
uniform float currentTime;
void main(){
    gl_Position = vec4(in_position.x/currentTime,in_position.y,0.f,1.f);
}