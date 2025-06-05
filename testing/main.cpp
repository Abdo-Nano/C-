#include<iostream>
#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <array>
#include <chrono>
#include <thread>
#include <unordered_map>
#include <numeric>
using namespace std;

/*
 * most of the problems depend on the frequency trick
 *
 *
 */

void solve(int arr[], size_t size) {
    if (size < 2) {
        cout << "Array should have at least two elements!" << endl;
        return;
    }

    int first = arr[0];
    int second = INT_MIN;  // Initialize second with smallest possible value

    for (int i = 1; i < size; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] < first) {
            second = arr[i];
        }
    }

    cout << first <<  endl;
    cout << second << endl;
}


void another(int arr [] , size_t size) {
    int frequancy [size + 1] = {0};
    for (int i = 0 ;i < size ;i++) {
        frequancy[arr[i]]++;
    }
    for (int i = 0 ;i < size ;i++) {
       cout << frequancy[i] << " ";
    }
}

bool isIncreasing(int arr[] , int size) {

    for (int i = 1;i < size ;i++) {
        if (arr[i] < arr[i -1])
            return false;
    }
    return true;
}

void printArray(int arr[] , size_t size) {
    for (int i = 0 ;i < size ;i++)
        cout << arr[i] << " ";
    cout << endl;
}

void minMax(int arr[] , size_t size) {
    int minValue = *min_element(arr , arr + size);
    int maxValue = *max_element(arr , arr + size);

    for (int i = 0 ;i < size ;i++) {
        if (arr[i] == minValue)
            arr[i] = maxValue;
        else if (arr[i] == maxValue)
            arr[i] = minValue;
    }

   printArray(arr ,size);

}

void uniqueNumbers(int arr[] , size_t size) {
    int i = 0;
    while (i < size){
        cout << arr[i] << " ";
        int j = i + 1;
        while (arr[j] == arr[i] && j < size) {
            j++;
        }
        i = j;
    }
    cout << endl;
}


bool isPlaindrom(int arr[] , size_t size) {

    int left = 0;
    int right = size - 1;

    while (left <= right) {
        if (arr[left] != arr[right])
            return false;
        left++;
        right--;
    }
    return true;
}

// not completed
void pairing(int arr[] , size_t size) {
    // A[i] + A[j] + j -i
    // 1 <= i < j <= N -> size of an array

    int minValue = INT_MAX;
    int j = 0;
    int i = 1;
    while (j < size) {
        j = i + 1;
        int exptr = arr[i] + arr[j] + j - i;
        minValue = min(minValue , exptr);
        i++;
    }

    cout << minValue << endl;
}


void threeMinimum(int arr[] , size_t size) {
    if (size < 3)
        cout << "the size should be at least 3 numbers" << endl;
    int first = INT_MAX;
    int second = INT_MAX;
    int third = INT_MAX;

    for (int i = 0 ; i < size ;i++) {
        if (arr[i] < first) {
            second = first;
            first = arr[i];
        }
        else if (arr[i] < second && arr[i] > first) {
            third = second;
            second = arr[i];
        }
        else if (arr[i] < third && arr[i] > second) {
            third = arr[i];
        }
    }
    cout << first << endl;
    cout << second << endl;
    cout << third << endl;
}


int mostFrequent(int arr[], size_t size) {
    // Find the maximum absolute value in arr[]
    int maxElement = *std::max_element(arr, arr + size, [](int a, int b) {
        return std::abs(a) < std::abs(b);
    });

    // Create a frequency array of size (maxElement + 1) initialized to 0
    int frequancy[maxElement + 1] = {0};

    // Count occurrences
    for (size_t i = 0; i < size; i++) {
        frequancy[std::abs(arr[i])]++;
    }

    // Find the most frequent number
    int maxFreq = 0, mostFrequentValue = arr[0];
    for (size_t i = 0; i <= maxElement; i++) {
        if (frequancy[i] > maxFreq) {
            maxFreq = frequancy[i];
            mostFrequentValue = i;  // Since `i` is the number that appeared the most
        }
    }

    return mostFrequentValue;
}


void

void digitsFrequency() {
    int result[10] = {0};  // Array to store the count of digits (0-9)
    int number;
    char choice;

    do {
        cout << "Enter a digit (0-9): ";
        cin >> number;

        // Validate input to avoid out-of-bounds errors
        if (number >= 0 && number <= 9) {
            result[number]++;
        } else {
            cout << "Invalid input! Please enter a digit between 0 and 9." << endl;
        }

        cout << "Do you want to enter again? (y/n): ";
        cin >> choice;

    } while (choice != 'n' && choice != 'N'); // Allow 'N' as well

    cout << "\nDigit Frequency:\n";
    for (int i = 0; i < 10; i++) {
        cout << i << " -> " << result[i] << endl;
    }
}

