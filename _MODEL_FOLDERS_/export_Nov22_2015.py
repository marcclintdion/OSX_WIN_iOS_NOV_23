# TODO:  PLEASE_ADD_THE_TEXTURE_COPY_AND_MOVE_OPERATION_INTO_A_(IS_DIRTY)_TEST_SO_ONLY_TEXTURES_WHICH_HAVE_CHANGED_WILL_BE_SAVED

#===========
import os
import bpy
import bmesh
#===========


obj_names=[]    # names of meshes in "C-suitable" format
vtx = []        # list of dictionaries for each mesh
faces = []      # list of lists
vl = []         # list of vertices for each mesh
nl = []         # list of normals for each mesh
uvl =   []      # list of UV coords for each mesh
obj_mtx=[]      # list of local transformations for each object
obj_cnt = 0     # object count
max_vcnt= 0     # qty of vertices for biggest mesh


###########################################################
#
#   Round values of the 3D vector
#
###########################################################

def r3d(v):
    return round(v[0],6), round(v[1],6), round(v[2],6)

###########################################################
#
#   Round values of the 2D vector
#
###########################################################

def r2d(v):
    return round(v[0],6), round(v[1],6)


###########################################################
#
#   Convert object name to be suitable for C definition
#
###########################################################

def clearName(name):
    tmp=name.upper()
    ret=""
    for i in tmp:
        if (i in " ./\-+#$%^!@"):
            ret=ret+"_"
        else:
            ret=ret+i
    return ret


print('\n')     
print('\n')     
print('============================__START__====================================')
print('\n')     
print('\n')  

#====================================================================================
#------SYNC_NAMES -> Thanks Brita
#====================================================================================
bpy.ops.object.mode_set(mode='OBJECT')#-------------CHANGE_MODE

if bpy.context.selected_objects:
    for obj in bpy.context.selected_objects:
        bpy.context.scene.objects.active = obj

        print('===================================================')

        print(bpy.context.object.active_material.name)
        print(bpy.context.scene.objects.active.name)
        print(bpy.context.object.data.name)

        bpy.context.scene.objects.active.name = bpy.context.object.active_material.name
        bpy.context.object.data.name          = bpy.context.object.active_material.name

        print(bpy.context.object.active_material.name)
        print(bpy.context.scene.objects.active.name)
        print(bpy.context.object.data.name)

#====================================================================================
#----MAIN_FUNCTIONS_THAT_RELY_ON_PATH
#====================================================================================

