#include "list.hpp"
#include <iostream>

#define ERROR -1
#define NOT_FOUND -2
#define MEMORY_ALLOCATED -3

struct Node{
    int data;
    struct Node *next;
};

List::List(){
    this->head = nullptr;
    this->tail = nullptr;
    this->count_node = 0;
}

List::~List(){
    while(head != nullptr){
        Node *tmp = head->next;
        delete head;
        head = tmp;
    }
    this->count_node = 0;
}

List::List(const List &lst){
    while(this->count_node != 0)
        pop_elem(0);
    Node *tmp = lst.head;
    while(tmp){
        push_in_list(tmp->data);
        tmp = tmp->next;
    }
}

List &List::operator=(const List &rhs){
    if (this == &rhs)
        return *this;
    while(this->count_node != 0)
        pop_elem(0);
    Node *tmp = rhs.head;
    while(tmp){
        push_in_list(tmp->data);
        tmp = tmp->next;
    }
    return *this;
}

int List::push_in_list(int data){
    if(!this)
        return ERROR;
    if (this->head == nullptr){
        this->head = new(std::nothrow)Node;
        if(!(this->head)) return MEMORY_ALLOCATED;
        this->tail = this->head;
        this->head->data = data;
        this->head->next = nullptr;
        ++(this->count_node);
    }
    else{
        this->tail->next = new(std::nothrow) Node;
        if (!(this->tail->next)) return MEMORY_ALLOCATED;
        this->tail = this->tail->next;
        this->tail->data = data;
        this->tail->next = nullptr;
        ++(this->count_node);
    }
    return 0;
}

int List::pop_elem(int i){
    Node *tmp;
    int j = 0;
    if (count_node == 0 || i < 0 || i > this->count_node - 1)
        return ERROR;
    if (i == 0){
        tmp = this->head->next;
        delete head;
        this->head = tmp;
    }
    else{
        tmp = head;
        Node *tmp_back = tmp;
        while(j != i){
            tmp_back = tmp;
            tmp = tmp->next;
            j++;
        }
        tmp_back->next = tmp->next;
        delete tmp;
    }
    --(this->count_node);
    return 0;
}

int List::get_elem(int i){
    if (!this)
        return ERROR;
    Node *tmp = this->head;
    if (count_node == 0 || i < 0 || i > this->count_node - 1)
        return ERROR;
    for (int j = 0; j < i; j++)
        tmp = tmp->next;
    return tmp->data;
}

int List::get_len(){
    if (this)
        return this->count_node;
    return ERROR;
}

int List::find_max(){
    if (!this)
        return ERROR;
    Node *node = head;
    if (!node)
        return ERROR;
    int max;
    while(node){
        if (node == head)
            max = node->data;
        else
            if(max < (node->data))
                max = node->data;
        node = node->next;
    }
    return max;
}

int List::find_min(){
    if (!this)
        return ERROR;
    Node *node = head;
    if (!node)
        return ERROR;
    int min;
    while(node){
        if (node == head)
            min = node->data;
        else
            if(min > (node->data))
                min = node->data;
        node = node->next;
    }
    return min;
}

int List::find_element(int key){
    if (!this)
        return ERROR;
    Node *node = head;
    if (!node)
        return ERROR;
    int ind = 0;
    while(node){
        if (key == (node->data))
            return ind;
        node = node->next;
        ++ind;
    }
    return NOT_FOUND;
}

void List::bubble_sort_list() { 
    if (this != NULL) {
        Node *p = NULL;
        Node *start = head;
        while (start->next != NULL) {
            p = start->next;
            do {
                if (p->data < start->data) {
                    int tmp = p->data;
                    p->data = start->data;
                    start->data = tmp;
                }
                p = p->next;
            } while (p != NULL);
            start = start->next;
        }
    }
}
