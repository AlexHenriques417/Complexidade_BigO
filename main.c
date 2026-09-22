#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencher_vetor(int n, int v[n], int auto_fill) {
    for (int i = 0; i < n; i++) {
        if (auto_fill) v[i] = rand() % 20;
        else { printf("V[%d]: ", i); scanf("%d", &v[i]); }
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


// Questão 03 


// Questão 04


// Questão 05



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
    }

    return 0;
}