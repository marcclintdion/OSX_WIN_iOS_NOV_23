

//=========================================
#if defined(__APPLE__) && defined(__MACH__)
	/* Apple OSX and iOS (Darwin). */
    #include <TargetConditionals.h>
#endif
//=========================================

#if TARGET_IPHONE_SIMULATOR == 1
    /* xCode Simulator */

#elif TARGET_OS_IPHONE == 1
 //==================================================================================================================
    spriteImage             = [UIImage imageNamed:@"robotStatue_DOT3.png"].CGImage;
    width                   =  CGImageGetWidth(spriteImage);                                          
    height                  =  CGImageGetHeight(spriteImage);                                         
    spriteData              = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));                    
    spriteContext           =  CGBitmapContextCreate(spriteData, width,                               
                                                                 height,                              
                                                                 8,                                   
                                                                 width * 4,                           
                                                                 CGImageGetColorSpace(spriteImage),   
                                                                 kCGImageAlphaNoneSkipLast);          
    CGContextSetBlendMode(spriteContext, kCGBlendModeCopy);                                           
    CGContextTranslateCTM (spriteContext, 0, (float)height);//--FLIP_Y_AXIS                           
    CGContextScaleCTM (spriteContext, 1.0, -1.0);           //--FLIP_Y_AXIS                           
    CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);                 
    CGContextRelease(spriteContext);                                                                  
    //---------                                                                                       
        glGenTextures(1, &robotStatue_NORMALMAP);
        glBindTexture(GL_TEXTURE_2D, robotStatue_NORMALMAP);
        ConfigureAndLoadTexture(spriteData,  width, height);                                          
        if(spriteData != NULL)                                                                        
        {                                                                                             
             free(spriteData);                                                                        
        }                                                                                             
    //-------------------------------------------------------------------------------------           
    spriteImage             = [UIImage imageNamed:@"frozenKnight_HIGH_EMIT.png"].CGImage;
    width                   =  CGImageGetWidth(spriteImage);                                          
    height                  =  CGImageGetHeight(spriteImage);                                         
    spriteData              = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));                    
    spriteContext           =  CGBitmapContextCreate(spriteData,                                      
                                                     width,                                           
                                                     height,                                          
                                                     8,                                               
                                                     width * 4,                                       
                                                     CGImageGetColorSpace(spriteImage),               
                                                     kCGImageAlphaNoneSkipLast);                      
    CGContextSetBlendMode(spriteContext, kCGBlendModeCopy);                                           
    CGContextTranslateCTM (spriteContext, 0, (float)height);//--FLIP_Y_AXIS                           
    CGContextScaleCTM (spriteContext, 1.0, -1.0);           //--FLIP_Y_AXIS                           
    CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);                 
    CGContextRelease(spriteContext);                                                                  
    //---------                                                                                       
        glGenTextures(1, &robotStatue_HIGH_COLORMAP);
        glBindTexture(GL_TEXTURE_2D, robotStatue_HIGH_COLORMAP);
        ConfigureAndLoadTexture(spriteData,  width, height);                                          
        if(spriteData != NULL)                                                                        
        {                                                                                             
            free(spriteData);                                                                         
        }                                                                                             
//====================================================================================================================

#elif TARGET_OS_MAC == 1 || WIN32 == 1


        glGenTextures( 1, &robotStatue_HIGH_COLORMAP );
        glBindTexture( GL_TEXTURE_2D, robotStatue_HIGH_COLORMAP );
    loadTexture("_MODEL_FOLDERS_/robotStatue/frozenKnight_HIGH_EMIT.png");
    //-------------------------------------------------------------------------------------------
        glGenTextures( 1, &robotStatue_NORMALMAP );
        glBindTexture( GL_TEXTURE_2D, robotStatue_NORMALMAP );
    loadTexture("_MODEL_FOLDERS_/robotStatue/robotStatue_DOT3.png");
    //-------------------------------------------------------------------------------------------


#endif





    //=====================================================
    load_robotStatue_VBOs();
    //=====================================================
    robotStatue_boundingBox[0] = -5.296644f;
    robotStatue_boundingBox[1] =  5.296644f;
    robotStatue_boundingBox[2] = -2.199093f;
    robotStatue_boundingBox[3] =  1.515242f;
    robotStatue_boundingBox[4] = -6.104839f;
    robotStatue_boundingBox[5] =  7.277227f;  

