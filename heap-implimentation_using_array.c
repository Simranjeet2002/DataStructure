//implimentation of heap using array.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insert_tree(int a[20],int ele);
int main()
{
    int c,ele,i,a[20];
    a[0]=0;
    do
    {
        printf("\nIN heap \nchoose \n1.insert\n2.delete\n3.display tree\n\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
        {
            printf("\nenter the data u want to insert\n");
            scanf("%d",&ele);
            insert_tree(a,ele);
            break;
        }
        case 2:
        {
            delete_tree(a);
            break;

        }
        case 3:
        {
            for(i=1; i<=a[0]; i++)
                printf("%d ",a[i]);
            break;
        }
        default:
            exit(0);
        }
    } while(1);
    return 0;
}
void delete_tree(int a[])
{
    int key, ch,i; 
    if(a[0]==0)
    printf("empty");
    else
    {
    key=a[1];
    a[1]=a[a[0]];
    a[a[0]]=key;
    printf("deleted %d",a[a[0]]);
    a[0]=a[0]-1;
    
    for(i=1;2*i<=a[0];i=ch)
    {
    if(2*i+1<=a[0]&&a[2*i]<a[2*i+1])
    ch=2*i+1;
    else
    ch=2*i;
    key=a[i];
    a[i]=a[ch];
    a[ch]=key;
    }
    }
    
}
void insert_tree(int a[20],int ele)
{
    int pos,key;
    pos=a[0]=a[0]+1;
    a[pos]=ele;
    for(pos=a[0]; pos/2>=1; pos=pos/2)
    {
        if(a[pos]>a[pos/2])
        {
            key=a[pos];
            a[pos]=a[pos/2];
            a[pos/2]=key;
        }
        else
            break;
    }
}
