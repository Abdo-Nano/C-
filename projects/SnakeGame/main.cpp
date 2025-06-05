#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>
#include <algorithm>

void simplifyPath(const std::string& path) {
    std::stringstream ss(path);
    std::string token;
    std::stack<std::string> stk;

    // Split by '/' and process each token
    while (std::getline(ss, token, '/')) {
        if (token.empty() || token == ".") {
            continue; // skip empty and "."
        } else if (token == "..") {
            if (!stk.empty()) stk.pop(); // go up one level
        } else {
            stk.push(token); // valid directory
        }
    }

    // Build the result path
    std::vector<std::string> parts;
    while (!stk.empty()) {
        parts.push_back(stk.top());
        stk.pop();
    }
    std::reverse(parts.begin(), parts.end());

    std::string result;
    for (const auto& part : parts) {
        result += "/" + part;
    }

    if (result.empty()) result = "/";

}

int main() {
    std::cout << "Hello , world" << std::endl;
    simplifyPath("/.../a/../b/c/../d/.");
}