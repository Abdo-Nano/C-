#include <iostream>
#include "BookManagement.h"
#include "Member.h"
#include "MemberManagement.h"
#include "Library.h"
#include <vector>
#include <list>




/*
 * ======== some important notes from uncle Chatgpt ===========
 *
 * --> Many standard C++ APIs (and even STL containers like std::map::find)
 *      return pointers or iterators for search functions, not copies.
 *
 * --> Prefer safety and encapsulation over minor performance gains,
 *      especially when learning and building reusable components.
 *
 * --> Advantages when you separate the logic from I/O
        Follows SRP — method only prepares data.
        Reusable in different contexts (CLI, GUI, Web).
        Testable — you can check if returned titles are correct in unit tests.
        Flexible — you can add more info later if needed.

* --> returning iterator VS object Itself Vs optional<reference_wrapper>
*       - For retrieval (without modification): std::optional<std::reference_wrapper<T>> is great.
*       - For deletion: Always use iterators directly to avoid extra lookups and invalid API usage.
*       - If performance is critical, prefer std::optional<std::reference_wrapper<T>>.
*       - If you need to modify the object, return an iterator.
        - If safety is the top priority, return a copy of the object.
*/


#include <fstream>
#include <sys/stat.h>   // for stat()
#include <unistd.h>     // for access(), getuid(), getgid()
#include <sys/types.h>  // for uid_t, gid_t
#include <pwd.h>        // for getpwuid()
#include <grp.h>        // for getgrgid()
#include <fcntl.h>      // for open(), O_RDONLY, etc.
#include <sys/stat.h>
#include <filesystem>
#include <signal.h>


using namespace std::filesystem;

bool isReadable(const std::string & path) {
   return access(path.c_str() , F_OK) == 0;
}

bool isWritable(const std::string & path) {
    return access(path.c_str() , W_OK) == 0;
}


std::string readFile(const std::string & path) {
    if (!isReadable(path)) {
        throw std::runtime_error("the file is not readable");
    }

    std::ifstream file(path);
    if (!file){
        throw std::runtime_error("failed to open the file");
    }

}


int main() {
    std::cout << "Hello world" << std::endl;
    path proc = "/proc/";

    if (exists(proc) && is_directory(proc)) {
        for (auto const & entry : directory_iterator(proc)) {
            struct stat info;
            path file = entry.path();
            if (!stat(file.c_str(), &info) == 0) {
                perror("stat Faild");
            }

            kill(12 , SIGTERM);
            std::cout << info.st_uid << std::endl;
        }
    }
    return 0;
}
