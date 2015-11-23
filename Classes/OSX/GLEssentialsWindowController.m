/*
     File: GLEssentialsWindowController.m
 Abstract: 
 Window controller class. Necessary to switch back and forth between a fullscreen and non-fullscreen window.
 The window property on NSWindowController is connected to the window in the NIB (via Interface Builder).
 
  Version: 1.7
 
 Disclaimer: IMPORTANT:  This Apple software is supplied to you by Apple
 Inc. ("Apple") in consideration of your agreement to the following
 terms, and your use, installation, modification or redistribution of
 this Apple software constitutes acceptance of these terms.  If you do
 not agree with these terms, please do not use, install, modify or
 redistribute this Apple software.
 
 In consideration of your agreement to abide by the following terms, and
 subject to these terms, Apple grants you a personal, non-exclusive
 license, under Apple's copyrights in this original Apple software (the
 "Apple Software"), to use, reproduce, modify and redistribute the Apple
 Software, with or without modifications, in source and/or binary forms;
 provided that if you redistribute the Apple Software in its entirety and
 without modifications, you must retain this notice and the following
 text and disclaimers in all such redistributions of the Apple Software.
 Neither the name, trademarks, service marks or logos of Apple Inc. may
 be used to endorse or promote products derived from the Apple Software
 without specific prior written permission from Apple.  Except as
 expressly stated in this notice, no other rights or licenses, express or
 implied, are granted by Apple herein, including but not limited to any
 patent rights that may be infringed by your derivative works or by other
 works in which the Apple Software may be incorporated.
 
 The Apple Software is provided by Apple on an "AS IS" basis.  APPLE
 MAKES NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION
 THE IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS
 FOR A PARTICULAR PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND
 OPERATION ALONE OR IN COMBINATION WITH YOUR PRODUCTS.
 
 IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL
 OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 INTERRUPTION) ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION,
 MODIFICATION AND/OR DISTRIBUTION OF THE APPLE SOFTWARE, HOWEVER CAUSED
 AND WHETHER UNDER THEORY OF CONTRACT, TORT (INCLUDING NEGLIGENCE),
 STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
 
 Copyright (C) 2013 Apple Inc. All Rights Reserved.
 */



/*
NOTE: reference where the input controls come from.

It's the only example I could find that has keyboard input 
which does not use OS repeat delay although it does this too if not called in the proper place.

Perhaps that is all that is needed for other setups to work as well.
*/

extern  int mousePos[];

extern  int     KEY_A;
extern  int     KEY_B;
extern  int     KEY_C;
extern  int     KEY_D;
extern  int     KEY_E;
extern  int     KEY_F;
extern  int     KEY_G;
extern  int     KEY_H;
extern  int     KEY_I;
extern  int     KEY_J;
extern  int     KEY_K;
extern  int     KEY_L;
extern  int     KEY_M;
extern  int     KEY_N;
extern  int     KEY_O;
extern  int     KEY_P;
extern  int     KEY_Q;
extern  int     KEY_R;
extern  int KEY_S;
extern  int KEY_T;
extern  int KEY_U;
extern  int KEY_V;
extern  int KEY_W;
extern  int KEY_X;
extern  int KEY_Y;
extern  int KEY_Z;
//----------------
extern  int KEY_LEFT;
extern  int KEY_RIGHT;
extern  int KEY_UP;
extern  int KEY_DOWN;
//------------------
extern  int KEY_HOME;
extern  int KEY_END;
extern  int KEY_DELETE;
extern  int KEY_PG_UP;
extern  int KEY_PG_DOWN;
//----------------------
extern  int KEY_NUMLOCK;
extern  int KEY_NUMPAD_SLASH_F;
extern  int KEY_NUMPAD_STAR;
extern  int KEY_NUMPAD_MINUS;
extern  int KEY_NUMPAD_PLUS;
extern  int KEY_NUMPADENTER;
extern  int KEY_NUMPAD1;
extern  int KEY_NUMPAD2;
extern  int KEY_NUMPAD3;
extern  int KEY_NUMPAD4;
extern  int KEY_NUMPAD5;
extern  int KEY_NUMPAD6;
extern  int KEY_NUMPAD7;
extern  int KEY_NUMPAD8;
extern  int KEY_NUMPAD9;
extern  int KEY_NUMPAD0;
extern  int KEY_NUMPAD_DOT;
//----------------------
extern  int KEY_TILDE;
extern  int KEY_1;
extern  int KEY_2;
extern  int KEY_3;
extern  int KEY_4;
extern  int KEY_5;
extern  int KEY_6;
extern  int KEY_7;
extern  int KEY_8;
extern  int KEY_9;
extern  int KEY_0;
extern  int KEY_MINUS;
extern  int KEY_EQUALS;
extern  int KEY_BACKSPACE;
//--
extern  int KEY_BRACKET_L;
extern  int KEY_BRACKET_R;
extern  int KEY_BACKSLASH;
extern  int KEY_SEMI;
extern  int KEY_APOSTROPHY;
extern  int KEY_ENTER;
extern  int KEY_COMMA;
extern  int KEY_DOT;
extern  int KEY_FRONTSLASH;
//--
extern  int KEY_SHIFT_L;
extern  int KEY_SHIFT_R;
extern  int KEY_CTRL_L;
extern  int KEY_CTRL_R;
extern  int KEY_ALT_L;
extern  int KEY_ALT_R;
extern  int KEY_OS;
extern  int KEY_FN;
extern  int KEY_TAB;
extern  int KEY_CAPS;
//----------------------
extern  int KEY_ESC;
extern  int KEY_F1;
extern  int KEY_F2;
extern  int KEY_F3;
extern  int KEY_F4;
extern  int KEY_F5;
extern  int KEY_F6;
extern  int KEY_F7;
extern  int KEY_F8;
extern  int KEY_F9;
extern  int KEY_F10;
extern  int KEY_F11;
extern  int KEY_F12;
extern  int KEY_PAUSE;
extern  int KEY_PRINT;
//==========================











