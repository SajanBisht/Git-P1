#include<stdio.h>
#include<stdlib.h>
typedef struct BST{
    struct BST *left;
    int data;
    struct BST *right;
}bst;
void insert(bst**,int num);
bst* delete(bst*,int v);
void display(bst*);
int main()
{
    bst* head=NULL,*root=NULL;
    int num,v,n;
    do
    {
       printf("enter 1-insert,2-delete,3-display,0-exit\n");
       scanf("%d",&n);
       switch(n)
       {
        case 1:
            printf("enter data to insert\n");
            scanf("%d",&num);
            insert(&root,num);
            if(head==NULL)
                head=root;
            break;
        case 2:
            printf("enter value to search\n");
            scanf("%d",&v);
            head=delete(head,v);
            break;
        case 3:
            display(head);
       }
    } while (n !=0);
    return 0; 
}
void insert(bst ** rt,int num)
{
    bst* p=NULL;
    p=(bst*)malloc(sizeof(bst));
    if(p!=NULL)
    {
         p->data=num;
         p->left=NULL;
         p->right=NULL;
        if((*rt)==NULL)
        {
            *rt=p;
            return;
        }
        else
        {
            if((*rt)->data>num)
                insert(&((*rt)->left),num);
            else
                insert(&((*rt)->right),num);
        }
    }
    else
    printf("memory allocation failed\n ");
}
bst* delete(bst* rt,int v)
{ bst* t=NULL,*p=NULL;
    if(rt->data==v)
    {
        if(rt->left==NULL && rt->right==NULL)
            return NULL;
        if(rt->left !=NULL && rt->right==NULL)
        {
            t=rt->left;
            free(rt);
            return t;
        }
        if(rt->right!=NULL)
        {
            t=rt->right;
            p=rt->right;
            while(t->left!=NULL)
                t=t->left;
            t->left=rt->left;
            free(rt);
            return p;
        }
    }
else{
    bst * x=NULL,*c=NULL;
    x=p=rt;
    while(x!=NULL)
    {
        p=x;
        x=(x->data>v)?(x->left):(x->right);
        if(x->data==v)
            break;
    }
    if(x==NULL)
    {
        printf("element not found\n");
        return rt;
    }
    if(x->left==NULL && x->right ==NULL)
    {
        t=NULL;
    }
    if(x->left!=NULL && x->right ==NULL)
    {
        t=x->left;
    }
    if(x->right!=NULL)
    {
        t=x->right;
        while(t->left!=NULL)
            t=t->left;
        t->left=x->left;
    }
        if(p->data>v)
            p->left=t;
        else
            p->right=t;
        free(x);
        return rt;
}
return rt;
}
void display(bst* rt)
{
    if(rt==NULL)
        return;
    else{
    display(rt->left);
    printf("%d\t",rt->data);
    display(rt->right);
    }
}