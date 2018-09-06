/* *
  Definition for singly-linked list. */
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int temp=0;
        ListNode *p1 = l1, *p2=l2,*p, *cur;
        p = new ListNode(0);
        if (p1 == NULL && p2 == NULL)
            return p;
        cur = p;
        for(;p1!=NULL&&p2!=NULL;p1=p1->next,p2=p2->next){
            cur->next = new ListNode((p1->val + p2->val + temp)%10);
            cur = cur->next;
            temp = (p1->val + p2->val + temp)/10;
        }
        ListNode *_p = (p1 == NULL)?p2:p1;
        for(;_p!=NULL;_p=_p->next){
            cur->next = new ListNode((_p->val + temp)%10);
            cur = cur->next;
            temp = (_p->val + temp)/10;
        }
        if(temp != 0)
            cur->next = new ListNode(temp);
        ListNode *result = p->next;
        delete p;
        return result;
    }
};

int main(){
    ListNode *p1 ,*p2;
    p1 = new ListNode(2);
    p2 = new ListNode(8);
    p1->next = new ListNode(9);
    p2->next = new ListNode(5);
    Solution solu;
    ListNode* p = solu.addTwoNumbers(p1,p2);
    for(;p!=NULL;p=p->next)
        cout<<p->val<<"->";
    return 0;
}