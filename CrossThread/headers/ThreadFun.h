#ifndef THREAD_FUN_H
#define THREAD_FUN_H
#include <stdio.h>
#include <stdlib.h>

typedef struct ThreadTypeStruct {
	void* field;
} ThreadType;

ThreadType threadRoutin(void *);

#endif //THREAD_FUN_H
