#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zeroPositions;
        int row = matrix.size();
        int column = matrix[0].size();
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if(matrix[i][j] == 0){
                    zeroPositions.push_back({i, j});
                }
            }
        }
        
        for(auto& pos : zeroPositions){
            int r = pos.first;
            int c = pos.second;
            for(int i = 0; i < row; i++){
                matrix[i][c] = 0;
            }
            for(int j = 0; j < column; j++){
                matrix[r][j] = 0;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    
    solution.setZeroes(matrix);
    
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}