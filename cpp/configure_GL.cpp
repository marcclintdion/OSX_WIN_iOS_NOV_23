#if defined(__APPLE__) && defined(__MACH__)
/* Apple OSX and iOS (Darwin). ------------------------------ */
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR == 1
/* xCode Simulator */

#elif TARGET_OS_IPHONE == 1
/* iOS on iPhone, iPad, etc. */

#elif TARGET_OS_MAC == 1
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <stdio.h>

#define   glGenerateMipmap          glGenerateMipmapEXT         //_CREATE SYNONYMS_SO_THAT_ONLY_ONE_CODE_PATHWAY_IS_NEEDED_FOR_ALL_PLATFORMS.
#define   glGenFramebuffers         glGenFramebuffersEXT
#define   glBindFramebuffer         glBindFramebufferEXT        //_WEAK_DRIVERS_TEND_TO_FAIL_WHEN_PASSED_NEWER_EXTENSIONS_EVEN_IF_THE_FEATURE_IS_WELL_SUPPORTED_BY_THE_HARDWARE
#define   glDeleteFramebuffers      glDeleteFramebuffersEXT
#define   glFramebufferTexture2D    glFramebufferTexture2DEXT   //_A_WELL-WRITTEN_DRIVER_SHOULD_BE_ABLE_TO_MAP_THIS_OVER_TO_THE_OPTIMAL_PATH

#endif
#endif


#ifdef WIN32
#include "../include/gl.h"
#include "../include/glext.h"
#include "../include/glext_Init_A.cpp"
#define   glGenerateMipmap          glGenerateMipmapEXT         //_CREATE SYNONYMS_SO_THAT_ONLY_ONE_CODE_PATHWAY_IS_NEEDED_FOR_ALL_PLATFORMS.
#define   glGenFramebuffers         glGenFramebuffersEXT
#define   glBindFramebuffer         glBindFramebufferEXT        //_WEAK_DRIVERS_TEND_TO_FAIL_WHEN_PASSED_NEWER_EXTENSIONS_EVEN_IF_THE_FEATURE_IS_WELL_SUPPORTED_BY_THE_HARDWARE
#define   glDeleteFramebuffers      glDeleteFramebuffersEXT
#define   glFramebufferTexture2D    glFramebufferTexture2DEXT   //_A_WELL-WRITTEN_DRIVER_SHOULD_BE_ABLE_TO_MAP_THIS_OVER_TO_THE_UPDATED_PATH

#endif
