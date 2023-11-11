#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
struct node
{
    int data;
    struct node *left, *right;
};
// Function to create a binary tree
struct node *create()
{
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    int x;
    printf("Enter data (-1 for no node) : ");
    scanf("%d",&x);
    if(x==-1)
    {
        return NULL;
    }
    else
    {
        new_node->data=x;
        printf("Enter left child of %d : ",x);
        new_node->left=create();
        printf("Enter right child of %d : ",x);
        new_node->right=create();
        return new_node;
    } 
}
// Function to perform preorder traversal
void preorder(struct node *root)
{
    if(root==NULL)      // if(root==0)  // i.e., NULL means zero 
    {
        return;
    }
    else
    {
        printf("%d ",root->data);       // Print the current node's data
        preorder(root->left);           // Traverse the left subtree
        preorder(root->right);          // Traverse the right subtree
    }
}
// Function to perform inorder traversal
void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);            // Traverse the left subtree
        printf("%d ",root->data);       // Print the current node's data
        inorder(root->right);           // Traverse the right subtree
    }
}
// Function to perform postorder traversal
void postorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        postorder(root->left);          // Traverse the left subtree
        postorder(root->right);         // Traverse the right subtree
        printf("%d ",root->data);       // Print the current node's data
    }
}
int main()
{
    struct node *root;
    root=create();

    printf("Preorder traversal : ");
    preorder(root);
    printf("\n");

    printf("Inorder traversal : ");
    inorder(root);
    printf("\n");

    printf("Postorder traversal : ");
    postorder(root);
    printf("\n");

    return 0;
}