//=============================
extern  int     passViewWidth;
extern  int     passViewHeight;


    //==================================
    bool LEFT_BUTTON_DOWN       = false;
    bool RIGHT_BUTTON_DOWN      = false;
    bool MIDDLE_BUTTON_DOWN     = false;
    bool MOUSE_MOVE             = false;
    bool LEFT_BUTTON_UP         = false;
    bool RIGHT_BUTTON_UP        = false;
    bool MIDDLE_BUTTON_UP       = false;




#import <Cocoa/Cocoa.h>

#import "GLEssentialsWindowController.h"
#import "GLEssentialsFullscreenWindow.h"

extern GLfloat eyePosition[4];

@interface GLEssentialsWindowController ()


@end

//============================================================
//============================================================

@implementation GLEssentialsWindowController


bool isFullscreen = 1;


// Were we set in the background?
BOOL wasBackgroundedOutOfFullScreen;

    CGPoint ptMousePrev     = {0.0, 0.0};
	CGPoint ptMouseCurrent  = {0.0, 0.0};


// Fullscreen window 
GLEssentialsFullscreenWindow *fullscreenWindow;


// Non-Fullscreen window (also the initial window)
NSWindow* standardWindow;

- (id)initWithWindow:(NSWindow *)window
{
    self = [super initWithWindow:window];

//NSTrackingArea* trackingArea = [ [ NSTrackingArea alloc] initWithRect:[ window frame] options:(NSTrackingMouseMoved | NSTrackingActiveAlways ) owner:self userInfo:nil);
//[container addTrackingArea:trackingArea];



   // [self setAcceptsMouseMovedEvents:YES];

	if (self)
	{
		// Initialize to nil since it indicates app is not fullscreen
		fullscreenWindow = nil;
    }
    
    
    passViewWidth  = 1920;
    passViewHeight = 1080;
    
    //NSLog(@"passViewWidth: %i",  (int)passViewWidth);
    //NSLog(@"initWithWindowFunc: %i", (int)passViewHeight);
	

    
    return self;
}


NSRect windowSize;


- (void) goFullscreen
{

	if(fullscreenWindow)
	{
		//...don't do anything
		return;
	}

    fullscreenWindow = [[GLEssentialsFullscreenWindow alloc] init];    // Allocate a new fullscreen window

    NSRect viewRect = [fullscreenWindow frame];    // Resize the view to screensize

    
    
    windowSize = viewRect;

    [view setFrameSize: viewRect.size];    // Set the view to the size of the fullscreen window

    [fullscreenWindow setContentView:view];	// Set the view in the fullscreen window

	standardWindow = [self window];

    [standardWindow orderOut:self];	// Hide non-fullscreen window so it doesn't show up when switching out	// of this app (i.e. with CMD-TAB)

    [self setWindow:fullscreenWindow];	// Set controller to the fullscreen window so that all input will go to	// this controller (self)
    
    [fullscreenWindow makeKeyAndOrderFront:self];	// Show the window and make it the key window for input
    
    


}


- (void) goWindow
{
	
    
    
    // If controller doesn't have a full screen window...
	if(fullscreenWindow == nil)
	{
		//...app is already windowed so don't do anything
		return;
	}

	NSRect viewRect = [standardWindow frame];
	
    windowSize = viewRect;

	[view setFrame:viewRect];

	[self setWindow:standardWindow];

	[[self window] setContentView:view];

	[[self window] makeKeyAndOrderFront:self];

	[fullscreenWindow release];

	fullscreenWindow = nil;
    
    

}
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>




void FsPollDevice(void);


int FsInkey(void);
int FsInkeyChar(void);
int FsKeyState(int fsKeyCode);




int FsGetKeyState(int fsKeyCode)
{
	return FsKeyState(fsKeyCode);
}


#include "../fssimplewindow.h"



static int mouseLb=0,mouseMb=0,mouseRb=0;


