#include <stdio.h>

void rec_dec(char *s) {
  if (*s) {
    printf("%c,", *s);
    rec_dec(s + 1);
  } else printf("\n");
}

void hanoi_tower(int n, char source, char spare, char target) {
  if (n > 0) {
    hanoi_tower(n - 1, source, target, spare);
    FILE* fp = fopen("hanoi.txt", "a+");
    fprintf(fp, "Move disk %d from %c to %c\n", n, source, target);
    fclose(fp);
    hanoi_tower(n - 1, spare, source, target);
  }
}

int multiplication(int i, int j) {
  if (i == 10) return 0;
  if (j == 9) {
    printf("%d*%d=%d \n", i, j, i * j);
    multiplication(i + 1, 1);
  } else {
    printf("%d*%d=%d ", i, j, i * j);
    multiplication(i, j + 1);
  };
  return 0;
}

int main() {
  char s[] = "1234567890";
  rec_dec(s);
  printf("func#1-----------------------\n");
  hanoi_tower(16, 'A', 'B', 'C');
  printf("func#2-----------------------\n");
  multiplication(1, 1);
  printf("func#3-----------------------\n");
  return 0;
}
