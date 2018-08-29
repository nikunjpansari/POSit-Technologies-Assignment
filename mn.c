/* Program to check children sum property */
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has value, left child and right child */
struct node
{
	int value;
	struct node* left;
	struct node* right;
	String data;
	int nodeNumber;
	String nodeId;
	String referenceNodeId;
	String childReferenceNodeId;
	String genesisReferenceNodeId;
	String HashValue;
};

struct node *root;

typedef struct node bt;

bt *new,*ptr,*ptr1,*ptr2;
bt* create()

{

    new = (bt *)malloc(sizeof(bt));

    new->left = NULL;

    new->right = NULL;

    return new;

}
void construct_binary_tree()

{

    root = create();

    root->value = 50;

 

    ptr = create();

    root->left = ptr;

    ptr->value = 20;

 

    ptr1 = create();

    ptr->left = ptr1;

    ptr1->value = 70;

 

    ptr2 = create();

    ptr1->left = ptr2;

    ptr2->value = 10;

 

    ptr2 = create();

    ptr1->right = ptr2;

    ptr2->value = 40;

 

    ptr1 = create();

    ptr->right = ptr1;

    ptr1->value = 80;

 

    ptr2 = create();

    ptr1->right = ptr2;

    ptr2->value = 60;

 

    ptr = create();

    root->right = ptr;

    ptr->value = 30;

}


    int depth1 = 0, depth2 = 0;

 

    construct_binary_tree();

    ptr = root;

    while (ptr->l != NULL || ptr->r != NULL)

    {

        depth1++;

        if (ptr->l == NULL)

            ptr = ptr->r;

        else

            ptr = ptr->l;

    }

    ptr = root;    

    while (ptr->l != NULL || ptr->r != NULL)

    {

        depth2++;

        if (ptr->r == NULL)

            ptr = ptr->l;

        else

            ptr = ptr->r;

    }

/*

 *DEPTH IS CONSIDERED FROM LEVEL-0 ALSO HEIGHT IS CONSIDERED AS NUMBER OF EDGES

 */

    if (depth1 > depth2)

        printf("height of the tree is %d\ndepth of the tree is %d",depth1,depth1);

    else    

        printf("height of the tree is %d\ndepth of the tree is %d",depth2,depth2);


/* returns 1 if children sum property holds for the given
	node and both of its children*/
int isSumProperty(struct node* node)
{
/* left_value is left child value and right_value is for right 
	child value*/
int left_value = 0, right_value = 0;

/* If node is NULL or it's a leaf node then
	return true */
if(node == NULL ||
	(node->left == NULL && node->right == NULL))
	return 1;
else
{
	/* If left child is not present then 0 is used
	as value of left child */
	if(node->left != NULL)
	left_value = node->left->value;

	/* If right child is not present then 0 is used
	as value of right child */
	if(node->right != NULL)
	right_value = node->right->value;

	/* if the node and both of its children satisfy the
	property return 1 else 0*/
	if((node->value == left_value + right_value)&&
		isSumProperty(node->left) &&
		isSumProperty(node->right))
	return 1;
	else
	return 0;
}
}
