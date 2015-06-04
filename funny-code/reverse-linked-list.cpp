/*
Implemented iterative and recursive method to reverse a linked list.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val) { this->val = val, next = NULL; }
};

class MyList
{
private:
    Node *h;

public:
    MyList(int n)
    {
        h=NULL;
        if(n==0) return;
        Node *pre = NULL;
        for(int i=0; i<n; ++i)
        {
            if( i==0 )
            {
                Node *cur = new Node(i);
                h = cur;
                pre = cur;
            }
            else
            {
                Node *cur = new Node(i);
                pre->next = cur;
                pre = cur;
            }
        }
    }

    Node *rev1() // reverse the list by iterative method
    {
        Node *cur = h;
        Node *pre = NULL;
        while(cur != NULL)
        {
            if(pre == NULL)
            {
                pre = cur;
                cur = cur->next;
                pre->next = NULL;
            }
            else
            {
                Node *tmp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = tmp;
            }
        }
        h = pre;
        return h;
    }

    Node *rev2()
    {
        return rev(NULL, h);
    }

    Node *rev(Node *pre, Node *cur) // reverse list by recursive method
    {
        if(cur == NULL)
        {
            h = pre;
            return h;
        }
        if(pre == NULL)
        {
            pre = cur;
            cur = cur->next;
            return rev(pre, cur);
        }
        else
        {
            if(pre == h)
            {
                pre->next = NULL;
                Node *tmp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = tmp;
                return rev(pre, cur);
            }
            else
            {
                Node *tmp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = tmp;
                return rev(pre, cur);
            }
        }
    }

    void display()
    {
        Node *cur = h;
        while(cur != NULL)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main()
{
    MyList ml(6);
    ml.display();
    ml.rev1();
    ml.display();
    ml.rev2();
    ml.display();
    return 0;
}
