       glUseProgram(SHADER_shadow_32bit_Stride);    
       //-----------------------------------------------------------------------------
       LoadIdentity(moveSet_x_modelWorldMatrix);
       MultiplyMatrix(moveSet_x_modelWorldMatrix, moveSetMatrix, modelWorldMatrix);        
      
      
       //-----------------------------------------------------------------------------
       LoadIdentity(tempMatrix_E);  
       MultiplyMatrix(tempMatrix_E, shadowViewMatrix, viewRotateMatrix);            
       //-----------------------------------------------------------------------------
       LoadIdentity(tempMatrix_A);  
       MultiplyMatrix(tempMatrix_A, shadowProjectionMatrix, shadowViewMatrix);            
       //-----------------------------------------------------------------------------
       LoadIdentity(tempMatrix_B); 
       MultiplyMatrix(tempMatrix_B, tempMatrix_A, moveSet_x_modelWorldMatrix);            
       
       
/*     
    LoadIdentity(tempMatrix_A);    
    MultiplyMatrix(tempMatrix_A, viewMatrix, viewRotateMatrix);    
    //---------------------------------------------------------------------    
    MultiplyMatrix(moveSet_x_modelWorldMatrix, moveSetMatrix, modelWorldMatrix);    
    //---------------------------------------------------------------------    
    LoadIdentity(tempMatrix_B);     
    MultiplyMatrix(tempMatrix_B,  shadowTextureMatrix, moveSet_x_modelWorldMatrix);     
    //---------------------------------------------------------------------    
    LoadIdentity(tempMatrix_C);     
    MultiplyMatrix(tempMatrix_C,  projectionMatrix, tempMatrix_A);       
    //---------------------------------------------------------------------    
    LoadIdentity(tempMatrix_D);     
    MultiplyMatrix(tempMatrix_D,  tempMatrix_C, moveSet_x_modelWorldMatrix);        
*/     
              
        //MultiplyMatrix(light_ModelView, light_View, modelWorld);                                                                                                                         
       //-------------------------------------------------------------------------------------------
                           glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
                           glEnableVertexAttribArray(0);	
                           glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
                           glEnableVertexAttribArray(1);  
                           glVertexAttribPointer(2,   2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
                           glEnableVertexAttribArray(2);                                                       
                           //-----------------------------------------------------------------------
                           glUniformMatrix4fv(UNIFORM_SHADOW_PROJECTION_MATRIX_shadow_32bit_Stride,     1, 0,   tempMatrix_B);                           
                           glUniformMatrix4fv(UNIFORM_SHADOW_VIEW_MATRIX_shadow_32bit_Stride,           1, 0,   shadowViewMatrix);                             
                           glUniformMatrix4fv(UNIFORM_MOVESET_MATRIX_shadow_32bit_Stride,               1, 0,   moveSetMatrix);  
                           glUniformMatrix4fv(UNIFORM_SHADOW_MODELWORLD_MATRIX_shadow_32bit_Stride,     1, 0,   modelWorldMatrix);                           
                           glUniformMatrix4fv(UNIFORM_MOVESET_x_MODELWORLD_MATRIX_shadow_32bit_Stride,  1, 0,   moveSet_x_modelWorldMatrix);    

