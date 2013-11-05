// Author: qushuqian
// Problem: judge the list if there has circle
// solution:
 
#include <iostream>
#include <assert.h>

using namespace std;

struct ListNode {
  int val;
  struct ListNode* next;
  ListNode():val(0),next(NULL){}
};

class Solution {
 public:
   ListNode *rotateRight(ListNode *head, int k) {
     // IMPORTANT: Please reset any member data you declared, as
     // the same Solution instance will be reused for each test case.
     if (!head || k<= 0) return head;
     ListNode* p = head;
     int len = 0;
     while (p) {
       p = p->next;
       len++;
     }
     int rotate = k%len;
     cout << rotate << endl;
     p = NULL;
     ListNode* cur = head;
     ListNode* ret = head;
//     while (cur) {
//       if (rotate == 0) {
//         if (p) p->next = NULL;
//         ret = cur;
//       }
//       p = cur;
//       cur = cur->next;
//       rotate--;
//     }
     if (p) p->next = head;
     return ret;
   }
};

int main() {
  ListNode* head = new ListNode();
  ListNode* p = head;
  for (int i = 1; i < 1; i++) {
    ListNode* temp = new ListNode();
    temp->val = i;
    p->next = temp;
    p = p->next;
  }

  p = head;
  while (p) {
    cout << p->val << '\t';
    p = p->next;
  }
  cout << endl;
  Solution test;
  head = test.rotateRight(head, 1);


  p = head;
  while (p) {
    cout << p->val << '\t';
    p = p->next;
  }
  cout << endl;

  p = head;
  while (p) {
    ListNode* temp = p->next;
    delete p;
    p = temp;
  }
  return 0;
}
