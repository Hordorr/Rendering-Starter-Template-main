#version 410

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec2 inUv;
uniform float currentTime;
uniform mat4 view_projection_matrix;
out vec3 vertex_position;
out vec2 uv;
void main(){
    vertex_position = in_position;
    uv = inUv;
    gl_Position = view_projection_matrix * vec4(in_position,1.f);
    
}