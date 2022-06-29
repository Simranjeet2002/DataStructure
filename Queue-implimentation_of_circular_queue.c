#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void enqueue(char q[],int size,int* rear,int* front);
void dequeue(char q[],int size,int* rear,int* front);
void display(char q[],int size,int* rear,int* front);
int isempty(int* rear,int* front,int size);
int isfull(int* rear ,int * front,int size);
int main()
{
    char q[25];
    int size,n;
    printf ("enter the size of queue=");
    scanf("%d",&size);
      int rear=-1,front=-1;
    while(1)
    {
    printf("\nchoose\n 1.ENQUEUE\n 2.DEQUEUE\n 3.DISPLAY\n 4.EXIT\n ");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        {
            enqueue(q,size,&rear,&front);
            break;
        }
        case 2:
        {
            dequeue(q,size,&rear,&front);
            break;
        }
        case 3:
        {
            display(q,size,&rear,&front);
            break;
        }
        case 4:
        exit(0);
        break;
    }
    }
    return 0;
}
void enqueue(char q[],int size,int* rear,int* front)
{   
    char val;
    if(isfull(rear,front,size))
    {
        printf("its full😁");
    }
    else
    {   if(*front==-1)
        {
        *front=0;
        }
        printf("enter the value u want to enqueue");
        scanf(" %c", &val);
        *rear=(*rear+1)%size;
        q[*rear]=val;       
    }
}
void dequeue(char q[],int size,int* rear,int* front)
{
    if(isempty(rear,front,size)==1)
    {
        printf("its empty😅");
    }
    else if(*rear==*front)
    {
        printf("value removed is=%c",q[*front]);
         *rear=-1;
        *front=-1;
    }
    else
    {
        printf("value removed is=%c",q[*front]);
        *front=(*front+1)%size;
    }
}
void display(char q[],int size,int* rear,int* front)
{
   int i;
   int f=*front;
   int r=*rear;
    if(isempty(rear,front,size)==1)
    printf("its empty🤨");    
    else
    {       
        while(f!=r)
        {
            printf("%c",q[f]);
            f=(f+1)%size;
            
        }
        printf("%c",q[f]);
    }    
}
int isempty(int* rear,int* front,int size)
{
    if(front==-1)
    return 1;
    else 
    return 0;
}
int isfull(int* rear,int* front,int size)
{
    if((*rear+1)%size==*front)
    return 1;
    else 
    return 0;
}