#include <stdio.h>

typedef struct my_mm {
  int id;
  int p[10];
} my_mm_t;
int g_mem[10];
my_mm_t mms;

int *my_calloc(int n, int size) {
  int indx = -1;
  for (int i = 0; indx < 0 && i < 10; i++) {
    int j = 0;
    for (int k = 0; !j && k < size; k++) {
      if (g_mem[i + k] != 0 || i + k >= 10) j = 1;
    };
    if (!j) indx = i;
  };
  if (indx >= 0) {
    for (int i = 0; i < size; i++) g_mem[indx + i] = mms.id + 1;
    mms.p[mms.id] = n;
    mms.id++;
  };
  for (int i = 0; i < 10; i++) g_mem[i] ? printf("%i", mms.p[g_mem[i] - 1]) : printf("0");
  printf("\n");
  return indx >= 0 ? &mms.p[mms.id - 1] : NULL;
}
void my_free(int *p) {
  int indx = -1;
  for (int i = 0; indx < 0 && i < 10; i++) {
    if (&mms.p[i] == p) indx = i;
  };
  for (int i = 0; indx >= 0 && i < 10; i++) {
    if (g_mem[i] == indx + 1) g_mem[i] = 0;
  };
  for (int i = 0; i < 10; i++) g_mem[i] ? printf("%i", mms.p[g_mem[i] - 1]) : printf("0");
  printf("\n");
}

int main() {
  int *np1 = my_calloc(1, 1);
  int *np2 = my_calloc(1, 2);
  int *np3 = my_calloc(1, 3);
  int *np4 = my_calloc(1, 4);
  my_free(np1);
  my_free(np4);
  int *np5 = my_calloc(1, 3);
  return 0;
}
