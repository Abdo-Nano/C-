#include <iostream>
#include <filesystem>

/*
 *
 *
 *
 */

class Tree {
public:
    static int counter;
    static void printDashesAndFileName(int counter , const std::string & fileName);
    static void tree(std::filesystem::path path);
    static bool validateDire(const std::filesystem::path& path);

};

int Tree::counter = 1;

void Tree::printDashesAndFileName(int counter ,const std::string & fileName) {
    for (int i = 0 ;i < counter ;i++)
        std::cout << "-";
    std::cout << fileName << std::endl;
}


bool Tree::validateDire(const std::filesystem::path & path) {
     return !std::filesystem::exists(path) || !std::filesystem::is_directory(path) || std::filesystem::is_empty(path);
}

void Tree::tree(std::filesystem::path path) {
    printDashesAndFileName(counter , path.filename());
    if (validateDire(path)) {
        return;
    }
    for (std::filesystem::path entry : std::filesystem::directory_iterator(path)) {
        counter++;
        tree(entry);
        counter--;
    }
}


int main() {
    std::filesystem::path currPath = "/mnt/sdb1/programming/C++/projects/exposedirs/test";
    Tree::tree(currPath);
    return 0;
}
