//implimentation of heap using linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *q[50]= {NULL};
int i=-1;
struct node* search_tree(struct node *root,int key);
struct node* create_node(struct node *nn,int ele);
struct node* insert_tree(struct node *root,int ele);
struct node* delete_tree(struct node *root);
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
            scanf(" %d", &ele);

            root=insert_tree(root,ele);
            break;
        }
        case 2:
        {
            //  for(choice=0;choice<=i;choice++)
            //  printf("%d",q[choice]->data);
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
            root=delete_tree(root);
            break;
        }
        default:
            exit(0);
        }
    }
    return 0;
}

struct node* create_node(struct node *root,int ele)
{
    struct node *nn,*s;
    int k;
    nn=(struct node *)malloc(sizeof(struct node)) ;
    nn->data=ele;
    nn->left=nn->right=NULL;
    
    if(root==NULL)
    {
        root=nn;
        i++;
        q[i]=root;
        return root;
    }
    else if(q[i]->left==NULL)
    {
        q[i]->left=nn;
        k=2*i+1;
        q[k]=nn;
    }
    else if(q[i]->right==NULL)
    {
        q[i]->right=nn;
        k=2*i+2;
        q[k]=nn;
    }
    return nn;
}


struct node* insert_tree(struct node *root,int ele)
{
    struct node *nn,*pos, *par;
    int key,f=1;
    if(i!=-1&&q[i]->right!=NULL)
       i=i+1;
    if(root==NULL)
    {
        root=create_node(root,ele);
    }
    else
    {
        pos=create_node(root,ele);
        while(pos!=root)
        {
            par=parent(root,pos->data);

            if(pos->data>par->data)
            {
                key=par->data;
                par->data=pos->data;
                pos->data=key;
                pos=par;
            }
            else
                break;
        }
    }
    return root;
}
struct node* delete_tree(struct node *root)
{   int key;
    struct node *p=NULL,*r=root,*par;
    if(root==NULL)
        printf("its empty\n");
    else if(root->left==NULL&&root->right==NULL)
    {
        free(root);
        i=0;
        printf("deleted %d",root->data);
        return NULL;
    }
    else
    {
        if(q[2*i+2]!=NULL)
        {
            p=q[2*i+2];
            q[2*i+2]=NULL;
        }
        else
        {
            p=q[2*i+1];            
            q[2*i+1]=NULL;
        }
        key=p->data;
        p->data=root->data;
        root->data=key;
         par=parent(root,p->data);
         if(par->left==p)
        {
         par->left=NULL;   
        i--; 
        } 
        else
         par->right=NULL;
        printf("deleted %d",p->data);       
       free(p);
        while(root->left!=NULL)
        {
            if(root->right!=NULL&&root->right->data>root->left->data)
            {
                p=root->right;
            }
            else
                p=root->left;
            key=p->data;
            p->data=root->data;
            root->data=key;
            root=p;
        }      
    }
    return r;

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
    if(root->left!=NULL&&r==NULL)
        r= search_tree(root->left,ele);
    if(root->right!=NULL&&r==NULL)
        r=search_tree(root->right,ele);
    return r;
}
struct node* parent(struct node* root,int ele)
{   struct node* r=NULL;
    if(root==NULL)
        return root;
    if((root->left!=NULL&&root->left->data==ele)||(root->right!=NULL&&root->right->data==ele))
        r=root;
    else
    {
        if(root->left!=NULL&&r==NULL)
            r= parent(root->left,ele);
        if(root->right!=NULL&&r==NULL)
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
    