static int FsNormalKeyCode[256]=
{
	0,                 // 0
	0,                 // 1
	0,                 // 2
	0,                 // 3
	0,                 // 4
	0,                 // 5
	0,                 // 6
	0,                 // 7
	0,                 // 8
	FSKEY_TAB,         // 9
	0,                 // 10
	0,                 // 11
	0,                 // 12
	FSKEY_ENTER,       // 13
	0,                 // 14
	0,                 // 15
	0,                 // 16
	0,                 // 17
	0,                 // 18
	0,                 // 19
	0,                 // 20
	0,                 // 21
	0,                 // 22
	0,                 // 23
	0,                 // 24
	0,                 // 25
	0,                 // 26
	FSKEY_ESC,         // 27
	0,                 // 28
	0,                 // 29
	0,                 // 30
	0,                 // 31
	FSKEY_SPACE,       // 32
	0,                 // 33
	0,                 // 34
	0,                 // 35
	0,                 // 36
	0,                 // 37
	0,                 // 38
	FSKEY_SINGLEQUOTE, // 39
	0,                 // 40
	0,                 // 41
	0,                 // 42
	FSKEY_PLUS,        // 43
	FSKEY_COMMA,       // 44
	FSKEY_MINUS,       // 45
	FSKEY_DOT,         // 46
	FSKEY_SLASH,       // 47
	FSKEY_0,           // 48
	FSKEY_1,           // 49
	FSKEY_2,           // 50
	FSKEY_3,           // 51
	FSKEY_4,           // 52
	FSKEY_5,           // 53
	FSKEY_6,           // 54
	FSKEY_7,           // 55
	FSKEY_8,           // 56
	FSKEY_9,           // 57
	FSKEY_SEMICOLON,   // 58
	0,                 // 59
	0,                 // 60
	0,                 // 61
	0,                 // 62
	0,                 // 63
	0,                 // 64
	FSKEY_A,           // 65
	FSKEY_B,           // 66
	FSKEY_C,           // 67
	FSKEY_D,           // 68
	FSKEY_E,           // 69
	FSKEY_F,           // 70
	FSKEY_G,           // 71
	FSKEY_H,           // 72
	FSKEY_I,           // 73
	FSKEY_J,           // 74
	FSKEY_K,           // 75
	FSKEY_L,           // 76
	FSKEY_M,           // 77
	FSKEY_N,           // 78
	FSKEY_O,           // 79
	FSKEY_P,           // 80
	FSKEY_Q,           // 81
	FSKEY_R,           // 82
	FSKEY_S,           // 83
	FSKEY_T,           // 84
	FSKEY_U,           // 85
	FSKEY_V,           // 86
	FSKEY_W,           // 87
	FSKEY_X,           // 88
	FSKEY_Y,           // 89
	FSKEY_Z,           // 90
	FSKEY_LBRACKET,    // 91
	FSKEY_BACKSLASH,   // 92
	FSKEY_RBRACKET,    // 93
	0,                 // 94
	0,                 // 95
	0,                 // 96
	FSKEY_A,           // 97
	FSKEY_B,           // 98
	FSKEY_C,           // 99
	FSKEY_D,           // 100
	FSKEY_E,           // 101
	FSKEY_F,           // 102
	FSKEY_G,           // 103
	FSKEY_H,           // 104
	FSKEY_I,           // 105
	FSKEY_J,           // 106
	FSKEY_K,           // 107
	FSKEY_L,           // 108
	FSKEY_M,           // 109
	FSKEY_N,           // 110
	FSKEY_O,           // 111
	FSKEY_P,           // 112
	FSKEY_Q,           // 113
	FSKEY_R,           // 114
	FSKEY_S,           // 115
	FSKEY_T,           // 116
	FSKEY_U,           // 117
	FSKEY_V,           // 118
	FSKEY_W,           // 119
	FSKEY_X,           // 120
	FSKEY_Y,           // 121
	FSKEY_Z,           // 122
	FSKEY_LBRACKET,    // 123
	0,                 // 124
	FSKEY_RBRACKET,    // 125
	FSKEY_TILDA,       // 126
	FSKEY_BS,          // 127
	0,                 // 128
	0,                 // 129
	0,                 // 130
	0,                 // 131
	0,                 // 132
	0,                 // 133
	0,                 // 134
	0,                 // 135
	0,                 // 136
	0,                 // 137
	0,                 // 138
	0,                 // 139
	0,                 // 140
	0,                 // 141
	0,                 // 142
	0,                 // 143
	0,                 // 144
	0,                 // 145
	0,                 // 146
	0,                 // 147
	0,                 // 148
	0,                 // 149
	0,                 // 150
	0,                 // 151
	0,                 // 152
	0,                 // 153
	0,                 // 154
	0,                 // 155
	0,                 // 156
	0,                 // 157
	0,                 // 158
	0,                 // 159
	0,                 // 160
	0,                 // 161
	0,                 // 162
	0,                 // 163
	0,                 // 164
	0,                 // 165
	0,                 // 166
	0,                 // 167
	0,                 // 168
	0,                 // 169
	0,                 // 170
	0,                 // 171
	0,                 // 172
	0,                 // 173
	0,                 // 174
	0,                 // 175
	0,                 // 176
	0,                 // 177
	0,                 // 178
	0,                 // 179
	0,                 // 180
	0,                 // 181
	0,                 // 182
	0,                 // 183
	0,                 // 184
	0,                 // 185
	0,                 // 186
	0,                 // 187
	0,                 // 188
	0,                 // 189
	0,                 // 190
	0,                 // 191
	0,                 // 192
	0,                 // 193
	0,                 // 194
	0,                 // 195
	0,                 // 196
	0,                 // 197
	0,                 // 198
	0,                 // 199
	0,                 // 200
	0,                 // 201
	0,                 // 202
	0,                 // 203
	0,                 // 204
	0,                 // 205
	0,                 // 206
	0,                 // 207
	0,                 // 208
	0,                 // 209
	0,                 // 210
	0,                 // 211
	0,                 // 212
	0,                 // 213
	0,                 // 214
	0,                 // 215
	0,                 // 216
	0,                 // 217
	0,                 // 218
	0,                 // 219
	0,                 // 220
	0,                 // 221
	0,                 // 222
	0,                 // 223
	0,                 // 224
	0,                 // 225
	0,                 // 226
	0,                 // 227
	0,                 // 228
	0,                 // 229
	0,                 // 230
	0,                 // 231
	0,                 // 232
	0,                 // 233
	0,                 // 234
	0,                 // 235
	0,                 // 236
	0,                 // 237
	0,                 // 238
	0,                 // 239
	0,                 // 240
	0,                 // 241
	0,                 // 242
	0,                 // 243
	0,                 // 244
	0,                 // 245
	0,                 // 246
	0,                 // 247
	0,                 // 248
	0,                 // 249
	0,                 // 250
	0,                 // 251
	0,                 // 252
	0,                 // 253
	0,                 // 254
	0                  // 255
};

