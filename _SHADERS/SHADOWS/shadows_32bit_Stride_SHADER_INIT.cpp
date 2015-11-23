    
    SHADER_shadow_32bit_Stride = glCreateProgram();
    //---------------------------------------------------- 
const GLchar *vertexSource_shadow_32bit_Stride =

"    #define highp                                                                                                                                 \n"


"    uniform      mat4  shadowProjectionMatrix;                                                                                                    \n"
"    uniform      mat4  shadowViewMatrix;                                                                                                          \n"
"    uniform      mat4  moveSetMatrix;                                                                                                             \n"  
"    uniform      mat4  modelWorldMatrix;                                                                                                    \n"
"    uniform      mat4  moveSet_x_modelWorldMatrix;                                                                                                \n"

"    attribute    vec4  position;                                                                                                                  \n"



"    void main()                                                                                                                                   \n"
"    {                                                                                                                                             \n"                                                                            

"         highp vec4 tempPosition    =  shadowProjectionMatrix  * position;             \n"


"         gl_Position                =  tempPosition;                                                                                              \n"

"    }\n";

    //---------------------------------------------------------------------

const GLchar *fragmentSource_shadow_32bit_Stride =     

" #ifdef GL_ES                                                                                                                                     \n"
" #else                                                                                                                                            \n"
" #define highp                                                                                                                                    \n"
" #endif                                                                                                                                           \n"


"     void main()                                                                                                                                  \n"
"     {                                                                                                                                            \n"


"         gl_FragColor = highp vec4(1.0, 1.0, 1.0, 1.0);                                                                                           \n"         


"    }\n";
    //--------------------------------------------------------------------------------------------------------------------------------------   
    SHADER_VERTEX_shadow_32bit_Stride = glCreateShader( GL_VERTEX_SHADER);
    glShaderSource( SHADER_VERTEX_shadow_32bit_Stride, 1, &vertexSource_shadow_32bit_Stride, NULL );
    glCompileShader( SHADER_VERTEX_shadow_32bit_Stride);

    //----------------------------------------------------        
    SHADER_FRAGMENT_shadow_32bit_Stride = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource( SHADER_FRAGMENT_shadow_32bit_Stride, 1, &fragmentSource_shadow_32bit_Stride, NULL );
    glCompileShader(SHADER_FRAGMENT_shadow_32bit_Stride);
       
    //--------------------------------------------------------------------------------------------------------------------------------------    
    glAttachShader( SHADER_shadow_32bit_Stride, SHADER_VERTEX_shadow_32bit_Stride );
    glAttachShader( SHADER_shadow_32bit_Stride, SHADER_FRAGMENT_shadow_32bit_Stride );
    //--------------------------------------------------------------------------------------------------------------------------------------    
    glBindAttribLocation(SHADER_shadow_32bit_Stride,   0, "position");    
    glBindAttribLocation(SHADER_shadow_32bit_Stride,   1, "normal");    
    glBindAttribLocation(SHADER_shadow_32bit_Stride,   2, "texture");       
    //--------------------------------------------------------------------------------------------------------------------------------------    
    glDeleteShader(SHADER_VERTEX_shadow_32bit_Stride);
    glDeleteShader(SHADER_FRAGMENT_shadow_32bit_Stride);   
    glLinkProgram( SHADER_shadow_32bit_Stride);  
    //--------------------------------------------------------------------------------------------------------------------------------------  
    UNIFORM_SHADOW_PROJECTION_MATRIX_shadow_32bit_Stride             = glGetUniformLocation(SHADER_shadow_32bit_Stride, "shadowProjectionMatrix");  
    UNIFORM_SHADOW_VIEW_MATRIX_shadow_32bit_Stride                   = glGetUniformLocation(SHADER_shadow_32bit_Stride, "shadowViewMatrix");
    UNIFORM_MOVESET_MATRIX_shadow_32bit_Stride                       = glGetUniformLocation(SHADER_shadow_32bit_Stride, "moveSetMatrix");  
    UNIFORM_SHADOW_MODELWORLD_MATRIX_shadow_32bit_Stride             = glGetUniformLocation(SHADER_shadow_32bit_Stride, "modelWorldMatrix");
    UNIFORM_MOVESET_x_MODELWORLD_MATRIX_shadow_32bit_Stride          = glGetUniformLocation(SHADER_shadow_32bit_Stride, "moveSet_x_modelWorldMatrix");
