// Author: qushuqian
// Problem: 单链表逆置
// solution:
 
#include <iostream>
#include <assert.h>

using namespace std;

struct Node {
  int data;
  struct Node* next;
  Node():data(0),next(NULL){}
};

void reverse_list(Node*& origin_list) {
  if (!origin_list || !origin_list->next) return;
  Node* p = origin_list;
  Node* cur = origin_list->next;
  while (cur) {
    Node* temp = cur->next;
    cur->next = p;
    p = cur;
    cur = temp;
  }
  origin_list->next = NULL;
  origin_list = p;
  return;
}

int main() {
  Node* head = new Node();
  Node* p = head;
  for (int i = 1; i < 10; i++) {
    Node* temp = new Node();
    temp->data = i;
    p->next = temp;
    p = p->next;
  }

  p = head;
  while (p) {
    cout << p->data << '\t';
    p = p->next;
  }
  cout << endl;

  reverse_list(head);

  p = head;
  while (p) {
    cout << p->data << '\t';
    p = p->next;
  }
  cout << endl;

  p = head;
  while (p) {
    Node* temp = p->next;
    delete p;
    p = temp;
  }
  return 0;
}
