#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* create_node(struct node *nn);
struct node* create_list(struct node *nn,struct node *head);
void display_list(struct node *traverse);
void search_list(struct node *traverse);
struct node* insert_node(struct node *nn,struct node *traverse);
struct node* insert_beg(struct node *nn,struct node *head);
struct node* insert_end(struct node *nn,struct node *head);
struct node* insert_loc(struct node *nn,struct node *head);
struct node* delete_node(struct node *nn,struct node *traverse);
struct node* delete_beg(struct node *nn,struct node *head);
struct node* delete_end(struct node *nn,struct node *head);
struct node* delete_loc(struct node *nn,struct node *head);
struct node* move_node(struct node *head);
struct node* swap_node(struct node *head);
int main()
{
    int choice,flag;
    struct node *head=NULL,*head1,*nn;
    do
    {
        printf("\nchoose\n 0.creare list\n1. insert_ele\n 2.display_list \n 3.searching\n 4.delete\n 5.move node\n 6.swap nodes\n 7.EXIT\n");
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
            if(head==NULL)
                printf("\nlist is empty\n");
            else
                head=move_node(head);
            break;
        }
        case 6:
        {
            if(head==NULL)
                printf("\nlist is empty\n");
            else
                head=swap_node(head);
            break;
        }
        case 7:
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
            traverse=nn;
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

struct node* insert_node(struct node *nn,struct node *head)
{
    struct node* traverse;
    int choice;
    printf("choose\n 1.insert node in beginning\n 2. inser node at end\n");
    printf("3.insert at location\n");
    scanf("%d",&choice);
    nn= create_node(nn);
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
    if(head==NULL)
    {
        nn->next=NULL;
        head=nn;
    }
    else
    {
        nn->next=head;
        head=nn;
    }
    return head;
}
struct node* insert_end(struct node *nn,struct node *head)
{
    struct node *traverse;
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
    }
    return head;
}
struct node* insert_loc(struct node *nn,struct node *head)
{
    struct node  *traverse;
    int c=1,l;
    traverse=head;

    printf("\nenter the node no ");
    scanf("%d",&l);
    if(l==1)
    {
        nn->next=head;
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
            nn->next=traverse->next;
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
    free(traverse);
    return head;
}
struct node* delete_end(struct node *nn,struct node *head)
{
    struct node* traverse,*back;
    back=head;
    traverse=head;
    while(traverse->next!=NULL)
    {   back=traverse;
        traverse=traverse->next;
    }
    if(traverse==head)
    {
        head=NULL;
    }
    else
    {
        back->next =NULL;
    }
    free(traverse);
    return head;
}
struct node* delete_loc(struct node *nn,struct node *head)
{
    struct node  *traverse,*back;
    int c=1,l;
    traverse=head;
    printf("\nenter the node no ");
    scanf("%d",&l);
    if(l==1)
    {
        head=traverse->next;
        free(traverse);
    }
    else
    {
        while((c!=l)&&traverse!=NULL)
        {
            c++;
            back=traverse;
            traverse=traverse->next;
        }
        if(traverse==NULL)
            printf("\ninvalid choice\n");
        else
        {
            back->next=traverse->next;
            free(traverse);
        }
    }
    return head;
}
struct node* move_node(struct node *head)
{
    int n,c=1;
    struct node *traverse,*ptr;
    traverse=head;
    printf("\nenter the node no\n");
    scanf("%d",&n);
    for(c=1; (c!=n)&&(traverse!=NULL); c++)
    {
        ptr=traverse;
        traverse=traverse->next;
    }
    if(traverse==NULL)
    {
        printf("\ninvalid position\n");
    }
    else if(traverse!=head)
    {
        ptr->next=traverse->next;
        traverse->next=head;
        head=traverse;
    }
    return head;
}
struct node* swap_node(struct node *head)
{
    int n1,n2,c=1;
    struct node *traverse1,*ptr1,*traverse2,*ptr2,*temp;
     ptr1=NULL;
    ptr2=NULL;
    traverse1=head;
    traverse2=head;
    printf("\nenter the node no's to swap\n");
    scanf("%d",&n1);
    scanf("%d",&n2);
    while((c!=n1)&&(traverse1!=NULL))
    {
        ptr1=traverse1;
        traverse1=traverse1->next;
        c++;
    }
    c=1;
    while((c!=n2)&&(traverse2!=NULL))
    {
        ptr2=traverse2;
        traverse2=traverse2->next;
        c++;
    }
    if(traverse1==NULL||traverse2==NULL)
    {
        printf("\ninvalid node\n");
    }
    else
    {
        if(ptr1==NULL)
        {
            ptr2->next=traverse1;
            head=traverse2;
        }
        else if(ptr2==NULL)
        {
            ptr1->next=traverse2;
            head=traverse1;
        }
        else
        {
            temp=ptr1->next;
            ptr1->next=ptr2->next;
            ptr2->next=temp;
        }
    }
    temp=traverse1->next;
    traverse1->next=traverse2->next;
    traverse2->next=temp;
    return head;
}

