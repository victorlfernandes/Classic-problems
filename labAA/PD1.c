#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int min(int a, int b, int c) {
    if (a < b && a < c)
        return a;
    if (b < c)
        return b;
    return c;
}

int melhorPreco(int nDias, int precos[3], int *dias) {

    int diasAnalisados = dias[nDias - 1] + 1;
    int *melhorValorDiario = calloc(diasAnalisados, sizeof(int));

    for (int i = 1; i <= diasAnalisados; i++) {

        bool flag = false;
        for (int j = 0; j < nDias; j++)
            if (i == dias[j])
                flag = true;

        if (flag) {
            melhorValorDiario[i] = min(
                melhorValorDiario[max(i - 30, 0)] + precos[2], 
                melhorValorDiario[max(i - 7, 0)] + precos[1], 
                melhorValorDiario[max(i - 1, 0)] + precos[0]
            );
        }
        else 
            melhorValorDiario[i] = melhorValorDiario[i - 1];
    }

    int retorno = melhorValorDiario[diasAnalisados - 1];
    free(melhorValorDiario);
    return retorno;
}

int main() {

    int nDias = 0;
    scanf(" %d\n", &nDias);

    int precos[3];
    for (int i = 0; i < 3; i++)
        scanf(" %d", &precos[i]);

    int *dias = malloc(nDias * sizeof(int));
    for (int i = 0; i < nDias; i++)
        scanf(" %d", &dias[i]);

    printf("%d\n", melhorPreco(nDias, precos, dias));

    free(dias);
    return 0;
}