#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct NODE
{
    int val;
    struct NODE *next;
    NODE(int value) { val = value; next = NULL; }
}Node;

class CusList
{
private:
    Node *head;

public:
    CusList(int n)
    {
        head = NULL;
        Node *cur = NULL;
        for(int i=0; i<n; ++i)
        {
            int val; scanf("%d", &val);
            Node *temp = new Node(val);
            if(i==0)
            {
                head = temp; cur = temp;
            }
            else
            {
                cur->next = temp;
                cur = temp;
            }
        }
        qsort(head, NULL);
        display();
    }

    void swap(Node &a, Node &b);
    Node* partition(Node *beg, Node *end);
    void qsort(Node *beg, Node *end);
    void display();
};

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        CusList cl(n);
    }
    return 0;
}

void CusList::swap(Node &a, Node &b)
{
    int temp = a.val; a.val = b.val; b.val = temp;
}

Node* CusList::partition(Node *beg, Node *end)
{
    if(beg == end) return NULL;
    int piv = beg->val;
    Node *bigger = beg;
    Node *cur = beg->next;
    while(cur!=end && cur->val < piv) { cur=cur->next; }
    if(cur == end)
    {
        if(beg->next != NULL) swap(*beg, *(beg->next));
        return cur;
    }
    
    bigger = cur;
    while(cur!=end)
    {
        printf("cur->val %d\n", cur->val);
        if(cur->val < piv)
        {
            swap(*bigger, *cur);
            bigger = bigger->next;
        }
        cur = cur->next;
    }
    return bigger;
}

void CusList::qsort(Node *beg, Node *end)
{
    if(beg == NULL || beg->next == end || beg==end) return ;
    Node *mid = partition(beg, end);
    if(mid!=NULL) printf("mid %d\n", mid->val);
    else printf("mid NULL");
    qsort(beg, mid);
    qsort(mid, end);
}

void CusList::display()
{
    Node *cur = head;
    while(cur != NULL) { printf("%d ", cur->val); cur = cur->next; }
    printf("\n");
}

