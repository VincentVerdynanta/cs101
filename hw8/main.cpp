#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
};

class LinkedList {
  private:
    Node* head;

  public:
    LinkedList() { head = NULL; }
    ~LinkedList() {
      Node *temp;
      while (head != NULL) {
        temp = head;
        head = head->next;
        cout << "free([" << temp->data << "])->";
        free(temp);
      };
      cout << "null" << endl;
    }
    Node *allocate_node(int data) {
      Node *node = (Node *)malloc(sizeof(Node));
      node->data = data;
      node->next = NULL;
      return node;
    }
    void show_list() {
      Node *temp = head;
      while (temp != NULL) {
        cout << "[" << temp->data << "]->";
        temp = temp->next;
      };
      cout << "null" << endl;
    }
    void append_node(int new_data) {
      Node *node = allocate_node(new_data);
      node->data = new_data;
      node->next = NULL;
      if (head == NULL) {
        head = node;
      } else {
        Node *lastNode = head;
        while (lastNode->next != NULL) lastNode = lastNode->next;
        lastNode->next = node;
      };
      show_list();
    }
    void del_node(int n) {
      Node *temp = head;
      if (n == 0) {
        head = temp->next;
        free(temp);
      } else {
        for (int i = 0; temp != NULL && i < n - 1; i++) temp = temp->next;
        if (temp != NULL && temp->next != NULL) {
          Node *next = temp->next->next;
          free(temp->next);
          temp->next = next;
        };
      };
      show_list();
    }
};

int main() {
  LinkedList mylink;
  mylink.append_node(0);
  mylink.append_node(1);
  mylink.append_node(2);
  mylink.append_node(3);
  mylink.del_node(1);
  return 0;
}
