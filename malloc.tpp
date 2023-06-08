#include "malloc.h"

template<typename Type>
Type *realloc(Type *array, int size) {
    Type* new_array = new Type[size + 1];
    for(int i = 0; i < size; i++)
        new_array[i] = array[i];
    return new_array;
}
