#include "opengl-framework/opengl-framework.hpp" // Inclue la librairie qui va nous servir à faire du rendu
#include "glm/ext/matrix_clip_space.hpp"


int main()
{
    // Initialisation
    
    gl::init("TPs de Rendering"); // On crée une fenêtre et on choisit son nom
    gl::maximize_window(); // On peut la maximiser si on veut
    glEnable(GL_BLEND);
    glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE_MINUS_DST_ALPHA, GL_ONE); // On peut configurer l'équation qui mélange deux couleurs, comme pour faire différents blend mode dans Photoshop. Cette équation-ci donne le blending "normal" entre pixels transparents.
    auto camera = gl::Camera{};
    gl::set_events_callbacks({camera.events_callbacks()});

    auto const rectlangle_mesh = gl::Mesh{{
        .vertex_buffers = {{
            .layout = {gl::VertexAttribute::Position2D{0}},
            .data = {                
                -.5f,-.5f,
                +.5f,-.5f,
                +.5f,+.5f,
                -.5f,+.5f,                            
            },
        

        }},
        .index_buffer = {
            0,1,2,
            0,2,3
        },
    }};

    auto const triDim_mesh = gl::Mesh{{
        .vertex_buffers = {{
            .layout = {gl::VertexAttribute::Position3D{0}},
            .data = {                
                -1.f,-1.f,0.f,
                +1.f,-1.f,1.f,
                +1.f,+1.f,0.f,
                -1.f,+1.f,1.f                         
            },
        

        }},
        .index_buffer = {
            0,2,1,
            0,2,3
        },
    }};



    auto const shader = gl::Shader{{
    
    .vertex   = gl::ShaderSource::File{"res/vertex.glsl"},
    .fragment = gl::ShaderSource::File{"res/fragment.glsl"}
    
    }};

    auto const shaderOpacity = gl::Shader{{
    
    .vertex   = gl::ShaderSource::File{"res/vertexOpacity.glsl"},
    .fragment = gl::ShaderSource::File{"res/fragmentOpacity.glsl"}
    
    }};
    
    

    while (gl::window_is_open())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glm::mat4 const view_matrix = camera.view_matrix();
        glm::mat4 const projection_matrix = glm::ortho(-2.f,2.f,-1.5f,1.5f,0.01f,100.f);
        glm::mat4 const view_projection_matrix = projection_matrix * view_matrix;
        
        
        glClearColor(0.f,0.f,1.f,1.f);
        shader.bind();
        shader.set_uniform("view_projection_matrix",view_projection_matrix);
        shader.set_uniform("alpha",1.f);        
        triDim_mesh.draw();
        //CamOrtho
        
        
        
        // Rendu à chaque frame
    }
}

