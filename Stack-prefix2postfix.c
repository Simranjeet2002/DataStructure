#include<stdio.h>
#include<string.h>
#include<math.h>
void push( char s[25][25],int size,int *top,char* val);
char* pop(char s[25][25],int size,int *top);
void display(char s[25][25],int size,int *top);
int isfull(int top,int size);
int isempty(int top);
int isoperator(char symbol);

int main()
{
    int i=0,j=0,s[25][25],top=-1,size=25;
    char symbol[25],ch[25],op1[25],op2[25];

    printf("enter the prefix expression");
    scanf("%s",ch);
    for(i=strlen(ch)-1; i>=0; i--)
    {
        symbol[0]=ch[i];
        symbol[1]='\0';

        if(isoperator(symbol[0])==1)
        {
            strcpy(op1,pop(s,size,&top));
            strcpy(op2,pop(s,size,&top));
            strcat(op1,op2);
            strcat(op1,symbol);
            push(s,size,&top,op1);
        }
        else
        {
            push(s,size,&top,symbol);
        }
    }
printf("result= %s",s[0]);
return 0;
}
int isoperator( char symbol)
{
    if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/'||symbol=='^')
    {
        return 1;
    }
}
void push(char s[25][25],int size,int *top,char* symbol)
{
    if(isfull(*top,size)==1)
        printf("stack is full😁");
    else
    {
        *top=*top+1;
        strcpy(s[*top],symbol);
    }
}

char* pop(char s[25][25],int size,int *top)
{
    char *ele;
    if(isempty(*top)==1)
        printf("\nstack is empty🤨\n");

    else
    {
        //  printf("\nvalue removed is %d\n",val);
        ele=s[*top];
        *top=*top-1;
    }
    return ele;
}

void display(char s[][25],int size,int *top)
{
    int i,a= *top;
    if(isempty(*top)==1)
    {
        printf("\nits 🤔empty \n");
    }
    else
    {
        for(i=a; i>=0; i--)
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