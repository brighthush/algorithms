#include <iostream>
#include <cstdio>

using namespace std;


  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    // If two linked list are intersected at some node, return the point to
    // the intersected node. If they are not intersected, return NULL.
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)
            return NULL;
        int n = getListLength(headA);
        int m = getListLength(headB);

        ListNode *stepa = headA;
        ListNode *stepb = headB;
        int left = min(n, m);
        if(n>m)
        {
            for(int i=0; i<n-m; ++i)
                stepa = stepa->next;
        }
        else if(n<m)
        {
            for(int i=0; i<m-n; ++i)
                stepb = stepb->next;
        }

        for(int i=0; i<left; ++i)
        {
            if( ((int)stepa) == ((int)stepb))
            {
                return stepa;
            }
            stepa = stepa->next;
            stepb = stepb->next;
        }
        return NULL;

    }

    int getListLength(ListNode *h)
    {
        int cnt = 0;
        while(h!=NULL)
        {
            cnt += 1;
            h = h->next;
        }
        return cnt;
    }
};


