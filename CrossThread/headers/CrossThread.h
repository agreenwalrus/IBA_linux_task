#ifndef CROSS_THREAD_H
#define CROSS_THREAD_H

#include <stdio.h>
#include <stdlib.h>
#include "ThreadFun.h"

#define ALL_RIGHT 0
#define SOME_ERRORS 1
#define TRUE 1
#define FALSE 0

typedef struct ThreadHandleStruct {
	void* threadKey;
} ThreadHandle;

int localCreateThread(ThreadHandle* handle, ThreadType(* threadFunction)(void*));
/*
 Wait for all threads
*/
int waitManyThreads(ThreadHandle* handles, int arraySiz);

#endif //CROSS_THREAD_H
