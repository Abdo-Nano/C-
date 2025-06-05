#include <iostream>
#include <memory>
#include <functional>

/*
 * ========== Important Notes about Unique Smart Pointers =======
 * - use make_unique as you can instead of row pointer style
 * - If you pass it by value , then you must move its ownership using std::move
 * - when pass it by reference use const to protect it from destroying
 * - release method of unique_ptr destroys the pointer and return "row" pointer
 * - instead of reset method use the make_unique for more safety
 */

/*
 * ======== Shared Smart Pointers =========
 * - It allows multiple references to the same object
 * - It uses the reference counting mechanism to count all the reference to that object
 * - You can't use the operator assigment with it , but it's Ok with copy constructor
 * - Try to avoid the shared pointers as you can , and when you use them the carefully
 * - You have to be smart when you use the smart pointers
 */


/*
 * ======== Weak Pointers =========
 * - Weak pointer is a pointer to a pointer
 * -
*/







int main() {
    
    std::cout << "Hello, world!" << std::endl;
    std::cout << "Hello, world!" << std::endl;
    std::cout << "Hello, world!" << std::endl;
    std::cout << "Hello, world!" << std::endl;
    std::cout << "Hello, world!" << std::endl;
    return 0;
}