if bpy.context.selected_objects:
    for obj in bpy.context.selected_objects:
        bpy.context.scene.objects.active = obj
        bpy.ops.object.mode_set(mode='OBJECT')

        #============================================================
        #directoryPath    = '//Jewel/_MODEL_FOLDERS_/' #<-presumably, the double slash is doing the same as the following
        #directoryPath    = "\OSL_MOUNTAINS\_MODEL_FOLDERS_\\" #<-here the escape is cancelling the escape.
        #path = bpy.path.abspath(directoryPath)

        #path = r"C:\marcclintdion\\Documents\CONTENT_GLSL\!!!!_ELEMENTS_OF_ZELDA\monkeyHeadCave\_MODEL_FOLDERS_"
        
        path = r"/Users/marcclintdion/Documents/CONTENT_GLSL/!!_A_NEW_FORMAT/OSX_WIN_iOS/_MODEL_FOLDERS_"


        #------------------------------------
        #if os.path.exists(path + "\\" + obj.name) == False:
        #    os.mkdir(path +  "\\" + obj.name)
        #print('@@@@@@@@@@@@@@@@@@@@@@@@')
        #print(path + "\\" + obj.name)
        #-----
        if os.path.exists(path + "/" + obj.name) == False:
            os.mkdir(path +  "/" + obj.name)
        print('@@@@@@@@@@@@@@@@@@@@@@@@')
        print(path + "/" + obj.name)
        
        #============================================================
        #----THE_OPEN_GL_EXPORTER_DOES_IT'S_THING
        #============================================================
        msh = obj.to_mesh(bpy.context.scene,False,'PREVIEW', True) #-------THE_'False'_IS_THE_APPLY_MODIFIERS_FLAG
        
        
        print(obj)
        print(msh)
        print(obj.name)
        print('\n')
        #============================================================
        lvdic = {} # -------------local dictionary
        lfl = [] # ---------------local faces index list
        lvl = [] # ---------------local vertex list
        lnl = [] # ---------------local normal list
        luvl = [] # --------------local uv list
        lvcnt = 0 # --------------local vertices count
        isSmooth = False
        hasUV = True    # true by default, it will be verified below
    
        print("Building for: %s\n"%obj.name)
        #============================================================ 
        if (len(msh.tessface_uv_textures) > 0):
            if (msh.tessface_uv_textures.active is None):
                hasUV=False
        else:
            hasUV = False
        #-------------------
        if (hasUV):
            activeUV = msh.tessface_uv_textures.active.data
        #============================================================ 
        obj_names.append(clearName(obj.name))
        obj_cnt+=1 
        print('objectCount =', obj_cnt)
        print('\n')
        #============================================================ 
        for i,f in enumerate(msh.tessfaces):
            isSmooth = f.use_smooth
            tmpfaces = []
            for j,v in enumerate(f.vertices):  
                vec = msh.vertices[v].co
                vec = r3d(vec)
                
                if (isSmooth):  # use vertex normal
                    nor = msh.vertices[v].normal
                else:           # use face normal
                    nor = f.normal
            
                nor = r3d(nor)
            
                if (hasUV):
                    co = activeUV[i].uv[j]
                    co = r2d(co)
                else:
                    co = (0.0, 0.0)
            
                key = vec, nor, co
                vinx = lvdic.get(key)
            
                if (vinx is None): # vertex not found
                    lvdic[key] = lvcnt
                    lvl.append(vec)
                    lnl.append(nor)
                    luvl.append(co)
                    tmpfaces.append(lvcnt)
                    lvcnt+=1
                else:
                    inx = lvdic[key]
                    tmpfaces.append(inx)
        
            if (len(tmpfaces)==3): 
                lfl.append(tmpfaces)
            else:
                lfl.append([tmpfaces[0], tmpfaces[1], tmpfaces[2]])
                lfl.append([tmpfaces[0], tmpfaces[2], tmpfaces[3]])
        
   
        bpy.data.meshes.remove(msh)
        #===============================================================    
        #update global lists and dictionaries
        vtx.append(lvdic)
        faces.append(lfl)
        vl.append(lvl)
        nl.append(lnl)
        uvl.append(luvl)
        obj_mtx.append(obj.matrix_local)
        
        #===============================================================
        #============---WRITE_INDICES========
        #===============================================================      
        numberOfFaces = len(lfl)
        numberOfIndices = numberOfFaces * 3
        #-----------------------------------
        filename = obj.name + '_INDICES' + '.cpp'
        #=======
        #file = open(path + '\\' + obj.name + '\\' + filename, "w", newline="\n") #_WIN
        #
        file = open(path + '/' + obj.name + '/' + filename, "w", newline="\n") #_OSX
        #--------------------
        file.write("GLuint ")
        file.write(obj.name)
        file.write("_INDICES[] = \n{\n")
        file.write("    //numberOfIndices = %d\n" %numberOfIndices)
        file.write("\n")
        #-------------------------------------------------------------------
        for faceCount in range(numberOfFaces):#---------print the index list
            file.write("%d" %lfl[faceCount][0])
            file.write(", ")
            file.write("%d" %lfl[faceCount][1])
            file.write(", ")
            file.write("%d" %lfl[faceCount][2])
            file.write(", ")
            file.write("\n")
        #---------------------------------------
        file.write("}; \n")
        file.close()
        #=========================================================================
        #============---WRITE_VERTICES========
        #=========================================================================
        numberOfVerts    = len(lvl)
        print(numberOfVerts)
        numberOfVertices = numberOfVerts
        #-----------------------------------
        filename = obj.name + '.cpp'
        #=======
        #file = open(path + '\\' + obj.name + '\\' + filename, "w", newline="\n") #_WIN
        #
        file = open(path + '/' + obj.name + '/' + filename, "w", newline="\n") #_OSX
        #---------------------
        file.write("GLfloat ")
        file.write(obj.name)
        file.write("[] = \n{\n")
        file.write("    //numberOfVertices = %d\n" %numberOfVertices)
        file.write("\n")
        #-------------------------------------------------------------------
        for vertCount in range(numberOfVertices):#---------print the vertex list
            file.write("\t%f " %lvl[vertCount][0])
            file.write(", ")
            file.write("\t%f " %lvl[vertCount][1])
            file.write(", ")
            file.write("\t%f " %lvl[vertCount][2])
            file.write(", ")
            file.write("\t%f " %lnl[vertCount][0])
            file.write(", ")
            file.write("\t%f " %lnl[vertCount][1])
            file.write(", ")
            file.write("\t%f " %lnl[vertCount][2])
            file.write(", ")
            file.write("\t%f " %luvl[vertCount][0])
            file.write(", ")
            file.write("\t%f " %luvl[vertCount][1])
            file.write(", ")
            file.write("\n")

        #--------------------------------------
        file.write("}; \n")  
        file.close()
        
        
        #=============================================================================================================
        #------PRINT_GLOBALS
        #============================================================================================================
        ###filename = obj.name + '_GLOBALS' + '.cpp'
        ###file = open(path + '\\' + obj.name + '\\' + filename, "w", newline="\n")
        ###filename = obj.name + '_GLOBALS.cpp' #_OSX
        ###file = open(path  + obj.name + '/' + filename, "w", newline="\n") #_OSX

        filename = obj.name + '_GLOBALS' + '.cpp'
        #=======
        #file = open(path + '\\' + obj.name + '\\' + filename, "w", newline="\n") #_WIN
        #
        file = open(path + '/' + obj.name + '/' + filename, "w", newline="\n") #_OSX
        
        #---------------------
        file.write("GLfloat %s_POSITION[]             = { %ff, %ff, %ff, 1.0 }; " %(obj.name, obj.location[0], obj.location[1], obj.location[2]))
        file.write("\n")
        file.write("GLfloat %s_ROTATION[]             = { %ff, %ff, %ff, %ff }; " %(obj.name, obj.rotation_axis_angle[0], obj.rotation_axis_angle[1], obj.rotation_axis_angle[2], obj.rotation_axis_angle[3]))
        file.write("\n")
        file.write("GLfloat %s_SCALE[]                = { %ff, %ff, %ff, 1.0 }; " %(obj.name, obj.scale[0], obj.scale[1], obj.scale[2]))
        file.write("\n//----------------------------------------------------------------- \n")
        file.write("GLfloat %s_LIGHT_POSITION_01[]    = { 2.0, 15.0, 30.0, 1.0 }; " %(obj.name))
        file.write("\n")
        file.write("GLfloat %s_SHININESS              = 80.0; " %(obj.name))
        file.write("\n")
        file.write("GLfloat %s_ATTENUATION            =  1.0; " %(obj.name))
        file.write("\n//----------------------------------------------------------------- \n")
        file.write("GLuint %s_VBO; " %(obj.name))
        file.write("\n")
        file.write("GLuint %s_INDICES_VBO; " %(obj.name))
        file.write("\n//----------------------------------------------------------------- \n")
        file.write("GLuint %s_NORMALMAP; " %(obj.name))
        file.write("\n")
        file.write("\n")
        file.write("GLuint %s_COLORMAP; " %(obj.name))
        file.write("\n")
        file.write("GLuint %s_MASK0MAP; " %(obj.name))
        file.write("\n")
        file.write("\n//----------------------------------------------------------------- \n")
        file.write("GLfloat %s_boundingBox[6]; " %(obj.name))
        file.write("\n")
        
        #-----------
        file.close()
        
        #=============================================================================================================
        #------CALCULATE_BOUNDING_BOXES
        #=============================================================================================================
        smallest_X = 0.0
        largest_X  = 0.0
        smallest_Y = 0.0
        largest_Y  = 0.0
        smallest_Z = 0.0
        largest_Z  = 0.0
        
        for vertCount in range(numberOfVertices):#---------print the vertex list

            #=============================
            if lvl[vertCount][0] < smallest_X:
                smallest_X = lvl[vertCount][0]
            if lvl[vertCount][0] > largest_X:
                largest_X  = lvl[vertCount][0]
            #-----------------------------
            if lvl[vertCount][1] < smallest_Y:
                smallest_Y = lvl[vertCount][1]
            if lvl[vertCount][1] > largest_Y:
                largest_Y  = lvl[vertCount][1]
            #-----------------------------
            if lvl[vertCount][2] < smallest_Z:
                smallest_Z = lvl[vertCount][2]
            if lvl[vertCount][2] > largest_Z:
                largest_Z  = lvl[vertCount][2]
            #-----------------------------
   
        #=============================================================================================================
        #------PRINT_INITIALIZE
        #=============================================================================================================
        filename = obj.name + '_INIT' + '.cpp' 
        #=======
        #file = open(path + '\\' + obj.name + '\\' + filename, "w", newline="\n") #_WIN
        
        file = open(path + '/' + obj.name + '/' + filename, "w", newline="\n")#_OSX
        
        #---------------------
        file.write("\n      //===========================================================================================")
        file.write("\n     /* #ifdef __APPLE__")
        file.write("\n      //--------------\n")
        file.write("      spriteImage             = [UIImage imageNamed:@\"%s_DOT3.png\"].CGImage ; \n" %(obj.name))
        file.write("      width                   =  CGImageGetWidth(spriteImage); \n")
        file.write("      height                  =  CGImageGetHeight(spriteImage);  \n")
        file.write("      spriteData              = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));  \n")
        file.write("      spriteContext           =  CGBitmapContextCreate(spriteData, width, height, 8, width * 4, CGImageGetColorSpace(spriteImage), kCGImageAlphaNoneSkipLast);  \n")
        file.write("      CGContextSetBlendMode(spriteContext, kCGBlendModeCopy); \n")
        file.write("      CGContextTranslateCTM (spriteContext, 0, (float)height);//--FLIP_Y_AXIS \n")
        file.write("      CGContextScaleCTM (spriteContext, 1.0, -1.0);           //--FLIP_Y_AXIS \n")
        file.write("      CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);  \n")
        file.write("      CGContextRelease(spriteContext); \n")
        file.write("      //--------- \n")
        file.write("              glGenTextures(1, &%s_NORMALMAP);  \n" %obj.name)
        file.write("              glBindTexture(GL_TEXTURE_2D, %s_NORMALMAP);   \n" %obj.name)
        file.write("      ConfigureAndLoadTexture(spriteData,  width, height); \n")
        file.write("      if(spriteData != NULL) \n")
        file.write("      { \n")
        file.write("              free(spriteData); \n")
        file.write("      } \n")
        file.write("\n      //-------------------------------------------------------------------------------------------\n")
        file.write("      spriteImage             = [UIImage imageNamed:@\"%s.png\"].CGImage ; \n" %(obj.name))
        file.write("      width                   =  CGImageGetWidth(spriteImage); \n")
        file.write("      height                  =  CGImageGetHeight(spriteImage);  \n")
        file.write("      spriteData              = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));  \n")
        file.write("      spriteContext           =  CGBitmapContextCreate(spriteData, width, height, 8, width * 4, CGImageGetColorSpace(spriteImage), kCGImageAlphaNoneSkipLast);  \n")
        file.write("      CGContextSetBlendMode(spriteContext, kCGBlendModeCopy); \n")
        file.write("      CGContextTranslateCTM (spriteContext, 0, (float)height);//--FLIP_Y_AXIS \n")
        file.write("      CGContextScaleCTM (spriteContext, 1.0, -1.0);           //--FLIP_Y_AXIS \n")
        file.write("      CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);  \n")
        file.write("      CGContextRelease(spriteContext); \n")
        file.write("      //--------- \n")
        file.write("              glGenTextures(1, &%s_COLORMAP);  \n" %obj.name)
        file.write("              glBindTexture(GL_TEXTURE_2D, %s_COLORMAP);   \n" %obj.name)
        file.write("      ConfigureAndLoadTexture(spriteData,  width, height); \n")
        file.write("      if(spriteData != NULL) \n")
        file.write("      { \n")
        file.write("              free(spriteData); \n")
        file.write("      } \n")
        file.write("\n      //-------------------------------------------------------------------------------------------\n")
        file.write("      spriteImage             = [UIImage imageNamed:@\"%s_MASK0.png\"].CGImage ; \n" %(obj.name))
        file.write("      width                   =  CGImageGetWidth(spriteImage); \n")
        file.write("      height                  =  CGImageGetHeight(spriteImage);  \n")
        file.write("      spriteData              = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));  \n")
        file.write("      spriteContext           =  CGBitmapContextCreate(spriteData, width, height, 8, width * 4, CGImageGetColorSpace(spriteImage), kCGImageAlphaNoneSkipLast);  \n")
        file.write("      CGContextSetBlendMode(spriteContext, kCGBlendModeCopy); \n")
        file.write("      CGContextTranslateCTM (spriteContext, 0, (float)height);//--FLIP_Y_AXIS \n")
        file.write("      CGContextScaleCTM (spriteContext, 1.0, -1.0);           //--FLIP_Y_AXIS \n")
        file.write("      CGContextDrawImage(spriteContext,  CGRectMake(0, 0, width, height), spriteImage);  \n")
        file.write("      CGContextRelease(spriteContext); \n")
        file.write("      //--------- \n")
        file.write("              glGenTextures(1, &%s_MASK0MAP);  \n" %obj.name)
        file.write("              glBindTexture(GL_TEXTURE_2D, %s_MASK0MAP);   \n" %obj.name)
        file.write("      ConfigureAndLoadTexture(spriteData,  width, height); \n")
        file.write("      if(spriteData != NULL) \n")
        file.write("      { \n")
        file.write("              free(spriteData); \n")
        file.write("      } \n")
        file.write("      //---- \n")       
        file.write("      #endif */\n")   
        #--------------
        file.write("      //========================================================================================================\n")   
        file.write("      #ifdef WIN32 \n")       



        file.write("      glGenTextures( 1, &%s_NORMALMAP); \n"                                 %(obj.name))
        file.write("      glBindTexture( GL_TEXTURE_2D, %s_NORMALMAP);\n"                       %(obj.name))
        
        file.write("      loadTexture(\"_MODEL_FOLDERS_/%s/%s_DOT3.png\"); \n"                  %(obj.name, obj.name))

        
        file.write("      glGenTextures( 1, &%s_COLORMAP);\n"                                   %(obj.name))
        file.write("      glBindTexture( GL_TEXTURE_2D, %s_COLORMAP);\n"                        %(obj.name))
        file.write("      loadTexture(\"_MODEL_FOLDERS_/%s/%s.png\"); \n"                       %(obj.name, obj.name))
        
        
        file.write("      //glGenTextures( 1, &%s_MASK0MAP );\n"                                %(obj.name))
        file.write("      //glBindTexture( GL_TEXTURE_2D, %s_MASK0MAP);\n"                      %(obj.name))
        file.write("      //loadTexture(\"_MODEL_FOLDERS_/%s/%s_MASK0.png\"); \n"               %(obj.name, obj.name))
        #--------------
        file.write("      #endif \n")
        file.write("      //------------------------------------------------------------------------------\n")
        file.write("      #include    \"%s.cpp\" \n" %obj.name)
        file.write("      glGenBuffers(1,              &%s_VBO);  \n" %obj.name)
        file.write("      glBindBuffer(GL_ARRAY_BUFFER, %s_VBO);  \n" %obj.name)
        file.write("      glBufferData(GL_ARRAY_BUFFER, sizeof(%s), %s, GL_STATIC_DRAW);  \n" %(obj.name, obj.name))
        file.write("      glBindBuffer(GL_ARRAY_BUFFER, 0); \n")
        file.write("      //------------------------------------------------------------------------------\n")
        file.write("      #include    \"%s_INDICES.cpp\"   \n" %obj.name)                                                                                               
        file.write("      glGenBuffers(1,              &%s_INDICES_VBO);  \n" %obj.name)                                                                                
        file.write("      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, %s_INDICES_VBO);   \n" %obj.name)                                                                           
        file.write("      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(%s_INDICES), %s_INDICES, GL_STATIC_DRAW);   \n" %(obj.name, obj.name))                    
        file.write("      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);   \n")
        file.write("      //========================================================================================================\n")   
        #--------------
        file.write("      %s_boundingBox[0] = %ff;   \n" %(obj.name, smallest_X))
        file.write("      %s_boundingBox[1] =  %ff;  \n" %(obj.name, largest_X))
        file.write("      %s_boundingBox[2] = %ff;   \n" %(obj.name, smallest_Y))
        file.write("      %s_boundingBox[3] =  %ff;  \n" %(obj.name, largest_Y))
        file.write("      %s_boundingBox[4] = %ff;   \n" %(obj.name, smallest_Z))
        file.write("      %s_boundingBox[5] =  %ff;  \n" %(obj.name, largest_Z))
        
        file.write("\n")
        file.write("\n")       
        #-----------
        file.close()

        #=============================================================================================================
        #------PRINT_SHADOW_0_PASS
        #=============================================================================================================
        filename = obj.name + '_SHADOW_0' + '.cpp'
        #=======
        #file = open(path + '\\' + obj.name + '\\' + filename, "w", newline="\n") #_WIN

        file = open(path + '/' + obj.name + '/' + filename, "w", newline="\n")#_OSX
        
        #---------------------
        file.write("setupTransforms_Shadows();\n")
        file.write("    //--------------------------\n")
        file.write("    glBindBuffer(GL_ARRAY_BUFFER, %s_VBO);  \n" %obj.name)
        file.write("    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, %s_INDICES_VBO);  \n" %obj.name)
        file.write("    //--------------------------------\n")
        file.write("    LoadIdentity(modelWorldMatrix); \n")
        file.write("    //--------------------------------------------------------\n")
        file.write("    Translate(modelWorldMatrix, %s_POSITION[0],\n                                %s_POSITION[1], \n                                %s_POSITION[2]); \n"  %(obj.name, obj.name, obj.name))
        file.write("    //--------------------------------------------------------\n")
        file.write("    Rotate(modelWorldMatrix,    %s_ROTATION[0],\n                                %s_ROTATION[1], \n                                %s_ROTATION[2], \n                                %s_ROTATION[3]); \n"  %(obj.name, obj.name, obj.name, obj.name))
        file.write("    //--------------------------------------------------------\n")
        file.write("    SelectShader(shaderNumber); \n")  
        file.write("    //--------------------------------------------------------\n")  
        file.write("    glDrawElements(GL_TRIANGLES, %d, GL_UNSIGNED_INT, 0); \n" %numberOfIndices )
        
        
        
        #-----------
        file.close()
        #=============================================================================================================
        #------PRINT_MAIN_COLOR
        #=============================================================================================================
        filename = obj.name + '_RENDER' + '.cpp' 
        #=======
        #file = open(path + '\\' + obj.name + '\\' + filename, "w", newline="\n") #_WIN
        #
        file = open(path  + '/' + obj.name + '/' + filename, "w", newline="\n") #_OSX
        #---------------------
        file.write("setupTransforms_MainColor();\n")
        file.write("    //--------------------------\n")
        file.write("    glBindBuffer(GL_ARRAY_BUFFER, %s_VBO);  \n" %obj.name)
        file.write("    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, %s_INDICES_VBO);  \n" %obj.name)
        file.write("    //--------------------------------\n")
        file.write("    LoadIdentity(modelWorldMatrix); \n")
        file.write("    //--------------------------------------------------------\n")
        file.write("    Translate(modelWorldMatrix, %s_POSITION[0],\n                                %s_POSITION[1], \n                                %s_POSITION[2]); \n"  %(obj.name, obj.name, obj.name))
        file.write("    //--------------------------------------------------------\n")
        file.write("    Rotate(modelWorldMatrix,    %s_ROTATION[0],\n                                %s_ROTATION[1], \n                                %s_ROTATION[2], \n                                %s_ROTATION[3]); \n"  %(obj.name, obj.name, obj.name, obj.name))
        file.write("    //--------------------------------------------------------\n")
        #-----------
        file.write("    LoadIdentity(modelRotationMatrix); \n")
        file.write("    //--------------------------------------------------------\n")
        file.write("    Rotate(modelRotationMatrix,    %s_ROTATION[0],\n                                   %s_ROTATION[1], \n                                   %s_ROTATION[2], \n                                   %s_ROTATION[3]); \n"  %(obj.name, obj.name, obj.name, obj.name))
        file.write("//===================================================   \n")
        file.write("SelectShader(shaderNumber); \n")
        file.write("//===================================================   \n")
        
        file.write("    glActiveTexture ( GL_TEXTURE0 );  \n")
        file.write("    glBindTexture(GL_TEXTURE_2D, %s_COLORMAP); \n" %obj.name)
        file.write("    //------------  \n")
        file.write("    glActiveTexture (GL_TEXTURE1);  \n")
        file.write("    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture); \n")
        file.write("    //------------  \n")
        file.write("    glActiveTexture (GL_TEXTURE2);  \n")
        file.write("    glBindTexture(GL_TEXTURE_2D, %s_NORMALMAP); \n" %obj.name)
        file.write("    //--------------  \n")
        file.write("    glActiveTexture (GL_TEXTURE3);  \n")
        file.write("    glBindTexture(GL_TEXTURE_2D, %s_MASK0MAP); \n" %obj.name)
   
        file.write("    //-----------------------------------------------------  \n")
        file.write("    glDrawElements(GL_TRIANGLES, %d, GL_UNSIGNED_INT, 0); \n" %numberOfIndices )
        
        
        #-----------
        file.close()
        #=============================================================================================================
        #------PRINT_SHUTDOWN
        #=============================================================================================================
        filename = obj.name + '_SHUTDOWN' + '.cpp' 
        #=======
        #file = open(path + '\\' + obj.name + '\\' + filename, "w", newline="\n") #_WIN

        file = open(path  + '/' + obj.name + '/' + filename, "w", newline="\n") #_OSX
        #---------------------
        file.write("    if(%s_NORMALMAP != 0) \n" %obj.name)
        file.write("    { \n")
        file.write("        glDeleteTextures(1, &%s_NORMALMAP); \n" %obj.name)
        file.write("        %s_NORMALMAP = 0; \n" %obj.name)
        file.write("    } \n")
        file.write("    if(%s_COLORMAP  != 0)\n" %obj.name)
        file.write("    { \n")
        file.write("        glDeleteTextures(1, &%s_COLORMAP); \n" %obj.name)
        file.write("        %s_COLORMAP  = 0; \n" %obj.name)
        file.write("    } \n")
        file.write("    if(%s_MASK0MAP  != 0)\n" %obj.name)
        file.write("    { \n")
        file.write("        glDeleteTextures(1, &%s_MASK0MAP); \n" %obj.name)
        file.write("        %s_MASK0MAP  = 0; \n" %obj.name)
        file.write("    } \n")

        file.write("    //-------------------------------------------------- \n")
        file.write("    if(%s_VBO  != 0) \n" %obj.name)
        file.write("    { \n")
        file.write("        glDeleteBuffers(1, &%s_VBO); \n" %obj.name)
        file.write("        %s_VBO  = 0; \n" %obj.name)
        file.write("    } \n")
        file.write("    if(%s_INDICES_VBO  != 0) \n" %obj.name)
        file.write("    { \n")
        file.write("        glDeleteBuffers(1, &%s_INDICES_VBO); \n" %obj.name)
        file.write("        %s_INDICES_VBO  = 0; \n" %obj.name)
        file.write("    } \n")
        
        #-----------
        file.close()




