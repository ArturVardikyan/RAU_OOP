// C++Lessons.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

template <typename T>
class MyArray {
private :
    T* dataPointer;
    size_t size;
public:
    MyArray(size_t s) {
        size = s;
        dataPointer = (T*)malloc(size * sizeof(T));
        if (dataPointer == nullptr) {
            std::cout << "Size mismatch in assignment\n";
            exit(EXIT_FAILURE);
        }
    }
    ~MyArray() {
        free(dataPointer);
    }
    MyArray& operator=(const MyArray& other) {
        if (this != &other)
        {
            if (size != other.size) { // Проверка на размер
                std::cerr << "Size mismatch in assignment\n";
                exit(EXIT_FAILURE);
            }
            for (size_t i = 0; i < size; i++)
            {
                dataPointer[i] = other.at_(i);
            }
        }
        return *this;
    }
    T& operator[](size_t index) {
        if (index >= size && index >= 0) {
                std::cout << "Index out of bounds\n";
                exit(EXIT_FAILURE);
            }
        
        return dataPointer[index];
    }
    void fill_(T element) {
        for (size_t i = 0; i < size; i++)
        {
            dataPointer[i] = element;
        }
    }
    void clear_(){
        for (size_t i = 0; i < size; i++)
        {
            dataPointer[i] = T();
        }
    }
    bool empty_(int index) {
        if (index < size && index >=0)
        {
            if (dataPointer[index-1] == T())
            {
                return false;
            }
            
        }
        return true;
        
    }
    size_t getSize() const {
        return size;
    }
    T max_size_() const{
        if (size == 0) {
            std::cout << "Array is empty\n";
            exit(EXIT_FAILURE);
        }
        T max = dataPointer[0];
        for (size_t i = 0; i < size; i++)
        {
            if (dataPointer[i] > max)
            {
                max = dataPointer[i];
            }
        }
        return max;
    }
    void print_() const{
        for (size_t i = 0; i < size; i++)
        {
            std::cout << dataPointer[i] <<  " ";
        }
        std::cout << endl;
    }
    T front_() const {
        if (size == 0) {
            std::cout << "Array is empty\n";
            exit(EXIT_FAILURE);
        }
        return dataPointer[0];
    }
    T back_() const{
        if (size == 0) {
            std::cout << "Array is empty\n";
            exit(EXIT_FAILURE);
        }
        return dataPointer[size - 1];
    }
    T data_() const {
        return front_();
    }
    T at_(int index) {
        if (index < size && index >= 0)
        {
            return dataPointer[index];
        }
        std::cout << "Index out of bounds\n";
        return T();
    }
   
};
int main() {
    MyArray<int> array1(5);
    //array1.fill_(5);
    for (size_t i = 0; i < array1.getSize(); i++)
    {
        array1[i] = i;
    }
    std::cout << "Array elements: " ;
    array1.print_();
    
    std::cout << "Max element: " << array1.max_size_() << std::endl;
    std::cout << "First element: " << array1.front_() << std::endl;
    std::cout << "Last element: " << array1.back_() << std::endl;
    std::cout << "Second element check: " << array1.empty_(2) << std::endl;
    array1.clear_();
    std::cout << "Array cleaned" << std::endl;
   
    for (size_t i = 0; i < array1.getSize(); i++)
    {
        std::cout <<"Element - " << i << " check: " << array1.at_(i) << std::endl;
    }
    
    return 0;
}



