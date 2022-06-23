#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char data;
  struct node *next;
} LinkedList;

LinkedList *allocateList(int data) {
  LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
  node->data = data;
  node->next = NULL;
  return node;
}

void showList(LinkedList *list) {
  LinkedList *temp = list;
  while (temp != NULL) {
    printf("[%c]->", temp->data);
    temp = temp->next;
  };
  printf("->NULL\n");
}

LinkedList *appendList(LinkedList *list, int new_data) {
  LinkedList *node = allocateList(new_data);
  node->data = new_data;
  node->next = NULL;
  if (list == NULL) {
    list = node;
  } else {
    LinkedList *lastNode = list;
    while (lastNode->next != NULL) lastNode = lastNode->next;
    lastNode->next = node;
  };
  return list;
}

LinkedList *reverseList(LinkedList *list) {
  LinkedList *prev = NULL;
  LinkedList *current = list;
  LinkedList *next = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

int main() {
  LinkedList *head = NULL;
  head = appendList(head, 'A');
  head = appendList(head, 'B');
  head = appendList(head, 'C');
  head = appendList(head, 'D');
  head = appendList(head, 'E');
  showList(head);
  head = reverseList(head);
  showList(head);
  return 0;
}

