		
		//FreeImage_Save(FIF_JPEG, dib, "mybitmap.jpg", JPEG_QUALITYSUPERB);
/*
void ConfigureAndLoadTexture(GLubyte *textureData, GLint texWidth, GLint texHeight )
{
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST); 
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);	
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, textureData);
    
    glGenerateMipmapEXT(GL_TEXTURE_2D);
}
*/


//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================


void ConfigureAndLoadTexture(GLubyte *textureData, GLint texWidth, GLint texHeight )
{
#if defined(__APPLE__) && defined(__MACH__)
	/* Apple OSX and iOS (Darwin). ------------------------------ */
#include <TargetConditionals.h>
#endif
    
#if TARGET_OS_IPHONE == 1 || TARGET_IPHONE_SIMULATOR == 1
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    //---------------
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4.0);
    //---------------
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData);
    glGenerateMipmap(GL_TEXTURE_2D);
    
#elif TARGET_OS_MAC == 1 || WIN32
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    //----------------
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 4.0);
    //----------------
    glTexParameteri( GL_TEXTURE_2D, GL_GENERATE_MIPMAP_SGIS, GL_TRUE );
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, textureData);
    
#endif

    
    //==========
  
    
}


//=======================================================================================================================
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//=======================================================================================================================

#if defined(__APPLE__) && defined(__MACH__)
	/* Apple OSX and iOS (Darwin). ------------------------------ */
#include <TargetConditionals.h>
#endif

#if TARGET_IPHONE_SIMULATOR == 1

    
#elif TARGET_OS_IPHONE == 1

    
#elif TARGET_OS_MAC == 1 || WIN32
    void loadTexture(char *textureFileName) //
    {
        FREE_IMAGE_FORMAT fifmt = FreeImage_GetFileType(textureFileName, 0);
        
        FIBITMAP *dib = FreeImage_Load(fifmt, textureFileName,0);
        
        FIBITMAP *temp = dib;
        dib = FreeImage_ConvertTo32Bits( temp);
        FreeImage_Unload(temp);
        //--------------------------------------------------------------------
        if( dib != NULL )
        {
            BYTE *pixels = (BYTE*)FreeImage_GetBits(dib);
            
            ConfigureAndLoadTexture(pixels,  FreeImage_GetWidth(dib),  FreeImage_GetHeight(dib) );
            
            pixels = 0;
            free(pixels);
            FreeImage_Unload(dib);
        }
        
        
    }
    
#endif





