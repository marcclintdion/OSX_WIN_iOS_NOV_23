#ifdef WIN32
#define   WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <process.h>

#include <iostream.h>
#include <fstream.h>
#include <vector>
//-----------------------------------------------------------------------------
void InitGL(void);
void RenderGL(void);//int width, int height
//void KillALData(void);
void ProcessKeyboard(void);
void shutDownGL(void);
bool CreateDummyGLWindow();
//-------------------------------
bool keys[256], keypressed[256];
bool mkeyIsReset = true;
//#include "cpp/winInit.cpp"        //__THESE_2_ARE_FILE_FINDER_NOTES_SO_THE_OLD_MODULES
//#include "cpp/configureWindow.cpp"//__CAN_BE_FOUND_AND_MERGED_WITH_LESS_FORMAT_CHANGE_CONFUSION
bool                g_isFullScreen;
#include "WGL_ARB_multisample.h"
//-------------------------------
#include "../headerFiles/VSync.h"
#include <windows.h>
#endif

