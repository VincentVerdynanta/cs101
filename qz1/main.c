#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int slot(int arr[7]) {
  for (int i = 0; arr[5] == 0;) {
    int num = (rand() % 69) + 1, j = 0;
    for (int k = 0; k < i && j == 0; k++) (arr[k] == num) ? j = 1 : 0;
    if (j == 0) arr[i++] = num;
  };
  for (int i = 0; i < 5; i++) {
    int key = arr[i + 1], j = i;
    while (key < arr[j] && j >= 0) {
      arr[j + 1] = arr[j];
      j--;
    };
    arr[j + 1] = key;
  };
  arr[6] = (rand() % 10) + 1;
  return arr[7];
}

int main() {
  FILE* fp;
  int slots = 0, order[] = {0};
  char fn[16];
  time_t date = time(NULL);
  srand((unsigned)time(NULL));
  printf("　歓迎光臨長庚楽透彩購買機台\n　請問您要買幾組楽透彩（1－5）：");
  scanf("%d", &slots);
  if (slots < 1 || slots > 5) {
    main();
    return 0;
  };
  if ((fp = fopen("counter.bin", "r")) != NULL) fread(order, sizeof(int), sizeof(order), fp);
  order[0]++;
  fp = fopen("counter.bin", "wb+");
  fwrite(order, sizeof(int), sizeof(order), fp);
  fclose(fp);
  sprintf(fn, "lotto[%04d].txt", order[0]);
  fp = fopen(fn, "w+");
  fprintf(fp, "======== lotto649 =========\n");
  fprintf(fp, "=======+ No.%05d +========\n", order[0]);
  fprintf(fp, "= %s =\n", strtok(ctime(&date), "\n"));
  for (int i = 0; i < 5; i++) {
    fprintf(fp, "[%d]：", i + 1);
    if (i < slots) {
      int arr[7] = {0};
      slot(arr);
      for (int j = 0; j < 7; j++) fprintf(fp, "%02d %s", arr[j], (j == 6) ? "\n" : "");
    } else {
      for (int j = 0; j < 7; j++) fprintf(fp, "-- %s", (j == 6) ? "\n" : "");
    };
  };
  fprintf(fp, "======== csie@CGU =========\n");
  fclose(fp);
  printf("　以為您購買的 %d 組楽透組合輸出至 %s\n", slots, fn);
  return 0;
}