void uniquenumbers(int arr[] , size_t size) {
    int maxValue = *max_element(arr , arr + size);
    int frequency [maxValue+ 1] = {0};
    for (int i = 0 ;i < size ;i++) {
        if (frequency[arr[i]] == 0) {
            cout << arr[i] << " ";
            frequency[arr[i]]++;
        }
    }
    cout << endl;
}

// the max value in the array is 500
void sorting_numbers(int arr[] , size_t size) {

}


// done
void conc(string first , string second) {
    int i = 0 , j = 0;
    while (i < first.size() && j < second.size()) {
        cout << first[i] << second[j];
        i++;
        j++;
    }

    if (i < first.size())
        for (int x = i ; x < first.size() ;x++)
            cout << first[x];

    if (j < second.size())
        for (int x = j;x < second.size() ;x++)
            cout << second[x];

}

void lettersFrequency(const string & str) {

    // don't forget to initialize the array to a value cuz the garbage collection
    int frequency [123] = {0};
    for (int i = 0 ;i < str.size() ;i++) {
       if (str[i] >= 'a' && str[i] <= 'z') {
           int ch = str[i];
           frequency[ch]++;
       }
    }

    for (int i = 97 ;i < 123;i++) {
        if (frequency[i] > 0) {
            char ch = i;
            cout << ch << " " << frequency[i] << endl;
        }
    }
}

bool isPrefix(string first , string second) {
    int i = 0;
    int j = 0;

    while (i < first.size()) {
        if (first[i] != second[j])
            return false;
        i++;
        j++;
    }
    return true;
}


bool isSubstring(const std::string& first, const std::string& second) {
    int m = first.size(), n = second.size();

    if (m > n) return false;

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (second[i + j] != first[j])
                break;
        }
        if (j == m) return true;
    }
    return false;
}


bool isSubsequence(const string & first , const string & second) {
    /* ========= some tricks =============
     * brief the code as you can
     * focus on edge cases
     */
    int i = 0;
    int j = 0;
    while (i < first.size() && j < second.size()) {
        if (first[i] == second[j]) {
            i++;
        }
        j++;
    }
    return i == first.size();
}

// not completed
void strToInt(string number) {

    int result = 0;
    for (int i = 0 ;i < number.size() ;i++) {

    }
}

void grouping(const string & str) {
    for (int i = 0;i < str.size() ;i++) {
        if (i != 0 && str[i -1] == str[i])
            cout << " ";
        cout << str[i];
    }
}
int maxMatrix(int arr[3][5] , size_t rows , size_t cols) {
    int maxValue = INT_MIN;

    for (int row = 0 ; row < rows ; row++) {
        for (int col = 0 ; col < cols ; col++) {
            maxValue = max(arr[row][col] , maxValue);
        }
    }

    return maxValue;
}

void specialPrint(int arr[3][5]) {
    int firstRow = 0;
    int lastRow = 0;

    for (int row = 0 ; row < 3 ; row++) {
        firstRow += arr[row][0];
        lastRow += arr[row][4];
    }

    int i = 0;
    int j = 0;
    int rightDiagonal = 0;
    while (i < 3 && j < 5) {
        rightDiagonal += arr[i++][j++];
    }
}


void swapMatrix(int arr[3][5]) {
    int row = 0;
    while (row < 3) {
        swap(arr[row][0] , arr[row][4]);
        row++;
    }
    // printMatrix(arr);
}

int greedyRobot(int arr[3][5]) {

    // it just moves either right , bottom or diagonal
    // we want to get the right , bottom and diagonal and return the position of the max
    return 0;
}

void smallerRow(int arr[3][4] , int queries) {
    for (int i = 0 ; i < queries ;++i) {
        // rows
        int first , second;
        cout << "enter first" << endl;
        cin.ignore() >> first;

        cout << "enter second" << endl;
        cin.ignore() >> second;

        int col = 0;
        bool done = true;
        while (col < 4) {
            if (arr[first][col] > arr[second][col]) {
                cout << "No" << endl;
                done = false;
                break;
            }
            col++;
        }
        if (done)
            cout << "yes" << endl;
    }
}

int sumTraingular(int arr[3][3]) {

    int result = 0;
    int col = 0;
    for (int i = 0 ;i < 3 ;i++) {
        int row = 0;
        for (int j = 0 ; j <= col ; ++j) {
            result += arr[row][col];
            row++;
        }
        col++;
    }

    return result;
}


void printMatrix(int arr[4][3]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


void transpose(int arr[3][4], int result[4][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            result[j][i] = arr[i][j];  // Transposing elements
        }
    }
}

int first (int a , int b , int c) {
    return max(a , max(b , c));
}

int second(int a , int b , int c , int d) {
    return max(first(a,b,c) , d);
}

int third(int a , int b , int c , int d , int f) {
    return max(second(a , b , c , d) , f);
}

string reverse_string(const string & str) {

    string result (str.size()  , ' ');
    int j = 0;
    for (int i = (int) result.size() -1 ;i >= 0 ;i--) {
        result[i] = str[j];
        j++;
    }

    return result;
}

