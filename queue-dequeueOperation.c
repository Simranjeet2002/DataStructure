#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void enqueueF(int q[],int size,int* rear,int* front);
void dequeueF(int q[],int size,int* rear,int* front);
void enqueueR(int q[],int size,int* rear,int* front);
void dequeueR(int q[],int size,int* rear,int* front);
void display(int q[],int size,int* rear,int* front);
int isempty(int* rear,int* front,int size);
int isfull(int* rear ,int * front,int size);
int main()
{
    int q[25];
    int size,n;
    printf ("enter the size of queue=");
    scanf("%d",&size);
      int rear=-1,front=-1;
    while(1)
    {
    printf("\nchoose\n 1.ENQUEUE from front\n 2.ENQUEUE from rear\n 3.DEQUEUE from front\n 4.DEQUEUE from rear\n 5.DISPLAY\n 6.EXIT\n ");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        {
            enqueueF(q,size,&rear,&front);
            break;
        }
          case 2:
        {
            enqueueR(q,size,&rear,&front);
            break;
        }
        case 3:
        {
            dequeueF(q,size,&rear,&front);
            break;
        }
        case 4:
        {
            dequeueR(q,size,&rear,&front);
            break;
        }
        case 5:
        {
            display(q,size,&rear,&front);
            break;
        }
        case 6:
        exit(0);
        break;
    }
    }
    return 0;
}
void enqueueR(int q[],int size,int* rear,int* front)
{   
    int val;
    if((*rear+1)%size==*front)
    {
        printf("its full😁");
    }
    else
    {   if(*front==-1)
        {
        *front=0;
        }
        printf("enter the value u want to enqueue");
        scanf(" %d", &val);
        *rear=(*rear+1)%size;
        q[*rear]=val;       
    }
}
void enqueueF(int q[],int size,int* rear,int* front)
{   
    int val;
    if(((*front-1+size)%size)==*rear)
    {
        printf("its full😁");
    }
    else
    {   
        printf("enter the value u want to enqueue");
        scanf("%d", &val);
       if(*rear==-1&&*front==-1)
        {
         *rear=0;
         *front=0;
         q[*front]=val; 
        }
        else
        {
        *front=(*front-1+size)%size;
        q[*front]=val;   
        }    
    }
}
void dequeueF(int q[],int size,int* rear,int* front)
{
    if(*front==-1)
    {
        printf("its empty😅");
    }
    else if(*rear==*front)
    {
        printf("value removed is=%d",q[*front]);
         *rear=-1;
        *front=-1;
    }
    else
    {
        printf("value removed is=%d",q[*front]);
        *front=(*front+1)%size;
    }
}
void dequeueR(int q[],int size,int* rear,int* front)
{
    if(*front==-1)
    {
        printf("its empty😅");
    }
    else if(*rear==*front)
    {
        printf("value removed is=%d",q[*rear]);
         *rear=-1;
        *front=-1;
    }
    else
    {
        printf("value removed is=%d",q[*rear]);
        *rear=(*rear-1+size)%size;
    }
}
void display(int q[],int size,int* rear,int* front)
{
   int i;
   int f=*front;
   int r=*rear;
    if(f==-1)
    printf("its empty🤨");    
    else
    {       
        while(f!=r)
        {
            printf("%d",q[f]);
            f=(f+1)%size;
            
        }
        printf("%d",q[f]);
    }    
}
