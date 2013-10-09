// Author: qushuqian
// Problem: 
// solution:
 
#include <iostream>
#include <assert.h>

using namespace std;

struct Node {
  int data;
  struct Node* next;
  Node():data(0),next(NULL){}
};

void reverse_list(Node*& head_list) {
  if (!head_list) return;
  Node* pre = NULL;
  Node* cur = head_list;
  Node* nex = head_list->next;
  while (nex) {
    cur->next = pre;
    pre = cur;
    cur = nex;
    nex = nex->next;
  }
  cur->next = pre;
  head_list = cur;
}

void list_back_and_forth(Node* head_list) {
  if (!head_list) return;
  Node* p = head_list;
  Node* q = head_list->next;
  while (q && q->next) {
    p = p->next;
    q = q->next->next;
  }
  q = p->next;
  p->next = NULL;
  reverse_list(q);
  p = head_list;
  while (p) {
    Node* s = p->next;
    p->next = q;
    q = q->next;
    p->next->next = s;
    p = s;
  }
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

  list_back_and_forth(head);
//  reverse_list(head);

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
