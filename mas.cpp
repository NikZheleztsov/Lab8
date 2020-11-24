#include <iostream>

class point // Impossible to overload '=' whithout using class!
{
    public:

        int x;
        int y;

        int operator == (point& b)
        {
            if ((this->x == b.x) && (this->y == b.y))
                return 1;
            else return 0;
        }

        int operator != (char b)
        {
            if (this->x != b || this->y != b)
                return 1;
            else return 0;
        }

        int operator != (point& b)
        {
            if ((this->x != b.x) || (this->y != b.y))
                return 1;
            else return 0;
        }

        void operator= (char b)
        {
            this->x = b;
            this->y = b;
        }
};

std::ostream& operator << (std::ostream& out, const point& p)
{
    out << '(' << p.x << ',' << p.y << ") ";
    return out;
}

template <typename T, int size>
struct list
{
    T arr[size];
};

template <typename T, int size>
void init(list<T,size>& list, T info)
{
    for (int i = 0; i < size; i++)
        list.arr[i] = EOF; //check overload // can't to overload =

    list.arr[0] = info;
};

template <typename T, int size>
int size_of_list (list<T,size>& list)
{
    int num = 0;
    for (num = 0; list.arr[num] != EOF; num++);
    return num;
}

template <typename T, int size>
void add (list<T,size>& list, T info, bool dir) // 0 - beginning; else - end;
{
    if (size_of_list(list) == size)
        std::cout << "List is full\n";
    else {
        if (dir == 0)
        {
            for (int i = size_of_list(list); i > 0; i--)
                list.arr[i] = list.arr[i-1];
            list.arr[0] = info;

        } else 
            list.arr[size_of_list(list)] = info;
    } 
}

template <typename T, int size>
void add_index (list<T,size>& list, T info, int index)
{
    if (size_of_list(list) == size)
        std::cout << "List is full\n";
    else {
        if (size_of_list(list) < index)
            std::cout << "Unable to add an element\n";
        else {
            for (int i = size_of_list(list); i >= index; i--)
                list.arr[i] = list.arr[i-1];
            list.arr[index] = info;
        }
    }
}

template <typename T, int size>
T pop (list<T,size>& list, bool dir) //0 - beginning
{
    T ret;
    if (dir == 0)
    {
        ret = list.arr[0];
        for (int i = 0; i < size_of_list(list); i++)
            list.arr[i] = list.arr[i+1];
    } else { 
        ret = list.arr[size_of_list(list) - 1];
        list.arr[size_of_list(list) - 1] = EOF;
    }
    
    return ret;
}

template <typename T, int size>
T pop_index (list<T,size>& list, int index) 
{
    T ret;
    if (index > size_of_list(list) - 1)
        std::cout << "Unable to pop an element\n";
    else {
        ret = list.arr[index];
        for (int i = index; i < size_of_list(list); i++)
            list.arr[i] = list.arr[i+1];
    }

    return ret;
}

template <typename T, int size>
T get_data(const list<T,size>& list, int index)
{
   return list.arr[index]; 
}

template <typename T, int size>
std::string find(list<T,size>& list, T data)
{
    int num = 0;
    while (list.arr[num] != data && num < size_of_list(list))
        num++;
    if (num == size_of_list(list))
    {
        //std::cout << "Element wasn't found\n";
        return "Element wasn't found\n";

    } else {
        return std::to_string(num);
    }
}


template <typename T, int size>
void print(list<T,size>& list)
{
    for (int i = 0; i < size_of_list(list); i++)
        std::cout << list.arr[i] << ' ';
    std::cout << std::endl;
}

template <typename T, int size>
void destruct(list<T,size>& list)
{
    for (int i = 0; i < size_of_list(list); i++)
        list.arr[i] = EOF;
}

int main ()
{
    /*
    list<int, 10> list;

    init(list, 1);
    std::cout << "Size: " << size_of_list(list) << std::endl;
    print(list);

    add(list, 5, 0);
    add(list, 2, 1);
    print(list);

    add_index(list, 3, 1);
    print(list);

    std::cout << "Popped element from beginning: " <<  pop(list, 0) << std::endl;
    print(list);

    std::cout << pop_index(list, 1) << std::endl;
    print(list);

    std::cout << "Data of 0 elem: " << get_data(list, 0) << std::endl;
    print(list);

    add(list, 0, 0);
    add(list, 6, 0);
    add(list, 5, 0);
    print(list);

    std::cout << find(list, 0);

    destruct(list);
    print(list);
*/
    ////////////////////////////////////////////////////////
    std::cout << "---------------------------" << std::endl;
    ////////////////////////////////////////////////////////
    
    list<point, 10> list2;

    point first;
    first.x = 0;
    first.y = 0;

    point second;
    second.x = 1;
    second.y = 1;

    point third;
    third.x = 2;
    third.y = 2;

    point fourth;
    fourth.x = 3;
    fourth.y = 3;

    init(list2, first);    
    print(list2);

    add(list2, second, 1); 
    add(list2, third, 0);
    print(list2);

    std::cout << "Size: " << size_of_list(list2) << std::endl;

    pop(list2, 0);
    pop(list2, 1);
    print(list2);

    add_index(list2, second, 1);
    print(list2);

    std::cout << "Data of 0 element: " <<  get_data(list2,0) << std::endl;

    std::cout << "Find element (3,3): " << find(list2, fourth);
    std::cout << "The position of (1,1) element: " << find(list2, second) << std::endl;

    add_index(list2, fourth, 2);
    print (list2);

    pop_index(list2, 0);
    print(list2);

    destruct(list2);
    return 0;
}
