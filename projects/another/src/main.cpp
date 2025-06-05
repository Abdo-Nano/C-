#include <iostream>
#include <SQLiteCpp/SQLiteCpp.h>

int main() {

    try {
        SQLite::Database db("test.db", SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);

        std::cout << "Run " << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }



    return 0;
}
