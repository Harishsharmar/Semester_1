/**********
*Author : HARISH R SHARMA
*Date : 01/11/2021
*Purpose : Assignment 3 - List Assignments solved using assertions
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include "logic.h"

/*Question 1 : Create a single list with methods to add and delete elements from head and tail positions.
               Provide method to check whether an element is present in the list. Count number of elements in the list.*/

/* Create new empty list */
Slist slist_new()
{
    Slist list={NULL,NULL,0};
    return list;
}

/* Finding the count of the list */
uint32_t slist_count(const Slist *list)
{
    assert(list != NULL);
    return list->count;
}

/* Creating a new node to be added to list */
static Node* _get_new_node_(int32_t ele)
{
    Node * new_node = (Node*)malloc(sizeof(Node));
    new_node->data = ele;
    new_node->next = NULL;
    return new_node;
}

/* Adding new element to list at head */
Slist* slist_add_node_at_head(Slist *list, int32_t ele)
{
    assert(list!=NULL);
    Node* new_node = _get_new_node_(ele);
    new_node->next = list->head;
    list->head = new_node;
    if(list->tail == NULL)
        list->tail = new_node;
    ++list->count;
    assert(((list->head == list->tail) && (list->count == 1)) || ((list->head != list->tail) && (list->count != 0)));
    return list;
}
/* To check whether the element is successfully added to the list or not */
uint8_t slist_lookup(const Slist *list,int32_t key)
{
    assert(list !=NULL);
    Node *cur;
    for(cur=list->head; cur!=NULL; cur=cur->next)
    {
        if(cur->data == key)
            break;
    }
    return (cur!=NULL);
}

/* Display the list */
void display_list(const Slist *list)
{
    assert(list != NULL);
    Node *cur;
    for(cur=list->head; cur!=NULL; cur=cur->next)
        printf("%d ",cur->data);
    printf("\n");
}

/* Adding new element to list at tail */
Slist* slist_add_node_at_tail(Slist *list, int32_t ele)
{
    assert(list!=NULL);
    Node* new_node = _get_new_node_(ele);
    if(list->tail != NULL)
    {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    else
        list->head = list->tail = new_node;

    ++list->count;
    assert(((list->head == list->tail) && (list->count == 1)) || ((list->head != list->tail) && (list->count != 0)));
    return list;
}

/* deleting node from head */
Slist* delete_node_from_head(Slist *list)
{
    assert(list!=NULL);
    Node *cur;
    if(list->count > 0)
    {
        cur=list->head;
        list->head = cur->next;  // assigning next node's address to Head (because 1st node is getting deleted)
        if(list->head == NULL)  // only one node in list
        {
            list->tail = NULL;
        }
        --list->count;
        free(cur);
    }
    return list;
}

/* Delete node from tail */
Slist* delete_node_from_tail(Slist *list)
{
    assert(list!=NULL);
    Node *cur,*last;
    if(list->count > 0)
    {
        last = list->tail;
        if(list->head == list->tail)  // Single node in the list
        {
            list->head=list->tail=NULL;
        }
        else
        {
            for(cur=list->head; cur->next!=last; cur=cur->next); // Traversing the list until last but one node (LBO node)
            cur->next = NULL; // This is done because last node is getting deleted. So LBO node's 'Next' will point to NULL (i.e LBO node now becomes Last node)
            list->tail = cur;
        }
        --list->count;
        free(last);
    }
    return list;
}
/*-----------------------------------------------------------------------------------------------------*/
//Question 2 : Add methods to Q1 to find maximum and minimum elements in the list.
void slist_max_min(const Slist *list,int32_t *max, int32_t *min)
{
    assert(list!=NULL);
    Node *cur;
    cur = list->head;
    *max = *min = cur->data;
    for(cur=list->head;cur!=NULL;cur=cur->next)
    {
        if(cur->data > *max)
            *max = cur->data;
        if(cur->data < *min)
            *min = cur->data;
    }
}
/*------------------------------------------------------------------------------------------------------*/
//Question 3 : Modify Q1 such that one can add a new element after any specified element.
Slist* add_after_specified_element(Slist *list,int32_t key, int32_t ele)
{
    assert(list!=NULL);
    Node *cur,*new_node;
    new_node = _get_new_node_(ele);
    for(cur=list->head;cur!=NULL;cur=cur->next)
    {
        if(cur->data == key)
        {
            new_node->next = cur->next;
            cur->next = new_node;
            if(cur == list->tail) // if key is last node, we need to update tail in Slist after adding new element
                list->tail = new_node;
            ++list->count;
        }
    }
    display_list(list);
    return list;
}
/*-----------------------------------------------------------------------------------------------------*/
//Question 4 : Modify Q1 such that one can delete any specified element from the list.
Slist* delete_any_specified_element(Slist *list,int32_t ele)
{
    assert(list!=NULL);
    Node *cur,*cur_prev;
    for(cur=list->head;cur!=NULL;cur=cur->next)
    {
        if(cur->data == ele)
            break;           //Finding out the node of element to be deleted
    }

    if(cur==list->head)  // If element to be deleted is in Head node
    {
        list->head = list->head->next;
    }
    else
    {
        for(cur_prev=list->head;cur_prev->next!=cur;cur_prev=cur_prev->next); // Finding out previous node
        //printf("%d",cur_prev->data);
        cur_prev->next = cur->next;
        if(cur == list->tail)  // If element is in tail node, update tail as prev node in Slist
            list->tail = cur_prev;
    }
    --list->count;
    display_list(list);
    free(cur);
    return list;
}
/*-----------------------------------------------------------------------------------*/
//Question 5 : Write a method to reverse the elements in the same list.
Slist* reverse_elements_in_the_list(Slist *list,Slist *list1)
{
    assert(list!=NULL);
    assert(list1!=NULL);
    Node *temp;
    int32_t ele;
    for(temp=list->head;temp!=NULL;temp=temp->next)
    {
        ele=temp->data;
        list1=slist_add_node_at_head(list1,ele); // reversing the list
    }
    return list1;
}
