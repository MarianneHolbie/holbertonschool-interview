# Double Circular Linked List

A double circular linked list is a linked data structure that consists of a set of sequentially linked records called nodes. Each node contains two fields, called links, that are references to the previous and to the next node in the sequence of nodes. The beginning and ending nodes' previous and next links, respectively, point to some sentinel node or null to facilitate traversal of the list. If there is only one sentinel node, then the list is circularly linked via the sentinel node. A double circular linked list is a circular linked list where the last node links to the first node and the first node links to the last node.

## TASK

Create the source file `0-add_node.c` that contains the following functions:

- Add a new node to **the end** of a double circular linked list:
    - Prototype: `List *add_node_end(List **list, char *str);`
        - `List`: the list to modify
        - `str`: the string to copy into the new node
        - Returns: Address of the new node, or NULL on failure
- Add a new node to **the beginning** of a double circular linked list:
    - Prototype: `List *add_node_begin(List **list, char *str);`
    - `List`: the list to modify
        - `str`: the string to copy into the new node
        - Returns: Address of the new node, or `NULL` on failure
        