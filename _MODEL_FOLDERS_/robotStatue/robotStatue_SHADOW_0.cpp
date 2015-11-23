setupTransforms_Shadows();
    //--------------------------
    glBindBuffer(GL_ARRAY_BUFFER, robotStatue_VBO);  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, robotStatue_INDICES_VBO);  
    //--------------------------------
    LoadIdentity(modelWorldMatrix); 
    //--------------------------------------------------------
    Translate(modelWorldMatrix, robotStatue_POSITION[0] + moveSet[0],
                                robotStatue_POSITION[1] + moveSet[1], 
                                robotStatue_POSITION[2] + moveSet[2]); 
    //--------------------------------------------------------
    Rotate(modelWorldMatrix,    robotStatue_ROTATION[0],
                                robotStatue_ROTATION[1], 
                                robotStatue_ROTATION[2], 
                                robotStatue_ROTATION[3]); 
    //--------------------------------------------------------
    SelectShader(shaderNumber); 
    //--------------------------------------------------------
    //glDrawElements(GL_TRIANGLES, 55704, GL_UNSIGNED_INT, 0);
