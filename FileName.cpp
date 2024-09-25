#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct ListNode {
    ListNode* next;
    int val;
    ListNode(int val) {
        next = NULL;
        this->val = val;
    }
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0), * cur1 = list1, * cur2 = list2;
        ListNode* cur = dummy;
        while (cur1 != NULL && cur2 != NULL) {
            ListNode** pp = (cur1->val > cur2->val) ? &cur2 : &cur1;
            cur->next = *pp;
            cur = cur->next;
            *pp = (*pp)->next;
        }
        if (cur1 == NULL)cur->next = cur2;
        else cur->next = cur1;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};