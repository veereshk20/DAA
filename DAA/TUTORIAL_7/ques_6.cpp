#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *head;
    head = NULL;
    head = (struct node *) malloc(sizeof(struct node));
    head->next = NULL;
    int n;
    cout<<"Enter the number of people:";
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
            temp = (struct node *) malloc(sizeof(struct node));
            cin>>temp->data;
            temp->next = NULL;
            ptr->next = temp;
            ptr = ptr->next;
        }
    }
    ptr->next = head;
    ptr = head;
    struct node *qtr;
    while(ptr->next!=ptr)
    {
        qtr = ptr->next;
        ptr->next = ptr->next->next;
        free(qtr);
        ptr = ptr->next;
        
    }
    cout<<"Survivor:"<<ptr->data;
}
