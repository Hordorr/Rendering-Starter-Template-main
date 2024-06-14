#version 410

layout(location = 0) in vec2 in_position;
layout(location = 1) in vec2 inUv;

uniform mat4 view_projection_matrix;
out vec3 vertex_position;
out vec2 uv;
void main(){
    gl_Position = vec4(in_position,0.f,1.f);
    uv = inUv;
    
    
}