#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;
struct node* create_node(struct node *nn);
struct node* create_stack(struct node *nn,struct node *head);
void display_list(struct node *traverse);
void search_list(struct node *traverse);
struct node* push(struct node *nn,struct node *traverse);
struct node* pop(struct node *nn,struct node *head);
int main()

{
    int choice,flag;
    struct node *head=NULL,*head1,*nn;
    do
    {
        printf("\nchoose\n 0.creare stack\n 1.push a ele\n2.display \n 3.searching\n 4.pop a ele\n 5.EXIT\n");
        scanf("%d",&choice);
        clrscr();
        switch(choice)
        {
        case 0:
        {
            head= create_stack(nn,head);
            break;
        }
        case 1:
        {
            head = push(nn,head);
            break;
        }
        case 2:
        {
            head1=head;
            display_list(head);
            break;
        }
        case 3:
        {
            head1=head;
            search_list(head1);
            break;
        }
        case 4:
        {
            head=pop(nn,head);
            break;
        }
        case 5:
        {
            exit(0);
            break;
        }
        }
    } while(1);
    return 0;
}
struct node* create_node(struct node *nn)
{
    nn=(struct node *)malloc(sizeof(struct node)) ;
    printf("enter the data\n");
    scanf("%d",&(nn->data));
    nn->next=NULL;
}


struct node* create_stack(struct node *nn,struct node *head)
{
    struct node *traverse;
    head=NULL;
    top=NULL;
    int choice;
    do {
        nn= create_node(nn);
        if(head==NULL)
        {
            head=nn;
            traverse=nn;
            top=nn;
        }
        else
        {
            traverse->next=nn;
            traverse=nn;
            top=nn;
        }
        printf("do u want to create node\n 1.yess \n 2. no\n");
        scanf("%d",&choice);
    } while(choice==1);
    return(head);
}

void display_list(struct node *head1)
{   if(head1==NULL)
        printf("\nlist is empty\n");
    else
    {
        printf("elements are\n");
        while(head1!=NULL)
        {

            printf("%d\t",head1->data);
            head1=head1->next;
        }
    }
}

void search_list(struct node *search)
{
    int  flag=0;
    int element;
    printf("enter the element u want to search\n");
    scanf("%d", &element);
    while(search!=NULL)
    {
        if((search->data)==element)
        {
            printf("element found\n");
            flag=1;
            break;
        }
        search=search->next;
    }

    if(flag==0)
    {
        printf("element not found\n");
    }
}
struct node* push(struct node* nn,struct node *head)
{
    nn=create_node(nn);
    struct node *traverse;
    if(head==NULL)
    {

        head=nn;
        top=nn;
    }
    else
    {
        traverse=head;
        while(traverse->next!=NULL)
        {
            traverse =traverse->next;
        }
        traverse->next=nn;
        top=nn;
    }
    return head;
}

struct node* pop(struct node *nn,struct node *head)
{
    struct node* traverse;
    if(top==NULL)
        printf("list is empty\n");
    else
    {
        traverse=head;
        while(traverse->next!=top)
        {   
            traverse=traverse->next;
        }
        if(top==head)
        {
            head=NULL;
            top=NULL;
        }
        else
        {
            free(traverse->next);
            traverse->next =NULL;
            top=traverse;
        }
    }
    return head;
}
