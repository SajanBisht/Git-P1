#include<stdio.h>
#include<stdlib.h>
typedef struct single_ll
{
    int data;
    struct single_ll *next;
}ll;
ll* insert(ll*);
ll* delete(ll*);
void display(ll*);
ll* reverse(ll*);

int main()
{
    ll* top=NULL,*t=NULL;
    int n;
    do
    {
        printf("enter 1-insert,2-delete,3-display,4-reverse\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            top=insert(top);
            if( t==NULL)
            {
                    t=top;
            }
            if(t==NULL)
            {
                t=top;
            }
            break;
            case 2:
            t=delete(t);
            if(t==NULL)
                top=NULL;
            break;
            case 3:
            display(t);
            break;
            case 4:
            top=t;
            t=reverse(t);
        }
    } while (n<=4);
    return 0;
}
ll* insert(ll*top)
{
    ll* p=NULL;
    p=(ll*)malloc(sizeof(ll));
    if(p!=NULL)
    {
        printf("enter data\n");
        scanf("%d",&p->data);
        if(top!=NULL)
        {
            top->next=p;
            top=p;
        }

    }
    else
    printf("memory allocation failed\n");
    p->next=NULL;
    return p;
}
ll* delete(ll*t)
{
    if(t==NULL)
    printf("Empty\n");
    else
    {
    printf("deleted\t:%d\t",t->data);
    t=t->next;
    }
    return t;
}
void display(ll*t)
{
    if(t==NULL)
    printf("Empty\n");
    while(t!=NULL)
    {
        printf("%d\n",t->data);
        t=t->next;
    }
}
ll* reverse(ll* t)
{
    ll *prev=NULL,*nxtt=NULL;
    while(t!=NULL)
    {
        nxtt=t->next;
        t->next=prev;
        prev=t;
        t=nxtt;
    }
    return prev;
}