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

void test_create_empty_list();
void test_add_node_at_head_or_tail(Slist*);
void test_delete_node_from_head(Slist*);
void test_delete_node_from_tail(Slist*);
void test_reverse_list();
void test_check_if_lists_are_same();
void test_union_and_intersection_of_two_lists();
void test_unique_element_list();
void test_double_linked_list();

int main()
{
    
    int32_t min,max;
    test_create_empty_list();

    //---------------Question 1-----------------
    Slist l1 = slist_new();
    Slist *list = &l1;

    test_add_node_at_head_or_tail(list);  // List looks as follows : 50 30 10 20 40
    test_delete_node_from_head(list);     // List looks as follows : 30 10 20 40
    test_delete_node_from_tail(list);     // List looks as follows : 30 10 20
    assert(slist_lookup(list, 10) == 1);
    assert(slist_lookup(list, 40) == 0); // 40 is deleted
    assert((slist_count(list))==3);

    //---------------Question 2-----------------
    slist_max_min(list,&max,&min);
    assert(max==30);
    assert(min==10);

    //---------------Question 3-----------------
    add_after_specified_element(list,10,70); // List looks as follows : 30 10 70 20
    add_after_specified_element(list,20,80); // List looks as follows : 30 10 70 20 80
    assert(slist_lookup(list,70) == 1);
    //printf("%d",list->tail->data);  // just to check whether tail node is updated in Slist or not after adding 80
    assert(slist_count(list) == 5);

    //---------------Question 4-----------------
    delete_any_specified_element(list,70);  // List looks as follows : 30 10 20 80
    //printf("%d  %d",list->head->data, list->tail->data);
    assert(slist_lookup(list,70) == 0); // 70 is deleted
    assert(slist_count(list) == 4);

    //---------------Question 5-----------------
    test_reverse_list();

    //---------------Question 6-----------------
    test_check_if_lists_are_same();

    //---------------Question 7 and 8-----------
    test_union_and_intersection_of_two_lists();

    //---------------Question 9-----------------
    test_unique_element_list();

    //---------------Question 10----------------
    test_double_linked_list();
    return 0;
}

void test_create_empty_list()
{
    Slist l1 = slist_new();
    Slist *list = &l1;
    assert((slist_count(list))==0);
}

void test_add_node_at_head_or_tail(Slist *list)
{
    list = slist_add_node_at_head(list,10);
    assert((slist_count(list))==1);
    list = slist_add_node_at_tail(list,20);
    list = slist_add_node_at_head(list,30);
    list = slist_add_node_at_tail(list,40);
    list = slist_add_node_at_head(list,50);
    assert((slist_count(list))==5);
    assert(slist_lookup(list, 20) == 1); // 1 means data present
    assert(slist_lookup(list, 60) == 0); // 0 means data not present
    //display_list(list);
}

void test_delete_node_from_head(Slist *list)
{
    list=delete_node_from_head(list);  /* List looks as follows : 30 10 20 40 */
    display_list(list);
    assert(slist_lookup(list, 20) == 1);
    assert(slist_lookup(list, 50) == 0); // 50 is deleted
    assert((slist_count(list))==4);
}

void test_delete_node_from_tail(Slist *list)
{
    list=delete_node_from_tail(list);  /* List looks as follows : 30 10 20 */
    display_list(list);
    assert(slist_lookup(list, 20) == 1);
    assert(slist_lookup(list, 40) == 0); // 40 is deleted
    assert((slist_count(list))==3);
}

void test_reverse_list()
{
    Slist l1 = slist_new();
    Slist *list = &l1;
    Slist l2 = slist_new();
    Slist *list1 = &l2;
    test_add_node_at_head_or_tail(list);
    reverse_elements_in_the_list(list,list1);
    display_list(list);
    display_list(list1);
}

void test_check_if_lists_are_same()
{
    Slist l1 = slist_new();
    Slist *list1 = &l1;
    Slist l2 = slist_new();
    Slist *list2 = &l2;
    test_add_node_at_head_or_tail(list1); // List is as follows : 50 30 10 20 40
    list2 = slist_add_node_at_tail(list2,20);
    list2 = slist_add_node_at_head(list2,30);
    list2 = slist_add_node_at_tail(list2,40);
    list2 = slist_add_node_at_head(list2,30);
    list2 = slist_add_node_at_head(list2,50);
    display_list(list1); // 50 30 10 20 40
    display_list(list2); // 50 30 30 20 40
    assert(check_if_lists_are_same(list1,list2) == 1); // Lists are not same
}

void test_union_and_intersection_of_two_lists()
{
    Slist l1 = slist_new();
    Slist *list1 = &l1;
    Slist l2 = slist_new();
    Slist *list2 = &l2;
    test_add_node_at_head_or_tail(list1);
    list1 = slist_add_node_at_tail(list1,10); // List is as follows : 50 30 10 20 40 10
    list2 = slist_add_node_at_tail(list2,10);
    list2 = slist_add_node_at_head(list2,30);
    list2 = slist_add_node_at_tail(list2,60);
    list2 = slist_add_node_at_head(list2,90);
    list2 = slist_add_node_at_head(list2,50);
    list2 = slist_add_node_at_head(list2,30);
    display_list(list1); // 50 30 10 20 40 10
    display_list(list2); // 30 50 90 30 10 60
    Slist *union_list = union_of_two_lists(list1,list2);
    display_list(union_list); // 50 30 10 20 40 90 60
    Slist *intersection_list = intersection_of_two_lists(list1,list2);
    display_list(intersection_list); // 50 30 10
}

void test_unique_element_list()
{
    Slist l1 = slist_new();
    Slist *list = &l1;
    unique_element_list(list,10);
    unique_element_list(list,30);
    unique_element_list(list,20);
    unique_element_list(list,10);
    unique_element_list(list,20);
    display_list(list); //10 30 20
    assert((slist_count(list))==3);
}

void test_double_linked_list()
{
    Dlist dl1 = dlist_new();
    Dlist *list = &dl1;
    assert(dlist_count(list) == 0);
    dlist_add_node_at_head(list,10);
    dlist_add_node_at_head(list,20);
    dlist_add_node_at_head(list,30);
    //display_dlist(list);   // list : 30 20 10
    assert(dlist_count(list) == 3);
    assert(dlist_lookup(list,10) == 1);
    assert(dlist_lookup(list,50) == 0); // 50 is not present in the dlist

    dlist_add_node_at_tail(list,40);
    dlist_add_node_at_tail(list,70);
    assert(dlist_lookup(list,70) == 1);
    //display_dlist(list);  // list : 30 20 10 40 70

    dlist_add_after_specified_element(list,30,5);
    dlist_add_after_specified_element(list,70,75);
    assert(dlist_lookup(list,5) == 1);
    //display_dlist(list);  // list : 30 5 20 10 40 70 75

    delete_dnode_from_head(list);
    delete_dnode_from_tail(list);
    assert(dlist_lookup(list,5) == 1);
    assert(dlist_lookup(list,75) == 0);
    //display_dlist(list);    // list : 5 20 10 40 70

    dlist_delete_any_specified_element(list,10);
    assert(dlist_lookup(list,10) == 0); // 10 is deleted
    display_dlist(list);  // list : 5 20 40 70
}
