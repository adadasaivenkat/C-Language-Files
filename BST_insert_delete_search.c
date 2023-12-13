#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>


struct node
{
    int data;
    struct node *left,*right;
};


struct node *create(int data)
{
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}


struct node *insert(struct node *root, int data)
{
    if(root==NULL)
    {
        root=create(data);
    }
    else if(data==root->data)
    {
        printf("Cannot insert %d, already in binary search tree!!\n",data);
        exit(1);
    }
    else if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else        // data>root->data
    {
        root->right=insert(root->right,data);
    }
    return root;
}


struct node *min_of(struct node *root)
{
    struct node *temp;
    temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}


struct node *delete(struct node *root, int value)
{
    // Search for the node to be deleted
    if(root==NULL)
    {
        printf("Element %d is not found in the binary search tree!\n",value);
        return root;
    }
    else if(value<root->data)
    {
        root->left=delete(root->left,value);
    }
    else if(value>root->data)
    {
        root->right=delete(root->right,value);
    }
    // Deletion strategy when the node is found
    else
    {
        if(root->left==NULL && root->right==NULL)           // Leaf node i.e., Zero nodes
        {
            free(root);
            root=NULL;
        }
        else if(root->left==NULL)                           // Single node i.e., Right node
        {
            struct node *temp;
            temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL)                          // Single node i.e., Left node
        {
            struct node *temp;
            temp=root;
            root=root->left;
            free(temp);
        }
        else                                                // Two nodes i.e., Both Left and Right nodes
        {
            struct node *temp;
            temp=min_of(root->right);
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
        }
    }
    return root;
}


struct node *search(struct node *root, int key)
{
    if(root==NULL || key==root->data)
    {
        return root;
    }
    else if(key<root->data)
    {
        return search(root->left,key);
    }
    else        // else if(key>root->data)
    {
        return search(root->right,key);
    }
}


void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);          
        printf("%d ",root->data);      
        inorder(root->right);           
    }
}


int main()
{
    struct node *root;
    root=NULL;
    int n,data,i;
    printf("Enter the number of elements in the binary search tree : ");
    scanf("%d",&n);
    printf("Enter the elements of the binary search tree : \n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&data);
        root=insert(root,data);
    }

    printf("Inorder traversal : ");
    inorder(root);
    printf("\n");

    int value;
    printf("Enter the element you want to delete from the binary search tree : ");
    scanf("%d",&value);
    root=delete(root,value);

    printf("Inorder traversal : ");
    inorder(root);
    printf("\n");

    int key;
    printf("Enter the element you want to search in the binary search tree : ");
    scanf("%d",&key);
    struct node *search_ele;
    search_ele=search(root,key);
    if(search_ele!=NULL)
    {
        printf("Element %d is found in the binary search tree!\n",key);
    }
    else
    {
        printf("Element %d is not found in the binary search tree!\n",key);
    }

    return 0;
}