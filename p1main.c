/* 
   Alexander Schnackenberg
   AS766116    
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "constants.h"
#include "struct_def.h"
#include "prototypes.h"

int main(int argc, char *argv[]){
	node *head = NULL;
	FILE *input_file = NULL;
	FILE *output_file = NULL;
	char input_string[INPUT_SIZE];
	
	/*check number of arguments passed in */
	if (argc != ARGNUM){
		fprintf(stderr, "Wrong number of input arguments \n");
		exit(1);
	}
	
	if ((input_file = fopen(argv[INFILE], "r")) == NULL){
		fprintf(stderr, "Input file could not be opened \n");
		exit(1);
	}

	if ((output_file = fopen(argv[OUTFILE], "w")) == NULL){
		fprintf(stderr, "Output file could not be opened \n");
		exit(1);
	}

	/*read file, create bst*/
	while(fscanf(input_file, "%s", input_string) != EOF){
		insert(input_string, &head);
	}
	
	/*create requisite output*/
	fprintf(output_file, "%s %-d \n", "No. of strings in the input file    = ", num_strings(head));
	fprintf(output_file, "%s %-d \n", "Height of the search tree           = ", height(head));
	fprintf(output_file, "%s %-d \n", "Number of leaves in the tree        = ", num_leaves(head));
	
	//recursive function for height returns -1 if tree is empty, should instead output 0
	if (height(head->left) == -1){
		fprintf(output_file, "%s %-d \n", "Height of the left subtree of root  = ", 0);
	}
	else{
		fprintf(output_file, "%s %-d \n", "Height of the left subtree of root  = ", height(head->left));
	}
	fprintf(output_file, "%s %-d \n", "No. of strings in the left subtree  = ", num_strings(head->left));

	//again, if height returns -1, the tree is really empty and so should output 0	
	if (height(head->right) == -1){
		fprintf(output_file, "%s %-d \n", "Height of the right subtree of root = ", 0);
	}
	else{
		fprintf(output_file, "%s %-d \n", "Height of the right subtree of root = ", height(head->right));
	}	
	
	fprintf(output_file, "%s %-d \n", "No. of strings in the right subtree = ", num_strings(head->right));

return 0;
}
