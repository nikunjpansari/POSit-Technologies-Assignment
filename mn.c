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
