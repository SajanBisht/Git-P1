#include<stdio.h>
# define max 10
int insert(int[],int);
int delete(int[],int);
void display(int[],int);
int main()
{ 
    int stack[max],n,top=-1;
    do
     {
        printf("enter 1-insert,2-delete,3-display\n");
        scanf("%d",&n);
        switch(n)
         {
            case 1:
                top=insert(stack,top);
            break;
            case 2:
                top=delete(stack,top);
            break;
             case 3:
                display(stack,top);
            break;
        }
    }while(n<=3);
    return 0;
}
int insert(int stack[],int top)
{   
    top++;
    if(top==max)
        printf("stack is full");
    else{
        printf("enter data\n");
        scanf("%d",&stack[top]);
    }
    return top;
}
int delete(int stack[],int top)
{
    if(top==-1)
        printf("stack is empty\n");
    else   
    {
         printf("deleted data:%d\n",stack[top]);
        top--;
    } 
    return top;
}
void display(int stack[],int top)
{
    if(top<0)
        printf("stack is empty\n");
    else{
         for(int i=0;i<=top;i++)
         {
            printf("%d",stack[i]);
         }
    }
}