#version 410

out vec4 out_color;
in vec3 vertex_position;
in vec2 uv;
uniform sampler2D my_texture;
uniform float alpha;

void main()
{    
    //out_color = vec4(uv.x,uv.y,0.f,1.f);
    vec4 texture_color = texture2D(my_texture,uv);
    float val = (texture_color.x+texture_color.y+texture_color.z)/3;
    vec4 bawTexColor = vec4(val,val,val,1);
    vec4 redtex = texture_color * vec4(1,0,0,1);
    out_color = vec4(bawTexColor);
}