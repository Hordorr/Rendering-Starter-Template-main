#version 410

out vec4 out_color;
uniform float alpha;
void main()
{
    out_color = vec4(0.0, 1.0, 0.05, alpha);
}