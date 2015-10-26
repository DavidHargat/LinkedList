#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

#include <stdlib.h>

/* @Author David Hargat */

/*
* Basic Explanation of Linked Lists:
* 	A Linked List is a data structure
* 	where a list is made up of linked
* 	nodes. Each node points to either
* 	the next node in the list, or to
* 	NULL (the end of the list). The
* 	first node in a Linked List is 
* 	called the 'root' or 'head' node 
* 	and usually does not contain 
* 	important data
* 	(other than a link to the next node).
*
* Example:
* 	R->A->B->C->NULL
*
* In the above example, R (the root)
* points to A, A points to B and so on.
* The final node 'C' point to NULL.
*
* Note:
* 	This implementation contains checks for
* 	undefined behavior and should be mostly
* 	'safe' (won't cause seg faults if you mess up).
* 	For example if you try to node_get(root,3) where
* 	root only has 2 children, it will return NULL.
*/

struct Node {
	struct Node *next;
	int data;
};

int node_count(struct Node *root);
signed char node_push(struct Node *root, struct Node *n);
struct Node *node_create(int d);
struct Node *node_pop(struct Node *root);
struct Node *node_get(struct Node *root, int index);
struct Node *node_remove(struct Node *root, int index);

/* Allocates a Node on the heap.
*/
struct Node *node_create(int d){
	struct Node *n;
	n = malloc(sizeof(struct Node));
	n->data = d;
	n->next = NULL;
	return n;
}

/*
* Counts how many children a Node has by traversing until it finds a pointer
* to NULL.
*/
int node_count(struct Node *root){
	if( root == NULL ) return -1; // If the given node is NULL return error
	if( root->next == NULL ) return 0; // If there are no children return 0

	struct Node *next;
	next = root->next;

	int counter = 0;
	// Iterate until we hit the last node (where next is null)
	while( next != NULL ){
		next = next->next;
		counter++;
	}

	return counter;
}

/* Adds a node to the end of the list
*  returns 1 if successful, -1 if not successful.
*/
signed char node_push(struct Node *root, struct Node *n){
	if( root == NULL ) return -1;

	if( root->next == NULL){
		root->next = n;
		return 1;
	}

	struct Node *next = root->next;
	while( next->next != NULL ){
		next = next->next;
	}

	next->next = n;
	return 1;
}

/* Removes the last node in the list
*  returns said node if successful. NULL if not successful. (list was empty, root was NULL, etc.)
*/
struct Node *node_pop(struct Node *root){
	if( root == NULL ) return NULL; // can't pop if root is NULL
	if( root->next == NULL) return NULL; // can't pop if root has no children

	struct Node *before, *popped;
	before = root->next;

	if( before->next == NULL){
		root->next = NULL;
		return before;
	}

	popped = before->next;
	
	while( popped->next != NULL ){
		before = popped;
		popped = popped->next;
	}

	before->next = NULL;
	return popped;	
}

/* Find the Nth (index) node in a list.
*  If the list contains N return it, else return NULL.
*/
struct Node *node_get(struct Node *root, int index){
	if( root == NULL ) return NULL; // If the given node is NULL return NULL
	if( root->next == NULL ) return NULL; // If there are no children return NULL

	struct Node *next;
	next = root->next;

	int counter = 0;
	// Iterate until we hit the last node (where next is null)
	while( next != NULL ){
		if( counter == index ) return next;
		next = next->next;
		counter++;
	}

	return NULL;
}

/* Where 0 is the index of the first child of Node root. 
 * Removes the Nth (index) child of root
 * by pointing [index-1] to [index+1]. 
 *
 * Returns the removed node on success, NULL on error (the child or root was null).
 *
 * Example:
 *	list before: r->a->b->c->NULL
 * 	node_remove(r,1)
 * 	list after: r->a->c->NULL
 */
struct Node *node_remove(struct Node *root, int index){
	if( root == NULL) return NULL;
	if( index < 0 ) return NULL;

	struct Node *node_before, *node_remove;
	node_before = root;

	// If index is not 0, iterate through the list to find [index]
	if(index != 0){
		int i = -1;
		// If we haven't found the index, or hit the end of the list.
		while( i < (index-1) && node_before != NULL ){
			node_before = node_before->next; // Find the next element.
			i++;
		}
		if( i != (index-1) || node_before == NULL) return NULL;
	}
	
	if( node_before->next == NULL ) return NULL;

	node_remove = node_before->next;

	// If the node to remove was the last node
	if( node_remove->next == NULL ){
		node_before->next = NULL; // set the index-1 node->next to NULL
	}else{
		node_before->next = node_remove->next; // else [index-1]->next=[index+1]
	}

	return node_remove; // Success
}



#endif