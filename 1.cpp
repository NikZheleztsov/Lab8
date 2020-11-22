#include <iostream>

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
void init(circ_linked_list<T>& list, T info)
{
    node<T>* zero = new node<T>;
    zero->data = info;
    zero->next = zero;
    zero->prev = zero;

    list.first = zero;
    list.last = zero;
}
     
//adding to: 0 - beginning; 1 - end
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

    if (index == 0)

        add(list,info, 0);

    else if (index == size(list))

        add(list,info, 1);

    else {

        for (int i = 0; i < index - 1; ++i)
        pointer = pointer->next;

        new_one->prev = pointer;
        pointer = pointer->next;
        new_one->next = pointer;

        new_one->prev->next = new_one;
        new_one->next->prev = new_one;

    }
}

template<typename T> 
void add_pointer (circ_linked_list<T>& list, T info, node<T>* pointer)
{
    node<T>* new_one = new node<T>;
    new_one->data = info;

    new_one->prev = pointer->prev;
    new_one->next = pointer;

    new_one->prev->next = new_one;
    new_one->next->prev = new_one;
}

template<typename T>
T pop (circ_linked_list<T>& list, bool direct) // 0 - from beginning; 1 - from end
{
    T info;
    node<T>* temp;

    if (direct == 0)
    {
        list.first->next->prev = list.last;
        list.last->next = list.first->next;

        temp = list.first;
        info = list.first -> data;
        list.first = list.first -> next;

        delete temp;

    } else {
        
        list.last->prev->next = list.first;
        list.first->prev = list.last->prev;

        temp = list.last;
        info = list.last->data;
        list.last = list.last->prev;

        delete temp;
    }

    return info;
}

template<typename T>
T pop_index (circ_linked_list<T>& list, int num)
{
    T info;
    node<T>* point = list.first;

    for (int i = 0; i < num; i++)
        point = point->next; 

    point->prev->next = point->next;
    point->next->prev = point->prev;

    if (point == list.first)
        list.first = point->next;
    else if (point == list.last)
        list.last = point->prev;

    info = point->data;

    delete point;
    return info;
}

template<typename T>
T pop_pointer (circ_linked_list<T>& list, node<T>* point)
{
    T info;

    point->next->prev = point->prev;
    point->prev->next = point->next;
    info = point->data;

    if (point == list.first)

        list.first = point-> next;

    else if (point == list.last)

        list.last = point->prev;

    delete point;
    return info;
}


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

template<typename T>
void destruct (circ_linked_list<T>& list)
{
    for (int i = 0; i < size(list); i++)
        pop(list, 0);
}

template<typename T>
T get_data (circ_linked_list<T>& list, int number)
{
    T info;
    node<T>* point = list.first;

    for(int i = 0; i < number; i++)
        point = point->next;

    info = point->data;
    return info;
}
    
template <typename T>
void print (const circ_linked_list<T>& list)
{
    node<T>* pointer = list.first;

    do {
        std::cout << pointer->data << ' ';
        pointer = pointer->next;
    } while (pointer != list.first);

    std::cout << std::endl;
}

int main () 
{
    circ_linked_list<int> list;

    int first = 0;
    init <int> (list, first);

    add(list, 1, 1); //end
    add(list, -1, 0); //start
    add_index(list, 5, 2); // add 5 at second place
    add_index(list, 25, 1);

    node<int>* pointer = list.first->next;
    add_pointer(list, 10, pointer);

    if (find(list, 10) != -1)
        std::cout << find(list, 10) << std::endl;
    else std::cout << "Item not find" << std::endl;

    print(list);

    std::cout << "Popped element (beginning): " << pop(list, 0) << std::endl
              << "Popped element (end): " << pop(list, 1) << std::endl;

    print(list);

    pop_index(list, 2);

    print(list);

    node<int>* pointer2 = list.first->next;
    pop_pointer(list, pointer2);

    print(list);

    std::cout << "Element 1: " << get_data(list, 1) << std::endl;

    print(list);

    std::cout << "Size: " << size(list) << std::endl;

    destruct(list);

    return 0;
}
