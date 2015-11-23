//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//======================================================================================================================
//======================================================================================================================
#if defined(__APPLE__) && defined(__MACH__)
/* Apple OSX and iOS (Darwin). ------------------------------ */
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR == 1
glGenTextures(1, &m_uiShadowMapTexture);
//------------
glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);
glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, 2000,
             1000,
             0, GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, 0);

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//------------------------------------------------------------------
glGenFramebuffers(1, &m_uiFrameBufferObject);
glBindFramebuffer(GL_FRAMEBUFFER, m_uiFrameBufferObject);
//---------------------
glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_uiShadowMapTexture, 0);
glBindFramebuffer(GL_FRAMEBUFFER, 0);

#elif TARGET_OS_IPHONE == 1
glGenTextures(1, &m_uiShadowMapTexture);
//------------
glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);
glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, 2000,
             1000,
             0, GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, 0);

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//------------------------------------------------------------------
glGenFramebuffers(1, &m_uiFrameBufferObject);
glBindFramebuffer(GL_FRAMEBUFFER, m_uiFrameBufferObject);
//---------------------
glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_uiShadowMapTexture, 0);
glBindFramebuffer(GL_FRAMEBUFFER, 0);

#elif TARGET_OS_MAC == 1
glGenTextures(1, &m_uiShadowMapTexture);
//------------
glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);
glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, (GLsizei)viewWidth  * resize_SHADOW_FBO,
             (GLsizei)viewHeight * resize_SHADOW_FBO,
             0, GL_DEPTH_COMPONENT,  GL_UNSIGNED_INT,  NULL);

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//------------------------------------------------------------------
glGenFramebuffers(1, &m_uiFrameBufferObject);
glBindFramebuffer(GL_FRAMEBUFFER, m_uiFrameBufferObject);
//---------------------
glDrawBuffer(GL_NONE);//_ON_SOME_MACHINES_THIS_IS_REQUIRED / ON_SOME_IT_FAILS
glReadBuffer(GL_NONE);//_SAME_AS_ABOVE
//---------------------
glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_uiShadowMapTexture, 0);
glBindFramebuffer(GL_FRAMEBUFFER, 0);

#endif
#endif
//===================== NSLog(@"viewWidth: %f", (GLfloat)viewWidth);






#ifdef WIN32
glGenTextures(1, &m_uiShadowMapTexture);
//------------
glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);
glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, (GLsizei)viewWidth  * resize_SHADOW_FBO,
             (GLsizei)viewHeight * resize_SHADOW_FBO,
             0, GL_DEPTH_COMPONENT,  GL_UNSIGNED_INT,  NULL);

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//------------------------------------------------------------------
glGenFramebuffers(1, &m_uiFrameBufferObject);
glBindFramebuffer(GL_FRAMEBUFFER, m_uiFrameBufferObject);
//---------------------
glDrawBuffer(GL_NONE);//_ON_SOME_MACHINES_THIS_IS_REQUIRED / ON_SOME_IT_FAILS(ALTHOUGH__NOW_THAT_I_THINK_OF_IT...THIS_PROBLEM_SEEMS_TO_HAVE_MOSTLY_GONE_AWAY
glReadBuffer(GL_NONE);//_SAME_AS_ABOVE--------------------------------------------------------------------------------------------------------------> SHOULD_DO_SOME_RESEARCH_HERE :)
//---------------------
glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_uiShadowMapTexture, 0);
glBindFramebuffer(GL_FRAMEBUFFER, 0);
#endif



//======================================================================================================================
//======================================================================================================================

    //glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS,   &getOpenGL_ExtentionValues);//use to test for extention info

    //=============================================================================================================

    //#include "_SHADERS/cubeMaps/cubeMap_INIT.cpp"
    //====================================================================================

    //#####################################################################################################################


    //====================================================================================
    #include "_SHADERS/SHADOWS/shadows_32bit_Stride_SHADER_INIT.cpp"
    //====================================================================================
    //#include "_SHADERS/gaussianBlur_9x/gaussianBlur_9x_Horizontal_SHADER_INIT.cpp"
    //#include "_SHADERS/gaussianBlur_9x/gaussianBlur_9x_Vertical_SHADER_INIT.cpp"  
    //====================================================================================

    #include "_SHADERS/basic/basic_SHADER_INIT.cpp"
    //====================================================================================        



    //#####################################################################################################################
    
    //=========================================================================
    #include "_MODEL_FOLDERS_/robotStatue/robotStatue_INIT.cpp"
    //=========================================================================