static int FsSpecialKeyCode[256]=
{
	FSKEY_UP,           // 0
	FSKEY_DOWN,         // 1
	FSKEY_LEFT,         // 2
	FSKEY_RIGHT,        // 3
	FSKEY_F1,           // 4
	FSKEY_F2,           // 5
	FSKEY_F3,           // 6
	FSKEY_F4,           // 7
	FSKEY_F5,           // 8
	FSKEY_F6,           // 9
	FSKEY_F7,           // 10
	FSKEY_F8,           // 11
	FSKEY_F9,           // 12
	FSKEY_F10,          // 13
	FSKEY_F11,          // 14
	FSKEY_F12,          // 15
	FSKEY_F1,           // 16 0x10
	FSKEY_F2,           // 17
	FSKEY_F3,           // 18
	FSKEY_F4,           // 19
	FSKEY_F5,           // 20
	FSKEY_F6,           // 21
	FSKEY_F7,           // 22
	FSKEY_F8,           // 23
	FSKEY_F9,           // 24
	FSKEY_F10,          // 25
	FSKEY_F11,          // 26
	FSKEY_F12,          // 27
	FSKEY_F1,           // 28
	FSKEY_F2,           // 29
	FSKEY_F3,           // 30
	FSKEY_F4,           // 31
	FSKEY_F5,           // 32 0x20
	FSKEY_F6,           // 33
	FSKEY_F7,           // 34
	FSKEY_F8,           // 35
	FSKEY_F9,           // 36
	FSKEY_F10,          // 37
	FSKEY_F11,          // 38
	FSKEY_INS,          // 39
	FSKEY_DEL,          // 40
	FSKEY_HOME,         // 41
	0,                  // 42 Begin
	FSKEY_END,          // 43
	FSKEY_PAGEUP,       // 44
	FSKEY_PAGEDOWN,     // 45
	FSKEY_PRINTSCRN,    // 46
	FSKEY_SCROLLLOCK,   // 47
	FSKEY_PAUSEBREAK,   // 48 0x30
	0,                  // 49
	FSKEY_PAUSEBREAK,   // 50
	0,                  // 51 Reset
	0,                  // 52 Stop
	0,                  // 53 Menu
	0,                  // 54 User
	0,                  // 55 System
	FSKEY_PRINTSCRN,    // 56
	0,                  // 57 Clear line
	0,                  // 58 Clear display
	0,                  // 59 Insert line
	0,                  // 60 Delete line
	FSKEY_INS,          // 61
	FSKEY_DEL,          // 62
	FSKEY_PAGEUP,       // 63
	FSKEY_PAGEDOWN,     // 64
	0,                  // 65 Select
	0,                  // 66 Execute
	0,                  // 67 Undo
	0,                  // 68 Redo
	0,                  // 69 Find
	0,                  // 70 Help
	0,                  // 71 Mode Switch
	0,                  // 72
	0,                  // 73
	0,                  // 74
	0,                  // 75
	0,                  // 76
	0,                  // 77
	0,                  // 78
	0,                  // 79
	0,                  // 80
	0,                  // 81
	0,                  // 82
	0,                  // 83
	0,                  // 84
	0,                  // 85
	0,                  // 86
	0,                  // 87
	0,                  // 88
	0,                  // 89
	0,                  // 90
	0,                  // 91
	0,                  // 92
	0,                  // 93
	0,                  // 94
	0,                  // 95
	0,                  // 96
	0,                  // 97
	0,                  // 98
	0,                  // 99
	0,                  // 100
	0,                  // 101
	0,                  // 102
	0,                  // 103
	0,                  // 104
	0,                  // 105
	0,                  // 106
	0,                  // 107
	0,                  // 108
	0,                  // 109
	0,                  // 110
	0,                  // 111
	0,                  // 112
	0,                  // 113
	0,                  // 114
	0,                  // 115
	0,                  // 116
	0,                  // 117
	0,                  // 118
	0,                  // 119
	0,                  // 120
	0,                  // 121
	0,                  // 122
	0,                  // 123
	0,                  // 124
	0,                  // 125
	0,                  // 126
	0,                  // 127
	0,                  // 128
	0,                  // 129
	0,                  // 130
	0,                  // 131
	0,                  // 132
	0,                  // 133
	0,                  // 134
	0,                  // 135
	0,                  // 136
	0,                  // 137
	0,                  // 138
	0,                  // 139
	0,                  // 140
	0,                  // 141
	0,                  // 142
	0,                  // 143
	0,                  // 144
	0,                  // 145
	0,                  // 146
	0,                  // 147
	0,                  // 148
	0,                  // 149
	0,                  // 150
	0,                  // 151
	0,                  // 152
	0,                  // 153
	0,                  // 154
	0,                  // 155
	0,                  // 156
	0,                  // 157
	0,                  // 158
	0,                  // 159
	0,                  // 160
	0,                  // 161
	0,                  // 162
	0,                  // 163
	0,                  // 164
	0,                  // 165
	0,                  // 166
	0,                  // 167
	0,                  // 168
	0,                  // 169
	0,                  // 170
	0,                  // 171
	0,                  // 172
	0,                  // 173
	0,                  // 174
	0,                  // 175
	0,                  // 176
	0,                  // 177
	0,                  // 178
	0,                  // 179
	0,                  // 180
	0,                  // 181
	0,                  // 182
	0,                  // 183
	0,                  // 184
	0,                  // 185
	0,                  // 186
	0,                  // 187
	0,                  // 188
	0,                  // 189
	0,                  // 190
	0,                  // 191
	0,                  // 192
	0,                  // 193
	0,                  // 194
	0,                  // 195
	0,                  // 196
	0,                  // 197
	0,                  // 198
	0,                  // 199
	0,                  // 200
	0,                  // 201
	0,                  // 202
	0,                  // 203
	0,                  // 204
	0,                  // 205
	0,                  // 206
	0,                  // 207
	0,                  // 208
	0,                  // 209
	0,                  // 210
	0,                  // 211
	0,                  // 212
	0,                  // 213
	0,                  // 214
	0,                  // 215
	0,                  // 216
	0,                  // 217
	0,                  // 218
	0,                  // 219
	0,                  // 220
	0,                  // 221
	0,                  // 222
	0,                  // 223
	0,                  // 224
	0,                  // 225
	0,                  // 226
	0,                  // 227
	0,                  // 228
	0,                  // 229
	0,                  // 230
	0,                  // 231
	0,                  // 232
	0,                  // 233
	0,                  // 234
	0,                  // 235
	0,                  // 236
	0,                  // 237
	0,                  // 238
	0,                  // 239
	0,                  // 240
	0,                  // 241
	0,                  // 242
	0,                  // 243
	0,                  // 244
	0,                  // 245
	0,                  // 246
	0,                  // 247
	0,                  // 248
	0,                  // 249
	0,                  // 250
	0,                  // 251
	0,                  // 252
	0,                  // 253
	0,                  // 254
	0                   // 255
};

