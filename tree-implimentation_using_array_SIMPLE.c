#include<stdio.h>
#include<math.h>
int main()
{
    int h,n,i,ch,c;
    char a[10000];
    printf("Enter the height of the tree\n");
    scanf("%d",&h);
    n=(pow(2,h)-1);
    int m=floor(n/2);
    for(i=0; i<m; i++)
    {
    if(i==0)
    {
    printf("Enter the Parent:\n"); 	
    	scanf("%s",&a[i]);
    }
        printf("Press 1 for left child of %dth parent else press 0\n",i+1);
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter the left node\n");
            scanf("%s",&a[2*i+1]);
        }
        else
        {
            a[2*i+1]='-1';
        }
        printf("Press 1 for Right child of %dth parent else press 0\n",i+1);
        scanf("%d",&c);
        if(c==1)
        {
            printf("Enter the right node\n");
            scanf("%s",&a[2*i+2]);
        }

        else
        {
            a[2*i+1]='-1';
        }
    }
    printf("Tree is\n");
    for(i=0; i<m; i++)
    {
        
        printf("\nParent:%c\nLeft child:%c\nRight child:%c\n",a[i],a[2*i+1],a[2*i+2]);
    }
    return 0;
}