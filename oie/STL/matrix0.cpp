#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        bool flag[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                flag[i][j] = false;
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    flag[i][j] = true;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (flag[i][j]) {
                    for (int z = 0; z < rows; z++) {
                        matrix[z][j] = 0;
                    }
                    for (int z = 0; z < cols; z++) {
                        matrix[i][z] = 0;
                    }
                }
            }
        }
    }
};

int main() {
    Solution solution;
    
    // Create a sample matrix
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    
    cout << "Original matrix:" << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    // Call the setZeroes function
    solution.setZeroes(matrix);
    
    cout << "\nMatrix after setting zeroes:" << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}