#include <iostream>
#include <cstdio>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1) return head;
        ListNode *beg = head;
        ListNode *pre=NULL, *cur = NULL;
        while(true) {
            int step = 1;
            cur = beg;
            while(cur != NULL) {
                cur = cur->next;
                ++step;
                if(step == k) {
                    break;
                }
            }
            if(step != k || cur==NULL) break;

            ListNode *next = cur->next;
            cur->next = NULL;

            //printf("beg %d cur %d\n", beg->val, cur->val);
            //lzhDisplay(beg);
            ListNode *temp = reverseList(beg);
            //lzhDisplay(temp);

            if(pre == NULL) {
                head = temp;
                pre = beg;
                beg->next = next;
                beg = next;
            }
            else {
                //printf("\tpre %d beg %d\n", pre->val, beg->val);
                pre->next = temp;
                pre = beg;
                beg->next = next;
                beg = next;
            }
            //cout << "all ";
            //lzhDisplay(head);
        }
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        ListNode *pre = NULL, *cur = head;
        while(cur != NULL) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    void lzhDisplay(ListNode *head) {
        ListNode *cur = head;
        while(cur != NULL) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

};

int main() {
    Solution s;
    int n, val;
    while(scanf("%d", &n) != EOF) {
        ListNode *head = NULL;
        ListNode *cur = NULL;
        for(int i=0; i<n; ++i) {
            scanf("%d", &val);
            ListNode *temp = new ListNode(val);
            if(head == NULL) {
                head = temp;
                cur = temp;
            }
            else {
                cur->next = temp;
                cur = temp;
            }
        }
        int k;
        scanf("%d", &k);
        ListNode *rhead = s.reverseKGroup(head, k);
        s.lzhDisplay(rhead);
    }
    return 0;
}
