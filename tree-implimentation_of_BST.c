#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* search_tree(struct node *root,int key);
struct node* create_node(struct node *nn,int ele);
struct node* insert_tree(struct node *root,int ele);
struct node* delete_tree(struct node *root,int ele);
struct node* parent(struct node* root,int ele);
struct node* successor(struct node* root,int ele);
void display_pre(struct node *traverse);
void display_post(struct node *traverse);
void display_in(struct node *root);
int main()
{
    int ele, c,choice;
    struct node *root=NULL,*head,*p;
    while(1)
    {
        printf("\nIN BST \nchoose \n1.insert\n2.display tree\n3.search\n4.delete\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
        {
            printf("\nenter the data u want to insert\n");
            scanf("%d",&ele);
            root=insert_tree(root,ele);
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
            printf("\nenter ele to search");
            scanf("%d",&ele);
            head= search_tree(root,ele);
            if(head==NULL)
                printf("\nele not found\n");
            else
            {
                p=parent(root,ele);
                if(p!=NULL)
                    printf("\n%d found having parent %d\n",head->data,p->data);
                else
                    printf("%d found at root",head->data);
            }
            break;
        }
        case 4:
        {
            printf("\nenter ele to delete");
            scanf("%d",&ele);
            root=delete_tree(root,ele);
            break;
        }
        default:
            exit(0);
        }
    }
    return 0;
}

struct node* create_node(struct node *nn,int ele)
{
    nn=(struct node *)malloc(sizeof(struct node)) ;
    nn->data=ele;
    nn->left=nn->right=NULL;
}
struct node* insert_tree(struct node *root,int ele)
{
    struct node *traverse,*nn;
    int c;
    if(root==NULL)
        root= create_node(nn,ele);
    else if(ele<root->data)
        root->left=insert_tree(root->left,ele);
    else  if(ele>root->data)
        root->right=insert_tree(root->right,ele);
    return root;
}

void display_post(struct node *root)
{
    if(root->left!=NULL)
        display_post(root->left);
    if(root->right!=NULL)
        display_post(root->right);
    printf(" %d",root->data);

}
void display_pre(struct node *root)
{
    printf(" %d",root->data);
    if(root->left!=NULL)
        display_pre(root->left);
    if(root->right!=NULL)
        display_pre(root->right);
}
void display_in(struct node *root)
{
    if(root->left!=NULL)
        display_in(root->left);
    printf(" %d",root->data);
    if(root->right!=NULL)
        display_in(root->right);
}
struct node* search_tree(struct node *root,int ele)
{
    struct node* r;
    r=NULL;
    if(root->data==ele)
    {
        r=root;
    }
    /* if(root->left==ele||root->right==ele)
     {
         r[1]= root;
     }*/
    if(ele<root->data&&root->left!=NULL&&r==NULL)
        r= search_tree(root->left,ele);
    if(ele>root->data&&root->right!=NULL&&r==NULL)
        r=search_tree(root->right,ele);
    return r;
}
struct node* parent(struct node* root,int ele)
{     struct node* r=NULL;
       if(root==NULL)
       return root;
      else if((root->left!=NULL&&root->left->data==ele)||(root->right!=NULL&&root->right->data==ele))
      { 
       r=root;
      }
   else 
   {
    if(ele<root->data&&root->left!=NULL&&r==NULL)
    r= parent(root->left,ele);
    else (ele>root->data&&root->right!=NULL&&r==NULL)
    r= parent(root->right,ele);
    }
    return r;
}
struct node* successor(struct node* root,int ele)
{
    root=search_tree(root,ele);
    root=root->right;
    if(root!=NULL)
    {
        for(; root->left!=NULL; root=root->left)
        {
        }
    }
    return root;
}
struct node* delete_tree(struct node *root,int ele)
{
    struct node *p=NULL,*r=root,*ps=NULL,*s=NULL;
    p=parent(root,ele);
    root=search_tree(root,ele);
    if(root->left==NULL&&root->right==NULL)
    {
        if(p->left->data==ele)
            p->left=NULL;
        else if(p->right->data==ele)
            p->right=NULL;
        free(root);
    }
    else if(root->left==NULL||root->right==NULL)
    {
       
        if(p->left!=NULL&&p->left->data==ele)
        {
            if(root->right==NULL)
                p->left=root->left;
            else if(root->left==NULL)
                p->left=root->right;
        }        
        else if(p->right!=NULL&&p->right->data==ele)
        {
            if(root->right==NULL)
                p->right=root->left;
            else if(root->left==NULL)
                p->right=root->right;
        }
        free(root);
    }
    else if(root->left!=NULL&&root->right!=NULL)
    {
    s=successor(root,ele);
    ps=parent(r,s->data);
    root->data=s->data;
    if(root->right==s)
     root->right=s->right;
    else
    ps->left=s->right;
    free(s);   
    }
    return r;
    
}