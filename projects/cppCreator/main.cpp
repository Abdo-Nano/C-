#include <complex>
#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
#include <limits.h>
#include <queue>
#include <openssl/opensslconf.h>

#include "CMakeFiles.h"

void createCMakeFileInsideSrc(std::string ProjectName) {
    std::ofstream file("src/CMakeLists.txt");

    if (!file)
        std::cerr << "there is something wrong";

    std::string content = "add_executable(" + ProjectName + " main.cpp)\n"
    "target_link_libraries(" + ProjectName + " PRIVATE mylib external_lib)\n"
    "target_include_directories(" + ProjectName + " PRIVATE\n"
    "    ${PROJECT_SOURCE_DIR}/lib\n"
    "    ${PROJECT_SOURCE_DIR}/external\n"
    ")";

    file << content;

    file.close();
}
void createCMakeFile(std::string projectName) {
    std::ofstream file("CMakeLists.txt");
    std::string content =
        "cmake_minimum_required(VERSION 3.10)\n"
        "project("+ projectName +")\n\n"
        "set(CMAKE_CXX_STANDARD 17)\n"
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)\n\n"
        "# Add subdirectories\n"
        "add_subdirectory(lib)\n"
        "add_subdirectory(external)\n"
        "add_subdirectory(src)\n"
        "add_subdirectory(test)\n";

    file << content;
    file.close();
}


void createMainFile() {
    std::filesystem::path fileName = "src/main.cpp";
    std::ofstream file(fileName);
    if (!file)
        std::cerr <<  "something wrong";

    std::string content = "#include <iostream> \n"
    "int main(int argc , char *argv[]) { \n"
    "\tstd::cout << \"Hello world\" << std::endl;\n"
    "\treturn 0;\n"
    "}";
    file  << content;
    file.close();
}
void createDirectories(std::filesystem::path path) {
    // don't forget to check the path validly
    std::filesystem::create_directory(path);
    std::filesystem::current_path(path);
    std::vector<std::string> dirs {"src" , "lib" , "external" , "test"  , "build"};
    for (auto dir : dirs)
        std::filesystem::create_directory(dir);

}

void mainProject(std::filesystem::path path) {
    createDirectories(path);
    createCMakeFile(path);
    createMainFile();
}





int main() {
    std::queue<int> arr;
    
    return 0;
}