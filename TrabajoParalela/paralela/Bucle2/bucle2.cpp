#include <iostream>
#include <chrono>  

using namespace std;
using namespace chrono;


#define MAX 1000

void fillarray(double Array[MAX]) {
    for (int i = 0; i < MAX; i++) {
        Array[i] = 0;
    }
}

void fillarray2(double Array[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        fillarray(Array[i]);
    }
}


int main() {
    double A[MAX][MAX], x[MAX], y[MAX];

    fillarray(x);
    fillarray(y);
    fillarray2(A);

    int i, j;
     auto start = high_resolution_clock::now();
    for (j = 0; j < MAX; j++)
        for (i = 0; i < MAX; i++)
            y[i] += A[i][j]*x[j];

    auto end = high_resolution_clock::now();

    
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Tiempo: " 
         << duration.count() << " ms" << endl;

  
}
