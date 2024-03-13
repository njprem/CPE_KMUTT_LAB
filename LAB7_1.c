//66070503421 Nutthawut Jaroenchokwittaya
// Binary search tree Rotate L R LR RL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
} Binarytree;

Binarytree *setroot(int value)
{
    Binarytree *newnode = (Binarytree *)malloc(sizeof(Binarytree));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

int height(Binarytree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return root->height;
    }
}

int max(int a, int b)
{
    if(a > b){
        return a;
    }else{
        return b ;
    }
}

int balanced(Binarytree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return height(root->left) - height(root->right);
    }
}

Binarytree *rotate_right(Binarytree *root)
{
    Binarytree *newroot = root->left;
    Binarytree *temp = newroot->right;
    newroot->right = root;
    root->left = temp;
    root->height = max(height(root->left), height(root->right)) + 1;
    newroot->height = max(height(newroot->left), height(newroot->right)) + 1;
    return newroot;
}

Binarytree *rotate_left(Binarytree *root)
{
    Binarytree *newroot = root->right;
    Binarytree *temp = newroot->left;
    newroot->left = root;
    root->right = temp;
    root->height = max(height(root->left), height(root->right)) + 1;
    newroot->height = max(height(newroot->left), height(newroot->right)) + 1;
    return newroot;
}

Binarytree *insert(Binarytree *root, int value)
{
    if (root == NULL)
    {
        return setroot(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        // Value already exists in the tree
        return root;
    }

    // Update the height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Check balance factor
    int balance = balanced(root);

    // Left rotation
    if (balance > 1 && value < root->left->data)
    {
        return rotate_right(root);
    }
    // Right rotation
    if (balance < -1 && value > root->right->data)
    {
        return rotate_left(root);
    }
    // Left-Right rotation
    if (balance > 1 && value > root->left->data)
    {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }
    // Right-Left rotation
    if (balance < -1 && value < root->right->data)
    {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}

Binarytree *deleted(Binarytree *root, int value)
{
    if (root == NULL)
    {
        printf("Node not found.\n");
        return root;
    }

    if (value < root->data)
    {
        root->left = deleted(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleted(root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            Binarytree *ptr = root->right;
            free(root);
            return ptr;
        }
        else if (root->right == NULL)
        {
            Binarytree *ptr = root->left;
            free(root);
            return ptr;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Binarytree *ptr = root->right;
        while (ptr->left != NULL)
        {
            ptr = ptr->left;
        }

        // Copy the inorder successor's data to this node
        root->data = ptr->data;

        // Delete the inorder successor
        root->right = deleted(root->right, ptr->data);
    }

    // Update height and balance factor after deletion
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = balanced(root);

    // Perform rotations if necessary
    if (balance > 1 && balanced(root->left) >= 0)
    {
        return rotate_right(root);
    }
    if (balance > 1 && balanced(root->left) < 0)
    {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }
    if (balance < -1 && balanced(root->right) <= 0)
    {
        return rotate_left(root);
    }
    if (balance < -1 && balanced(root->right) > 0)
    {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}


void printtree(Binarytree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        printtree(root->left);
        printtree(root->right);
    }
}

int main(void)
{
    Binarytree *root = NULL;
    char choices[10];
    while (1)
    {
        scanf(" %s", choices);
        if (strcmp(choices, "INSERT") == 0)
        {
            int value1;
            while (scanf("%d", &value1) == 1)
            {
                root = insert(root, value1);
            }
        }
        else if (strcmp(choices, "DELETE") == 0)
        {
            int value2;
          while (scanf("%d", &value2) == 1)
          {
              root = deleted(root, value2);
          }
        }
        else if (strcmp(choices, "PRINT") == 0)
        {
            if (root == NULL)
            {
                printf("Tree is empty.\n");
                continue;
            }
            else
            {
                printtree(root);
                printf("\n");
            }

        }
        else if (strcmp(choices, "EXIT") == 0)
        {
            break;
        }
        else{
          printf("Invalid command.\n");
        }
    }
    return 0;
}
