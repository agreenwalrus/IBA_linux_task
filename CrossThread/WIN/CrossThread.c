#include <Windows.h>
#include "CrossThread.h"


/*
	Windows implementation
*/

int localCreateThread(ThreadHandle* handle, ThreadType(* threadFunction)(void*)/*, void *param*/) {

	handle->threadKey = (DWORD WINAPI*)malloc(sizeof(DWORD WINAPI));
	DWORD lpThreadId;
	if (!handle->threadKey) {
		printf("Error at memory allocation:\nint localCreateThread()");
		return SOME_ERRORS;
	}
	*((HANDLE*)handle->threadKey) = CreateThread(
		NULL,                   // default security attributes
		0,                      // use default stack size  
		(LPTHREAD_START_ROUTINE)threadFunction,       // thread function name
		NULL/*param*/,          // argument to thread function 
		0,                      // use default creation flags 
		&lpThreadId);   // returns the thread identifier 
	if (*((HANDLE*)handle->threadKey) == INVALID_HANDLE_VALUE)
		return SOME_ERRORS;
	return ALL_RIGHT;
}

int waitManyThreads(ThreadHandle* handles, int arraySiz) {
	HANDLE* ar = (HANDLE*)malloc(arraySiz * sizeof(HANDLE));
	for (int i = 0; i < arraySiz; i++)
		ar[i] = *(HANDLE*)(handles[i].threadKey);
	if (!ar) {
		printf("Error at memory allocation:\nint waitManyThreads(ThreadHandle* handles, int arraySiz)");
		return SOME_ERRORS;
	}
	WaitForMultipleObjects(arraySiz, ar, TRUE, INFINITE);
	free((void*)ar);
	return ALL_RIGHT;
}
