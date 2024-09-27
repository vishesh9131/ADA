#include <iostream>
#include <iomanip>

class pascals_triangle {
public:
    static int Ncr(int n, int r) {
        int result = 1;
        for (int i = 0; i < r; i++) {
            result = result * (n - i);
            result = result / (i + 1);
        }
        return result;
    }

    static void printPascalsTriangle(int n) {
        for (int i = 1; i <= n; i++) {
            // Print spaces
            for (int j = 1; j <= n - i; j++) {
                std::cout << " ";
            }
            // Print numbers
            for (int k = 1; k <= i; k++) {
                std::cout << Ncr(i - 1, k - 1) << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int n = 2;
    pascals_triangle::printPascalsTriangle(n);
    return 0;
}