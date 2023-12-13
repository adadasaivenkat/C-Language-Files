#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

struct node
{
    int data;
    struct node *left, *right;
};

//Finding height
int height(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left_height=height(root->left);
    int right_height=height(root->right);
    return (left_height > right_height ? left_height : right_height) + 1;
}

//Balance Factor
int balance_factor(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return height(root->left)-height(root->right);
    }
}

//Right rotation
struct node *right_rotate(struct node *root)
{
    struct node *temp_1, *temp_2;
    temp_1=root->left;
    temp_2=temp_1->right;
    temp_1->right=root;
    root->left=temp_2;
    return temp_1;
}

//Left rotation
struct node *left_rotate(struct node *root)
{
    struct node *temp_1, *temp_2;
    temp_1=root->right;
    temp_2=temp_1->left;
    temp_1->left=root;
    root->right=temp_2;
    return temp_1;
}

//Create function
struct node *create(int data)
{
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

//Insert function
struct node *insert(struct node *root, int data)
{
    //BST Insertion logic
    if(root==NULL)
    {
        return create(data);        //root=create(data);
    }
    else if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=insert(root->right,data);
    }
    else    //if(data==root->data)  //Duplicate values are not allowed...
    {
        printf("Cannot insert %d, already in the AVL tree!\n",data);
        exit(1);
    }
    int balance;
    balance=balance_factor(root);       // Other than {-1,0,1} then, the tree is unbalanced...
    //Left Heavy
    if(balance>1)
    {
        //Left-Left Case --> Right-Right rotation
        if(data<root->left->data)
        {
            return right_rotate(root);
        }
        //Left-Right Case --> Left-Right rotation
        else if(data>root->left->data)
        {
            root->left=left_rotate(root->left);
            return right_rotate(root);
        }
    }
    //Right Heavy
    if(balance<-1)
    {
        //Right-Right Case --> Left-Left rotation
        if(data>root->right->data)
        {
            return left_rotate(root);
        }
        //Right-Left Case --> Right-Left rotation
        else if(data<root->right->data)
        {
            root->right=right_rotate(root->right);
            return left_rotate(root);
        }
    }
    return root;
}

//Minimum element in the right sub-tree
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

//Deletion Function
struct node *delete(struct node *root, int value)
{
    // Search for the node to be deleted
    if(root==NULL)
    {
        printf("Element %d is not found in the AVL tree!\n",value);
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
    //Deletion strategy when the node is found
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
    //Balancing the tree after deleting the node
    int balance;
    balance=balance_factor(root);
    //Left Heavy
    if(balance>1)
    {
        //Left-Left Case --> Right-Right rotation
        if(balance_factor(root->left)>=0)
        {
            return right_rotate(root);
        }
        //Left-Right Case --> Left-Right rotation
        else if(balance_factor(root->left)<0)
        {
            root->left=left_rotate(root->left);
            return right_rotate(root);
        }
    }
    //Right Heavy
    if(balance<-1)
    {
        //Right-Right Case --> Left-Left rotation
        if(balance_factor(root->right)<=0)
        {
            return left_rotate(root);
        }
        //Right-Left Case --> Right-Left rotation
        else if(balance_factor(root->right)>0)
        {
            root->right=right_rotate(root->right);
            return left_rotate(root);
        }
    }
    return root;
}

//Preoder traversal
void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        printf("%d ",root->data);
        preorder(root->left);                
        preorder(root->right);           
    }
}

//Main function
int main()
{
    struct node *root=NULL;
    int n,data,i;
    printf("Enter the number of elements in the AVL tree : ");
    scanf("%d",&n);
    printf("Enter the elements of the AVL tree : \n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&data);
        root=insert(root,data);
    }
    printf("Preorder traversal : ");
    preorder(root);
    printf("\n");
    int value;
    printf("Enter the element you want to delete from the AVL tree : ");
    scanf("%d",&value);
    root=delete(root,value);
    printf("Preorder traversal : ");
    preorder(root);
    printf("\n");
    return 0;
}