#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct single_ll
{
    int no;
    char str[50];
    struct single_ll *next;
}ll;
ll* insert(ll*);
ll* delete(ll*);
void display(ll*);
void del_dup(ll*);

int main()
{
    ll* top=NULL,*t=NULL;
    int n;
    do
    {
        printf("enter 1-insert,2-delete,3-display,4-delete duplicate\n");
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
            del_dup(t);
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
        printf("enter name and roll no.\n");
        scanf("%s",&p->str);
        scanf("%d",&p->no);
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
    printf("deleted name and rollno\t:%s%d\t",t->str,t->no);
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
        printf("%s\n%d\n",t->str,t->no);
        t=t->next;
    }
}
void del_dup(ll* t)
{
    ll* temp,*prev,*store;
    while(t!=NULL && t->next!=NULL)
    {
        prev=t;
        temp=t->next;
        store=prev;
        while(temp!=NULL)
        {
            if(strcmp(prev->str,temp->str)==0)
            {
                store->next=temp->next;
                temp=temp->next;
            }
            else
            {
                store=temp;
                temp=temp->next;
            }
        }
        t=t->next;
    }
}
