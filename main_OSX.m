//Copyright (C) 2013 Apple Inc. All Rights Reserved.
 


#if defined (__APPLE__) && TARGET_OS_IPHONE == 1
#import <UIKit/UIKit.h>
#else
#import <Cocoa/Cocoa.h>
#endif

int main(int argc, char *argv[])
{
	int retVal = 1;
#if ESSENTIAL_GL_PRACTICES_IOS
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    retVal = UIApplicationMain(argc, argv, nil, nil);
    [pool release];
#else
	retVal = NSApplicationMain(argc,  (const char **) argv);
#endif
	
    return retVal;
}
