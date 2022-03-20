#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct lotto_record {
  int lotto_no;
  int lotto_receipt;
  int emp_id;
  char lotto_date[9];
  char lotto_time[9];
} lotto_record_t;

typedef struct emp_record {
  int emp_id;
  char emp_name[32];
  int emp_salary;
} emp_record_t;

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
  int slots = 0, operator[] = {-1}, order[] = {0}, id = 0;
  time_t date = time(NULL);
  srand((unsigned)time(NULL));
  while (operator[0] < 0 || operator[0] > 5) {
    printf("　歓迎光臨長庚楽透彩購買機台\n　請輸入操作人員 ID（0－5）：");
    scanf("%d", &operator[0]);
  };
  if (operator[0] == 0) {
    emp_record_t employees[100];
    if ((fp = fopen("operator_id.bin", "r")) != NULL) fread(employees, sizeof(emp_record_t), sizeof(employees), fp);
    while (id < 1 || id > 99) {
      printf("　請輸入要新増操作人員 ID（1－99）：");
      scanf("%d", &id);
    };
    employees[id].emp_id = id;
    printf("　請輸入要新増操作人員 Name：");
    scanf("%s", employees[id].emp_name);
    printf("　請輸入要新増操作人員 Salary：");
    scanf("%d", &employees[id].emp_salary);
    fp = fopen("operator_id.bin", "wb+");
    fwrite(employees, sizeof(emp_record_t), sizeof(employees), fp);
    fclose(fp);
    printf("　輸入完成\n");
  } else {
    char fn[16];
    lotto_record_t record[1];
    while (slots < 1 || slots > 5) {
      printf("　請問您要買幾組楽透彩（1－5）：");
      scanf("%d", &slots);
    };
    if ((fp = fopen("counter.bin", "r")) != NULL) fread(order, sizeof(int), sizeof(order), fp);
    order[0]++;
    fp = fopen("counter.bin", "wb+");
    fwrite(order, sizeof(int), sizeof(order), fp);
    fclose(fp);
    record[0].lotto_no = order[0];
    record[0].lotto_receipt = slots * 50 * 1.1;
    record[0].emp_id = operator[0];
    strftime(record[0].lotto_date, 100, "%Y%m%d", localtime(&date));
    strftime(record[0].lotto_time, 100, "%H:%M:%S", localtime(&date));
    fp = fopen("records.bin", "ab+");
    fwrite(record, sizeof(lotto_record_t), sizeof(record), fp);
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
    fprintf(fp, "=======* Op.%05d *========\n", operator[0]);
    fprintf(fp, "======== csie@CGU =========\n");
    fclose(fp);
    printf("　以為您購買的 %d 組楽透組合輸出至 %s\n", slots, fn);
  }
  return 0;
}
