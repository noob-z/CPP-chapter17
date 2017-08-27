#ifndef DEFINE_H_
#define DEFINE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TTSIZE 45
#define FMAX 5

struct film {
	char title[TTSIZE];
	int rating;
};

struct film2 {
	char title[TTSIZE];
	int rating;
	struct film2 * next;
};

char * s_gets(char * st, int n);
void films1(void);

void films3(void);

#endif
