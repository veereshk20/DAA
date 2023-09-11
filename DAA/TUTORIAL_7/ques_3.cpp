#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node * next;
    struct node * prev;
};
int main()
{
    struct node * head;
    head = NULL;
    head = (struct node *) malloc(sizeof(struct node));
    head->next = NULL;
    head->prev = NULL;
    int n;
    cout<<"Enter the number of elements in the array:";
    cin>>n;
    struct node *ptr = head;
    for(int i = 0; i<n; i++)
    {
        if(i==0)
        {
            cin>>head->data;
        }
        else
        {
            struct node *temp;
            temp = (struct node*) malloc(sizeof(struct node));
            temp->next = NULL;
            temp->prev = NULL;
            cin>>temp->data;
            ptr->next = temp;
            temp->prev = ptr;
            ptr = ptr->next;
        }
    }
    struct node *qtr = head;
    for(int i = 0; i<n; i++)
    {
        if(qtr->data==0)
        {
            if(qtr->prev==NULL)
            {
                qtr = qtr->next;            
            }
            else if(qtr->next==NULL)
            {
                head->prev = qtr;
                qtr->prev->next = NULL;
                qtr->next = head;
                qtr->prev = NULL;
                head = qtr;
            }
            else
            {
                struct node * temp = qtr->next;
                qtr->prev->next = qtr->next;
                qtr->next->prev = qtr->prev;
                head->prev = qtr;
                qtr->next = head;
                qtr->prev = NULL;
                head = qtr;
                qtr = temp;
            }
        }
        else
        {
        qtr = qtr->next;
        }
    }
    qtr = head;
    while(qtr->next!=NULL)
    {
        qtr = qtr->next;
    }
    ptr = qtr;
    qtr = head;
    for(int i = 0; i<n; i++)
    {
        if(qtr->data==2)
        {
            
            if(qtr->next==NULL)
            {
                qtr = qtr->next;
                continue;
            }
            else
            {
                struct node * temp = qtr->next;
                qtr->prev->next = qtr->next;
                qtr->next->prev = qtr->prev;
                ptr->next = qtr;
                qtr->prev = ptr;
                ptr = ptr->next;
                ptr->next = NULL;
                qtr = temp;
            }
        }
        else
        {
            qtr = qtr->next;
        }
        
    }
    qtr = head;
    for(int i = 0; i<n; i++)
    {
        cout<<qtr->data<<" ";
        qtr = qtr->next;
    }
}
