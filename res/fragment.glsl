#version 410

out vec4 out_color;
in vec3 vertex_position;
uniform float alpha;
void main()
{
    out_color = vec4(vertex_position,1.f);
}