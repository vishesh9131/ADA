#include <iostream>

using namespace std;

const int INF = 999999; 

int graph[7][7] = {
    {0, 28, 0, 0, 0, 10, 0},
      {28, 0, 16, 0, 0, 0, 14},
    {0, 16, 0, 12, 0, 0, 0},
    {0, 0, 12, 0, 22, 0, 18},
      {0, 0, 0, 22, 0, 25, 24},
       {10, 0, 0, 0, 25, 0, 0},
    {0, 14, 0, 18, 24, 0, 0}
};
bool ss[7]; 
int n = 7; 

void PA() {
    int edj = 0;
    int minCost = 0;
   
    for (int i = 0; i < 7; i++) {
        ss[i] = false;
    }
    ss[0] = true;

    while (edj < n - 1) {
        int min = INF;
      int x = 0, y = 0;

        for (int i = 0; i < n; i++) {
            if (ss[i]) {
            for (int j = 0; j < n; j++) {
             if (!ss[j] && graph[i][j]) { 
             if (min > graph[i][j]) { //True
                min = graph[i][j];
                x = i; //0
                y = j;  //0
                    }
                }
            }
        }
        }

        cout << "Edge " << x << "-" << y << " : " << graph[x][y] << endl;
        minCost+= graph[x][y];
        ss[y] = true;
        edj++;
    }
cout << "Minimum cost = " << minCost << endl;
}

int main() {
    PA();

    return 0;
}