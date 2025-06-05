//
// Created by abdo on 4/30/25.
//

#include "CMakeFiles.h"

#include <iostream>

CMakeFiles::CMakeFiles(const std::filesystem::path path, const std::string projectName, const std::string libName):
 path(path) , projectName(projectName)  , libName(libName){

}


std::vector<std::string> CMakeFiles::getAllContents() {
    return {
        // lib/CMakeLists.txt
        "file(GLOB LIB_SOURCES *.cpp)\n"
        "add_library(" + this->libName + " STATIC ${LIB_SOURCES})\n"
        "target_include_directories(" + this->libName + " PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})",

        // external/CMakeLists.txt
        "file(GLOB EXTERNAL_SOURCES *.cpp)\n"
        "add_library(external_lib STATIC ${EXTERNAL_SOURCES})\n"
        "target_include_directories(external_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})",

        // test/CMakeLists.txt
        "# Testing setup\n"
        "enable_testing()\n\n"
        "# Find GTest package\n"
        "find_package(GTest REQUIRED)\n\n"
        "# Create test executable (only include this if you have test files)\n"
        "file(GLOB TEST_SOURCES \"test/*.cpp\")\n"
        "if(TEST_SOURCES)\n"
        "    add_executable(" + this->projectName + "Tests ${TEST_SOURCES})\n"
        "    target_include_directories(" + this->projectName + "Tests PRIVATE include)\n"
        "    target_link_libraries(" + this->projectName + "Tests PRIVATE \n"
        "        GTest::GTest \n"
        "        GTest::Main\n"
        "        " + this->projectName + "\n"
        "    )\n"
        "    add_test(NAME LibraryTests COMMAND " + this->projectName + "Tests)\n"
        "endif()"
    };
}

std::vector<std::string> CMakeFiles::getAllPathes() {
    return {this->projectName+"/lib/CMakeLists.txt" ,
        this->projectName+ "/external/CMakeLists.txt" ,
        this->projectName+ "/test/CMakeLists.txt"};
}

void CMakeFiles::createCMakeFiles() {
    std::vector<std::string> contents = this->getAllContents();
    std::vector<std::string> pathes = this->getAllPathes();

    for (int i = 0 ;i < contents.size();i++) {
        std::ofstream file(pathes[i]);
        if (!file)
            std::cerr << "there is something wrong";
        file << contents[i];
        file.close();
    }
}




