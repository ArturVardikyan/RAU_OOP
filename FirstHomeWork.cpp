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
            cout << "Size mismatch in assignment\n";
            exit(EXIT_FAILURE);
        }
    }
    ~MyArray() {
        free(dataPointer);
    }
    MyArray& operator=(const MyArray& other) {
        if (this != &other)
        {
            if (size != other.size) { 
                cout << "Size mismatch in assignment\n";
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
                cout << "Index out of bounds\n";
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
            cout << "Array is empty\n";
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
            cout << dataPointer[i] <<  " ";
        }
        cout << endl;
    }
    T front_() const {
        if (size == 0) {
            cout << "Array is empty\n";
            exit(EXIT_FAILURE);
        }
        return dataPointer[0];
    }
    T back_() const{
        if (size == 0) {
            cout << "Array is empty\n";
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
        cout << "Index out of bounds\n";
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
    
    cout << "Max element: " << array1.max_size_() << endl;
    cout << "First element: " << array1.front_() << endl;
    cout << "Last element: " << array1.back_() << endl;
    cout << "Second element check: " << array1.empty_(2) << endl;
    array1.clear_();
    cout << "Array cleaned" << endl;
   
    for (size_t i = 0; i < array1.getSize(); i++)
    {
        cout <<"Element - " << i << " check: " << array1.at_(i) << endl;
    }
    array1.fill_(5);
    cout << "Array filed with 5" << endl;
    array1.print_();
    return 0;
}





