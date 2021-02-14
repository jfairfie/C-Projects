#include "sequence.h"
#include <iostream>

namespace main_savitch_5 {

    typedef double value_type;
    typedef std::size_t size_type;
	node *head_ptr;
	node *tail_ptr;
	node *cursor;
	node *precursor;
	size_type many_nodes;
        // CONSTRUCTORS and DESTRUCTOR
    sequence::sequence() {
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
        many_nodes = 0;
    }

    sequence::sequence(const sequence &source) {
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes;
        if (source.precursor == NULL) {
            if (source.cursor == NULL) {
                cursor = NULL;
            } else {
                cursor = head_ptr;
            }
            precursor = NULL;
        } else {
            node *tmp_ptr = head_ptr;
            node *source_ptr = source.head_ptr;
            while (source_ptr != source.precursor) {
                source_ptr = source_ptr->link();
                tmp_ptr = tmp_ptr->link();
            }
            cursor = tmp_ptr->link();
            precursor = tmp_ptr;
        }
    }

    void sequence::operator=(const sequence &source) {
        many_nodes = source.many_nodes;
        list_copy(source.head_ptr, head_ptr, tail_ptr);

        node* temp;
        temp = source.head_ptr;
        precursor = head_ptr;

        if (source.cursor == NULL) {
            if (source.precursor == NULL) {
                cursor = NULL;
                precursor = NULL;
            } else {
                precursor = tail_ptr;
                cursor = NULL;
            }
        } else {
            if (source.precursor == NULL) {
                cursor = head_ptr;
                precursor = NULL;
            } else {
                while (temp != source.precursor) {
                    temp = temp->link();
                    precursor = precursor->link();
                }
                cursor = precursor->link();
            }
        }
    }

    sequence::~sequence() {
        list_clear(head_ptr);
    }

    void sequence::start() {
        precursor = NULL;
        cursor = head_ptr;
    }

    void sequence::advance() {
        precursor = cursor;
        cursor = cursor->link();
    }

    void sequence::insert(const sequence::value_type &entry) {
        if (!is_item()) {
            list_head_insert(head_ptr, entry);
            cursor = head_ptr;
            precursor = NULL;
        } else {
            if (precursor == NULL) {
                list_head_insert(head_ptr, entry);
                cursor = head_ptr;
            } else {
                list_insert(precursor, entry);
                cursor = precursor->link();
            }
        }
        many_nodes++;
    }

    void sequence::attach(const sequence::value_type &entry) {
        if (!is_item()) {
            if (head_ptr == NULL) {
                list_head_insert(head_ptr, entry);
                cursor = head_ptr;
                precursor = NULL;
            } else {
                //Locates final node in the list
                precursor = list_locate(head_ptr, many_nodes);
                list_insert(precursor, entry);
                cursor = precursor->link();
            }

        } else {
            precursor = cursor;
            list_insert(cursor, entry);
            cursor = cursor->link();
        }
        many_nodes++;
    }

    void sequence::remove_current() {
        if (is_item()) {
            if (precursor == NULL){
                list_head_remove(head_ptr);
                cursor = head_ptr;
            } else {
                cursor = cursor->link();
                list_remove(precursor);
            }
        }
        many_nodes--;
    }

    sequence::value_type sequence::current() const {
        return cursor->data();
    }
}
