ColorRenderMatrixFunctions();

    glUseProgram(basic_SHADER);
        //------------------------------------------------------------------------------
        glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(2,     2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
        glEnableVertexAttribArray(2);
        //------------------------------------------------------------------------------------------------
        glUniformMatrix4fv(UNIFORM_SHADOW_TEX_MATRIX_basic,                1, 0,    tempMatrix_B);
        glUniformMatrix4fv(UNIFORM_MODEL_ROTATIONinv_MATRIX_basic,         1, 0,    modelRotationINVmatrix);
        glUniformMatrix4fv(UNIFORM_PROJECTION_MATRIX_basic,                1, 0,    tempMatrix_D);
        glUniformMatrix4fv(UNIFORM_MODELVIEW_MATRIX_basic,                 1, 0,    modelViewMatrix);
        //---------------

        //------------------------------------------------------------------------------------------------
        glUniform4f(UNIFORM_generic_Vec4_00_basic,                  generic_Vec4_00[0],
                                                                                    generic_Vec4_00[1],
                                                                                    generic_Vec4_00[2],
                                                                                    generic_Vec4_00[3]);

        //------------------------------------------
        glUniform4f(UNIFORM_LIGHT0_POS_basic,                       basic_LIGHT0_POS[0],
                                                                                    basic_LIGHT0_POS[1],
                                                                                    basic_LIGHT0_POS[2],
                                                                                    basic_LIGHT0_POS[3]);
                                                                       
        glUniform4f(UNIFORM_LIGHT1_POS_basic,                       basic_LIGHT1_POS[0],
                                                                                    basic_LIGHT1_POS[1],
                                                                                    basic_LIGHT1_POS[2],
                                                                                    basic_LIGHT1_POS[3]);
                                                                       
        glUniform4f(UNIFORM_LIGHT2_POS_basic,                       basic_LIGHT2_POS[0],
                                                                                    basic_LIGHT2_POS[1],
                                                                                    basic_LIGHT2_POS[2],
                                                                                    basic_LIGHT2_POS[3]);
                                                                       
          
        glUniform1f(UNIFORM_shadowBias_basic,                       shadowBias);
        //---------------------------------------
        glUniform1f(UNIFORM_f_0_basic,                              f_0_basic);
        glUniform1f(UNIFORM_f_1_basic,                              f_1_basic);
        glUniform1f(UNIFORM_f_2_basic,                              f_2_basic);
        glUniform1f(UNIFORM_f_3_basic,                              f_3_basic);
        glUniform1f(UNIFORM_f_4_basic,                              f_4_basic);
        glUniform1f(UNIFORM_f_5_basic,                              f_5_basic);
        glUniform1f(UNIFORM_f_6_basic,                              f_6_basic);
        glUniform1f(UNIFORM_f_7_basic,                              f_7_basic);
        glUniform1f(UNIFORM_f_8_basic,                              f_8_basic);
        glUniform1f(UNIFORM_f_9_basic,                              f_9_basic);
      
        //---------------------------------------

        glUniform1i(UNIFORM_TEX_COLOR_HIGH_basic,             0);
        glUniform1i(UNIFORM_TEX_DOT3_basic,                   1);
        //shadow
        glUniform1i(UNIFORM_CUBEMAP_basic,                    3);

















