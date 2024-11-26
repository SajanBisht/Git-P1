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

int main()
{
    ll* top=NULL,*t=NULL;
    int n;
    do
    {
        printf("enter 1-insert,2-delete,3-display\n");
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
        }
    } while (n<=3);
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