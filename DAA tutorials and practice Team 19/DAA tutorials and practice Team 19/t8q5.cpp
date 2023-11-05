#include<bits/stdc++.h>
using namespace std;

struct node
{
      int data,res;
      struct node *leftchild;
      struct node *rightchild;
};

struct node *Insert(struct node *root,int data)
{

      if(root==NULL)
      {
          struct node *temp;
          temp=(struct node *)malloc(sizeof(struct node));
          temp->data=data;
          temp->res=0;
          temp->leftchild=NULL;
          temp->rightchild=NULL;
          root=temp;
      }
      else if(data<root->data)
      {
          root->leftchild=Insert(root->leftchild,data);
      }
      else if(data>root->data)
      {
          root->rightchild=Insert(root->rightchild,data);
      }
      else
      {
          cout<<"Duplicate element\n";        
      }

      return root;
}

void Display(struct node *root)
{
    if(root)
      {
         Display(root->leftchild);
         cout<<root->res<<" ";
         Display(root->rightchild);
      }
}

int max_set(struct node *root)  
{  
    if (root == NULL)  
        return 0;  
  
    if (root->res!=0)  
        return root->res;  
  
    if (root->leftchild == NULL && root->rightchild == NULL)
    {
       root->res = 1;
       return root->res;
    }
  
    
    int res_child = max_set(root->leftchild) + max_set(root->rightchild);  
  
     
    int res_grand_child = 1;  
    if (root->leftchild)  
        res_grand_child += max_set(root->leftchild->leftchild) + max_set(root->leftchild->rightchild);  
    if (root->rightchild)  
        res_grand_child += max_set(root->rightchild->leftchild) + max_set(root->rightchild->rightchild);  
  
   
    root->res = max(res_child , res_grand_child);  
  
    return root->res;  
}  

int main()
{
    struct node *root;
    root=NULL;

    int n;
    cout<<"Enter the number of nodes:";
    cin>>n;

    cout<<"Enter:";
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        root=Insert(root,data);        
    }

    Display(root);

    cout<<"maximum independent set:"<<max_set(root);
}