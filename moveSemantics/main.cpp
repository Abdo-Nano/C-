#include <iostream>


/*
 * ======== Important Notes ==========
 * - prefix operator return by L-value reference
 * - postfix operator return by PrValue
 * - * operator convert from Prvalue to Lvalue
 * - & operator convert from Lvalue to Prvalue
 * - pointer to Prvalue will not compile , Except in C-style char array , Because it
 *      acts like array internally
 * - prvalue first priority matching is rvalue reference , Because
 *      It can avoid an extra copies
 * - Every Expression has a type  , and belongs to a value category
 */

int main() {

    int number = 10;

    int another = 20;


    return number + another;
}