#====================================================================================
#------PRINT_GLOBALS_STRINGS
#====================================================================================



numberOfObjects = 0

objectNameList = []

if bpy.context.selected_objects:
    for obj in bpy.context.selected_objects:
        bpy.context.scene.objects.active = obj
        bpy.ops.object.mode_set(mode='OBJECT')
        #=============================================================================================================
        #------GLOBALS_STRINGS_BUILD_NAMES_LIST
        #=============================================================================================================
        numberOfObjects += 1
        #append "obj.name" for all objects to a list for the next chunk which prints the names to C include paths

        objectNameList.append(obj.name)

#=============================================================================================================
#------GLOBALS_STRINGS_BUILD_NAMES_LIST
#=============================================================================================================
filename =  'GLOBALS_STRINGS.cpp'
#======
#path = r"C:\marcclintdion\Documents\CONTENT_GLSL\!!!!_ELEMENTS_OF_ZELDA\monkeyHeadCave" #_WIN
#file = open(path  + '\\'  + 'STRINGS' + '\\' + filename, "w", newline="\n")#_WIN
#-----
#_OSX
path = r"/Users/marcclintdion/Documents/CONTENT_GLSL/!!_A_NEW_FORMAT/OSX_WIN_iOS"               #_OSX_A
file = open(path  + '/'  + 'STRINGS' + '/' + filename, "w", newline="\n")





