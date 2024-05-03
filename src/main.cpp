#include "opengl-framework/opengl-framework.hpp" // Inclue la librairie qui va nous servir à faire du rendu



int main()
{
    // Initialisation
    
    gl::init("TPs de Rendering"); // On crée une fenêtre et on choisit son nom
    gl::maximize_window(); // On peut la maximiser si on veut
    glEnable(GL_BLEND);
    glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE_MINUS_DST_ALPHA, GL_ONE); // On peut configurer l'équation qui mélange deux couleurs, comme pour faire différents blend mode dans Photoshop. Cette équation-ci donne le blending "normal" entre pixels transparents.
    

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

    auto const opacityMask_mesh = gl::Mesh{{
        .vertex_buffers = {{
            .layout = {gl::VertexAttribute::Position2D{0}},
            .data = {                
                -1.f,-1.f,
                +1.f,-1.f,
                +1.f,+1.f,
                -1.f,+1.f,                            
            },
        

        }},
        .index_buffer = {
            0,1,2,
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
        //glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.f,0.f,1.f,1.f);        
        shaderOpacity.bind();
        shaderOpacity.set_uniform("alpha",.1f); 
        opacityMask_mesh.draw();
        shader.bind();
        shader.set_uniform("currentTime",gl::time_in_seconds()),
        shader.set_uniform("alpha",1.f);        
        rectlangle_mesh.draw();
        
        
        
        
        // Rendu à chaque frame
    }
}

