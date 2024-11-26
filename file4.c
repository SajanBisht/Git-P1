#include<stdio.h>
#include<stdlib.h>
typedef struct single_ll
{
    int data;
    struct single_ll *next;
}ll;
int main()
{
    ll* top=NULL,*t=NULL,*p=NULL;
    int n;
    do
    {
         p=(ll*)malloc(sizeof(ll));
        if(p!=NULL)
            {
                printf("enter data\n");
                scanf("%d",&p->data);
                if(top!=NULL)
                    top->next=p;
                top=p;
                p->next=NULL;
                if(t==NULL)
                {
                     t=top;
                }
            }
        else
            printf("memory allocation failed\n");
        printf("1-contine,0-exit\n");
        scanf("%d",&n);
    }while(n==1);
    while(t!=NULL)
    {
            printf("%d\t",t->data);
            t=t->next;
    }
}