static int YsMacUnicodeToFsKeyCode(int uni)
{
	if(0<=uni && uni<256)
	{
		return FsNormalKeyCode[uni];
	}
	else if(0xf700<=uni && uni<0xf800)
	{
		return FsSpecialKeyCode[uni-0xf700];
	}
	return 0;
}


struct FsMouseEventLog
{
	int eventType;
	int lb,mb,rb;
	int mx,my;
};


static int fsKeyIsDown[FSKEY_NUM_KEYCODE]={0};

#define NKEYBUF 256
static int nKeyBufUsed=0;
static int keyBuffer[NKEYBUF];

static int nCharBufUsed=0;
static int charBuffer[NKEYBUF];


static int nMosBufUsed=0;
static struct FsMouseEventLog mosBuffer[NKEYBUF];





- (void) flagsChanged: (NSEvent *)theEvent
{
	unsigned int flags;
	flags=[theEvent modifierFlags];

	if(flags&NSAlphaShiftKeyMask) // Caps
	{
		if(fsKeyIsDown[FSKEY_CAPSLOCK]==0 && nKeyBufUsed<NKEYBUF)
		{
			keyBuffer[nKeyBufUsed++]=FSKEY_CAPSLOCK;
		}
		fsKeyIsDown[FSKEY_CAPSLOCK]=1;
	}
	else
	{
		fsKeyIsDown[FSKEY_CAPSLOCK]=0;
	}

	if(flags&NSShiftKeyMask)
	{
		if(fsKeyIsDown[FSKEY_SHIFT]==0 && nKeyBufUsed<NKEYBUF)
		{
			keyBuffer[nKeyBufUsed++]=FSKEY_SHIFT;
		}
		fsKeyIsDown[FSKEY_SHIFT]=1;
	}
	else
	{
		fsKeyIsDown[FSKEY_SHIFT]=0;
	}

	if(flags&NSControlKeyMask)
	{
		if(fsKeyIsDown[FSKEY_CTRL]==0 && nKeyBufUsed<NKEYBUF)
		{
			keyBuffer[nKeyBufUsed++]=FSKEY_CTRL;
		}
		fsKeyIsDown[FSKEY_CTRL]=1;
	}
	else
	{
		fsKeyIsDown[FSKEY_CTRL]=0;
	}

	if((flags&NSAlternateKeyMask) || (flags&NSCommandKeyMask))
	{
		if(fsKeyIsDown[FSKEY_ALT]==0 && nKeyBufUsed<NKEYBUF)
		{
			keyBuffer[nKeyBufUsed++]=FSKEY_ALT;
		}
		fsKeyIsDown[FSKEY_ALT]=1;
	}
	else
	{
		fsKeyIsDown[FSKEY_ALT]=0;
	}

	// Other possible key masks
	// NSNumericPadKeyMask
	// NSHelpKeyMask
	// NSFunctionKeyMask
	// NSDeviceIndependentModifierFlagsMask
}
int FsPassedTime(void)
{
	int ms;

 	NSAutoreleasePool *pool=[[NSAutoreleasePool alloc] init];

	static NSTimeInterval last=0.0;
	NSTimeInterval now;

	now=[[NSDate date] timeIntervalSince1970];

	NSTimeInterval passed;
	passed=now-last;
	ms=(int)(1000.0*passed);

	if(ms<0)
	{
		ms=1;
	}
	last=now;

	[pool release];	

	return ms;
}

void FsPollDevice(void)
{
 	NSAutoreleasePool *pool=[[NSAutoreleasePool alloc] init];

	while(1)
	{
	 	[pool release];
	 	pool=[[NSAutoreleasePool alloc] init];
	
		NSEvent *event;
		event=[NSApp
			   nextEventMatchingMask:NSAnyEventMask
			   untilDate: [NSDate distantPast]
			   inMode: NSDefaultRunLoopMode
			   dequeue:YES];
		if([event type]==NSRightMouseDown)
		  {
		    printf("R mouse down event\n");
		  }
		if(event!=nil)
		{
			[NSApp sendEvent:event];
			[NSApp updateWindows];
		}
		else
		{
			break;
		}
	}

	[pool release];	
}





int FsInkey(void)
{
	if(nKeyBufUsed>0)
	{
		int i,fskey;
		fskey=keyBuffer[0];
		nKeyBufUsed--;
		for(i=0; i<nKeyBufUsed; i++)
		{
			keyBuffer[i]=keyBuffer[i+1];
		}
		return fskey;
	}
	return 0;
}

int FsInkeyChar(void)
{
	if(nCharBufUsed>0)
	{
		int i,c;
		c=charBuffer[0];
		nCharBufUsed--;
		for(i=0; i<nCharBufUsed; i++)
		{
			charBuffer[i]=charBuffer[i+1];
		}
		return c;
	}
	return 0;
}

