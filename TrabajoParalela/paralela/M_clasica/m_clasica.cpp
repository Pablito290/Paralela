#include <iostream>
#include <vector>
#include <cstdlib> 
#include <chrono>  

using namespace std;
using namespace chrono;


vector<vector<int>> initializeMatrix(int N) {
    return vector<vector<int>>(N, vector<int>(N, 0));
}

vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, int N) {
    vector<vector<int>> result(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

int main(int argc, char* argv[]) {
    
    int N = atoi(argv[1]); // Convertir argumento a entero

    
    
    vector<vector<int>> A = initializeMatrix(N);
    vector<vector<int>> B = initializeMatrix(N);

    
    auto start = high_resolution_clock::now();
    vector<vector<int>> result = multiplyMatrices(A, B, N);
    auto end = high_resolution_clock::now();

    
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Tiempo de multiplicación para una matriz de " << N << "x" << N << ": " 
         << duration.count() << " ms" << endl;

    return 0;
}

