#include <stdio.h>
#include <stdlib.h>

int *get_int_array(int n) { return (int *)calloc(n, sizeof(int)); }

void set_value(int *p, int v) { *p = v; }

void print_array(int *source, int size) {
  for (int i = 0; i < size; i++)
    printf("%s%i%s", i ? "" : "[", source[i], i != size - 1 ? ", " : "]\n");
}

typedef struct array_list {
  int n;
  int *(*get_int_array_list)(int);
  void (*set_value_list)(int *, int);
  void (*print_array_list)(int *, int);
} array_list_t;

char *func(char a[], char b[]) {
  int len_a = 0;
  int len_b = 0;
  while (a[len_a++])
    ;
  while (b[len_b++])
    ;
  char *ptr = (char *)calloc(len_a + len_b - 1, sizeof(char));
  for (int i = 0; i < len_a - 1; i++) {
    ptr[i] = a[i];
  }
  for (int i = 0; i < len_b - 1; i++) {
    ptr[len_a - 1 + i] = b[i];
  }
  ptr[len_a + len_b - 1] = '\0';
  return ptr;
}

char *add_str_func(char a[], char b[], char *(*func_ptr)(char *, char *)) {
  return func_ptr(a, b);
}

int main() {
  printf("No.1 ---------------\n");
  int n = 10;
  int *ip = get_int_array(n);

  for (int i = 0; i < n; i++) {
    set_value(ip + i, i + 1);
  }

  print_array(ip, n);

  printf("No.2 ---------------\n");
  array_list_t list;
  n = 20;
  list.get_int_array_list = get_int_array;
  list.set_value_list = set_value;
  list.print_array_list = print_array;
  ip = list.get_int_array_list(n);

  for (int i = 0; i < n; i++) {
    list.set_value_list(ip + i, i + 1);
  }

  list.print_array_list(ip, n);

  printf("No.3 ---------------\n");
  char a[] = "IU!IU!";
  char b[] = "@CGU";
  printf("add_str_func = %s\n", add_str_func(a, b, func));
  return 0;
}