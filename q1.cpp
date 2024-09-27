#include <iostream>

using namespace std;

void ss(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }}
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

void p(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
int employeeIDs[] = {1023, 1001, 1045, 1032, 1015};
int size =5;
cout << "Original employee id array : ";
    p(employeeIDs, size);
    ss(employeeIDs, size);

    cout << "Sorted employee ID array : ";
    p(employeeIDs, size);
    return 0;}
