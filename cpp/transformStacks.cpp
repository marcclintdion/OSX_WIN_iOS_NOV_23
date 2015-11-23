//=======================================================================================================================
//============================================================================================================================
void setupTransforms_MainColor(void)
{
    
    LoadIdentity(viewMatrix);
    Translate(viewMatrix,             eyePosition[0],
              eyePosition[1],
              eyePosition[2]);
    
    
    LoadIdentity(viewRotateMatrix);
    //-----------------------------
    Rotate(viewRotateMatrix, 1.0, 0.0, 0.0, rotateModelWithMiddleMouse[0] -60.0);//-60.0 - 00.0
    Rotate(viewRotateMatrix, 0.0, 0.0, 1.0, -rotateModelWithMiddleMouse[1]);
    
}

//============================================================================================================================
void setupTransforms_Shadows(void)
{
    
    LoadIdentity(shadowViewMatrix);
    //-------------------------------------------------
    /*       Translate(shadowViewMatrix,       eyePosition_SHADOW[0],
     eyePosition_SHADOW[1],
     eyePosition_SHADOW[2]);
     */
    LookAt(shadowViewMatrix, eyePosition_SHADOW[0], eyePosition_SHADOW[1], eyePosition_SHADOW[2] ,  0, 0, 0, 0.0f, 1.0f, 0.0f);
    
}

void ColorRenderMatrixFunctions(void)
{
    
    MultiplyMatrix(modelViewMatrix, viewMatrix, modelWorldMatrix);
    //------------------------------------------------------------
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
    
    //----------------------------------------------------------------------------------------------------------
    LoadIdentity(shadowTextureMatrix);
    MultiplyMatrix(shadowTextureMatrix, shadowBiasMatrix, shadowProjectionMatrix);
    MultiplyMatrix(shadowTextureMatrix, shadowTextureMatrix, shadowViewMatrix);    //_MULTIPLY THESE TO A TEMP MATRIX TO AVOID ROUND OFF ERRORS   //USES MORE CODE WITH INCREASED PRECISION
    //----------------------------------------------------------------------------------------------------------
    
    LoadIdentity(tempMatrix_E);
    MultiplyMatrix(tempMatrix_E, viewRotateMatrix, modelRotationMatrix);
    //----------------------------------------------------------------------------------------------------------
    LoadIdentity(modelRotationINVmatrix);
    InvertMatrix(modelRotationINVmatrix, tempMatrix_E);
    //----------------------------------------------------------------------------------------------------------
}
