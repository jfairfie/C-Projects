#include "node1.h"
#include "check_lists.h"
#include <iostream>

using namespace std;
using namespace main_savitch_5;

void list_print(node* head_ptr) {
    node* temp = head_ptr;
    while (temp != NULL) {
        std::cout << temp->data() << " ";
        temp = temp->link();
    }
    std::cout << std::endl;
}

int main() {
    node* head1 = new node;

    list_head_remove(head1);
    list_head_insert(head1, 23.5);
    list_head_insert(head1, 45.6);
    list_head_insert(head1, 67.7);
    list_head_insert(head1, 89.8);
    list_head_insert(head1, 12.9);

    list_print(head1);
    check_list1(head1);
    std::cout << std::endl;

    //Second Test
    node* head = new node;
    head = NULL;
    list_head_insert(head, 23.5);
    node* tail = head;
    list_insert(tail, 45.6);
    tail = tail->link();
    list_insert(tail, 67.7);
    tail = tail->link();
    list_insert(tail, -123.5);
    tail = tail->link();
    list_insert(tail, 89.8);
    tail = tail->link();
    list_insert(tail, 12.9);
    tail = tail->link();

    check_list2(head);
    list_print(head);
    std::cout << std::endl;

    //Third test
    node* head2 = new node;
    node* tail2 = new node;
    head2 = NULL;
    tail2 = NULL;

    head2 = head1;
    tail2 = head1;
    while (tail2->link() != NULL) {
        tail2 = tail2->link();
    }
    list_print(head2);
    check_list1(head2);
    list_print(tail2);
    std::cout << std::endl;

    //Fourth Test
    list_head_remove(head);
    list_print(head);
    check_list2B(head);
    std::cout << std::endl;

    //Fifth test
    node* cursor = head;
    cursor = cursor->link();
    list_remove(cursor);
    list_print(head);
    check_list2C(head);
}
