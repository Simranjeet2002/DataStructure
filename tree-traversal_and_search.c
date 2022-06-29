#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    char data;
    struct node *left;
    struct node *right;
};
struct node* search_tree(struct node *root,char key);
struct node* create_node(struct node *nn);
struct node* create_tree(struct node *root);
void display_pre(struct node *traverse);
void display_post(struct node *traverse);
void display_in(struct node *root);
int main()
{
    char ele,flag;
    int c;
    struct node *head=NULL,*head1=NULL,*nn,*root=NULL;
    while(1)
    {
        printf("\nchoose \n1.create tree \n2.display tree\n3.search\n\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
        {
            root=create_tree(root);
            break;
        }
        case 2:
        {
            printf("\npost order\n");
            display_post(root);
            printf("\npre order\n");
            display_pre(root);
            printf("\nin order\n");
            display_in(root);
            printf("\n");
            break;
        }
        case 3:
        {
            printf("enter ele to search");
            scanf(" %c",&choice);
            head1 = search_tree(root,choice);
            if(head1==NULL)
                printf("ele not found\n");
            else
                printf("%c found ",head1->data);
            break;
        }
        
        default:
            exit(0);
        }
    }
    return 0;
}

struct node* create_node(struct node *nn)
{
    nn=(struct node *)malloc(sizeof(struct node)) ;
    printf("enter the data\n");
    scanf(" %c",&(nn->data));
    nn->left=nn->right=NULL;

}
struct node* create_tree(struct node *root)
{
    struct node *traverse,*nn;
    int c;
    if(root==NULL)
        root= create_node(nn);
    printf("press 1.to add left child to PARENT %c else press 0\n",root->data);
    scanf("%d",&c);
    if(c==1)
    {
        root->left=create_tree(root->left);
    }
    printf("press 1.to add right child to PARENT %c else press 0\n",root->data);
    scanf("%d",&c);
    if(c==1)
    {
        root->right=create_tree(root->right);
    }

    return root;
}

void display_post(struct node *root)
{
    struct node* r;
    r=root;

    if(root->left!=NULL)
    {
        display_post(root->left);

    }

    if(root->right!=NULL)
    {
        display_post(root->right);

    }
    printf(" %c",root->data);

}
void display_pre(struct node *root)
{
    struct node* r;
    r=root;
    printf(" %c",root->data);
    if(root->left!=NULL)
    {

        display_pre(root->left);
    }
    if(root->right!=NULL)
    {
        display_pre(root->right);
    }
}
void display_in(struct node *root)
{
    struct node* r;
    r=root;

    if(root->left!=NULL)
    {

        display_in(root->left);
    }
    printf(" %c",root->data);
    if(root->right!=NULL)
    {

        display_in(root->right);
    }
}
struct node* search_tree(struct node *root,char key)
{
    struct node* r=NULL;

    if(root->data==key)
    {
        r=root;
    }
    if(root->left!=NULL&&r==NULL)
        r= search_tree(root->left,key);
    if(root->right!=NULL&&r==NULL)
        r=search_tree(root->right,key);
    return r;
}

