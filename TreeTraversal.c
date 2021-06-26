#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};
struct node *create()
{
    int x;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nenter value(enter  -1 for no node):\t");
    scanf("%d",&x);
    if(x==-1)
    {
        return 0;
    }
    newnode->data=x;
    printf("\nenter the left child of %d",x);
    newnode->left=create();
    printf("\nenter the right child of %d",x);
    newnode->right=create();
    return newnode;
}
void display(struct node *r,int l)
{
	int i;
	if(!r) return ;
	display(r->right,l+1);
	for(i=0;i<l;++i)
		printf(" ");
	printf("%d \n",r->data);
	display(r->left,l+1);


}
void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    printf("\t%d",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("\t%d",root->data);
    inorder(root->right);
    
}
void postorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("\t%d",root->data);
}
void main()
{
    struct node *root;
    root=0;
    root=create();
    
    printf("\nthe preorder is :\n");
    preorder(root);
    printf("\nthe inorder is :\n");
    inorder(root);
    printf("\nthe postorder:\n");
    postorder(root);
}
