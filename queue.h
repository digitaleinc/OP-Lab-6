#ifndef LAB6_QUEUE_H
#define LAB6_QUEUE_H

#include "malloc.tpp"
#include <iostream>

template <typename Type>
class Queue{
    Type* array;
    int size;
public:
    Queue();
    ~Queue();
    bool is_empty();
    void clear();
    void append(Type);
    Type pop();
    int get_size();
    void show();

    class Iterator{
    private:
        Type* current;
    public:
        Iterator(Type*);
        bool operator!=(const Iterator& other);
        bool operator==(const Iterator& other);
        Iterator& operator++();
        Iterator& operator++(int);
        Iterator& operator--();
        Iterator& operator--(int);
        Type& operator*();
    };

    Iterator begin()
    {
        return Iterator(array);
    }

    Iterator end()
    {
        return Iterator(array + size);
    }

    Iterator rbegin()
    {
        return Iterator(array + size - 1);
    }

    Iterator rend()
    {
        return Iterator(array - 1);
    }

};

#endif