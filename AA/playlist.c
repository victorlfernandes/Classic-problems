#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int *vetor, int inicio, int fim, int chave, int len) {

	if (inicio > fim)
		return -1;

	int centro = (int) ((inicio + fim) / 2);

    if (vetor[centro] == chave) return centro + 1;

    if (centro == 0 && vetor[centro] >= chave) return 1;

	if (vetor[centro] <= chave && vetor[centro + 1] >= chave) return centro + 2;

    if (centro == len - 1 && vetor[centro] <= chave) return len - 1;

	if (vetor[centro] < chave) return buscaBinaria(vetor, centro + 1, fim, chave, len);

	if (vetor[centro] > chave) return buscaBinaria(vetor, inicio, centro - 1, chave, len);

    return 0;
}

int main() {

    int nSongs = 0;
    int nMoments = 0;
    scanf(" %d %d\n", &nSongs, &nMoments);

    int *playlist = malloc(nSongs * sizeof(int));
    int currentTime = 0;

    for (int i = 0; i < nSongs; i++) {

        int amtOfTimesPlayed = 0;
        int songDuration = 0;
        scanf(" %d %d\n", &amtOfTimesPlayed, &songDuration);

        currentTime += amtOfTimesPlayed * songDuration;

        playlist[i] = currentTime;

    }

    for (int i = 0; i < nMoments; i++) {

        int moment = 0;
        scanf(" %d\n", &moment);
        printf("%d\n", buscaBinaria(playlist, 0, nSongs, moment, nSongs));

    }

    free(playlist);
    return 0;
}