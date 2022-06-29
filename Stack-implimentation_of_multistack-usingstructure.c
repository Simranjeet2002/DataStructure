#include<stdio.h>
#include<conio.h>
struct ms
{
char ele[20];
int top_x;
int top_y;
int size;
};
 void push_x(struct ms *sa)
   { int c;
    if(isfull_x(sa->top_x,sa->size,sa->top_y)==1)
     printf("stack is full😁");
     else
     {    sa->top_x=sa->top_x+1;
          printf("\nenter the integer value u want to push =");
          scanf(" %d",&c);
         
          sa->ele[sa->top_x]=c+48;
      
     }
   }

  void pop_x(struct ms *sa)
 {
  
   if(isempty_x(sa->top_x,sa->size)==1)
    printf("\nstack is empty🤨\n");
    else 
    {
    
    printf("\nvalue removed is %c\n",sa->ele[sa->top_x]);

    sa->top_x--;
    }
  }

 void display_x(struct ms* sa)
{ 
   int i;
    int a=sa->top_x;
   if(isempty_x(sa->top_x,sa->size)==1)
   {
     printf("\nits 🤔empty \n");
    }
    else
    {
     for(i=a;i>=0;i--)
    {
     printf("%c\n",sa->ele[i]);
    }
   }
}
 void push_y(struct ms* s)
   { char c;
    if(isfull_x(s->top_y,s->size,s->top_x)==1)
     printf("stack is full😁");
     else
     {    s->top_y=s->top_y-1;
          printf("\nenter the character value u want to push =");
          scanf(" %c",&c);
          s->ele[s->top_y]=c;
      
     }
   }

  void pop_y(struct ms* s)
 {
   char val;
   if(isempty_y(s->top_y,s->size)==1)
    printf("\nstack is empty🤨\n");
    else 
    {
     val=s->ele[s->top_y];
    printf("\nvalue removed is %c\n",val);
    s->top_y++;
    }
  }

 void display_y(struct ms* s)
{ 
   int i;
    char a=s->top_y;
   if(isempty_y(s->top_y,s->size)==1)
   {
     printf("\nits 🤔empty \n");
    }
    else
    {
     for(i=a;i<s->size;i++)
    {
     printf("%c\n",s->ele[i]);
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
int main()
{
    int n,size_x,size_y,table,size;
    struct ms s;
    s.top_x=-1;
    printf("enter the size of stack x and y=");
    scanf("%d %d",&size_x,&size_y);
    s.size=size_x+size_y;
    s.top_y=s.size;
  do{
    printf("\nchose  1.push_x\n 2.push_y\n 3.pop_x\n 4.pop_y\n 5.display_x\n 6.display_y\n 7.exit ");
    scanf("%d",&n);
   
    switch(n)
    {
     case 1:
    {   
     push_x(&s);
     break;
    }
    case 3:
    {
    pop_x(&s);
    break;
     
    }
    case 5:
    {
    display_x(&s);
    break;
    }
    case 2:
    {
     push_y(&s);
     break;
    }
    case 4:
    {
    pop_y(&s);
    break;  
    }
    case 6:
    {
    display_y(&s);
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