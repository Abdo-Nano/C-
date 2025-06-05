#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <memory>



/*
 * ======= Important Notes About Lambda Expression ==========
 * - When you need to call the anonymous function use "()".
 *      -  [](){std::cout << "welcome from anonymous function" << std::endl;}();
 * - To capture all the variables in the current scope by value "[=](){}"
 * - To capture all the variables in the current scope by reference "[&](){}"
 * - To capture all the variables in the current scope by reference except someone "[& , x](){}"
 * - To capture all the variables in the current scope by value except someon "[= , &x](){}"
 *
 */

template<typename  Function>
void foreach(std::vector<int>& vec , Function fun) {
    for (int & item : vec) {
        item = fun(item);
    }
}




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}