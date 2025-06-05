#include <iostream>
#include <vector>
#include <algorithm>


// don't forget to implement what did you learn in clean code book



// ====== some important notes =========
// "!" operator reflects the boolean value
// the postfix operator should'nt be in the left side assigment operator
//      while the prefix can do
// the comma operator evalutes from left to right like this (a++, ++a, a++, ++a, a++)
// 
//

int FixSlidingWindow(int arr[] , int n , int k){
    int slow = 0;
    int fast = 0;
    int sum = 0;
    int maxSum = -1;

    while (fast <k){
        sum += arr[fast];
        fast++;
    }

    maxSum = sum;

    while (fast <n) {
        sum -= arr[slow++];
        sum += arr[fast++];
        maxSum = std::max(maxSum , sum);
    }

    return maxSum;
} 


int main() {

    return 0;
}
