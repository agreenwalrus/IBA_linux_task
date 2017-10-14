#include <stdlib.h>
#include "CrossThread.h"
#define MAX_AMOUNT 60
#define PARAM 1


void freeMemory(ThreadHandle* ar, int siz);

int main(int argc, char* argv[]) {
	int n;
	ThreadHandle handles[MAX_AMOUNT];
	if (argc != 2 || !(n = atoi(argv[PARAM])) || n < 1 || n > MAX_AMOUNT) {
		printf("Program needs param (integer): amount of threads 0 < amount < 60.\n");
		return 1;
	}
	int i = 0;
	for (i = 0; i < n; i++) {
		if (localCreateThread(&handles[i], threadRoutin)) {
			printf("Error at Main\n");
			waitManyThreads(handles, i);
			freeMemory(handles, i);
                        return 1;
		}
	}
	waitManyThreads(handles, n);
	freeMemory(handles, n);
	
	printf("Press any key...");
	getchar();

	return 0;
}


void freeMemory(ThreadHandle* ar, int siz) {
	for (int i = 0; i < siz; i++)
		free((void*)ar[i].threadKey);
}
