#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;

node_t *allocate_node(int data) {
  node_t *node = (node_t *)malloc(sizeof(node_t));
  node->data = data;
  node->next = NULL;
  return node;
}

void show_list(node_t *list) {
  node_t *temp = list;
  while (temp != NULL) {
    printf("[%d]->", temp->data);
    temp = temp->next;
  };
  printf("null\n");
}

node_t *append_node(node_t *list, int new_data) {
  node_t *node = allocate_node(new_data);
  node->data = new_data;
  node->next = NULL;
  if (list == NULL) {
    list = node;
  } else {
    node_t *lastNode = list;
    while (lastNode->next != NULL) lastNode = lastNode->next;
    lastNode->next = node;
  };
  return list;
}

void free_all_node(node_t *list) {
  node_t *temp;
  while (list != NULL) {
    temp = list;
    list = list->next;
    printf("free([%d])->", temp->data);
    free(temp);
  };
  printf("null\n");
}

node_t *add_node(node_t *list, int new_data) {
  node_t *node = allocate_node(new_data);
  node->data = new_data;
  node->next = list;
  list = node;
  return list;
}

node_t *del_node(node_t *list, int n) {
  node_t *temp = list;
  if (n == 0) {
    list = temp->next;
    free(temp);
  } else {
    for (int i = 0; temp != NULL && i < n - 1; i++) temp = temp->next;
    if (temp != NULL && temp->next != NULL) {
      node_t *next = temp->next->next;
      free(temp->next);
      temp->next = next;
    };
  };
  return list;
}

int main() {
  node_t *head = NULL;
  head = append_node(head, 0);
  show_list(head);
  head = append_node(head, 1);
  show_list(head);
  head = add_node(head, -1);
  show_list(head);
  del_node(head, 1);
  show_list(head);
  free_all_node(head);
  return 0;
}
