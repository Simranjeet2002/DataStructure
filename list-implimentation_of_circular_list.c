//implimentation of circular list
#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};

struct node* create_list(struct node *nn);
void display_list(struct node *traverse);
void search_list(struct node *traverse);
int main()
{
    int choice,flag;
    struct node *nn,*traverse,*display,*search;
    traverse= create_list(nn);
    printf("choose\n 1.display_list \n 2.searching\n");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
    {
        display=traverse;
        display_list(display);
        break;
    }
    case 2:
    {
        search=traverse;
        search_list(search);
        break;
    }
    return 0;
    }
}

struct node* create_list(struct node *nn)
{
    struct node *head=NULL,*traverse;
    int choice;
    do
    {
        nn=(struct node *)malloc(sizeof(struct node)) ;
        printf("enter the data\n");
        scanf("%d",&(nn->data));
       
        if(head==NULL)
        {
            head=nn;
            nn->next=head;
            traverse=nn;
        }
        else
        {   
            traverse->next=nn;
            traverse=nn;
            nn->next=head;
        }
        printf("do u want to create node\n 1.yess \n 2. no");
        scanf("%d",&choice);
       
    } while(choice==1);

    return(head);
}

void display_list(struct node *display)
{   struct node *temp;
    temp=display;
    printf("elements are\n");
    do
    {
        printf("%d\t",display->data);
        display=display->next;
    }while(display!=temp);
}
void search_list(struct node *search)
{
    struct node *temp;
    temp=search;
    int  flag=0;
    int element;
    printf("enter the element u want to search\n");
    scanf("%d", &element);
    do
    {
        if((search->data)==element)
        {
            printf("element found\n");
            flag=1;
            break;
        }
        search=search->next;
    }while(search!=temp);

    if(flag==0)
    {
     printf("element not found\n");
     }
    
}
