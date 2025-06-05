#include <iostream>
#include <algorithm>

/*
* ========== General Notes About OO sofware development ===========
* - Delegation is used as alternative to inheritance. Inheritance is a good strategy when a close relationship exists in between parent 
*   and its child object. However, inheritance increases the coupling between the objects in the relationship.
*   On the other hand, delegation is a more flexible way to express a relationship between classes.
* 
*
* */


/*
* ============ Important Notes ==========
* - Use the initializer List when you define a new c++ class
* - Don't use the default initializtion for the class data members (use your own)
* - If you provided a paramterized constructore , then you should to provide a default one
* - constructore build , destructore destroy
* - "this" pointer 
*
* - A copy constructor is a constructor which does deep copy. 
*   You should write your own copy constructor when there is a pointer type variable inside the class. 
*   Compiler will insert copy constructor automatically when there is no explicit copy constructor written inside the code. 
*   The type of a copy constructor parameter should always be reference type, 
*   this to avoid infinite recursion due to the pass by value type.
*
* -  A parameterized constructor with default values replaces the default constructor if no other default constructor is declared.
* -  Initializer list considered as a vector<T> and you can do some logic upon these data 
*    and it has higher priority than the regular constructor 
*     - initializer list 
*     - regular constructor 
*     - aggregate constructor 
*
* - default constructor (default keyword)
* 
* - default initialization VS value initialization (() , {}) -> to prevent the garbage as it can 
* - always initialize your variables by using this style ({})
* - deleting a constructor 
*     -> constructor (signature) = delete keyword;
*
* - Tips for beginners 
*     - if you have a class with pointer member variables ,
*     - then delete the following
*        - copy constructor 
*        - assignment operator 
*
* */








int main() {
  return 0;

  for (int i = 0; i < 10; ++i)
  {

      std::cout << "Hello world" << std::endl;
        
    

  }
}
