//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#ifdef WIN32
        //----------------------------------------------------------------
        glClear (GL_DEPTH_BUFFER_BIT);
        glViewport(1, 1, (GLsizei)(viewWidth) * resize_SHADOW_FBO - 2, (GLsizei)(viewHeight) * resize_SHADOW_FBO - 2);
        //----------------------------------------------------------------

      LoadIdentity(shadowProjectionMatrix);
      PerspectiveMatrix(shadowProjectionMatrix, fieldOfView_SHADOW, (GLfloat)viewWidth /(GLfloat)viewHeight,  adjustNearFar_LIGHT[0],  adjustNearFar_LIGHT[1]);



/*
        //----------------------------------------------------------------
        glClear (GL_DEPTH_BUFFER_BIT);
        glViewport(1, 1, (2048)-2, (2048)-2);
        //----------------------------------------------------------------

        LoadIdentity(Light_Projection);
        PerspectiveMatrix(Light_Projection, fieldOfView_SHADOW, 2048 / 2048,  adjustNearFar[0],  adjustNearFar[1]);
*/
#endif
   
#ifdef   __APPLE__     
        //----------------------------------------------------------------
        glClear (GL_DEPTH_BUFFER_BIT);
        glViewport(1, 1, 2000 - 2, 1000 - 2);
        //----------------------------------------------------------------
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); 
        LoadIdentity(shadowProjectionMatrix);
        PerspectiveMatrix(shadowProjectionMatrix, fieldOfView_SHADOW, 2000 / 1000,  adjustNearFar_LIGHT[0],  adjustNearFar_LIGHT[1]);
#endif          
      

        //====================================================================================    

shaderNumber = 11;      
setupTransforms_Shadows();         

                                                            



    //========================================================================= 
    #include "_MODEL_FOLDERS_/robotStatue/robotStatue_SHADOW_0.cpp"

    //========================================================================= 

