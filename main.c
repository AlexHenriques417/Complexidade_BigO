#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// FUNÇÕES AUXILIARES DE PREENCHIMENTO E IMPRESSÃO

void preencher_vetor(int n, int v[n], int auto_fill) {
    for (int i = 0; i < n; i++) {
        if (auto_fill) v[i] = rand() % 20;
        else { printf("V[%d]: ", i); scanf("%d", &v[i]); }
    }
}

void imprimir_vetor(int n, int v[n], const char *nome) {
    printf("%s = [ ", nome);
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    printf("]\n");
}

void preencher_matriz(int n, int m[n][n], int auto_fill) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (auto_fill) m[i][j] = rand() % 20;
            else { printf("M[%d][%d]: ", i, j); scanf("%d", &m[i][j]); }
        }
    }
}

void imprimir_matriz(int n, int m[n][n], const char *nome) {
    printf("\nMatriz %s (%dx%d):\n", nome, n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }
}

void preencher_matriz_3d(int n, int m[n][n][n], int auto_fill) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                m[i][j][k] = auto_fill ? (rand() % 20) : 1;
}

void imprimir_matriz_3d(int n, int m[n][n][n], const char *nome) {
    printf("\nMatriz 3D %s (%dx%dx%d):\n", nome, n, n, n);
    for (int i = 0; i < n; i++) {
        printf("Fatia z = %d:\n", i);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                printf("%3d ", m[i][j][k]);
            }
            printf("\n");
        }
    }
}

int comparar_inteiros(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// QUESTÃO 01

int funcao1(int n, int v[n], int k, int busk[k]) {
    int total = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (busk[i] == v[j]) total++;
        }
    }
    return total;
}

// QUESTÃO 02

int pairAnalysisTriangularMatrix(int n, int m[n][n]) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if ((m[i][j] + m[j][i]) % 5 == 0) {
                printf("%d + %d = %d -> MULTIPLO DE 5\n",
                       m[i][j], m[j][i], m[i][j] + m[j][i]);
                total++;
            }
        }
    }
    return total;
}

// QUESTÃO 03

int comparar_matrizes_3d(int n, int A[n][n][n], int B[n][n][n]) {
    long long somaA = 0, somaB = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                somaA += A[i][j][k];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                somaB += B[i][j][k];

    printf("Soma A: %lld | Soma B: %lld\n", somaA, somaB);
    return (somaA >= somaB) ? 1 : 0;
}

// QUESTÃO 04

unsigned long long fatorial(int n) {
    if (n <= 1) return 1;
    unsigned long long fat = 1;
    for (int i = 2; i <= n; i++) fat *= i;
    return fat;
}

unsigned long long processar_vetor(int n, int v[n]) {
    unsigned long long soma = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            soma += v[i];
        } else {
            soma += fatorial(v[i]);
        }
    }
    return soma;
}

// QUESTÃO 05

int busca_binaria(int n, int v[n], int valor) {
    int inicio = 0, fim = n - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (v[meio] == valor) return 1;
        if (v[meio] < valor) inicio = meio + 1;
        else fim = meio - 1;
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

// MENU PRINCIPAL

int main() {
    srand(time(NULL));
    int opcao, auto_fill;

    printf("GRUPO: Alex Henriques, Davi Nogueira, Dereck Patrick e Lucas Gabriel\n\n");
    printf("Escolha a funcao (1 a 5): ");
    scanf("%d", &opcao);
    printf("Preencher automaticamente? (1 para SIM e 0 para NAO): ");
    scanf("%d", &auto_fill);
    printf("\n------------------------------------------------\n");

    if (opcao == 1) {
        int n = 10, k = 3;
        int v[n], busk[k];
        preencher_vetor(n, v, auto_fill);
        preencher_vetor(k, busk, auto_fill);
        
        imprimir_vetor(n, v, "Vetor Principal (n)");
        imprimir_vetor(k, busk, "Vetor Buscados (k)");
        
        printf("\nResultado F1: %d\n", funcao1(n, v, k, busk));

    } else if (opcao == 2) {
        int n = 4;
        int m[n][n];
        preencher_matriz(n, m, auto_fill);
        
        imprimir_matriz(n, m, "M");
        printf("\nPares validos:\n");
        printf("Resultado F2: %d\n", pairAnalysisTriangularMatrix(n, m));

    } else if (opcao == 3) {
        int n = 3;
        int A[n][n][n], B[n][n][n];
        preencher_matriz_3d(n, A, auto_fill);
        preencher_matriz_3d(n, B, auto_fill);
        
        imprimir_matriz_3d(n, A, "A");
        imprimir_matriz_3d(n, B, "B");
        
        printf("\nResultado F3: %d\n", comparar_matrizes_3d(n, A, B));

    } else if (opcao == 4) {
        int n = 6;
        int v[n];
        preencher_vetor(n, v, auto_fill);
        
        for (int i = 0; i < n && auto_fill; i++) v[i] = rand() % 12;
        
        imprimir_vetor(n, v, "Vetor V");
        printf("\nResultado F4: %llu\n", processar_vetor(n, v));

    } else if (opcao == 5) {
        int n = 10;
        int A[n], B[n];
        preencher_vetor(n, A, auto_fill);
        preencher_vetor(n, B, auto_fill);
        
        qsort(B, n, sizeof(int), comparar_inteiros);
        
        imprimir_vetor(n, A, "Vetor A (Nao Ordenado)");
        imprimir_vetor(n, B, "Vetor B (Ordenado)");
        
        printf("\nResultado F5: %d\n", contar_elementos_presentes(n, A, B));

    } else {
        printf("Opcao invalida!\n");
    }

    return 0;
}