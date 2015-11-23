
//===================================================================================================================
GLfloat robotStatue_POSITION[]             = { -0.000000f, -0.000000f, -0.000000f,  1.0f };
GLfloat robotStatue_ROTATION[]             = {  0.000000f,  0.000000f,  1.000000f,  0.0f };
GLfloat robotStatue_SCALE[]                = {  1.000000f,  1.000000f,  0.000000f,  1.0f };
//----------------------------------------------------------------- 
GLuint  robotStatue_VBO;
GLuint  robotStatue_INDICES_VBO;
//----------------------------------------------------------------- 

GLuint  robotStatue_HIGH_COLORMAP;

GLuint  robotStatue_NORMALMAP;



//__4th CHANNEL IS ->GLuint cubeMap[0]
//----------------------------------------------------------------- 
GLfloat robotStatue_boundingBox[6]; 

//===================================================================================================================
void load_robotStatue_VBOs(void)  
{ 
    #include    "robotStatue.cpp"
    glGenBuffers(1,              &robotStatue_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, robotStatue_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(robotStatue), robotStatue, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //------------------------------------------------------------------------------
        #include    "robotStatue_INDICES.cpp"
        glGenBuffers(1,              &robotStatue_INDICES_VBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, robotStatue_INDICES_VBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(robotStatue_INDICES), robotStatue_INDICES, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        //========================================================================================================
} 
