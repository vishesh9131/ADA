#include <iostream>
#include <algorithm>
#include <cstring> // For std::max

using namespace std;

int main() {
    string a1 = "2131434532425342";
    string a2 = "999999999999";

    // Reverse the strings to start addition from the least significant digit
    string rev_a1 = a1;
    string rev_a2 = a2;
    reverse(rev_a1.begin(), rev_a1.end());
    reverse(rev_a2.begin(), rev_a2.end());

    int s1 = rev_a1.size();
    int s2 = rev_a2.size();
    int maxSize = max(s1, s2);
    int res_size = maxSize + 1; // +1 for potential carry over

    // Dynamically allocate arrays for digits
    int* buf1 = new int[maxSize];
    int* buf2 = new int[maxSize];
    int* res = new int[res_size];

    // Initialize arrays to 0
    for(int i = 0; i < maxSize; i++) {
        buf1[i] = (i < s1) ? (rev_a1[i] - '0') : 0;
        buf2[i] = (i < s2) ? (rev_a2[i] - '0') : 0;
        res[i] = 0;
    }
    res[maxSize] = 0; // Initialize the last element for carry

    // Perform addition
    int carry = 0;
    for(int i = 0; i < maxSize; i++) {
        int sum = buf1[i] + buf2[i] + carry;
        carry = sum / 10;
        res[i] = sum % 10;
    }

    // Handle final carry
    if(carry) {
        res[maxSize] += carry;
    }

    // Determine the actual size of the result
    int actualSize = maxSize;
    if(res[maxSize] != 0) {
        actualSize += 1;
    }

    // Reverse the result to get the final sum
    string sumStr = "";
    for(int i = actualSize - 1; i >= 0; i--) {
        sumStr += to_string(res[i]);
    }

    cout << "Sum: " << sumStr << endl;

    // Free dynamically allocated memory
    delete[] buf1;
    delete[] buf2;
    delete[] res;

    return 0;
}