#ifndef LIST_HPP
#define LIST_HPP

class List{
    public:
        List();
        ~List();
        List &operator=(const List &rhs);
        List(const List &lst);

        int push_in_list(int data);
        int pop_elem(int i);
        int get_elem(int i);
        int get_len();
        int find_min();
        int find_max();
        int find_element(int key);

        void bubble_sort_list();
    private:
        struct Node *head, *tail;
        int count_node;

};

#endif // LIST_HPP
