#include "toolkit.h"
#include <cstdlib>
#include <assert.h>

std::size_t list_length(const node *head_ptr) {
    int length = 0;

    const node* trav = head_ptr;
    while(trav != NULL) {
        length++;
        trav = trav->link();
    }
    return length;
}


void list_head_insert(node *&head_ptr, const node::value_type &entry) {
    node *new_node = new node();
    new_node->set_data(entry);
    new_node->set_link(head_ptr);
    head_ptr = new_node;
}

void list_insert(node *previous_ptr, const node::value_type &entry) {
    node *new_node = new node(entry);
    new_node->set_link(previous_ptr->link());
    previous_ptr->set_link(new_node);
}


node *list_search(node *head_ptr, const node::value_type &target) {
    node *trav = head_ptr;
    // the first part of the condition guards the second part
    while((trav != NULL) && (trav->data() != target)) {
        trav = trav->link();
    }
    // examine the results
    // if trav is NULL, we didn't find it, so return NULL
    // if trav is not NULL then trav->data() == target,  so return trav
    return trav;

}

const node *list_search
        (const node *head_ptr, const node::value_type &target){
    const node *trav = head_ptr;
    // the first part of the condition guards the second part
    while((trav != NULL) && (trav->data() != target)) {
        trav = trav->link();
    }
    // examine the results
    // if trav is NULL, we didn't find it, so return NULL
    // if trav is not NULL then trav->data() == target,  so return trav
    return trav;
}


node *list_locate(node *head_ptr, std::size_t position) {
    if(position == 1) {
        return head_ptr;
    } else if(head_ptr == NULL) {
        return NULL;
    } else {
        return list_locate(head_ptr->link(), position-1);
    }
}

const node *list_locate(const node *head_ptr, std::size_t position) {
    const node *trav = head_ptr;
    int count = position;
    while((trav !=NULL) && (count > 1)) {
        trav = trav->link();
        count--;
    }
    return trav;
}


void list_head_remove(node *&head_ptr) {
    assert(head_ptr != NULL);
    node *tmp = head_ptr;  /// first node, soon to be removed
    head_ptr = head_ptr->link();  // head_ptr now points at the second node
    delete tmp;
}


void list_remove(node* previous_ptr)
    {
	node *remove_ptr;

	remove_ptr = previous_ptr->link( );
	previous_ptr->set_link( remove_ptr->link( ) );
	delete remove_ptr;
    }

void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
    // Library facilities used: cstdlib
    {
	head_ptr = NULL;
	tail_ptr = NULL;

	// Handle the case of the empty list.
	if (source_ptr == NULL)
	    return;

	// Make the head node for the newly created list, and put data in it.
	list_head_insert(head_ptr, source_ptr->data( ));
	tail_ptr = head_ptr;

	// Copy the rest of the nodes one at a time, adding at the tail of new list.
	source_ptr = source_ptr->link( );
	while (source_ptr != NULL)
	{
	    list_insert(tail_ptr, source_ptr->data( ));
	    tail_ptr = tail_ptr->link( );
	    source_ptr = source_ptr->link( );
	}
}


void list_clear(node *&head_ptr) {
    while(head_ptr != NULL ) {
        // we know that head_ptr is not NULL
        // so head_ptr points at the first node of the rest of the list
        node *rest = head_ptr->link();
        delete  head_ptr;  // get rid of first node
        head_ptr = rest;
    }
}
