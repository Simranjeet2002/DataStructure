////implimentation of double list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{    
    struct node *previous;
    int data;
    struct node *next;
};
struct node* create_node(struct node *nn);
struct node* create_list(struct node *nn,struct node *head);
void display_list(struct node *traverse);
void search_list(struct node *traverse);
struct node* insert_node(struct node *nn,struct node *head);
struct node* insert_beg(struct node *nn,struct node *head);
struct node* insert_end(struct node *nn,struct node *head);
struct node* insert_loc(struct node *nn,struct node *head);
struct node* delete_node(struct node *nn,struct node *head);
struct node* delete_beg(struct node *nn,struct node *head);
struct node* delete_end(struct node *nn,struct node *head);
struct node* delete_loc(struct node *nn,struct node *head);
int main()
{
    int choice,flag;
    struct node *head=NULL,*head1,*nn;
    do
    {
        printf("\nchoose\n 0.creare list\n1. insert_ele\n 2.display_list \n 3.searching\n 4.delete\n 5.EXIT\n");
        scanf("%d",&choice);
        clrscr();
        switch(choice)
        {
        case 0:
        {
            head= create_list(nn,head);
            break;
        }
        case 1:
        {
            head = insert_node(nn,head);
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
            if(head==NULL)
                printf("\nlist is empty\n");
            else
                head=delete_node(nn,head);
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
    nn->previous=NULL;
}
struct node* create_list(struct node *nn,struct node *head)
{
    struct node *traverse;
    head=NULL;
    int choice;
    do {
        nn= create_node(nn);
        if(head==NULL)
        {
            head=nn;
            traverse=nn;
        }
        else
        {
            traverse->next=nn;
            nn->previous=traverse;
            traverse=nn;
        }
        printf("do u want to create node\n 1.yess \n 2. no\n");
        scanf("%d",&choice);
    } while(choice==1);
    return(head);
}

void display_list(struct node *head1)
{ 
   if(head1==NULL)
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

struct node* insert_node(struct node *nn,struct node *head)
{
    struct node* traverse;
    int choice;
    printf("choose\n 1.insert node in beginning\n 2. inser node at end\n");
    printf("3.insert at location\n");
    scanf("%d",&choice);
    
    if(choice==1)
    {
        head=insert_beg(nn,head);
    }
    else if(choice==2)
    {
        head=insert_end(nn,head);
    }
    else if(choice==3)
    {
        head=insert_loc(nn,head);
    }
    else
        printf("\ninvalid choice\n");
    return head;
}

struct node* insert_beg(struct node *nn,struct node *head)
{
    nn= create_node(nn);
    if(head==NULL)
    {
        head=nn;
    }
    else
    {
        nn->next=head;
        head->previous=nn;
        head=nn;
    }
    return head;
}
struct node* insert_end(struct node *nn,struct node *head)
{
    struct node *traverse;
    nn= create_node(nn);
    if(head==NULL)
    {
        head=nn;
    }
    else
    {
        traverse=head;
        while(traverse->next!=NULL)
        {
            traverse =traverse->next;
        }
        traverse->next=nn;
        nn->previous=traverse;
    }
    return head;
}
struct node* insert_loc(struct node *nn,struct node *head)
{
    struct node  *traverse,*front;
    int c=1,l;
    traverse=head;

    printf("\nenter the node no ");
    scanf("%d",&l);
    nn= create_node(nn);
    if(l==1)
    {
        nn->next=head;
        head->previous=nn;
        head=nn;
    }
    else
    {
        while((c!=l-1)&&traverse!=NULL)
        {
            c++;
            traverse=traverse->next;
        }
        if(traverse==NULL)
            printf("\ninvalid choice\n");
        else
        {
         //   front=traverse->next;
            nn->next=traverse->next;
           nn->previous=traverse;
            if(traverse->next!=NULL)
            (traverse->next)->previous=nn;
             traverse->next=nn;
        }
    }
    return head;
}

struct node* delete_node(struct node *nn,struct node *head)
{
    int choice;
    printf("choose\n 1.delete node in beginning\n 2. delete node from end\n");
    printf("3.delete at location\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        head=delete_beg(nn,head);
    }
    else if(choice==2)
    {
        head=delete_end(nn,head);
    }
    else if(choice==3)
    {
        head=delete_loc(nn,head);
    }
    else
        printf("\ninvalid choice\n");
    return head;
}
struct node* delete_beg(struct node *nn,struct node *head)
{   struct node* traverse;
    traverse=head;
    head=traverse->next;
    if(head!=NULL)
    head->previous=NULL;
    free(traverse);
    return head;
}
struct node* delete_end(struct node *nn,struct node *head)
{
    struct node* traverse;
    traverse=head;
    while(traverse->next!=NULL)
    {  
        traverse=traverse->next;
    }
    if(traverse==head)
    {
        head=NULL;
    }
    else
    {
       (traverse->previous)->next=NULL;
      
    }
    free(traverse);
    return head;
}
struct node* delete_loc(struct node *nn,struct node *head)
{
    struct node  *traverse;
    int c=1,l;
    traverse=head;
    printf("\nenter the node no ");
    scanf("%d",&l);
    if(l==1)
    {
        head=traverse->next;
        if(head!=NULL)
        head->previous=NULL;
        free(traverse);
    }
    else
    {
        while((c!=l)&&traverse!=NULL)
        {
            c++;
            traverse=traverse->next;
        }
        if(traverse==NULL)
            printf("\ninvalid choice\n");
        else
        {
       
            (traverse->previous)->next=traverse->next;
            if((traverse->next)!=NULL)
            (traverse->next)->previous=traverse->previous;
            free(traverse);
        }
    }
    return head;
}
    