int FsKeyState(int fsKeyCode)
{
	if(0<=fsKeyCode && fsKeyCode<FSKEY_NUM_KEYCODE)
	{
		return fsKeyIsDown[fsKeyCode];
	}
	return 0;
}






//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================

- (void)toggleFullscreen
{

        if(FsGetKeyState(FSKEY_F12) != 0 && FsGetKeyState(FSKEY_CTRL))
		{
            if(isFullscreen == 1)
            {
                [self goFullscreen];
            }
            if(isFullscreen == 0)
            {
                [self goWindow];
            }
            if(isFullscreen == 1)
            {
                isFullscreen = 0;
            }
            else
                isFullscreen = 1;
        }
}



- (void) keyDown:(NSEvent *)theEvent
{
	unsigned int flags;
	flags=[theEvent modifierFlags];

	NSString *chrs,*chrsNoMod;
	chrs=[theEvent characters];
	if(0==(flags & NSCommandKeyMask) && [chrs length]>0)
	{
		int unicode;
		unicode=[chrs characterAtIndex:0];

		if(32<=unicode && unicode<128 && nCharBufUsed<NKEYBUF)
		{
			charBuffer[nCharBufUsed++]=unicode;
		}
	}

    chrsNoMod=[theEvent charactersIgnoringModifiers];
	if([chrsNoMod length]>0)
	{
		int unicode,fskey;
		unicode=[chrsNoMod characterAtIndex:0];
		fskey=YsMacUnicodeToFsKeyCode(unicode);

		if(fskey!=0)
		{
			fsKeyIsDown[fskey]=1;

			if(nKeyBufUsed<NKEYBUF)
			{
				keyBuffer[nKeyBufUsed++]=fskey;
			}

 
   		//=====================================
        
        
        }
	}
    
       [self toggleFullscreen];
    
   
}

+ (void) accessKeyboard
{

//FsPassedTime();
//FsPollDevice();


    
        if(FsGetKeyState(FSKEY_A)!=0)
		{
			               KEY_A = 1;
		}else              KEY_A = 0;
        //---------------------------    
        if(FsGetKeyState(FSKEY_B)!=0)
		{
			               KEY_B = 1;
		}else              KEY_B = 0;
        //---------------------------
        if(FsGetKeyState(FSKEY_C)!=0)
		{
			               KEY_C = 1;
		}else              KEY_C = 0;
        //---------------------------   
        if(FsGetKeyState(FSKEY_D)!=0)
		{
			               KEY_D = 1;
		}else              KEY_D = 0;
        //---------------------------    
        if(FsGetKeyState(FSKEY_E)!=0)
		{
			               KEY_E = 1;
		}else              KEY_E = 0;
        //---------------------------
        if(FsGetKeyState(FSKEY_F)!=0)
		{
			               KEY_F = 1;
		}else              KEY_F = 0;
        //---------------------------  
        if(FsGetKeyState(FSKEY_G)!=0)
		{
                           KEY_G = 1;
		}else              KEY_G = 0;
        //---------------------------    
        if(FsGetKeyState(FSKEY_H)!=0)
		{
			               KEY_H = 1;
		}else              KEY_H = 0;
        //---------------------------
        if(FsGetKeyState(FSKEY_I)!=0)
		{
			               KEY_I = 1;
		}else              KEY_I = 0;
        //---------------------------    
        if(FsGetKeyState(FSKEY_J)!=0)
		{
			               KEY_J = 1;
		}else              KEY_J = 0;
        //---------------------------
        if(FsGetKeyState(FSKEY_K)!=0)
		{
			               KEY_K = 1;
		}else              KEY_K = 0;
        //---------------------------
        if(FsGetKeyState(FSKEY_L)!=0)
		{
			               KEY_L = 1;
		}else              KEY_L = 0;
        //---------------------------
        if(FsGetKeyState(FSKEY_M)!=0)
		{
			               KEY_M = 1;
		}else              KEY_M = 0;
        //---------------------------    
        if(FsGetKeyState(FSKEY_N)!=0)
		{
			               KEY_N = 1;
		}else              KEY_N = 0;
        //---------------------------
        if(FsGetKeyState(FSKEY_O)!=0)
		{
			               KEY_O = 1;
		}else              KEY_O = 0;
        //---------------------------
        if(FsGetKeyState(FSKEY_P)!=0)
		{
			               KEY_P = 1;
		}else              KEY_P = 0;
        //---------------------------    
        if(FsGetKeyState(FSKEY_Q)!=0)
		{
			               KEY_Q = 1;
		}else              KEY_Q = 0;
        //---------------------------
        if(FsGetKeyState(FSKEY_R)!=0)
		{
			               KEY_R = 1;
		}else              KEY_R = 0;
        //---------------------------
        if(FsGetKeyState(FSKEY_S)!=0)
		{
			               KEY_S = 1;
		}else              KEY_S = 0;
        //---------------------------    
        if(FsGetKeyState(FSKEY_T)!=0)
		{
			               KEY_T = 1;
		}else              KEY_T = 0;
        //---------------------------
        if(FsGetKeyState(FSKEY_U)!=0)
		{
			               KEY_U = 1;
		}else              KEY_U = 0;
        //---------------------------    
        if(FsGetKeyState(FSKEY_V)!=0)
		{
			               KEY_V = 1;
		}else              KEY_V = 0;
        //---------------------------    
        if(FsGetKeyState(FSKEY_W)!=0)
		{
			               KEY_W = 1;
		}else              KEY_W = 0;
        //---------------------------
        if(FsGetKeyState(FSKEY_X)!=0)
		{
			               KEY_X = 1;
		}else              KEY_X = 0;
        //---------------------------       
        if(FsGetKeyState(FSKEY_Y)!=0)
		{
			               KEY_Y = 1;
		}else              KEY_Y = 0;
        //---------------------------     
        if(FsGetKeyState(FSKEY_Z)!=0)
		{
			               KEY_Z = 1;
		}else              KEY_Z = 0;
        //---------------------------       
        if(FsGetKeyState(FSKEY_COMMA)!=0)
		{
			               KEY_COMMA = 1;
		}else              KEY_COMMA = 0;
        //---------------------------       
    
    
    
    
    //============================
    if(FsGetKeyState(FSKEY_F1)!=0)
    {
        exit(0);
    }
    

    
}//_END_accessKeyboard





