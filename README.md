# cvectors
A simple vector system for C.

# Docs

How do I start the vector? No problem!

``` c
#include "vectors.h"

int main(){
  int *vec = NULL; // The NULL is important, if this is not here, the allocation will not happen and there could be a seg-fault!
  vector_push(vec, 69); // vector_push will allocate the vector automatically if NULL!
  vector_push(vec, 420);
  
  for (int i = 0 ; i < vector_len(vec) ; i++)
    printf("%d%c", vec[i], i == vector_len(vec) - 1 ? '\n' : ' ');

  vector_free(vec);
  return 0;
}
```

This is a simple program using my vector system, showing all the (useful) methods.
In addition, there is **vector_capacity(vec)** which returns the capacity of the vector.
