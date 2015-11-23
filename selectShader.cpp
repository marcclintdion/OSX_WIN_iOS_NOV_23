var shaderNumber = 0;

void SelectShader(var shaderNumber)
{
    
    
    
    
    if(shaderNumber ==  11)
    {
        #include "_SHADERS/SHADOWS/shadows_32bit_Stride_SHADER_RENDER.cpp"
    }
    
    
    
    if(shaderNumber ==  17)
    {
        #include "_SHADERS/basic/basic_SHADER_RENDER.cpp"
    }
    //--------------------------------------------------------------------------------------
    
    
    
    
}