- (void) keyUp:(NSEvent *)theEvent
{
	NSString *chrs,*chrsNoMod;
	chrs=[theEvent characters];
	if([chrs length]>0)
	{
		int unicode;
		unicode=[chrs characterAtIndex:0];
	}

	chrsNoMod=[theEvent charactersIgnoringModifiers];
	if([chrsNoMod length]>0)
	{
	  int unicode,fskey;
		unicode=[chrsNoMod characterAtIndex:0];
		fskey=YsMacUnicodeToFsKeyCode(unicode);

		if(fskey!=0)
		{
			fsKeyIsDown[fskey]=0;
		}
	}
}


//======================================================================================================


- (void) mouseMoved:(NSEvent *)theEvent
{
	
    ptMouseCurrent.x  = 0.0;
    ptMouseCurrent.y  = 0.0;
    MOUSE_MOVE        = true;
    //====================================================================================




//==============================================
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//==============================================   
NSPoint mouseLoc;
mouseLoc = [NSEvent mouseLocation]; //_____________________________________mouse position for the entire screen->not only the current window's coordinates. It starts from the BOTTOM_LEFT
//NSLog(@"Mouse location: %f %f", mouseLoc.x, mouseLoc.y);
//==============================================
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//==============================================   
//CGEventRef ourEvent = CGEventCreate(NULL);
//CGPoint point = CGEventGetLocation(ourEvent);
//NSLog(@"Location? x= %f, y = %f", (float)point.x, (float)point.y);//_______This is also global screen space but starting from the TOP_LEFT
//==============================================
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//==============================================
mousePos[0] = mouseLoc.x;
mousePos[1] = mouseLoc.y;
//NSLog(@"mousePos[0]: %i",  mousePos[0]);
//NSLog(@"mousePos[1]: %i",  mousePos[1]);
//==============================================
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//==============================================


    //====================================================================================    
    if(0<nMosBufUsed && FSMOUSEEVENT_MOVE==mosBuffer[nMosBufUsed-1].eventType)
	{
	  NSRect rect;
	  rect = windowSize;

		mosBuffer[nMosBufUsed-1].mx=(int)[theEvent locationInWindow].x;
		mosBuffer[nMosBufUsed-1].my=rect.size.height-1-(int)[theEvent locationInWindow].y;

    //==========================================================
    ptMouseCurrent.x =(int)[theEvent locationInWindow].x;
    ptMouseCurrent.y =rect.size.height-1-(int)[theEvent locationInWindow].y;
    

    //==========================================================

    }
	else if(NKEYBUF>nMosBufUsed)
	{
	  NSRect rect;
	  rect = windowSize;

		mosBuffer[nMosBufUsed].eventType=FSMOUSEEVENT_MOVE;
		mosBuffer[nMosBufUsed].mx=(int)[theEvent locationInWindow].x;
		mosBuffer[nMosBufUsed].my=rect.size.height-1-(int)[theEvent locationInWindow].y;
		mosBuffer[nMosBufUsed].lb=mouseLb;
		mosBuffer[nMosBufUsed].mb=mouseMb;
		mosBuffer[nMosBufUsed].rb=mouseRb;
		nMosBufUsed++;
    //==========================================================
    ptMouseCurrent.x =(int)[theEvent locationInWindow].x;
    ptMouseCurrent.y =rect.size.height-1-(int)[theEvent locationInWindow].y;
    //==========================================================
    }

    
    
    

    
        //=====================================================================================
            ptMousePrev.x = ptMouseCurrent.x;
            ptMousePrev.y = ptMouseCurrent.y;          
        //=====================================================================================

}


//================================================================================================



- (void) mouseDragged:(NSEvent *)theEvent
{
  [self mouseMoved:theEvent];
}

- (void) rightMouseDragged:(NSEvent *)theEvent
{
  [self mouseMoved:theEvent];
}

- (void) otherMouseDragged:(NSEvent *)theEvent
{
  [self mouseMoved:theEvent];
}



- (void) mouseDown:(NSEvent *)theEvent  //LEFT
{
    //==========================================================
    ptMousePrev.x     = 0.0;
    ptMousePrev.y     = 0.0;
	
    //ptMouseCurrent.x  = 0.0;
    //ptMouseCurrent.y  = 0.0;
    //==========================================================
    mouseLb=1;

	if(NKEYBUF>nMosBufUsed)
	{
	  NSRect rect;
	  rect = windowSize;

		mosBuffer[nMosBufUsed].eventType=FSMOUSEEVENT_LBUTTONDOWN;
		mosBuffer[nMosBufUsed].mx=(int)[theEvent locationInWindow].x;
		mosBuffer[nMosBufUsed].my=rect.size.height-1-(int)[theEvent locationInWindow].y;
		mosBuffer[nMosBufUsed].lb=mouseLb;
		mosBuffer[nMosBufUsed].mb=mouseMb;
		mosBuffer[nMosBufUsed].rb=mouseRb;
		nMosBufUsed++;
	
     //==========================================================
     ptMousePrev.x   = (int)[theEvent locationInWindow].x;
     ptMousePrev.y   = rect.size.height-1-(int)[theEvent locationInWindow].y;
     //==========================================================
     
    }

    
    LEFT_BUTTON_DOWN       = true;
  
    
}

