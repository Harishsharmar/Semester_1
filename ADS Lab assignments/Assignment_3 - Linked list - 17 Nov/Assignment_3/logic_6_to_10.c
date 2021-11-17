/**********
*Author : HARISH R SHARMA
*Date : 15/11/2021
*Purpose : Assignment 3 - List Assignments solved using assertions
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include "logic.h"

/*Question 6 : Create two separate single lists. Check two list are same.
                If the two lists have the same number of elements in the same order, then they are treated as same. */
int32_t check_if_lists_are_same(Slist *list1,Slist *list2)
{
    assert(list1!=NULL);
    assert(list2!=NULL);
    Node *temp1, *temp2;
    temp2 = list2->head;
    if(list1->count == list2->count)  // If two lists have different count then they can never be same
    {
        for(temp1=list1->head; temp1!=NULL && temp2!=NULL; temp1=temp1->next, temp2=temp2->next)
            if(temp1->data!=temp2->data)
                return 1;
    }
    return 0;
}

/*Question 7 : Write a method which creates the union of elements from two lists.*/
Slist* union_of_two_lists(Slist *list1,Slist *list2)
{
    assert(list1!=NULL);
    assert(list2!=NULL);
    Slist l3 = slist_new();
    Slist *union_list = &l3;
    Node *cur;
    for(cur=list1->head;cur!=NULL;cur=cur->next)  // Traversing list1 and finding unique elements to add to union_list
    {
        if(!(slist_lookup(union_list,cur->data)))  // if element is not present in union_list, add it.
        {
            slist_add_node_at_tail(union_list,cur->data);
        }
    }
    for(cur=list2->head;cur!=NULL;cur=cur->next)  // Traversing list2 and finding unique elements to add to union_list
    {
        if(!(slist_lookup(union_list,cur->data)))  // if element is not present in union_list, add it.
        {
            slist_add_node_at_tail(union_list,cur->data);
        }
    }

    return union_list;
}

/*Question 8 : Write a method which creates the intersection of elements from two lists.*/
Slist* intersection_of_two_lists(Slist *list1,Slist *list2)
{
    assert(list1!=NULL);
    assert(list2!=NULL);
    Slist l4 = slist_new();
    Slist *intersection_list = &l4;
    Node *cur;
    for(cur=list1->head;cur!=NULL;cur=cur->next)  // Traversing list1
    {
        /* Lookup is done to find whether list1 element is present in list2 or not.
           Also look whether that element is already present in intersection_list or not */
        if((slist_lookup(list2,cur->data)) && !(slist_lookup(intersection_list,cur->data)))
        {
            slist_add_node_at_tail(intersection_list,cur->data);
        }
    }
    return intersection_list;
}

/*Question 9 : Create single list such that it should always contain unique elements.
               Care should be taken that, if element is already present in the list, you should not add it again. */
int32_t unique_element_list(Slist *list,int32_t ele)
{
    assert(list!=NULL);
    if(!(slist_lookup(list,ele))) // if element is not present, then add it. Else ignore it.
        slist_add_node_at_tail(list,ele);

    return 0;
}

/*Question 10 : Create double linked list with methods to add, remove, to check the existence of element */

Dlist dlist_new()
{
    Dlist list={NULL,NULL,0};
    return list;
}

uint32_t dlist_count(const Dlist *list)
{
    assert(list != NULL);
    return list->count;
}

/* Creating a new node to be added to dlist */
static dNode* _get_new_node_(int32_t ele)
{
    dNode * new_node = (dNode*)malloc(sizeof(dNode));
    new_node->data = ele;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

/* Adding new element to dlist at head */
Dlist* dlist_add_node_at_head(Dlist *list, int32_t ele)
{
    assert(list!=NULL);
    dNode* new_node = _get_new_node_(ele);
    new_node->next = list->head;
    new_node->prev = NULL;
    list->head = new_node;
    if(list->tail == NULL)
        list->tail = new_node;
    ++list->count;
    assert(((list->head == list->tail) && (list->count == 1)) || ((list->head != list->tail) && (list->count != 0)));
    return list;
}

/* Adding new element to dlist at tail */
Dlist* dlist_add_node_at_tail(Dlist *list, int32_t ele)
{
    assert(list!=NULL);
    dNode* new_node = _get_new_node_(ele);
    if(list->tail != NULL)
    {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }
    else
        list->head = list->tail = new_node;

    ++list->count;
    assert(((list->head == list->tail) && (list->count == 1)) || ((list->head != list->tail) && (list->count != 0)));
    return list;
}

/* Adding new element to dlist after a specified element */
Dlist* dlist_add_after_specified_element(Dlist *list,int32_t key, int32_t ele)
{
    assert(list!=NULL);
    dNode *cur,*new_node;
    new_node = _get_new_node_(ele);
    for(cur=list->head;cur!=NULL;cur=cur->next)
    {
        if(cur->data == key)
        {
            new_node->next = cur->next;
            new_node->prev = cur;
            cur->next = new_node;
            if(cur == list->tail) // if key is last node, we need to update tail in Dlist after adding new element
                list->tail = new_node;
            ++list->count;
        }
    }
    //display_list(list);
    return list;
}

uint8_t dlist_lookup(const Dlist *list,int32_t key)
{
    assert(list !=NULL);
    dNode *cur;
    for(cur=list->head; cur!=NULL; cur=cur->next)
    {
        if(cur->data == key)
            break;
    }
    return (cur!=NULL);
}

void display_dlist(const Dlist *list)
{
    assert(list != NULL);
    dNode *cur;
    for(cur=list->head; cur!=NULL; cur=cur->next)
        printf("%d ",cur->data);
    printf("\n");
}

/* deleting dNode from head */
Dlist* delete_dnode_from_head(Dlist *list)
{
    assert(list!=NULL);
    dNode *cur;
    if(list->count > 0)
    {
        cur=list->head;
        list->head = cur->next;  // assigning next node's address to Head (because 1st node is getting deleted)
        list->head->prev = NULL;
        if(list->head == NULL)  // only one node in list
        {
            list->tail = NULL;
        }
        --list->count;
        free(cur);
    }
    return list;
}

/* Delete dnode from tail */
Dlist* delete_dnode_from_tail(Dlist *list)
{
    assert(list!=NULL);
    dNode *cur;
    if(list->count > 0)
    {
        if(list->head == list->tail)  // Single dnode in the dlist
        {
            list->head=list->tail=NULL;
        }
        else
        {
            cur = list->tail;
            list->tail = cur->prev;
            list->tail->next = NULL;
        }
        --list->count;
        free(cur);
    }
    return list;
}

/* Delete any specified element from the list */
Dlist* dlist_delete_any_specified_element(Dlist *list,int32_t ele)
{
    assert(list!=NULL);
    dNode *cur,*cur_prev;
    for(cur=list->head;cur!=NULL;cur=cur->next)
    {
        if(cur->data == ele)
            break;           //Finding out the node of element to be deleted
    }

    if(cur==list->head)  // If element to be deleted is in Head node
    {
        list->head = list->head->next;
    }
    else if(cur==list->tail)  // If element to be deleted is in Tail node
    {
        list->tail = list->tail->prev;
    }
    else
    {
        for(cur_prev=list->head;cur_prev->next!=cur;cur_prev=cur_prev->next); // Finding out previous node
        //printf("%d",cur_prev->data);
        cur_prev->next = cur->next;
        cur->next->prev = cur->prev;
    }
    --list->count;
    //display_dlist(list);
    free(cur);
    return list;
}
