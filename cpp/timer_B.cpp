#include <sys/timeb.h>

int getMilliCount(){
	struct timeb tb;
	ftime(&tb);
	int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
	return nCount;
}
int getMilliSpan(int nTimeStart){
	int nSpan = getMilliCount() - nTimeStart;
	if(nSpan < 0)
    nSpan += 0x100000 * 1000;
	return nSpan;
}

int start = 0;
int milliSecondsElapsed = 0;

int frameStart = 0;
int frameEnd   = 0;
int frameTime  = 0;


int timeTotal[10000];
int timeStorageIncrement = 0;
