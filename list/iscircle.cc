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
