                                                                                
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, robotStatue_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, robotStatue_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, robotStatue_POSITION[0],
                                                robotStatue_POSITION[1],
                                                robotStatue_POSITION[2]);
                    //--------------------------------------------------------              
/*
                    Rotate(modelWorldMatrix,      1.0,
                                                  0.0,
                                                  0.0,
                                                -60.0);

*/
                    Rotate(modelWorldMatrix,    robotStatue_ROTATION[0],
                                                robotStatue_ROTATION[1], 
                                                robotStatue_ROTATION[2],  
                                                robotStatue_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              


                    Rotate(modelRotationMatrix, robotStatue_ROTATION[0],
                                                robotStatue_ROTATION[1],
                                                robotStatue_ROTATION[2], 
                                                robotStatue_ROTATION[3]);


                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       

                    glActiveTexture(GL_TEXTURE0 );
                    glBindTexture(GL_TEXTURE_2D,        robotStatue_HIGH_COLORMAP);
                    //------------
                    glActiveTexture(GL_TEXTURE1);
                    glBindTexture(GL_TEXTURE_2D,        robotStatue_NORMALMAP);
                    //------------

                    //------------
                    glActiveTexture(GL_TEXTURE3);
                    glBindTexture(GL_TEXTURE_CUBE_MAP,  cubemapTexture[0]);
                    //======================================================
                    glDrawElements(GL_TRIANGLES, 18846, GL_UNSIGNED_INT, 0);

        
