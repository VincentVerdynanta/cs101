#include <stdio.h>
#include <stdlib.h>

void swap(int *source, int *dest) {
  int tmp;
  tmp = *source;
  *source = *dest;
  *dest = tmp;
}

void swapArray(int *source, int *dest, int size) {
  for (int i = 0; i < size; i++) swap(&source[i], &dest[i]);
}

void printArray(int *source, int size) {
  for (int i = 0; i < size; i++) printf("%i%s", source[i], i != size - 1 ? ", " : "]\n");
}

char *copy_string(char *s) {
  int size = 0;
  while (s[size++] != '\0');
  char *ptr = (char *)calloc(size, sizeof(char));
  for (int i = 0; i < size; i++) ptr[i] = s[i];
  return ptr;
}

int main() {
  printf("No.1 ---------------\n");
  int n, m;
  n = 1;
  m = 2;
  swap(&n, &m);
  printf("after swap, n=%i, m=%i\n", n, m);
  printf("No.2 ---------------\n");
  int size = 10;
  int source[10] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int dest[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  swapArray(source, dest, size);
  printf("after swap array, source array = [");
  printArray(source, size);
  printf("after swap array, dest array = [");
  printArray(dest, size);
  printf("No.3 ---------------\n");
  char str[] = "IU!IU!IU!IU!";
  char *cp_str = copy_string(str);
  printf("copy string = %s\n", cp_str);
  free(cp_str);
  return 0;
}