- (void) rightMouseDown:(NSEvent *)theEvent // RIGHT_DOWN         //!!!!!!!!!!!____NOT SURE THIS IS BEING CALLED____!!!!!!!!!!!
{
	
    //==========================================================
    ptMousePrev.x     = 0.0;
    ptMousePrev.y     = 0.0;
	
    //ptMouseCurrent.x  = 0.0;
    //ptMouseCurrent.y  = 0.0;
    //==========================================================
    
    mouseRb=1;

	if(NKEYBUF>nMosBufUsed)
	{
	  NSRect rect;
	  rect = windowSize;

		mosBuffer[nMosBufUsed].eventType=FSMOUSEEVENT_RBUTTONDOWN;
		mosBuffer[nMosBufUsed].mx=(int)[theEvent locationInWindow].x;
		mosBuffer[nMosBufUsed].my=rect.size.height-1-(int)[theEvent locationInWindow].y;
		mosBuffer[nMosBufUsed].lb=mouseLb;
		mosBuffer[nMosBufUsed].mb=mouseMb;
		mosBuffer[nMosBufUsed].rb=mouseRb;
		nMosBufUsed++;
	
     //==========================================================
     ptMousePrev.x   = (int)[theEvent locationInWindow].x;
     ptMousePrev.y   = rect.size.height-1-(int)[theEvent locationInWindow].y;
     //==========================================================
    }
    

    
    RIGHT_BUTTON_DOWN      = true;

}
- (void) otherMouseDown:(NSEvent *)theEvent // MIDDLE_DOWN
{
	
    //==========================================================
    ptMousePrev.x     = 0.0;
    ptMousePrev.y     = 0.0;
	
    //ptMouseCurrent.x  = 0.0;
    //ptMouseCurrent.y  = 0.0;
    //==========================================================
    
    mouseMb=1;

	if(NKEYBUF>nMosBufUsed)
	{
	  NSRect rect;
	  rect = windowSize;

		mosBuffer[nMosBufUsed].eventType=FSMOUSEEVENT_MBUTTONDOWN;
		mosBuffer[nMosBufUsed].mx=(int)[theEvent locationInWindow].x;
		mosBuffer[nMosBufUsed].my=rect.size.height-1-(int)[theEvent locationInWindow].y;
		mosBuffer[nMosBufUsed].lb=mouseLb;
		mosBuffer[nMosBufUsed].mb=mouseMb;
		mosBuffer[nMosBufUsed].rb=mouseRb;
		nMosBufUsed++;
	
     //==========================================================
     ptMousePrev.x   = (int)[theEvent locationInWindow].x;
     ptMousePrev.y   = rect.size.height-1-(int)[theEvent locationInWindow].y;
     //==========================================================
    
    }

    MIDDLE_BUTTON_DOWN     = true;

 
}





- (void) mouseUp:(NSEvent *)theEvent // LEFT_UP
{
	mouseLb=0;

	if(NKEYBUF>nMosBufUsed)
	{
	  NSRect rect;
	  rect = windowSize;

		mosBuffer[nMosBufUsed].eventType=FSMOUSEEVENT_LBUTTONUP;
		mosBuffer[nMosBufUsed].mx=(int)[theEvent locationInWindow].x;
		mosBuffer[nMosBufUsed].my=rect.size.height-1-(int)[theEvent locationInWindow].y;
		mosBuffer[nMosBufUsed].lb=mouseLb;
		mosBuffer[nMosBufUsed].mb=mouseMb;
		mosBuffer[nMosBufUsed].rb=mouseRb;
		nMosBufUsed++;
	}
    LEFT_BUTTON_UP         = true;

}

- (void) rightMouseUp:(NSEvent *)theEvent // RIGHT_UP
{
	mouseRb=0;

	if(NKEYBUF>nMosBufUsed)
	{
	  NSRect rect;
	  rect = windowSize;

		mosBuffer[nMosBufUsed].eventType=FSMOUSEEVENT_RBUTTONUP;
		mosBuffer[nMosBufUsed].mx=(int)[theEvent locationInWindow].x;
		mosBuffer[nMosBufUsed].my=rect.size.height-1-(int)[theEvent locationInWindow].y;
		mosBuffer[nMosBufUsed].lb=mouseLb;
		mosBuffer[nMosBufUsed].mb=mouseMb;
		mosBuffer[nMosBufUsed].rb=mouseRb;
		nMosBufUsed++;
	}
    
    RIGHT_BUTTON_UP        = true;

}

- (void) otherMouseUp:(NSEvent *)theEvent // MIDDLE_UP
{
	mouseMb=0;

	if(NKEYBUF>nMosBufUsed)
	{
	  NSRect rect;
	  rect = windowSize;

		mosBuffer[nMosBufUsed].eventType=FSMOUSEEVENT_MBUTTONUP;
		mosBuffer[nMosBufUsed].mx=(int)[theEvent locationInWindow].x;
		mosBuffer[nMosBufUsed].my=rect.size.height-1-(int)[theEvent locationInWindow].y;
		mosBuffer[nMosBufUsed].lb=mouseLb;
		mosBuffer[nMosBufUsed].mb=mouseMb;
		mosBuffer[nMosBufUsed].rb=mouseRb;
		nMosBufUsed++;
	}


    MIDDLE_BUTTON_UP       = true;



}





//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================
//==============================================================================================================













@end
