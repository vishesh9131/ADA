#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int fact(int n) {
    int ans = 1;
    for (int i = n; i > 0; i--) {
        ans *= i;
    }
    return ans;
}

vector<int> perm(vector<int> arr) {
    int ub = fact(arr.size());
    for (int i = 0; i < ub; i++) {
        if (i + 2 < arr.size()) {
            swap(arr[i + 1], arr[i + 2]);
        }
        if (i + 1 < arr.size()) {
            swap(arr[i], arr[i + 1]);
        }
    }
    return arr;
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> result = perm(arr);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}