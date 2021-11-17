/**********
*Author : HARISH R SHARMA
*Date : 01/11/2021
*Purpose : Assignment 3 - List Assignments solved using assertions
*/

#ifndef LOGIC_H_INCLUDED
#define LOGIC_H_INCLUDED
#include <stdint.h>
#include <assert.h>

//Single Linked List
typedef struct _node_ Node;
struct _node_
{
    int32_t data;
    Node *next;
};

typedef struct _slist_ Slist;
struct _slist_
{
    Node *head;
    Node *tail;
    uint32_t count;
};

//Doubly Linked List
typedef struct _dnode_ dNode;
struct _dnode_
{
    int32_t data;
    dNode *next;
    dNode *prev;
};

typedef struct _dlist_ Dlist;
struct _dlist_
{
    dNode *head;
    dNode *tail;
    uint32_t count;
};

/* Public interfaces */
Slist slist_new();
uint32_t slist_count(const Slist *list);
Slist* slist_add_node_at_head(Slist *list, int32_t ele);
uint8_t slist_lookup(const Slist *list,int32_t key);
void display_list(const Slist *list);
Slist* slist_add_node_at_tail(Slist *list, int32_t ele);
Slist* delete_node_from_head(Slist *list);
Slist* delete_node_from_tail(Slist *list);
void slist_max_min(const Slist *list,int32_t *max, int32_t *min);
Slist* add_after_specified_element(Slist *list,int32_t key, int32_t ele);
Slist* delete_any_specified_element(Slist *list,int32_t ele);
Slist* reverse_elements_in_the_list(Slist *list,Slist *list1);
int32_t check_if_lists_are_same(Slist *list1,Slist *list2);
Slist* union_of_two_lists(Slist *list1,Slist *list2);
Slist* intersection_of_two_lists(Slist *list1,Slist *list2);
int32_t unique_element_list(Slist *list,int32_t ele);

//Doubly Linked list functions
Dlist dlist_new();
uint32_t dlist_count(const Dlist *list);
Dlist* dlist_add_node_at_head(Dlist *list, int32_t ele);
Dlist* dlist_add_node_at_tail(Dlist *list, int32_t ele);
uint8_t dlist_lookup(const Dlist *list,int32_t key);
void display_dlist(const Dlist *list);
Dlist* dlist_add_after_specified_element(Dlist *list,int32_t key, int32_t ele);
Dlist* delete_dnode_from_head(Dlist *list);
Dlist* delete_dnode_from_tail(Dlist *list);
Dlist* dlist_delete_any_specified_element(Dlist *list,int32_t ele);

#endif // LOGIC_H_INCLUDED
