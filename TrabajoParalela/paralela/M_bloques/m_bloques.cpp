#include <iostream>
#include <vector>
#include <cstdlib> 
#include <chrono>   

using namespace std;
using namespace chrono;


#define Bloque 128


vector<vector<int>> initializeMatrix(int N) {
    return vector<vector<int>>(N, vector<int>(N, 0));
}


vector<vector<int>> multiplyMatricesBlocked(const vector<vector<int>>& A, const vector<vector<int>>& B, int N) {
    vector<vector<int>> result(N, vector<int>(N, 0));


    for (int bi = 0; bi < N; bi += Bloque) {  
        for (int bj = 0; bj < N; bj += Bloque) {  
            for (int bk = 0; bk < N; bk += Bloque) {  

                
                for (int i = bi; i < min(bi + Bloque, N); i++) {
                    for (int j = bj; j < min(bj + Bloque, N); j++) {
                        for (int k = bk; k < min(bk + Bloque, N); k++) {
                            result[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
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
    vector<vector<int>> result = multiplyMatricesBlocked(A, B, N);
    auto end = high_resolution_clock::now();

    
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Tiempo de multiplicación (bloques) para una matriz de " << N << "x" << N << ": " 
         << duration.count() << " ms" << endl;

    return 0;
}