for loopCounter in range(numberOfObjects):
    #---------------------
    file.write("    //========================================================================= \n")
    #file.write("    #include \"_MODEL_FOLDERS_\\%s\\%s_GLOBALS.cpp\"  \n" %(objectNameList[loopCounter], objectNameList[loopCounter]))#_WIN
    #
    file.write("    #include \"_MODEL_FOLDERS_/%s/%s_GLOBALS.cpp\"  \n" %(objectNameList[loopCounter], objectNameList[loopCounter]))#_OSX

#-----------
file.close()
#=============================================================================================================
#------INITIALIZE_STRINGS_BUILD_NAMES_LIST
#=============================================================================================================
filename =  'INITIALIZE_STRINGS.cpp'
#=====
file = open(path  + '/'  + 'STRINGS' + '/' + filename, "w", newline="\n")


for loopCounter in range(numberOfObjects):
    #---------------------
    file.write("    //========================================================================= \n")
    #file.write("    #include \"_MODEL_FOLDERS_\\%s\\%s_INIT.cpp\"     \n" %(objectNameList[loopCounter], objectNameList[loopCounter]))#_WIN
    #
    file.write("    #include \"_MODEL_FOLDERS_/%s/%s_INIT.cpp\"     \n" %(objectNameList[loopCounter], objectNameList[loopCounter]))#OSX