void set_powers(int arr[] , int len , int m) {
    for (int i = 0 ; i  < len ;i++) {
        arr[i] = pow(m , i);
    }

    for (int i = 0 ;i < len ;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool is_prime(int number) {
    if (number < 2) return false; // 0 and 1 are not prime numbers
    if (number == 2) return true; // 2 is the only even prime number
    if (number % 2 == 0) return false; // Even numbers >2 are not prime

    for (int i = 3; i <= sqrt(number); i += 2) { // Only check odd numbers
        if (number % i == 0)
            return false;
    }
    return true;
}

int nth_prime(int number) {
    int i = 2;
    int n = 0;

    while (n < number) {
        if (is_prime(i))
            n++;
        i++;
    }
    return i -1;
}

bool starts_with(const string & str , const string & pattern , int pos) {
    string result;
    for (int i = pos ; i < str.size();i++) {
            if (result.size() <= pattern.size() && result == pattern)
                return true;
            result += str[i];
    }
    return false;
}

string replace_str(string & str , const string & pattern ,const string& to) {
    // aabcabaaad
    size_t size = to.size();
    int i = 0;
    while (i < str.size()) {
        if (starts_with(str , pattern , i)) {
            str.replace(i , pattern.size() , to);
        }
        i += (size > 0)? size : 1;
    }
    return str;
}


void print_traingle(int levels) {
    if (levels == 0)
        return;
    for (int i = 0 ;i < levels ;i++)
        cout << "*";
    cout << endl;
    print_traingle(levels -1);
}

int ThreeNPlusOne(int number) {
    cout << number << " ";
    if (number == 1)
        return 1;

    if (number % 2 == 0)
        return 1 + ThreeNPlusOne(number / 2);
    return 1 + ThreeNPlusOne(number * 3 + 1);
}

int my_pow(int value , int p = 2) {
    if (p == 0)
        return 1;
    return value * my_pow(value , --p);
}

int arr_max(int arr[] , int len) {
    if (len < 0)
        return INT_MIN;
    return max(arr[len] , arr_max(arr , --len));
}

int arr_sum(int arr[] , int len) {
    if (len < 0)
        return 0;
    return arr[len] + arr_sum(arr , --len);
}
float print_average(int arr[], int len) {

    if (len == 0) return 0; // Avoid division by zero

    float sum = arr_sum(arr, len);
    return sum / len;
}

void arr_increment(int arr[] , int len) {
    if (len < 0) {
        cout << endl;
        return;
    }
    arr[len] += len;
    cout << arr[len] << " ";
    arr_increment(arr , --len);
}


void array_accumulation(int arr[] , int len) {
    if (len == 0) {
        cout << endl;
        return;
    }
    int sum = accumulate(arr , arr + len , 0);
    cout << sum << " ";
    array_accumulation(arr , --len);
}

void left_max(int arr[] , int len) {
    if (len < 0) {
        cout << endl;
        return;
    }
    int maxValue = *max_element(arr , arr+len);
    arr[len] = maxValue;
    cout << arr[len] << " ";
    left_max(arr , --len);
}

void right_max(int arr[], int len, int start_position = 0) {

    if (start_position == len - 1)
        return;
    right_max(arr , len , start_position + 1);
    arr[start_position] = max(arr[start_position] , arr[start_position +1]);

}

int suffix_sum(int arr [] , int len , int k) {
    if (k == 0)
        return 0;
    return arr[len] + suffix_sum(arr,len -1 , k -1);
}

bool is_palindrom(int arr[] , int first , int second) {
    if (first >= second) {
        return true;
    }
    if (arr[first] != arr[second])
        return false;
    return is_palindrom(arr , first + 1 , second -1);
}

bool is_prefix(const string & main , const string & prefix , int start_position = 0) {
    if (start_position == prefix.size())
        return true;
    if (main[start_position] != prefix[start_position])
        return false;
    return is_prefix(main , prefix , start_position + 1);
}

bool isPrime(int number, int i = 3) {
    if (number == 2)
        return true;
    if (number <= 1 || number % 2 == 0)
        return false;
    if (i * i > number)  // Instead of `if (number == i)`
        return true;
    if (number % i == 0)
        return false;
    return isPrime(number, i + 2); // Skip even numbers, only test odd divisors
}

int countPrimes(int start, int end) {
    if (start > end)
        return 0;
    if (isPrime(start))
        return 1 + countPrimes(start + 1, end);
    return countPrimes(start + 1, end);
}

// not completed
int path_sum(int grid [100][100] , int row , int col , int ROWS , int COLS) {
    return 0;
}

// it's so important
int fibonacci(int number) {
    // 6
    if (number <= 1)
        return 1;
    return fibonacci(number -1 ) + fibonacci(number -2);
}






int main(int argc , char ** argv) {
    std::cout << "Hello world" << std::endl;
    return 0;
}
