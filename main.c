#include <stdlib.h>
#include <stdio.h>
#include "list.h"


void print_node(struct Node *n){
	printf(" '%c'",n->data);
}

void print_list(struct Node *root){

	if(root==NULL){printf(" NULL\n");return;}

	//printf(" R");

	while(root->next != NULL){
		root = root->next;
		print_node(root);
	}
	printf("\n");
}

void test_basic(){
	struct Node *root,*n;

	root                         = node_create(' ');
	root->next                   = node_create('l');
	root->next->next             = node_create('i');
	root->next->next->next       = node_create('s');
	root->next->next->next->next = node_create('t');

	printf("initial list: \n");
	print_list(root);

	printf("\nnode_remove 0 : \n");
	node_remove(root,0);
	print_list(root);
	
	printf("\nnode_push 's' : \n");
	node_push(root,node_create('s'));
	print_list(root);

	printf("\nnode_pop: \n");
	struct Node *p = node_pop(root);
	print_list(root);
	printf("\npopped: \n");
	print_node(p);

	printf("\n\nnode_get 2:\n");
	p = node_get(root,2);
	print_node(p);
	printf("\n\n");

}

// Convert a string to a linked list!
struct Node *test_string(char *str){

	printf("test_string:\n");

	struct Node *root,*last;
	root = node_create('R');
	last = root;

	int i = 0;
	while(str[i] != '\0'){
		last->next = node_create(str[i++]);
		last = last->next;
	}
	last->next = NULL;

	return root;
}

void test(){

	test_basic();

	print_list(test_string("Hello World"));
}

int main(int argc , char **argv)
{

	test();	

	return(0);
} 