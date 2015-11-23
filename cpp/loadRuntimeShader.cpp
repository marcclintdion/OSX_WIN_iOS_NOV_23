unsigned char *readShaderFile( const char *fileName )
{
    
    char * dir = getcwd(NULL, 0); // Platform-dependent, see reference link below
    printf("Current dir: %s", dir);
    
    
    FILE *file = fopen( fileName, "r" );
    
    
    struct stat fileStats;
    
    stat( fileName, &fileStats );
    
    
    //unsigned char *buffer = new unsigned char[fileStats.st_size];
    
    unsigned char *buffer = (unsigned char*)malloc(sizeof(unsigned char) * fileStats.st_size);
    
    
    int bytes = fread( buffer, 1, fileStats.st_size, file );
    
    buffer[bytes] = 0;
    
    fclose( file );
    
    //free(buffer);
    
    return buffer;
    
}
