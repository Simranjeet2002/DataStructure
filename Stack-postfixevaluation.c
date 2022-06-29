#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
void tostring(int top,int s[]);
void push(int s[],int size,int *top,int val);
int pop(int s[],int size,int *top);
void display(int s[],int size,int *top);
int isfull(int top,int size);
int isempty(int top);
int isoperator(char symbol);
int result(int op1,char symbol,int op2);
int main()
{
    int j=0,i=0,n,ans,ele1,ele2,exit,op1,op2,top=-1,s[10],val,next,size=10;
    char symbol,ch[15];
    printf("\nkeep in mind that\n");
    printf("operand should be single digit\n");
    printf("input the postfix expression which should contain operand in integer and operators such as '+','-','*','/','^'");
   printf("\nfor printing the current state of stack input-'?'");
    printf("\nfor printing the top element of stack input-'%%'");
    printf("\nfor exiting out input -'!'\n");
       printf("enter the postfix expression");
    scanf("%s",ch);
   
   while(ch[i]!='\0')
    {
      symbol=ch[i];
   
        
      if(isoperator(symbol)==1)
       {
          op2=pop(s,size,&top);
         op1=pop(s,size,&top);
        ans= result(op1,symbol,op2);
        push(s,size,&top,ans);
        }
       else if(symbol=='?'||symbol=='%'||symbol=='!')
    {
     if(symbol=='?')
    { 
    printf("the current state of stack is\n");
     tostring(top,s);
    }
    
    else if(symbol=='!')
    {
     printf("\nexit");
     goto exit;
    }
    else 
    {
    ele1=pop(s,size,&top);
     
    printf(" the  elements present at top position is %d ",ele1);
    
    }
    }
      else  
       {  
         
         push(s,size,&top,(int)symbol-48);
         
       }
    
=        i++;
    
   }
   printf("result=%d",s[top]);
   exit:
    return 0;
}
 int isoperator( char symbol)
{
   if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/'||symbol=='^')
    {
    return 1;
    }
 }
 void tostring(int top, int s[])
{
int i;
for(i=0;i<=top;i++)
{
printf("%d\n",s[i]);
}
}
int result(int op1,char symbol,int op2)
{
 switch(symbol)
{
  case '+':
  {
   return op1+op2;
   break;
   }
   case '-':
  {
   return op1-op2;
   break;
   }
    case '*':
  {
   return (op1*op2);
   break;
   }
    case '/':
  {
   return op1/op2;
   break;
   }
    case '^':
  {
   return pow(op1,op2);
   break;
   }
}
}



 void push(int s[],int size,int *top,int val)
   {
    if(isfull(*top,size)==1)
     printf("stack is full😁");
     else
     {
         *top=*top+1;
        s[*top]=val;
     }
   }

  int pop(int s[],int size,int *top)
 {
   char val;
   if(isempty(*top)==1)
    printf("\nstack is empty🤨\n");
    
    else 
    {
     val=s[*top];
  //  printf("\nvalue removed is %d\n",val);
    *top=*top-1;
    return val;
    }
  }

 void display(int s[],int size,int *top)
{ 
   int i,a= *top;
   if(isempty(*top)==1)
   {
     printf("\nits 🤔empty \n");
    }
    else
    {
     for(i=a;i>=0;i--)
    {
     printf("%d\n",s[i]);
    }
   }
    
}
 int isempty(int top)
{
    if(top<=-1)
    return 1;
    else
    return 0;
}

int isfull(int top,int size)
   {
    if(top>=size-1)
    return 1;
    else 
    return 0;
   }