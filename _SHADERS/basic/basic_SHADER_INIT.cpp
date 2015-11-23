////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
basic_SHADER = glCreateProgram();

//----------------------------------------------------
const GLchar *vertexSource_basic =

"#define highp                                                                                         \n"

"attribute       vec4   position;                                                                                   \n"
"attribute       vec2   uv0;                                                                                        \n"

"uniform         mat4   projectionMatrix;                                                     \n"


"varying        highp vec2   uv0_PASS;                                                                              \n"



"//=======================================================================================================// \n"
"void main()                                                                                                         \n"
"{                                                                                                         \n"
"//=======================================================================================================// \n"






"    uv0_PASS                =  uv0;                                                                               \n"

"   //-------------------------------------------------------------------------------                           \n"
"   gl_Position             =  projectionMatrix * position; \n"







"//=======================================================================================================// \n"
"}\n";
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const GLchar *fragmentSource_basic =

" #ifdef GL_ES                                                                                                                                     \n"
" #else                                                                                                                                            \n"
" #define highp                                                                                                                                    \n"
" #endif                                                                                                                                           \n"

"uniform      sampler2D   ColorMAP_HIGH;                                                                             \n"

"varying     highp  vec2    uv0_PASS;                                                                                      \n"




"//=======================================================================================================//            \n"
"void main()                                                                                                            \n"
"{                                                                                                                      \n"
"//=======================================================================================================//            \n"





"    gl_FragColor            =   texture2D(ColorMAP_HIGH,  uv0_PASS.xy);                                                \n"




"//=======================================================================================================//            \n"
"}\n";
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



        //=======================================================================================================================                   
        basic_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);                                                          
        glShaderSource( basic_SHADER_VERTEX, 1,   &vertexSource_basic, NULL );
        glCompileShader( basic_SHADER_VERTEX);                                              //glShaderBinary                              
        //----------------------------------------------------                                                                  
        basic_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);                                                      
        glShaderSource( basic_SHADER_FRAGMENT, 1, &fragmentSource_basic, NULL );
        glCompileShader(basic_SHADER_FRAGMENT);                                              //glShaderBinary                                                                             
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( basic_SHADER, basic_SHADER_VERTEX );                                                        
        glAttachShader( basic_SHADER, basic_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(basic_SHADER,   0, "position");                                                              
        glBindAttribLocation(basic_SHADER,   1, "normal");                                                            
        glBindAttribLocation(basic_SHADER,   2, "uv0");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glDeleteShader( basic_SHADER_VERTEX);                                                                             
        glDeleteShader( basic_SHADER_FRAGMENT);                                                                           
        glLinkProgram(basic_SHADER);                                                                                      
        //--------------------------------------------------------------------------------------------------                    
        UNIFORM_SHADOW_TEX_MATRIX_basic                         = glGetUniformLocation(basic_SHADER, "shadowTexMatrix");  
        UNIFORM_MODEL_ROTATIONinv_MATRIX_basic                  = glGetUniformLocation(basic_SHADER, "modelRotationINVmatrix"); 
        UNIFORM_PROJECTION_MATRIX_basic                         = glGetUniformLocation(basic_SHADER, "projectionMatrix");          
        UNIFORM_MODELVIEW_MATRIX_basic                          = glGetUniformLocation(basic_SHADER, "modelViewMatrix");                  
  
        //-------------------------------
        UNIFORM_generic_Vec4_00_basic                           = glGetUniformLocation(basic_SHADER, "generic_Vec4_00");
        //-------------------------------      
        UNIFORM_LIGHT0_POS_basic                                = glGetUniformLocation(basic_SHADER, "light0_POS");
        UNIFORM_LIGHT1_POS_basic                                = glGetUniformLocation(basic_SHADER, "light1_POS");
        UNIFORM_LIGHT2_POS_basic                                = glGetUniformLocation(basic_SHADER, "light2_POS");   
        //================================== 
        UNIFORM_shadowBias_basic                                = glGetUniformLocation(basic_SHADER, "shadowBias");  
        //================================== 
        UNIFORM_f_0_basic                                       = glGetUniformLocation(basic_SHADER, "f_0"); 
        UNIFORM_f_1_basic                                       = glGetUniformLocation(basic_SHADER, "f_1"); 
        UNIFORM_f_2_basic                                       = glGetUniformLocation(basic_SHADER, "f_2"); 
        UNIFORM_f_3_basic                                       = glGetUniformLocation(basic_SHADER, "f_3"); 
        UNIFORM_f_4_basic                                       = glGetUniformLocation(basic_SHADER, "f_4"); 
        UNIFORM_f_5_basic                                       = glGetUniformLocation(basic_SHADER, "f_5"); 
        UNIFORM_f_6_basic                                       = glGetUniformLocation(basic_SHADER, "f_6"); 
        UNIFORM_f_7_basic                                       = glGetUniformLocation(basic_SHADER, "f_7"); 
        UNIFORM_f_8_basic                                       = glGetUniformLocation(basic_SHADER, "f_8"); 
        UNIFORM_f_9_basic                                       = glGetUniformLocation(basic_SHADER, "f_9"); 


                                   
        //--------------------------------
        UNIFORM_TEX_COLOR_HIGH_basic                            = glGetUniformLocation(basic_SHADER, "ColorMAP_HIGH");
        UNIFORM_TEX_DOT3_basic                                  = glGetUniformLocation(basic_SHADER, "NormalMAP");
      //shadow
        UNIFORM_CUBEMAP_basic                                   = glGetUniformLocation(basic_SHADER, "EnvMap");

//######################################################


//#include "settings.cpp"  This should be parsed as a text file so it won't override current settings with startup settings that are pre-compiled and in loaded here











