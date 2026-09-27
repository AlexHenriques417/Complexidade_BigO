#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencher_vetor(int n, int v[n], int auto_fill) {
    for (int i = 0; i < n; i++) {
        if (auto_fill) v[i] = rand() % 20;
        else { printf("V[%d]: ", i); scanf("%d", &v[i]); }
    }
}

void preencher_matriz(int n, int m[n][n], int auto_fill) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (auto_fill) m[i][j] = rand() % 20;
            else { printf("M[%d][%d]: ", i, j); scanf("%d", &m[i][j]); }
        }
    }
}

// Questão 01
int funcao1(int n, int v[n], int k, int busk[k]) {
    int total = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (busk[i] == v[j]) total++;
        }
    }
    return total;
}

// Questão 02
int pairAnalysisTriangularMatrix(int n, int m[n][n]) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if ((m[i][j] + m[j][i]) % 5 == 0) {
                printf("\n%d + %d = %d -> MULTIPLO DE 5\n",
                       m[i][j],
                       m[j][i],
                       m[i][j] + m[j][i]);

                total++;
            }
        }
    }
    return total;
}

// Questão 03
int comparar_matrizes_3d(int n, int A[n][n][n], int B[n][n][n]) {
    int somaA = 0;
    int somaB = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                somaA += A[i][j][k];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                somaB += B[i][j][k];
            }
        }
    }

    if (somaA >= somaB) {
        return 1;
    }

    return 0;
}

// Questão 04
long long processar_vetor(int n, int v[n]) {
    long long soma = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            soma += v[i];
        } else {
            soma += fatorial(v[i]);
        }
    }

    return soma;
}

// Questão 05
int busca_binaria(int n, int v[n], int valor) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (v[meio] == valor) {
            return 1;
        }

        if (v[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return 0;
}

int contar_elementos_presentes(int n, int A[n], int B[n]) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        if (busca_binaria(n, B, A[i])) {
            total++;
        }
    }

    return total;
}

int main() {
    srand(time(NULL));
    int opcao, auto_fill;

    printf("GRUPO: Alex Henriques, Carlos Herriot, Davi Nogueira, Dereck Patrick e Lucas Gabriel\n");

    printf("Escolha a funcao de 1 a 5: ");
    scanf("%d", &opcao);
    printf("Você deseja preencher automaticamente? (1 para SIM e 0 para NÃO): ");
    scanf("%d", &auto_fill);

    if (opcao == 1) {
        int n = 5, k = 2;
        int v[n], busk[k];
        preencher_vetor(n, v, auto_fill);
        preencher_vetor(k, busk, auto_fill);
        printf("Resultado F1: %d\n", funcao1(n, v, k, busk));
    } else if (opcao == 2) {
        int n = 4;
        int m[n][n];
        preencher_matriz(n, m, auto_fill);
        printf("\nResultado F2: %d\n", pairAnalysisTriangularMatrix(n, m));
    } else {
        printf("Opcao invalida");
    }

    return 0;
}