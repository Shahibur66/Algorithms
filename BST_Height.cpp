#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data; 
    struct node *right_child; 
    struct node *left_child; 
};

struct node* new_node(char data)
{
    struct node *p; 
    p =(struct node*)malloc(sizeof(struct node)); 
    p->data = data; 
    p->left_child = NULL; 
    p->right_child = NULL;

    return(p); 
}

void preorder(struct node *root)
{
    if(root!=NULL) 
    {
        printf(" %c ", root->data); 
        preorder(root->left_child); 
        preorder(root->right_child); 
    }
}

void postorder(struct node *root)
{
    if(root!=NULL) 
    {
        postorder(root->left_child); 
        postorder(root->right_child); 
        printf(" %c ", root->data); 
    }
}

void inorder(struct node *root)
{
    if(root!=NULL) 
    {
        inorder(root->left_child); 
        printf(" %c ", root->data);
        inorder(root->right_child);
    }
}

int is_leaf(struct node *a)
{
    if(a->right_child==NULL && a->left_child==NULL)
        return 1;
    return 0;
}

int get_max(int a, int b)
{
    return (a>b) ? a : b;
}

int get_height(struct node *a)
{
    if(a==NULL || is_leaf(a)) 
        return 0;
    return(get_max(get_height(a->left_child), get_height(a->right_child)) + 1);
    //return get_height(a->left_child)+get_height(a->right_child) + 1;
}

int main()
{
    struct node *root; //new structure
    root = new_node('D'); 

    root->left_child = new_node('A'); 


    root->right_child = new_node('F'); 

    root->left_child->left_child = new_node('E'); 


    root->left_child->right_child = new_node('B'); 

    printf("Preorder: \n");
    preorder(root);
    printf("\n");
    printf("Postorder: \n");
    postorder(root);
    printf("\n");
    printf("Inorder: \n");
    inorder(root);
    printf("\n");
    printf("Height: ");
    printf("%d\n", get_height(root));

    return 0;
}


/*
                     ____
                    |  D |
                   /|____|\
             ____ /       _\___
            |  A |        |  F |
           /|____|\       |____|
      ____/       _\___
     |  E |      |   B |
     |____|      |_____|


*/