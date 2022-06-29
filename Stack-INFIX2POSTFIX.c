#include<stdio.h>
#include<string.h>
void push(char s[],int size,int *top,char val);
char pop(char s[],int size,int *top);
void display(char s[],int size,int *top);
int isfull(int top,int size);
int isempty(int top);
int isoperator(char symbol);
int precedence(char symbol);
int main()
{
   int i=0,incoming,existing,symbol,top1=-1,top2=-1,val,size=25;
   char n[25],res[25],s[25] ;
   printf("enter the infix expression ");
   gets(n);
   while(n[i]!='\0')
 {    
     if(n[i]=='('||n[i]==')')
        {
            if(n[i]=='(')
              {
                  push(s,size,&top1,n[i]);
              }
              else 
              {
                  while(s[top1]!='(')
                    {
                         symbol=pop(s,size,&top1);
                         push(res,size,&top2,symbol);
                    }
                   top1--;
              }
        }
     else if(isoperator(n[i])==1)
        { 
            incoming=  precedence(n[i]);
            existing=precedence(s[top1]); 
            if(isempty(top1)==1||s[top1]=='(')
               {
                   push(s,size,&top1,n[i]);  
               }
             else if((incoming>existing)||((incoming==existing)&&(n[i]=='^')))               
               {
                   push(s,size,&top1,n[i]);
               }
            else if(precedence(n[i])<=precedence(s[top1]))
               {
                   while(precedence(n[i])<=precedence(s[top1])&&s[top1]!='(')
                     {
                        symbol=pop(s,size,&top1);
                         push(res,size,&top2,symbol);
                         if(isempty(top1)==1)
                         break;
                      }
                    push(s,size,&top1,n[i]); 
               }
        }
      else
        push(res,size,&top2,n[i]);
        i++;
  }   
      while(isempty(top1)==0)
        {
           if(s[top1]=='(')
            {
               printf("brackets were not balanced");
                return 0;
            }
            else
           symbol=pop(s,size,&top1);
           push(res,size,&top2,symbol);
         }
         //  display(res,size,&top2);
         printf("postfix expression is=");
         puts(res);
       return 0;
}
 int isoperator(char symbol)
   {
     if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/'||symbol=='$'||symbol=='^')
     return 1;
     else 
      return 0;
    }
int precedence( char symbol)
   {
    switch(symbol)
     {
       case '+':
        {
          return 1;
          break;
        }
       case '-':
        {
           return 1;
           break;
        }
       case '*':
        {
            return 2;
            break;
         }
        case '/':
         {
             return 2;
             break;
         } 
        case '^':
         {
              return 3;
               break;
         }
        case '$':
        {
             return 4;
            break;
        }
       }
    }



 void push(char s[],int size,int *top,char val)
   {
       if(isfull(*top,size)==1)
       printf("stack is full😁");
       else
         {
           *top=*top+1;
           s[*top]=val;
         }
   }

  char pop(char s[],int size,int *top)
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

 void display(char s[],int size,int *top)
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
              printf("%c\n",s[i]);
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