#-----------
file.close()



#=============================================================================================================
#------runDepth_STRINGS_BUILD_NAMES_LIST
#=============================================================================================================
filename =  'runDepth_STRINGS.cpp'

file = open(path  + '/'  + 'STRINGS' + '/' + filename, "w", newline="\n")


for loopCounter in range(numberOfObjects):
    #---------------------
    file.write("    //========================================================================= \n")
    
    #file.write("    #include \"_MODEL_FOLDERS_\\%s\\%s_SHADOW_0.cpp\"  \n" %(objectNameList[loopCounter], objectNameList[loopCounter]))#_WIN
    
    file.write("    #include \"_MODEL_FOLDERS_/%s/%s_SHADOW_0.cpp\"  \n" %(objectNameList[loopCounter], objectNameList[loopCounter]))#_OSX


#-----------
file.close()
#=============================================================================================================
#------drawMainColor_STRINGS_BUILD_NAMES_LIST
#=============================================================================================================
filename =  'drawMainColor_STRINGS.cpp'
#=======
file = open(path  + '/'  + 'STRINGS' + '/' + filename, "w", newline="\n")


for loopCounter in range(numberOfObjects):
    #---------------------
    file.write("    //========================================================================= \n")
    #file.write("    #include \"_MODEL_FOLDERS_\\%s\\%s_RENDER.cpp\"  \n" %(objectNameList[loopCounter], objectNameList[loopCounter]))#_WIN
    file.write("    #include \"_MODEL_FOLDERS_/%s/%s_RENDER.cpp\"  \n" %(objectNameList[loopCounter], objectNameList[loopCounter]))#_OSX

