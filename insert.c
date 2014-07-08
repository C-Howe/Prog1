/* 
   Alexander Schnackenberg
   AS766116    
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "constants.h"
#include "struct_def.h"

void insert(char string[], node **head){
	node *temp;
	//START ERROR
	if (*head == NULL){
		if ((temp = (node *)malloc(sizeof(node))) == NULL){ 
					printf("Node allocation failed. \n");
					exit(1); //stop program
		}
		*head = temp;
		//END ERROR		 
	}	
	if ((*head)->string[0] == '\0'){ 
		strcpy((*head)->string,string);
	}
	else{ 
		if (strcmp(string, (*head)->string) < 0){ //if string is less than root 
			insert(string, &((*head)->left)); //insert string into left subtree		
		} 
		else{ 
			insert(string, &((*head)->right)); //insert string into right subtree
		} 	
	} 
} 


