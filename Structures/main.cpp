#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


// this is a good trick about using templates in c++
template<int size>
struct Queue{

private:

    int arr[size];
    int length{};

public:
    /* ===== interface =====
     * add_front : void
     * add_end : void
     * remove_front : int
     * print : void
     *
     */

    Queue() {}

    // 1 - 2 - 3 - 4
    void addFront(int value) {
       if (length == size) {
           std::cout << "the queue is full" << std::endl;
       } else {
           for (int i = length ; i >= 0 ; i--) {
               arr[i] = arr[i - 1];
           }
           arr[0] = value;
           length++;
       }
    }

    void addEnd(int value) {
        if (length == size)
           std::cout << "the queue is full" << std::endl;

        else {
            arr[length++] = value;
        }
    }

    // 2 - 3 - 4 - 0
    int removeFront() {
        int result;
        if (length == 0) {
            std::cout << "the queue is empty" << std::endl;
            return 0;
        }
        else {
            result = arr[0];
            for (int i = 1 ;i < length ;i++) {
                arr[i - 1] = arr[i];
            }
            length--;
        }
        return result;
    }

    void print() {
        for (int i = 0 ;i < length ;++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};



// ========= templates section ========= //

// Some Notes About Templates
/*
 *  the core of using template is "the same logic"
 *  generated in compile time
 *  templates are hard in practice
 *  static variable in templates , every type you pass has its own static variables
 *  function template specialization
 */
template<class T>
struct MyNumber {
    T item;

    bool equal(T another) {
        return item == another;
    }
};

template<>
struct MyNumber<double> {
    double item;

    bool equal(double another) {
        if (std::fabs(item - another) < 0.00001)
            return true;
        return false;
    }
};

int main() {

    std::cout << "Hello , world!" << std::endl;
    return 0;

}