//
// Created by abdo on 5/2/25.
//

#include "BasicFileOperations.h"


BasicFileOperations::BasicFileOperations() = default;

BasicFileOperations::BasicFileOperations(std::filesystem::path current_path) {
    this->current_path = current_path;
}


bool BasicFileOperations::create_new_directory(std::filesystem::path dire_path) {
    try {
        std::filesystem::create_directory(dire_path);
        return true;
    }catch (std::filesystem::filesystem_error const & ex) {
        std::cout << ex.what() << std::endl;
        return false;
    }
}

void BasicFileOperations::list_files_and_directories() {
    for (std::filesystem::path  entry: std::filesystem::directory_iterator(this->current_path)) {
        if (std::filesystem::is_directory(entry))
            std::cout << "dire -> " << entry.filename() << std::endl;
        else
            std::cout << "file -> " << entry.filename() << std::endl;
    }
}

bool BasicFileOperations::create_new_file(std::filesystem::path file_path) {
    try {
        std::ofstream file(file_path);
        return file.good();
    } catch (const std::exception & e) {
        std::cerr <<  e.what();
        return false;
    }
}

void BasicFileOperations::delete_files_and_directories(std::filesystem::path path) {
    try {
        if (!std::filesystem::exists(path)) {
            std::cerr << "No such file or directory";
        }
        if (std::filesystem::is_regular_file(path)) {
            if (std::filesystem::remove(path)) {
                std::cout << "The file deleted successfully." << std::endl;
                return;
            }
        }
        if (std::filesystem::is_directory(path)) {
            if (std::filesystem::remove_all(path)) {
                std::cout << "The directory deleted successfully." << std::endl;
                return;
            }
        }
        else {
            std::cerr << "Unkonw filesystem object";
        }
    } catch (const std::filesystem::filesystem_error & ex) {
        std::cerr << ex.what() << std::endl;
    }
}
