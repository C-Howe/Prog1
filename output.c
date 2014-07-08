/* 
   Alexander Schnackenberg
   AS766116    
*/

#include <stdlib.h>
#include "constants.h"
#include "struct_def.h"


/*calculates the height of the tree
the height is equal to the maximum height of the 
subtrees - the root
*/
int height(node *head){
	if (head == NULL){
		return -1;
	}
	else{
		if (height(head->left) >= height(head->right)){ //covers the case if both subtrees are equal
			return height(head->left) + 1;
		}	
		else{
			return height(head->right) + 1;
		}
	}
}

int num_leaves(node *head){
	int is_leaf = 0;	
	if (head == NULL){
		return 0;
	}
	else{
		if((head->left) == NULL && (head->right) == NULL){
			is_leaf = 1;		
		}
		return num_leaves(head->left) + num_leaves(head->right) + is_leaf;
	}
}

int num_strings(node *head){
	if (head == NULL){
		return 0;
	}
	else{
		return num_strings(head->left) + num_strings(head->right) + 1;
	}
}

