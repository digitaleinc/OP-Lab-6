#include "queue.h"

template<typename Type>
Queue<Type>::Queue() {
    this->array = nullptr;
    size = 0;
}

template<typename Type>
Queue<Type>::~Queue() {
    if(this->array != nullptr)
    {
        delete[] array;
        size = 0;
    }
}

template<typename Type>
bool Queue<Type>::is_empty() {
    return array == nullptr;
}

template<typename Type>
void Queue<Type>::clear() {
    if(this->array != nullptr)
    {
        delete[] this->array;
        this->array = nullptr;
        this->size = 0;
    }
}

template<typename Type>
void Queue<Type>::append(Type data) {
    if(this->array == nullptr)
    {
        this->array = new Type[1];
        this->array[0] = data;
        size++;
    }
    else{
        this->array = realloc(this->array, size);
        this->array[size] = data;
        size++;
    }
}

template<typename Type>
Type Queue<Type>::pop() {
    if(array == nullptr)
    {
        std::cout << "List is empty\n";
        return static_cast<Type>(0);
    }
    else{
        Type result = array[0];
        size--;
        Type* new_array = new Type[size];
        for(int i = 0; i < size; i++)
            new_array[i] = array[i + 1];
        delete[] array;
        array = new Type[size];
        for(int i = 0; i < size; i++)
            array[i] = new_array[i];
        delete[]new_array;
        return result;
    }
}


template<typename Type>
void Queue<Type>::show() {
    if(array != nullptr)
    {
        for(int i = 0; i < size; i++)
            std::cout << *(array + i) << " ";
        std::cout << std::endl;
    }
    else{
        std::cout << "Queue is empty\n";
    }
}

template<typename Type>
int Queue<Type>::get_size() {
    return this->size;
}

template<typename Type>
Queue<Type>::Iterator::Iterator(Type *current) {
    this->current = current;
}

template<typename Type>
typename Queue<Type>::Iterator &Queue<Type>::Iterator::operator--(int) {
    current = current - 1;
    return *this;
}

template<typename Type>
typename Queue<Type>::Iterator &Queue<Type>::Iterator::operator--() {
    current = current - 1;
    return *this;
}

template<typename Type>
typename Queue<Type>::Iterator &Queue<Type>::Iterator::operator++(int) {
    current = current + 1;
    return *this;
}

template<typename Type>
typename Queue<Type>::Iterator &Queue<Type>::Iterator::operator++() {
    current = current + 1;
    return *this;
}

template<typename Type>
bool Queue<Type>::Iterator::operator==(const Queue::Iterator &other) {
    return current == other.current;
}

template<typename Type>
bool Queue<Type>::Iterator::operator!=(const Queue::Iterator &other) {
    return current != other.current;
}

template<typename Type>
Type &Queue<Type>::Iterator::operator*() {
    return *current;
}
