# list.h


A Linked List implimentation in C.


With a small library of functions for manipulating lists.


Example of use in `main.c`.


## Documentation


### `node_create`


parameters: `int d`


returns: `struct Node *`


description: allocates memory for a `struct Node` on the heap and returns a `struct Node *` to it


### `node_push`


parameters: `struct Node *root`, `struct Node *n`


returns: `int`


description: appends `struct Node *n` to the end of list `struct Node *root`


### `node_pop`


parameters: `struct Node *root`


returns: `struct Node *` or `NULL`


description: removes and returns the last `struct Node *` in list `struct Node *root` or `NULL` if `root` was empty or `NULL`


### `node_count`


parameters: `struct Node *root`


returns: `int`


description: returns the number of nodes in list `struct Node *root`, or `-1` if `root` is `NULL`


### `node_remove`


parameters: `struct Node *root`, `int index`


returns: `struct Node *root` or `NULL`


description: removes the node at `int index` of `struct Node *root` by linking the previous node to the next node, returns the removed node if or `NULL` if it could not be found


### `node_get`


parameters: `struct Node *root`, `int index`


returns: `struct Node *root` or `NULL`


description: returns the node at `int index` of `struct Node *root` or `NULL` if it could not be found

