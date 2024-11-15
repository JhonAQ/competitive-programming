#include <iostream>
#include <limits>

using namespace std;

/* ABREVIACIONES
* El codigo seria demasiado engorroso con variables descriptivas
* así que se usan las siguientes abreviaciones: 
* cCity = Ciudad Actual
* dCity = ciudad Destino
* rutaA = Ruta Actual
* idxR = Indice de Ruta
* cosA = Costo actual
* cosMin = Costo Minimo
* cosNext = Costo siguiente
*/

// Función recursiva SIN memoización para encontrar los caminos más seguros
void solveSinMemo(char cCity, char dCity, int costos[10][10], char rutaA[], int idxR, int cosA, int &cosMin, char rutasOptimas[][11], int &numRutasOptimas) {
    // Caso base: hemos llegado a la ciudad destino
    if (cCity == dCity) {
        rutaA[idxR] = dCity;
        rutaA[idxR + 1] = '\0';

        if (cosA < cosMin) {
            cosMin = cosA;
            numRutasOptimas = 1;
            for (int i = 0; i <= idxR; ++i) {
                rutasOptimas[0][i] = rutaA[i];
            }
            rutasOptimas[0][idxR + 1] = '\0';
        } else if (cosA == cosMin) {
            for (int i = 0; i <= idxR; ++i) {
                rutasOptimas[numRutasOptimas][i] = rutaA[i];
            }
            rutasOptimas[numRutasOptimas][idxR + 1] = '\0';
            numRutasOptimas++;
        }
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (costos[cCity - 'A'][i] != -1) {
            rutaA[idxR] = cCity;
            solveSinMemo(i + 'A', dCity, costos, rutaA, idxR + 1, cosA + costos[cCity - 'A'][i], cosMin, rutasOptimas, numRutasOptimas);
        }
    }
}

// Función recursiva CON memoización para encontrar los caminos más seguros
int memo[10][10];

int solveConMemo(char cCity, char dCity, int costos[10][10]) {
    if (cCity == dCity) {
        return 0;
    }

    if (memo[cCity - 'A'][dCity - 'A'] != -1) {
        return memo[cCity - 'A'][dCity - 'A'];
    }

    int cosMin = numeric_limits<int>::max();

    for (int i = 0; i < 10; i++) {
        if (costos[cCity - 'A'][i] != -1) {
            int costo = costos[cCity - 'A'][i] + solveConMemo(i + 'A', dCity, costos);
            if (costo < cosMin) {
                cosMin = costo;
            }
        }
    }

    memo[cCity - 'A'][dCity - 'A'] = cosMin;
    return cosMin;
}

int main() {
    int costos[10][10] = {
      //  A   B   C   D   E   F   G   H   I   J
        {-1,  2,  4,  3, -1, -1, -1, -1, -1, -1}, // A
        {-1, -1, -1, -1,  7,  4,  6, -1, -1, -1}, // B
        {-1, -1, -1, -1,  3,  2,  4, -1, -1, -1}, // C
        {-1, -1, -1, -1,  4,  1,  5, -1, -1, -1}, // D
        {-1, -1, -1, -1, -1, -1, -1,  1,  4, -1}, // E
        {-1, -1, -1, -1, -1, -1, -1,  6,  3, -1}, // F
        {-1, -1, -1, -1, -1, -1, -1,  3,  3, -1}, // G
        {-1, -1, -1, -1, -1, -1, -1, -1, -1,  3}, // H
        {-1, -1, -1, -1, -1, -1, -1, -1, -1,  4}, // I
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}  // J
    };

    // Inicialización de variables para rutas óptimas
    char rutasOptimas[100][11];
    int numRutasOptimas = 0;

    int cosMinSinMemo = numeric_limits<int>::max();
    char rutaSinMemo[11];
    solveSinMemo('A', 'J', costos, rutaSinMemo, 0, 0, cosMinSinMemo, rutasOptimas, numRutasOptimas);
    cout << "Costo minimo sin memoizacion: " << cosMinSinMemo << endl;


    // Inicializamos memo
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            memo[i][j] = -1;

    int cosMinConMemo = solveConMemo('A', 'J', costos);

    cout << "Costo minimo con memoizacion: " << cosMinConMemo << endl << endl;

    cout << "Rutas optimas:" << endl;
    for (int i = 0; i < numRutasOptimas; ++i)
        cout << rutasOptimas[i] << endl;

    return 0;
}
