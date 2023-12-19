#include <iostream>
#include <string>

using namespace std;

// Funció per imprimir espais
void imprimirEspais(int n) {
    if (n > 0) {
        cout << ' ';
        imprimirEspais(n - 1);
    }
}

// Funció per imprimir asteriscs
void imprimirAsteriscs(int n) {
    if (n > 0) {
        cout << '*';
        imprimirAsteriscs(n - 1);
    }
}

// Funció per dibuixar una fila de l'arbre
void dibuixarFilaArbre(int alcada, int fila) {
    imprimirEspais(alcada - fila);
    imprimirAsteriscs(2 * fila - 1);
    cout << endl;
}

// Funció per dibuixar el tronc de l'arbre
void dibuixarTroncArbre(int alcada, char caracter) {
    int alcadaTronc = alcada / 2;

    for (int i = 0; i < alcadaTronc; ++i) {
        cout << string(((2 * alcada) + 1) / 2 - 2, ' ') << string(4, caracter) << endl;
    }
}

// Funció principal per dibuixar l'arbre de Nadal amb recursivitat
void dibuixarArbreNadalRecursiu(int alcada, char caracter, int fila) {
    if (fila > alcada) {
        return;
    }

    dibuixarFilaArbre(alcada, fila);
    dibuixarArbreNadalRecursiu(alcada, caracter, fila + 1);
}

// Funció per dibuixar l'arbre de Nadal amb bucles
void dibuixarArbreNadalBucles(int alcada, char caracter) {
    for (int i = 1; i <= alcada; ++i) {
        dibuixarFilaArbre(alcada, i);
    }

    dibuixarTroncArbre(alcada, caracter);
}

// Funció principal per dibuixar l'arbre de Nadal amb recursivitat i bucles
void dibuixarArbreNadal(int alcada, char caracter) {

    // Utilitzant recursivitat
    cout << "\nUtilitzant Recursivitat:\n";
    dibuixarArbreNadalRecursiu(alcada, caracter, 1);
    dibuixarTroncArbre(alcada, caracter);

    // Utilitzant bucles
    cout << "\nUtilitzant Bucles:\n";
    dibuixarArbreNadalBucles(alcada, caracter);
}

// Funció principal
int main() {
    int midaArbre;
    char caracterArbre;

    cout << "Aplicacio de l'Arbre de Nadal\n";

    cout << "Introduiu l'alcada de l'arbre de Nadal: ";
    cin >> midaArbre;

    cout << "Introduiu el caracter que voleu utilitzar per a l'arbre: ";
    cin >> caracterArbre;

    // Crida a la funció per dibuixar l'arbre de Nadal
    dibuixarArbreNadal(midaArbre, caracterArbre);

    return 0;
}
