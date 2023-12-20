#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef long long int lli;

lli merge(lli *array, lli start, lli center, lli end) {

    lli i = start;
    lli j = center + 1;
    lli k = 0;
    lli amtCrosses = 0;
    lli *auxArray = malloc((end - start + 1) * sizeof(lli));

    while (i <= center && j <= end) {
        if (array[i] >= array[j]) {
            amtCrosses += (center - i + 1);
            auxArray[k] = array[j];
            j++;
        }
        else {
            auxArray[k] = array[i];
            i++;
        }
        k++;
    }

    while (i <= center) {
        auxArray[k] = array[i];
        i++; k++;
    }
    while (j <= end) {
        auxArray[k] = array[j];
        j++; k++;
    }
    for (i = start, k = 0; i <= end; i++, k++)
        array[i] = auxArray[k];

    free(auxArray);

    return amtCrosses;
}

lli crossings(lli *array, lli start, lli end) {

    if (start >= end) return 0;

    lli center = (start + end) / 2.0;
    lli amtCrosses = crossings(array, start, center);
    amtCrosses += crossings(array, center + 1, end);
    amtCrosses += merge(array, start, center, end);

    return amtCrosses;
}

int main() {

    lli amtTestCases = 0;
    scanf(" %lld", &amtTestCases);

    for (lli i = 0; i < amtTestCases; i++) {

        lli arrayLength = 0;
        scanf(" %lld", &arrayLength);

        lli *array = malloc(arrayLength * sizeof(lli));
        for (lli j = 0; j < arrayLength; j++) 
            scanf(" %lld", &array[j]);

        printf("%lld\n", crossings(array, 0, arrayLength - 1));

        free(array);
    }

    return 0;
}