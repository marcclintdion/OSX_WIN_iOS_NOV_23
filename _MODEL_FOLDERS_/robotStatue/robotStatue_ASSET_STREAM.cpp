#ifdef WIN32 
void load_robotStatue_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_robotStatue = FreeImage_GetFileType(robotStatue_FilePath, 0);                       
    dib_robotStatue   = FreeImage_Load(fifmt_robotStatue, robotStatue_FilePath, 0);                    
    temp_robotStatue  = dib_robotStatue;                                                      
    dib_robotStatue   = FreeImage_ConvertTo32Bits(temp_robotStatue);                          
    FreeImage_Unload(temp_robotStatue);                                            

    if( dib_robotStatue != NULL )                                                    
    {                                                                       
        pixels_robotStatue = (BYTE*)FreeImage_GetBits(dib_robotStatue);                       
    }                                                                     

    robotStatue_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_robotStatue_FromSystemRAM(void)                                          
{                                                                           
    if( dib_robotStatue != NULL )                                                    
    {                                                                       
        free(pixels_robotStatue);                                                    
        FreeImage_Unload(dib_robotStatue);                                           
    }                                                                     

}                                                                           
//==========================================================                
void load_robotStatue_DOT3_FromHDtoSystemRAM(void*)                                  
{                                                                           
    fifmt_robotStatue_DOT3 = FreeImage_GetFileType(robotStatue_DOT3_FilePath, 0);             
    dib_robotStatue_DOT3   = FreeImage_Load(fifmt_robotStatue_DOT3, robotStatue_DOT3_FilePath, 0);     
    temp_robotStatue_DOT3  = dib_robotStatue_DOT3;                                            
    dib_robotStatue_DOT3   = FreeImage_ConvertTo32Bits(temp_robotStatue_DOT3);                
    FreeImage_Unload(temp_robotStatue_DOT3);                                       

    if( dib_robotStatue_DOT3 != NULL )                                               
    {                                                                       
        pixels_robotStatue_DOT3 = (BYTE*)FreeImage_GetBits(dib_robotStatue_DOT3);             
    }                                                                     

    robotStatue_DOT3_isLoadedFromDriveAndWaiting = true;                             
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//-----------------------------------------------------------               
void delete_robotStatue_DOT3_FromSystemRAM(void)                                          
{                                                                           
    if( dib_robotStatue_DOT3 != NULL )                                                    
    {                                                                       
        free(pixels_robotStatue_DOT3);                                                    
        FreeImage_Unload(dib_robotStatue_DOT3);                                           
    }                                                                     

}                                                                           
#endif                                                                      
//==========================================================                