#-----------
file.close()
#=============================================================================================================
#------SHUTDOWN_STRINGS_BUILD_NAMES_LIST
#=============================================================================================================
filename =  'SHUTDOWN_STRINGS.cpp'
#=======
file = open(path  + '/'  + 'STRINGS' + '/' + filename, "w", newline="\n")

for loopCounter in range(numberOfObjects):
    #---------------------
    file.write("    //========================================================================= \n")
    #file.write("    #include \"_MODEL_FOLDERS_\\%s\\%s_SHUTDOWN.cpp\"  \n" %(objectNameList[loopCounter], objectNameList[loopCounter]))#_WIN
    file.write("    #include \"_MODEL_FOLDERS_/%s/%s_SHUTDOWN.cpp\"  \n" %(objectNameList[loopCounter], objectNameList[loopCounter]))#_OSX

#-----------
file.close()


        




#################################################################################################################
#######################################################___EOF___#################################################
#################################################################################################################

print('\n')
print('\n')
print('=============================__END__==============================')
print('\n')
print('\n')











              
'''
#====================================================================================
#------REMOVE_ALL_MODIFIERS -> using 2 CGC quickTools commands.
#====================================================================================
if bpy.context.selected_objects:
    for obj in bpy.context.selected_objects:
        bpy.context.scene.objects.active = obj#---------MODIFIERS ARE NOW BEING IGNORED
        bpy.ops.object.mode_set(mode='OBJECT')
        
        for mod in obj.modifiers:
            bpy.ops.object.modifier_remove(modifier=mod.name)   

#====================================================================================
#-----TRIANGULATE
#====================================================================================
if bpy.context.selected_objects:
    for obj in bpy.context.selected_objects:
        bpy.context.scene.objects.active = obj
        bpy.ops.object.mode_set(mode='OBJECT')
        #=======================================
        obj = bpy.context.object
        me = obj.data

        bm = bmesh.new()
        bm.from_mesh(me)
        bmesh.ops.triangulate(bm, faces=bm.faces)

        bm.to_mesh(me)
        bm.free()
        del bm


'''     