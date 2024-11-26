#include<stdio.h>
#include<stdlib.h>
typedef struct single_ll
{
    int data;
    struct single_ll *prev;
}ll;

int main()
{
    ll* top=NULL,*p=NULL;
    int n;
    do
    {
         p=(ll*)malloc(sizeof(ll));
        if(p!=NULL)
            {
                printf("enter data\n");
                scanf("%d",&p->data);
                if(!(top==NULL))
                {
                    p->prev=top;
                } 
                else
                    p->prev=NULL;
                top=p;
            }
         else
            printf("memory allocation failed\n");
         printf("1-contine,0-exit\n");
         scanf("%d",&n);
    } while (n==1);
    while(top!=NULL)
    {
        printf("%d\t",top->data);
        top=top->prev;
    }
}
    
    