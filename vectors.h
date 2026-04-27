#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int count;
	int capacity;
} Header;

#define VECTOR_INIT_CAPACITY 256
#define VECTOR_GROWTH 2

#define vector_len(vector) ((Header *)(vector) - 1)->count
#define vector_capacity(vector) ((Header *)(vector) - 1)->capacity

#define vector_push(vector, item) do { \
	if (!vector) (vector) = (void *)((Header *)malloc(sizeof(Header) + VECTOR_INIT_CAPACITY * sizeof(item)) + 1); \
		if ((vector) == NULL) { \
			perror("vector_push"); \
			exit(1); \
		} \
		(vector)[vector_len(vector)++] = item; \
		if (vector_capacity(vector) <= vector_len(vector)) {\
			Header *p = realloc(((Header*)(vector) - 1), sizeof(Header) + (vector_capacity(vector) *= VECTOR_GROWTH) * sizeof(item)); \
			if (p == NULL) { \
				perror("vector_push"); \
				exit(1); \
			} \
			(vector) = (void*)(p + 1); \
		} \
	} while (0)
	
#define vector_free(vector) free((Header *)(vector) - 1)
