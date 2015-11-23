//#include "headerFiles/glext.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

//================================================================================================================================
#define var GLfloat
#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))//to_use-> COUNT_OF( floorTile_2m_INDICES)
#define BUFFER_OFFSET(i) ((char *)0 + (i))
//================================================================================================================================
int  viewWidth  = 1280;
int  viewHeight = 720;

int mousePos[] =  {0, 0};

float  Pass_MIDDLE_Mouse[2];       //AT_SHUTDOWN_THESE_VALUES_ARE_BEING_PRINTED_THE_FILE->loadMouseSettings.cpp
float  Pass_MIDDLE_CONTROL_Mouse;  //
float  Pass_MIDDLE_SHIFT_Mouse[2]; //AT_RUNTIME_THESE_ARE_BEING_LOADED_INTO->WGL_ARB_multiSample.h
//================================================================================================================
#include "KEYBOARD/OS_DEFINES.cpp"
//==============================================================
#include "cpp/timer_B.cpp"
//==============================================================
#include "cpp/configure_GL.cpp"
//==============================================================
#include "headerFiles/FreeImage.h" //INSTALLED_TO /usr/local/lib
//==============================================================
#include "cpp/microsoft_WINDOW.cpp"
//==============================================================
#include "cpp/loadRuntimeShader.cpp"
//==============================================================
#include "cpp/buffers.cpp"
//==============================================================
#include "MATRIX_MATH.cpp"
//==============================================================



//==============================================================
//=======================_#############_========================
//=======================_#############_========================
//=======================_#############_========================
//=======================_#############_========================
//=======================_#############_========================
//=======================_#############_========================
//=======================_#############_========================
//=======================_#############_========================
//=======================_#############_========================
//==============================================================
void locator_GLOBALS(void)
{
    GLuint globalLocator = 0;
}

#include "GLOBALS.cpp"
//==============================================================
#include "cpp/FreeImage.cpp"
//==============================================================
#include "cpp/transformStacks.cpp"
//==============================================================
#include "selectShader.cpp"
//==============================================================
void initializeModels(void)
{
    #include "INITIALIZE.cpp"  
}
//=============================================================
void runDepth_PASS(void)
{
    glEnable(GL_DEPTH_TEST);
    glDepthMask(1);
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    glDepthFunc(GL_LESS);
    glBindFramebuffer(GL_FRAMEBUFFER, m_uiFrameBufferObject);
    
    #include "runDepth.cpp"
    
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    //glDepthMask(0);
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    //glDepthFunc(GL_EQUAL);

}
//==============================================================
void runColor_PASS(void)
{
#include "drawMainColor.cpp"
}
//==============================================================
void shutDownGL( void )
{
    
#include "SHUTDOWN.cpp"
}//__END__ void shutDownGL(void)
/*
 #ifdef WIN32
 void KillALData()
 {
 alDeleteBuffers(1, &Buffer_dungeonWAV);
 alDeleteSources(1, &Source_dungeonWAV);
 alutExit();
 }
 #endif
 */
//==============================================================
//=======================_#############_========================
//=======================_#############_========================
//=======================_#############_========================
//=======================_#############_========================
//=======================_#############_========================
//=======================_#############_========================
//=======================_#############_========================
//=======================_#############_========================
//=======================_#############_========================
//==============================================================




//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================




void InitGL( void )//__BEGIN_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
{
        start = getMilliCount();
    

#include "tier2_GLOBALS.cpp"
        
        //==========================================================================
        #ifdef WIN32
            #include "cpp/setPixelFormat.cpp"
            #include "include/glext_Init_B.cpp"
            //alutInit(NULL, 0);
            //-------------------------------------
            SetVSyncState(true);
            //-----------------------------------------------------------------------------
                        rotateModelWithMiddleMouse[0] = Pass_MIDDLE_Mouse[0];
                        rotateModelWithMiddleMouse[1] = Pass_MIDDLE_Mouse[1];
                        //-----------------------------------------------------------------
                        zoomModelWithMiddleMouse      = Pass_MIDDLE_CONTROL_Mouse;
                        //-----------------------------------------------------------------     
                        moveModelWithMiddleMouse[0]   = Pass_MIDDLE_SHIFT_Mouse[0];
                        moveModelWithMiddleMouse[1]   = Pass_MIDDLE_SHIFT_Mouse[1];
                        //-----------------------------------------------------------------       
       
        //=================
        #endif
    
                   
    

                
        //=======================
        GLuint initializeLocator = 0;
        initializeModels();
        //=======================



    //==============================================================================
    #ifdef WIN32   
        //atexit(KillALData);//_tell_openAL_to_run_KillALData_function_at_shutdown 
    #endif
        
    
    
    glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LEQUAL);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glAlphaFunc(GL_GREATER, 0.1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
        
//====================================================================================================================================

}//__END_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@




//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================

int runonce = 1;

