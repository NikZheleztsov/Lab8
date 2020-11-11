#include<iostream>

template <typename T>
struct node 
{
    T data;
    struct node* next;
    struct node* prev;
};

template <typename T> 
struct circ_linked_list
{ 
    node<T>* first;
    node<T>* last;
};

//constructor
template <typename T>
void init(circ_linked_list<T>&  list, T info)
{
    node<T>* zero = new node<T>;
    zero->data = info;
    zero->next = zero;
    zero->prev = zero;

    list.first = zero;
    list.last = zero;
}
     
//adding to: 0 - start; 1 - end
template <typename T>
void add (circ_linked_list<T>& list, T info, bool direct)
{
   node<T>* new_one = new node<T>;
   new_one->data = info;

   if (direct == 0)
   {
       new_one->next = list.first;
       new_one->prev = list.last;

       list.first->prev = new_one;
       list.last->next = new_one;

       list.first = new_one;
   } else {
       new_one->next = list.first;
       new_one->prev = list.last;

       list.first->prev = new_one;
       list.last->next =new_one;

       list.last = new_one;
   }
}

template<typename T>
void add_index (circ_linked_list<T>& list, T info, int index)
{
    node<T>* new_one = new node<T>;
    new_one->data = info;
    node<T>* pointer = list.first;

    for (int i = 0; i < index - 1; ++i)
        pointer = pointer->next;

    new_one->prev = pointer;
    pointer = pointer->next;
    new_one->next = pointer;

    new_one->prev->next = new_one;
    new_one->next->prev = new_one;

}

template<typename T> 
void add_pointer (circ_linked_list<T>& list, T info, node<T>* pointer)
{
    node<T>* new_one = new node<T>;
    new_one->data = info;

    new_one->prev = pointer;
    pointer = pointer->next;
    new_one->next = pointer;

    new_one->prev->next = new_one;
    new_one->next->prev = new_one;
}

template<typename T>
T pop (circ_lined_list<T>& list, bool direct)
{
    


template <typename T>
int size (circ_linked_list<T>& list)
{
    int num = 0;
    node<T>* pointer = list.first;

    do {
        ++num;
        pointer = pointer->next;
    } while (pointer != list.first);
    
    return num;
} 

template<typename T>
int find (const circ_linked_list<T>& list, T info)
{
    node<T>* pointer = list.first;
    int num = 0;

    do {
        if (pointer->data == info)
            return num;
        else 
        {
            ++num;
            pointer = pointer->next;
        }
    } while (pointer != list.first);
    delete(pointer);
    return -1;
}

/*
template<typename T>
void destruct (circ_linked_list<T>& list)
{
    node<T>* pointer = list.first;
    node<T>* pointer2 = pointer->next;
    delete pointer;
}
*/
    
template <typename T>
void print (const circ_linked_list<T>& list)
{
    node<T>* pointer = list.first;

    do {
        std::cout << pointer->data << ' ';
        pointer = pointer->next;
    } while (pointer != list.first);
}

int main () 
{
    circ_linked_list<int> list;

    int first = 0;
    init <int> (list, first);

    add(list, 1, 1);
    add(list, -1, 0);
    add_index(list, 5, 1);

    node<int>* pointer = list.first->next;
    add_pointer(list, 10, pointer);

    if (find(list, 10) != -1)
        std::cout << find(list, 10) << std::endl;
    else std::cout << "Item not find" << std::endl;

    print(list);
    
    std::cout << std::endl;

    std::cout << "Size: " << size(list) << std::endl;

    //destruct(list);

    return 0;
}
