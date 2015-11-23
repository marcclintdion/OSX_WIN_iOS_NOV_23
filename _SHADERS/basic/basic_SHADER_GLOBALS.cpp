//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
unsigned char *vertexSource_basic;                                                                                  
unsigned char *fragmentSource_basic;   
//=========================================================
var         generic_Vec4_00[] = {512, 1.673991, 3.0, 1.32};
//=========================================================================
var         basic_LIGHT0_POS[]   = { 0.1,  -1.0, 0.8, 1.0};
//=
var         basic_LIGHT1_POS[]   = { 0.0, 0.05, 1.0, 1.0};
var         basic_LIGHT2_POS[]   = {-9.0, 5.9, 11.15, 1.0};
var         basic_LIGHT3_POS[]   = { 1.0, 1.0, 1.0, 1.0};
//=========================================================================
var         f_0_basic;
var         f_1_basic;
var         f_2_basic;
var         f_3_basic;
var         f_4_basic;
var         f_5_basic;
var         f_6_basic;
var         f_7_basic;
var         f_8_basic;
var         f_9_basic;


//========

//-----------------------------------
//=====================================================================================
GLuint      basic_SHADER_VERTEX;                                                                                 
GLuint      basic_SHADER_FRAGMENT;                                                                               
GLuint      basic_SHADER;     
//-------------------------------------------------------------------------------------
GLuint      UNIFORM_generic_Vec4_00_basic;

//-------------------------------------------
GLuint      UNIFORM_LIGHT0_POS_basic;
GLuint      UNIFORM_LIGHT1_POS_basic;
GLuint      UNIFORM_LIGHT2_POS_basic;

//=====                                                                     
GLuint      UNIFORM_shadowBias_basic;
//--------------------------------------
GLuint      UNIFORM_f_0_basic;
GLuint      UNIFORM_f_1_basic;
GLuint      UNIFORM_f_2_basic;// f=float //_for generic_UI_inputs_and_shader_templates_maybe_this_will_be_useful
GLuint      UNIFORM_f_3_basic;
GLuint      UNIFORM_f_4_basic;
GLuint      UNIFORM_f_5_basic;
GLuint      UNIFORM_f_6_basic;
GLuint      UNIFORM_f_7_basic;
GLuint      UNIFORM_f_8_basic;
GLuint      UNIFORM_f_9_basic;

//-------------------------------------------------------------------------------------
GLuint      UNIFORM_SHADOW_TEX_MATRIX_basic;
GLuint      UNIFORM_MODEL_ROTATIONinv_MATRIX_basic;                 
GLuint      UNIFORM_PROJECTION_MATRIX_basic;  
GLuint      UNIFORM_MODELVIEW_MATRIX_basic; 
GLuint      UNIFORM_VIEW_MATRIX_basic; 

//-------------------------------------------------------------------------------------
GLuint      UNIFORM_TEX_COLOR_HIGH_basic;
GLuint      UNIFORM_TEX_DOT3_basic;
          //shadow
GLuint      UNIFORM_CUBEMAP_basic;
