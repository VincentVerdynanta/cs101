#include <stdio.h>

int main() {
  printf("No.1 -----------------------\n");
  {
    int n[] = {6, 4, 7, 2, 0, 9, 8, 1, 5, 3};
    int *p;
    int indx = 0;
    for (indx = 0; n[indx] != 9; indx++);
    p = n + indx;
    printf("&n[%i]->%p, n[%i]=%i; p->%p, *p=%i\n", indx, &n[indx], indx, n[indx], p, *p);
  }
  printf("No.2 -----------------------\n");
  {
    int n[] = {6, 4, 7, 2, 0, 9, 8, 1, 5, 3};
    int *ap[10];
    for (int i = 0; i < sizeof(n) / sizeof(n[0]); i++) {
      ap[n[i]] = n + i;
    };
    for (int i = 0; i < sizeof(ap) / sizeof(ap[0]); i++) {
      int indx = 0;
      for (indx = 0; n[indx] != *ap[i]; indx++);
      printf("&n[%i]->%p, n[%i]=%i; ap[%i]->%p, *ap[%i]=%i\n", indx, &n[indx], indx, n[indx], i, ap[i], i, *ap[i]);
    };
  }
  return 0;
}
