#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <typeinfo>
#include <filesystem>

/*

    ===== Notes =========
    - virtual functions  (calling functions cause at runtime depening of the pointed class )
    - pure virtual functions 
    - The asbtract class -> the class doesn't instantiate objects from it 
    - To make a class abstract , at least provide a pure virtual functions . 
        if you decide to get an object from that class , it will occure an CE
    - you should to override the pure virtual functions in all derived class , or it will be considred as
        abstract classes also
    - any function that doesn't implement the pure virtual function of the base class ,
        then the class will considered as abstract class

    - there is nothing called pure virtual desctructor (type it as = default)

    - you can define virtual function with it's defintion
    - Base class destructors should always be virtual
    - Friend function (If you found yourself use a lot fo friend functions , 
        then you should to think to redesign  your system)

    - Friend class (when you declare class a a friend inside another class , 
      then it can access all the private data of it's class)

    - static factory method , that a class has a static method which returns the type of another class
    - static member functions can only access the static member data

    - Initialization(copy constructor) is not assigenment operator
    - in the copy constructor the argument should passed by reference.
    - How to prohibit the copy constructor and assignment operator?
        - by implement them in the private section
    - typeid is used to get info about an unkowned class / object

*/


class Publication {

private:
    int price {};
    std::string title;

public:
    Publication(int price , std::string title): price(price) , title(title){}
    Publication() {}
    virtual void getData() {
        std::cout << "title: "; std::cin >> title;
        std::cout << "price: "; std::cin >> price;
    } 
    virtual void putData() {
        std::cout << this->title << std::endl;
        std::cout << this->price << std::endl;
    };
    virtual ~Publication() = default;
};

class Book : public Publication {

private:
    int PageCounter{};

public:
    Book() {}
    Book(int price , std::string title , int PageCounter):Publication(price , title) , PageCounter(PageCounter){}

    void getData() {
        Publication::getData();
        std::cin >> PageCounter;
    }
    
    void putData() {
        Publication::putData();
        std::cout << this->PageCounter << std::endl;
    }
};

class Tape : public Publication {
private:
    float PlayingTime{};

public:
    Tape() {}
    Tape(int price , std::string title , float PlayingTime):Publication(price , title) , PlayingTime(PlayingTime){}

    void getData() {
        Publication::getData();
        std::cin >> PlayingTime;
    }
    
    void putData() {
        Publication::putData();
        std::cout << this->PlayingTime<< std::endl;
    }
};

int main() {


}
