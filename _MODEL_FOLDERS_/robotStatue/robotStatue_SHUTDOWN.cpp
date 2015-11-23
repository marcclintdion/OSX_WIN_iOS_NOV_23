
    //--------------------------------------------------
    if(robotStatue_HIGH_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &robotStatue_HIGH_COLORMAP);
        robotStatue_HIGH_COLORMAP  = 0;
    } 
    //--------------------------------------------------
    if(robotStatue_NORMALMAP != 0)
    { 
        glDeleteTextures(1, &robotStatue_NORMALMAP); 
        robotStatue_NORMALMAP = 0; 
    } 
    //--------------------------------------------------


    //__4th CHANNEL IS ->GLuint cubeMap[0]
    
    //==================================================
    //--------------------------------------------------
    //==================================================
    if(robotStatue_VBO  != 0)
    { 
        glDeleteBuffers(1, &robotStatue_VBO); 
        robotStatue_VBO  = 0; 
    } 
    if(robotStatue_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &robotStatue_INDICES_VBO); 
        robotStatue_INDICES_VBO  = 0; 
    } 
