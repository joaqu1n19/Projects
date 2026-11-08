#ifndef MONOSTACK_H
#define MONOSTACK_H
#include <iostream>
#include <stdexcept> // need for runtime_eror

using namespace std;

template <typename T>
class MonoStack {
    public:
        MonoStack(); // constructor
        MonoStack(int size, char o); // size starts capacity. o is 'i' or 'd'
        ~MonoStack(); // destructor

        void push(T x); // adds x to top and keeps order
        T pop(); // removed and returns top
        T peek(); // returns top
        int size(); // number of elements in stack
        bool isEmpty(); 
        bool isFull(); 

    private:
        T* stackArr; // array that holds elements
        int topIndex; // index of top elemnt. -1 when empty
        int capacity; // amount of element array can hold
        char order; // 'i' increases. 'd' decrases.
};

template <typename T>
MonoStack<T>::MonoStack() { // constructor
    capacity = 10; // stating size
    order = 'd'; // default order decrasing
    topIndex = -1; // start empty so first push goes to 0
    stackArr = new T[capacity]; // makes array on heap
}

template <typename T>
MonoStack<T>::MonoStack(int size, char o) { // overloaded constructor
    if (size <= 0) { 
        throw runtime_error ("Size needs to be positive."); // stops bad sizes
    }
    if (o != 'i' && o != 'd') { // only those orders are allowed
        throw runtime_error ("Order needs to be 'i' or 'd'"); // stops bad orders
    }
    capacity = size; // capacity is size that was passed in
    order = o; // saves order
    topIndex = -1; // stack starts empty
    stackArr = new T[capacity]; // makes array on heap
}

template <typename T>
MonoStack<T>::~MonoStack() { // destructor
    delete[] stackArr; // frees array
}

template <typename T>
void MonoStack<T>::push(T x) { // adds x to top and keeps order. decreasing
    if (order == 'd') { // gets rid of everything smaller or equa;
        while (!isEmpty() && stackArr[topIndex] <= x) { // runs intil top us bigger
            pop(); // throws away top
        }
    } else { // inscreasing
        while (!isEmpty() && stackArr[topIndex] >= x) { // run until top uis smaller
            pop();
        }
    }

    if (isFull()) { // doubles array
        T* temp = new T[2 * capacity];
        for (int i = 0; i < capacity; ++i) { // copies everything
            temp[i] = stackArr[i];
        }
        delete[] stackArr; // frees old array
        stackArr = temp; // points at new array
        capacity *= 2;
    }
    stackArr[++topIndex] = x; // incriment and store
}

template <typename T>
T MonoStack<T>::pop() { // removes and return top
    if (isEmpty()) {
        throw runtime_error ("Cant poop from empty stack");
    }
    return stackArr[topIndex--]; // return top. moves topIndex down
}

template <typename T>
T MonoStack<T>::peek() { // returns. doesnt remove
    if (isEmpty()) {
        throw runtime_error ("Cant peek at empty stack.");
    }
    return stackArr[topIndex]; // topIndex stays the same
}

template <typename T>
int MonoStack<T>::size() { // number od elements in stack
    return topIndex + 1; // starts at -1 so adds 1
}

template <typename T>
bool MonoStack<T>::isEmpty() { // chexks if stack is empty
    return topIndex == -1; // true if nothing has been pushed
}

template <typename T>
bool MonoStack<T>::isFull() { // checks if array is full
    return topIndex == capacity - 1; // true when top is last spot
}
#endif