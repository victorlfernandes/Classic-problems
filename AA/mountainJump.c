#include <stdio.h>
#include <stdlib.h>

int min(int n, int *vetor) {
    int aux = 1902309232;
    for (int i = 0; i < n; i++) 
        if (vetor[i] < aux)
            aux = vetor[i];
    return aux;
}

int calculaEnergia(int nMontanhas, int *altura) {

    int *caminhos = malloc(sizeof(int));
    int k = 1;
    caminhos[0] = 0;
    int i = 1;

    while (i < nMontanhas) {

        int *energias = malloc(sizeof(int));
        int j = 1;
        energias[0] = caminhos[i - 1] + abs(altura[i - 1] - altura[i]);
        if (i > 1) {
            j++;
            energias = realloc(energias, j * sizeof(int));
            energias[j - 1] = caminhos[i - 2] + abs(altura[i - 2] - altura[i]);
        }
        k++;
        caminhos = realloc(caminhos, k * sizeof(int));
        caminhos[k - 1] = min(j, energias);
        i++;
        free(energias);
    }

    int retorno = caminhos[k - 1];
    free(caminhos);
    return retorno;
}

int main() {

    int nMontanhas = 0;
    scanf(" %d\n", &nMontanhas);

    int *altura = malloc(nMontanhas * sizeof(int));
    for (int i = 0; i < nMontanhas; i++)
        scanf(" %d", &altura[i]);

    int energiaMinina = calculaEnergia(nMontanhas, altura);
    printf("%d\n", energiaMinina);

    free(altura);
    return 0;
}