void RenderGL(void)
{


frameStart = getMilliSpan(start);



//=======================================================================================================================

      
                        //=================================================================
                        #if defined (__APPLE__) && TARGET_OS_IPHONE == 1
                        //--------------         
                                //eyePosition[0] -= PassTouchMovement[0];
                                //eyePosition[1] -= PassTouchMovement[1];
                                //eyePosition[2] -= PassTouchMovement[2];                   
                        
                                //PassTouchMovement[0] = 0.0;
                                //PassTouchMovement[1] = 0.0;
                                //PassTouchMovement[2] = 0.0;
                        
                        //--------------                        
                        #endif 
                        //=================================================================
                                      
                        //=================================================================        
                       // #ifdef WIN32
                        //------------
                                rotateModelWithMiddleMouse[0] = Pass_MIDDLE_Mouse[0];
                                rotateModelWithMiddleMouse[1] = Pass_MIDDLE_Mouse[1];
                                //-------------------------------------------------------
                                zoomModelWithMiddleMouse = Pass_MIDDLE_CONTROL_Mouse;
                                //-------------------------------------------------------
                                moveModelWithMiddleMouse[0] = Pass_MIDDLE_SHIFT_Mouse[0];
                                moveModelWithMiddleMouse[1] = Pass_MIDDLE_SHIFT_Mouse[1];
                        //------------ 
                        //#endif
                        //=================================================================  
    
    



    //==============================================================
    //turnTable += 0.1;

    LoadIdentity(moveSetMatrix);
    //Translate(moveSetMatrix, moveSet[0], moveSet[1],moveSet[2]);
    //==============================================================
    runDepth_PASS();
    //==============================================================

    
//========================================================================
//-------------------------------___iOS___--------------------------------
//========================================================================
#if defined (__APPLE__) && TARGET_OS_IPHONE == 1
                  if(iOS_MSAA_IS_ON)
                  {
                      glBindFramebuffer(GL_FRAMEBUFFER, msaaFramebuffer);     
                  }else 
                  {
                      glBindFramebuffer(GL_FRAMEBUFFER, viewRenderbuffer);  
                  }
#endif 
//========================================================================
//-------------------------------___iOS___--------------------------------
//========================================================================    
    
    
    
    GLuint RenderLocator = 0;
    runColor_PASS();
    //==============================================================



    
    
    
    
    


    
    

//==================================
frameEnd  = getMilliSpan(start);
frameTime = frameEnd - frameStart;

#if defined (__APPLE__)
    NSLog(@"frameTime = %i milliseconds", (int)frameTime);
#endif
   
    

    
}//_END_RenderGL()//#####################################################################################################


//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================



//==================================
#ifdef __APPLE__
    #include <TargetConditionals.h>
#endif
//==================================
#if TARGET_IPHONE_SIMULATOR == 1
    //PROCESS_TOUCH

//-------------------------
#elif TARGET_OS_IPHONE == 1
	//PROCESS_TOUCH

//-------------------------
#elif TARGET_OS_MAC == 1 || WIN32 == 1

void ProcessKeyboard(void)
{

    
    
    

    //=====================================================================
    if (KEY_R)
    {
             #include "_SHADERS/basic/basic_SHADER_INIT.cpp"
        
    }


    if(KEY_D)
    {
        eyePosition[0] += 0.051;
    }
    if(KEY_A)
    {
        eyePosition[0] -= 0.051;
    }
    if(KEY_W)
    {
        eyePosition[1] += 0.051;
    }
    if(KEY_S)
    {
        eyePosition[1] -= 0.051;
    }
    if(KEY_Q)
    {
        eyePosition[2] += 0.051;
    }
    if(KEY_E)
    {
        eyePosition[2] -= 0.051;
    }




    if(KEY_J)
    {
        basic_LIGHT0_POS[0] -= 0.01;
    }
    if(KEY_L)
    {
        basic_LIGHT0_POS[0] += 0.01;
    }
    if(KEY_K)
    {
        basic_LIGHT0_POS[1] -= 0.01;
    }
    if(KEY_I)
    {
        basic_LIGHT0_POS[1] += 0.01;
    }
    if(KEY_U)
    {
        basic_LIGHT0_POS[2] -= 0.01;
    }
    if(KEY_O)
    {
        basic_LIGHT0_POS[2] += 0.01;
    }
    
  
  
    if(KEY_Z)
    {
        generic_Vec4_00[0] -= 0.3012;
    }
    if(KEY_X)
    {
        generic_Vec4_00[0] += 0.3012;
    }
    if(KEY_C)
    {
        generic_Vec4_00[1] -= 0.002;
    }
    if(KEY_V)
    {
        generic_Vec4_00[1] += 0.002;
    }
    if(KEY_B)
    {
        generic_Vec4_00[2] -= 0.002;
    }
    if(KEY_N)
    {
        generic_Vec4_00[2] += 0.002;
    }  
    if(KEY_M)
    {
        generic_Vec4_00[3] -= 0.0011;
    }
    if(KEY_COMMA)
    {
        generic_Vec4_00[3] += 0.0011;
    }      
    
    

 

}//_END_ProcessKeyboard()

#endif








//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================

