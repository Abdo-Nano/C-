#include <iostream>
#include <queue>
#include <algorithm>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>


void printDeque(const std::deque<int> & data) {

    for (int value : data) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int countLowers(const std::string & word) {

    int lowersCounter = 0;

    for (char ch : word ) {
        if (islower(ch))
            lowersCounter++;
    }

    return lowersCounter;
}

void printVector(const std::vector<std::string> & items) {

    for (auto & item : items) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}


int slidingWindow(const std::vector<int> & arr , int k) {
    std::queue<int> q;
    std::vector<int> result;

    int sum = 0;
    for (int i = 0 ;i < k ;i++) {
        sum += arr[i];
        q.push(arr[i]);
    }
    result.push_back(sum);

    for (int i = 1 ;i < arr.size() ;i++) {
        sum -= q.front();
        q.pop();
        q.push(arr[i]);
        sum += q.back();
        result.push_back(sum);
    }

    return *std::max_element(result.begin() , result.end());
}


void reverse_queue_with_stack(std::queue<int> & q) {
    std::stack<int> stk;

    while (!q.empty()) {
        stk.push(q.front());
        q.pop();
    }

    while (!stk.empty()) {
        q.push(stk.top());
        stk.pop();
    }
}

void print_queue(std::queue<int> q) {
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }

    std::cout << std::endl;

}

void all_words_prefix() {
    int n;
    std::cin >> n;

    std::map<std::string , std::vector<std::string>> container;

    while (n--) {
        std::string word;
        std::cin >> word;

        std::string curr {};
        for (const auto ch : word) {
            curr += ch;
            container[curr].push_back(word);
        }
    }

    std::cin >> n;
    while (n--) {

        std::string prefix;
        std::cin >> prefix;

        for (const auto str : container[prefix])
            std::cout << str << " ";
        std::cout << std::endl;
    }
}

std::stack<int> storeDigitsInStack(int number) {
    std::stack<int> digits;
    while (number) {
        digits.push(number % 10);
        number /= 10;
    }
    return digits;
}

int reverseStackDigits(std::stack<int> digits) {
    int result = 0;
    int multiplier = 1;
    while (!digits.empty()) {
        result += digits.top() * multiplier;
        digits.pop();
        multiplier *= 10;
    }
    return result;
}

int reverseNumber(int number) {

    if (number == 0) return 0;
    std::stack<int> digits = storeDigitsInStack(number);
    int result = reverseStackDigits(digits);

    return result;
}


int main() {


    return 0;
}
