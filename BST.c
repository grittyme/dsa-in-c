#include <stdio.h>
#include <stdlib.h>

struct node {
   int data; 
	
   struct node *leftChild;
   struct node *rightChild;
};

struct node *root = NULL;

void insert(int data) {
	
	struct node *tempNode = (struct node*)malloc(sizeof((struct node)));
	struct node *current = NULL;
	struct node *parent = NULL;
	
	tempNode->data = data;
	tempNode->leftChild = NULL ;
	tempNode->rightChild = NULL ;
	
	/* if tree is empty */
	if (root == NULL)
	{
		/* Create a root node */
		root = tempNode;
	}
	else
	{
		current = root;
		while(1)
		{
			parent = current;
			if(tempNode->data <= parent->data)
			{
				/* go to left subtree 	 */
				current = current->leftChild;
				/*insert node */
				if(current == NULL)
				{
					parent->leftChild = tempNode;
					return;
				}			
			}
			else
			{
				/* go to right subtree 	 */
				current = current->rightChild;
				/*insert node */
				if(current == NULL)
				{
					parent->rightChild = tempNode;
					return;
				}
			}
			
		}
		
	}
	

}