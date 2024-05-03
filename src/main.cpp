#include "opengl-framework/opengl-framework.hpp" // Inclue la librairie qui va nous servir à faire du rendu

int main()
{
    // Initialisation
    gl::init("TPs de Rendering"); // On crée une fenêtre et on choisit son nom
    gl::maximize_window(); // On peut la maximiser si on veut
    auto const triangle_mesh = gl::Mesh{{
        .vertex_buffers = {{
            .layout = {gl::VertexAttribute::Position2D{0}},
            .data = {
                -.5f,+.5f,
                -.5f,-.5f,
                +.5f,+.5f,
                +.5f,-.5f,
                +.5f,+.5f,
                -.5f,-.5f                
            },
        

        }},
    }};
    while (gl::window_is_open())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.f,0.f,1.f,1.f);        
        gl::bind_default_shader();
        triangle_mesh.draw();
        
        
        
        // Rendu à chaque frame
    }
}

