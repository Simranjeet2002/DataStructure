#include<stdio.h>
#include<conio.h>
void push_x(int x[],int size,int *top_x,int val,int top_y);
void pop_x(int y[],int size,int *top_x);
void display_x(int x[],int size,int *top_x);
void push_y(char y[],int size,int *top_y,char val,int top_x);
void pop_y(char y[],int size,int *top_y);
void display_y(char y[],int size,int *top_y);
int isfull_x(int top_x,int size,int top_y);
int isempty_x(int top_x,int size);
int isfull_y(int top_y,int size,int top_x);
int isempty_y(int top_y,int size);
int main()
{
    int i,n,size_x,size_y,table,top_y,top_x=-1,x[40],val,size;
    char s, y[40];
    printf("enter the size of stack x and y=");
    scanf("%d %d",&size_x,&size_y);
    size=size_x+size_y;
    top_y=size;
  do{
    printf("\nchose  1.push_x\n 2.push_y\n 3.pop_x\n 4.pop_y\n 5.display_x\n 6.display_y\n 7.exit ");
    scanf("%d",&n);
   
    switch(n)
    {
     case 1:
    {
    printf("\nenter the interger value u want to push = ");
     scanf("%d",&val);
     push_x(x,size,&top_x,val,top_y);
     break;
    }
    case 3:
    {
    pop_x(x,size,&top_x);
    break;
     
    }
    case 5:
    {
    display_x(x,size,&top_x);
    break;
    }
    case 2:
    {
    printf("\nenter the character value u want to push =");
    scanf(" %c",&s);
     push_y(y,size,&top_y,s,top_x);
     break;
    }
    case 4:
    {
    pop_y(y,size,&top_y);
    break;  
    }
    case 6:
    {
    display_y(y,size,&top_y);
    break;
    }
    case 7:
    {
    printf("exit");
    goto table;
    }
   }
  }while(1);
    table:
    return 0;
}
 void push_x(int x[],int size,int *top_x,int val,int top_y)
   {
    if(isfull_x(*top_x,size,top_y)==1)
     printf("stack is full😁");
     else
     {
         *top_x=*top_x+1;
        x[*top_x]=val;
     }
   }

  void pop_x(int x[],int size,int *top_x)
 {
   int val;
   if(isempty_x(*top_x,size)==1)
    printf("\nstack is empty🤨\n");
    else 
    {
     val=x[*top_x];
    printf("\nvalue removed is %d\n",val);
    *top_x=*top_x-1;
    return val;
    }
  }

 void display_x(int x[],int size,int *top_x)
{ 
   int i,a= *top_x;
   if(isempty_x(*top_x,size)==1)
   {
     printf("\nits 🤔empty \n");
    }
    else
    {
     for(i=a;i>=0;i--)
    {
     printf("%d\n",x[i]);
    }
   }
    
}
 int isempty_x(int top_x,int size)
{
    if(top_x==-1)
    return 1;
    else
    return 0;
}

int isfull_x(int top_x,int size,int top_y)
   {
    if(top_x==top_y-1)
    return 1;
    else 
    return 0;
   }

void push_y(char y[],int size,int *top_y,char val,int top_x)
   {
    if(isfull_y(*top_y,size,top_x)==1)
     printf("stack is full😁");
     else
     {
         *top_y=*top_y-1;
        y[*top_y]=val;
     }
   }

 void pop_y(char y[],int size,int *top_y)
 {
   char val;
   if(isempty_y(*top_y,size)==1)
    printf("\nstack is empty🤨\n");
    else 
    {
     val=y[*top_y];
    printf("\nvalue removed is %c\n",val);
    *top_y=*top_y+1;
    return val;
    }
  }

 void display_y(char y[],int size,int *top_y)
{ 
   int i,a= *top_y;
   if(isempty_y(*top_y,size)==1)
   {
     printf("\nits 🤔empty \n");
    }
    else
    {
     for(i=*top_y;i<size;i++)
    {
     printf("%c\n",y[i]);
    }
   }
    
}
 int isempty_y(int top_y,int size)
{
    if(top_y==size)
    return 1;
    else
    return 0;
}

int isfull_y(int top_y,int size,int top_x)
   {
    if(top_y==top_x+1)
    return 1;
    else 
    return 0;
   }