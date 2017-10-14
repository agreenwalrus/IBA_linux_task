#include<pthread.h>
#include<unistd.h>
#include "CrossThread.h"


/*
	Linux implementation
*/

int localCreateThread(ThreadHandle* handle, ThreadType(* threadFunction)(void*)) {

	handle->threadKey = (pthread_t*)malloc(sizeof(pthread_t));
	if (!handle->threadKey) {
		printf("Error at memory allocation:\nint localCreateThread()");
		return SOME_ERRORS;
	}	
	if (pthread_create((pthread_t*)handle->threadKey, 0, (void*)threadFunction, 0))
		return SOME_ERRORS;
	return ALL_RIGHT;
}

int waitManyThreads(ThreadHandle* handles, int arraySiz) {
	for (int i = 0; i < arraySiz; i++) {
		pthread_t th = *(pthread_t*)(handles[i].threadKey);
		pthread_join(th, NULL);
	}
	return ALL_RIGHT;
}
