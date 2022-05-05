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

int main() {
  node_t *head = NULL;
  head = append_node(head, 0);
  show_list(head);
  head = append_node(head, 11);
  show_list(head);
  head = append_node(head, 222);
  show_list(head);
  head = append_node(head, 3333);
  show_list(head);
  free_all_node(head);
  return 0;
}
