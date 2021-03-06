// Author: qushuqian
// Problem: judge the list if there has circle
// solution:
 
#include <iostream>
#include <assert.h>

using namespace std;

struct Node {
  int data;
  struct Node* next;
  Node():data(0),next(NULL){}
};

bool exist_circle(Node* head_list) {
  if (!head_list) return false;
  Node* p = head_list;
  Node* q = head_list->next;
  while (q&&q->next) {
    if (p == q)
      return true;
    p = p->next;
    q = q->next->next;
  }
  return false;
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

  cout << exist_circle(head) << endl;

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
