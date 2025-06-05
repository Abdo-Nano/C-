//
// Created by abdo on 5/2/25.
//

#ifndef BASICFILEOPERATIONS_H
#define BASICFILEOPERATIONS_H
#include <filesystem>
#include <iostream>
#include <fstream>

class BasicFileOperations {

private:
    std::filesystem::path current_path;

public:
    BasicFileOperations();
    BasicFileOperations(std::filesystem::path current_path);
    void list_files_and_directories();
    void navigate_between_directories(std::filesystem::path new_path);
    bool create_new_file(std::filesystem::path file_path);
    bool create_new_directory(std::filesystem::path dire_path);
    void delete_files_and_directories(std::filesystem::path path);

};



#endif //BASICFILEOPERATIONS_H
