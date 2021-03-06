#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>

#include "memory.h"

void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
  if (newSize == 0) {
    free(pointer);
    return NULL;
  }

  printf("%p %zu %zu\n", pointer, oldSize, newSize);

  void* result = realloc(pointer, newSize);
  if (result == NULL) {
      perror("realloc");
      exit(1);
  }
  return result;
}