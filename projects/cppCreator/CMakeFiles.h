//
// Created by abdo on 4/30/25.
//

#ifndef CREATECMAKEFILES_H
#define CREATECMAKEFILES_H
#include <filesystem>
#include <vector>
#include <fstream>

class CMakeFiles {

private:
    std::filesystem::path path;
    std::string projectName;
    std::string libName;

public:
    CMakeFiles() = default;
    CMakeFiles(const std::filesystem::path path , const std::string projectName ,const std::string libName);
    std::vector<std::string> getAllPathes();
    std::vector<std::string> getAllContents();
    void createCMakeFiles();
    void createAllFiles();
};



#endif //CREATECMAKEFILES_H
