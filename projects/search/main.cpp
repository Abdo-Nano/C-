#include <iostream>
#include <filesystem>
#include <vector>
#include <cstring>


// Define ANSI color codes
#define RED     "\033[31m"
#define RESET   "\033[0m"

class Search {

private:
    std::vector<std::filesystem::path> result;
public:
    Search() = default;

    bool validateDire(std::filesystem::path path) {
        return !std::filesystem::exists(path) ||
            !std::filesystem::is_directory(path) ||
                std::filesystem::is_empty(path);
    }

    void search( std::filesystem::path path , const std::string & fileName) {
        if (path.filename() == fileName)
            result.push_back(path);

        if (validateDire(path))
            return;

        for (const auto & entry : std::filesystem::directory_iterator(path))
            search(entry , fileName);
    }

     void  getPathes() {
        for (const auto & path : result) {
            std::filesystem::path  newPath= path.parent_path() / ( RED + path.filename().string() +RESET);
            std::cout << "- " << newPath <<  std::endl;
        }

    }
};


void printCurrenPath() {
    std::cout << std::filesystem::current_path() << std::endl;
}


int main() {
    Search search;
    std::string fileName = "CMakeLists.txt";
    std::filesystem::path path = "/mnt/sdb1/programming/C++";
    search.search( path, fileName);
    search.getPathes();




}