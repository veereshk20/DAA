#include <stdio.h>
#include <stdlib.h>
//Duplicates and their multiplicity
//T.C. O(nlog(n))
//S.C O(n)
struct node
{
    int key,height;
    struct node *left;
    struct node * right;
    int count;
};

int height(struct node *root)
{
    if(root==NULL)
      return -1;

    return root->height;  
}

int max(int a,int b)
{
    return (a>b)?a:b;
}

int balance(struct node *root)
{
    if(root==NULL)
     return 0;

    return height(root->left)-height(root->right); 
}

struct node *rightrotation(struct node *root)
{
    struct node *x=root->left;
    struct node *y=x->right;

    x->right=root;
    root->left=y;

    root->height=max(height(root->left),height(root->right))+1;

    x->height=max(height(x->left),height(x->right))+1;

    return x;
}

struct node *leftrotation(struct node *root)
{
    struct node *x=root->right;
    struct node *y=x->left;

    x->left=root;
    root->right=y;

    root->height=max(height(root->left),height(root->right))+1;

    x->height=max(height(x->left),height(x->right))+1;

    return x;
}

struct node *Insert(struct node *root,int key)
{
    if(root==NULL)
    {
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node ));
        temp->key=key;
        temp->left=NULL;
        temp->right=NULL;
        temp->height=0;
        temp->count=1;

        return temp;
    }

    if(key<root->key)
       root->left=Insert(root->left,key);
    else if(key>root->key)
       root->right=Insert(root->right,key);
    else
      {
         root->count=root->count+1;
         return root;
      }


    root->height=max(height(root->left),height(root->right))+1;

    int b=balance(root);

    if(b>1&&key<root->left->key)
      return rightrotation(root);
    else if(b<-1&&key>root->right->key)
      return leftrotation(root);
    else if(b>1&&key>root->left->key)
      {
        root->left=leftrotation(root->left);
        return rightrotation(root);
      }
    else if(b<-1&&key<root->right->key)
      {
        root->right=rightrotation(root->right);
        return leftrotation(root);
      }               

      return root;

} 

void inorder(struct node *root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d-%d\n",root->key,root->count);
        inorder(root->right);
    }
}

int main()
{
    struct node *root;
    root=NULL;
    int arr[100],n;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
       {
          int a; 
          scanf("%d",&a);
          root=Insert(root,a);
          arr[i]=a;
       }

  inorder(root);   

  for(int i=0;i<n;i++)
     printf("%d ",arr[i]);
  printf("\n");

}