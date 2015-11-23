extern  int     viewWidth;
extern  int     viewHeight;
        int     passViewWidth;
        int     passViewHeight;




        
extern void FsPollDeviceC(void);
#import "GLEssentialsGLView.h"

#import "GLEssentialsWindowController.h"

#import <Cocoa/Cocoa.h>
//=====================================
CGImageRef spriteImage;
size_t width;
size_t height;
GLubyte * spriteData;
CGContextRef spriteContext;
//=====================================




#import "../../RunGL.cpp"



#define SUPPORT_RETINA_RESOLUTION 1

@interface GLEssentialsGLView (PrivateMethods)
- (void) initGL;

@end

@implementation GLEssentialsGLView



- (CVReturn) getFrameForTime:(const CVTimeStamp*)outputTime
{
	// There is no autorelease pool when this method is called
	// because it will be called from a background thread.
	// It's important to create one or app can leak objects.
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	[self drawView];
	
	[pool release];
	return kCVReturnSuccess;
}

// This is the renderer output callback function
static CVReturn MyDisplayLinkCallback(CVDisplayLinkRef displayLink,
									  const CVTimeStamp* now,
									  const CVTimeStamp* outputTime,
									  CVOptionFlags flagsIn,
									  CVOptionFlags* flagsOut, 
									  void* displayLinkContext)
{
    CVReturn result = [(GLEssentialsGLView*)displayLinkContext getFrameForTime:outputTime];
    return result;
}

- (void) awakeFromNib
{
    NSOpenGLPixelFormatAttribute attrs[] =
	{
		NSOpenGLPFADoubleBuffer,
		NSOpenGLPFADepthSize, 24,

		0
	};
	
	NSOpenGLPixelFormat *pf = [[[NSOpenGLPixelFormat alloc] initWithAttributes:attrs] autorelease];
	

	   
    NSOpenGLContext* context = [[[NSOpenGLContext alloc] initWithFormat:pf shareContext:nil] autorelease];
    
	
    [self setPixelFormat:pf];
    
    [self setOpenGLContext:context];
    
#if SUPPORT_RETINA_RESOLUTION
    // Opt-In to Retina resolution
    [self setWantsBestResolutionOpenGLSurface:YES];
#endif // SUPPORT_RETINA_RESOLUTION
}

- (void) prepareOpenGL
{
	[super prepareOpenGL];
	
	// Make all the OpenGL calls to setup rendering  
	//  and build the necessary rendering objects
    
    viewWidth  = passViewWidth;
    viewHeight = passViewHeight; //_RESIZE_WINDOW_MIGHT_CRASH_BECAUSE_FBO_SIZE_WILL_NOT_MATCH_VIEW?
    
    [self initGL];
	
	// Create a display link capable of being used with all active displays
	CVDisplayLinkCreateWithActiveCGDisplays(&displayLink);
	
	// Set the renderer output callback function
	CVDisplayLinkSetOutputCallback(displayLink, &MyDisplayLinkCallback, self);
	
	// Set the display link for the current renderer
	CGLContextObj cglContext = [[self openGLContext] CGLContextObj];
	CGLPixelFormatObj cglPixelFormat = [[self pixelFormat] CGLPixelFormatObj];
	CVDisplayLinkSetCurrentCGDisplayFromOpenGLContext(displayLink, cglContext, cglPixelFormat);
	
	// Activate the display link
	CVDisplayLinkStart(displayLink);
	
	// Register to be notified when the window closes so we can stop the displaylink
	[[NSNotificationCenter defaultCenter] addObserver:self
											 selector:@selector(windowWillClose:)
												 name:NSWindowWillCloseNotification
											   object:[self window]];
}

- (void) windowWillClose:(NSNotification*)notification
{
	// Stop the display link when the window is closing because default
	// OpenGL render buffers will be destroyed.  If display link continues to
	// fire without renderbuffers, OpenGL draw calls will set errors.
	
	CVDisplayLinkStop(displayLink);
    
    
}

- (void) initGL
{
	// The reshape function may have changed the thread to which our OpenGL
	// context is attached before prepareOpenGL and initGL are called.  So call
	// makeCurrentContext to ensure that our OpenGL context current to this 
	// thread (i.e. makeCurrentContext directs all OpenGL calls on this thread
	// to [self openGLContext])
	[[self openGLContext] makeCurrentContext];
	
	// Synchronize buffer swaps with vertical refresh rate
	GLint swapInt = 1;
	[[self openGLContext] setValues:&swapInt forParameter:NSOpenGLCPSwapInterval];

    
    InitGL();
    
//______________________________________________________________________________________!!!!!!!!!!!!_____________void initializeGL() GOES_HERE

}




- (void)renewGState
{	
	// Called whenever graphics state updated (such as window resize)
	
	// OpenGL rendering is not synchronous with other rendering on the OSX.
	// Therefore, call disableScreenUpdatesUntilFlush so the window server
	// doesn't render non-OpenGL content in the window asynchronously from
	// OpenGL content, which could cause flickering.  (non-OpenGL content
	// includes the title bar and drawing done by the app with other APIs)
	[[self window] disableScreenUpdatesUntilFlush];

	[super renewGState];
}



- (void) drawRect: (NSRect) theRect
{
    // Avoid flickering during resize by drawiing
	[self drawView];
    
    
}

/*
- (void) resetCursorRects
{
    [super resetCursorRects];
    
    NSCursor *myCursor = [[NSCursor alloc] initWithImage:[NSImage imageNamed:@"cursor.png"] hotSpot:NSMakePoint(0, 0)];
    [self addCursorRect:[self bounds] cursor:myCursor];

}
*/

- (void) drawView
{	 
	[[self openGLContext] makeCurrentContext];

	// We draw on a secondary thread through the display link
	// When resizing the view, -reshape is called automatically on the main
	// thread. Add a mutex around to avoid the threads accessing the context
	// simultaneously when resizing
	CGLLockContext([[self openGLContext] CGLContextObj]);


    //======================================================================
    NSWindow *plotWindow = [self window];
    NSPoint mousePosition = [plotWindow mouseLocationOutsideOfEventStream];
    //NSLog(@"mousePos[0]: %i",  (int)floor(mousePosition.x));
    //NSLog(@"mousePos[1]: %i",  (int)floor(mousePosition.y));
    //======================================================================
  
    
          [GLEssentialsWindowController accessKeyboard];


    ProcessKeyboard();
    RenderGL();


	CGLFlushDrawable([[self openGLContext] CGLContextObj]);
	CGLUnlockContext([[self openGLContext] CGLContextObj]);

}

- (void) dealloc
{
	// Stop the display link BEFORE releasing anything in the view
    // otherwise the display link thread may call into the view and crash
    // when it encounters something that has been release
	CVDisplayLinkStop(displayLink);

	CVDisplayLinkRelease(displayLink);

shutDownGL();
	
	[super dealloc];
}
@end
