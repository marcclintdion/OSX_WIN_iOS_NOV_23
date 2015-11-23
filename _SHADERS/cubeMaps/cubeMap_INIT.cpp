glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
glEnable(GL_TEXTURE_CUBE_MAP);
glGenTextures(1, &cubemapTexture[0]);
    glBindTexture(GL_TEXTURE_CUBE_MAP,  cubemapTexture[0]);

    char textName_POSX[] = "_SHADERS/cubeMaps/monoLake_posX.png";
    char textName_NEGX[] = "_SHADERS/cubeMaps/monoLake_negX.png";
    char textName_POSY[] = "_SHADERS/cubeMaps/monoLake_posY.png";
    char textName_NEGY[] = "_SHADERS/cubeMaps/monoLake_negY.png";
    char textName_POSZ[] = "_SHADERS/cubeMaps/monoLake_posZ.png";
    char textName_NEGZ[] = "_SHADERS/cubeMaps/monoLake_negZ.png";
    

    
    
    FREE_IMAGE_FORMAT fifmt;
    FIBITMAP *dib;
    FIBITMAP *temp = dib;    
    
    //------------------------------------------------------------------------------------------
    
    fifmt = FreeImage_GetFileType(textName_POSX, 0);
    dib = FreeImage_Load(fifmt,   textName_POSX, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        //free(pixels);
        FreeImage_Unload(dib);
	}
    //------------------------------------------------------------------------------------------
    
    fifmt = FreeImage_GetFileType(textName_NEGX, 0);
    dib = FreeImage_Load(fifmt,   textName_NEGX, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        pixels = 0;
        free(pixels);
        FreeImage_Unload(dib);
	}
    //------------------------------------------------------------------------------------------
    
    fifmt = FreeImage_GetFileType(textName_POSY, 0);
    dib = FreeImage_Load(fifmt,   textName_POSY, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        pixels = 0;
        free(pixels);
        FreeImage_Unload(dib);
	}
    //------------------------------------------------------------------------------------------
    
    fifmt = FreeImage_GetFileType(textName_NEGY, 0);
    dib = FreeImage_Load(fifmt,   textName_NEGY, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        pixels = 0;
        free(pixels);
        FreeImage_Unload(dib);
	}

    //------------------------------------------------------------------------------------------
    
    fifmt = FreeImage_GetFileType(textName_POSZ, 0);
    dib = FreeImage_Load(fifmt,   textName_POSZ, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        pixels = 0;
        free(pixels);
        FreeImage_Unload(dib);
	}
    //------------------------------------------------------------------------------------------
    
    fifmt = FreeImage_GetFileType(textName_NEGZ, 0);
    dib = FreeImage_Load(fifmt,   textName_NEGZ, 0);
    temp = dib;
    
    dib = FreeImage_ConvertTo32Bits(temp);
    FreeImage_Unload(temp);	 
	
    if( dib != NULL )
	{
        BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
        
        glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGBA, FreeImage_GetWidth(dib), FreeImage_GetHeight(dib), 0, GL_BGRA, GL_UNSIGNED_BYTE, pixels);
      
        pixels = 0;
        free(pixels);
        FreeImage_Unload(dib);
	}


    
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER,    GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER,    GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S,        GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T,        GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R,        GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_GENERATE_MIPMAP_SGIS,  GL_TRUE );    



    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################

