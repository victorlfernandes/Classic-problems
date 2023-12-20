#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool recursion(char **grid, char *word, int i, int j, int k, int height, int width, int wordSize) {

    // checking if indexes are valid
    if (i < 0 || j < 0 || i >= height || j >= width || k >= wordSize)
        return false;

    // stop condition
    if (grid[i][j] != word[k])
        return false;

    // success condition
    if (k + 1 == wordSize)
        return true;

    // marking this letter of the grid as visited
    grid[i][j] = '*';

    // recursive calls
    if (recursion(grid, word, i, j + 1, k + 1, height, width, wordSize)) return true;
    if (recursion(grid, word, i + 1, j, k + 1, height, width, wordSize)) return true;
    if (recursion(grid, word, i, j - 1, k + 1, height, width, wordSize)) return true;
    if (recursion(grid, word, i - 1, j, k + 1, height, width, wordSize)) return true;

    return false;
}

bool wordSearch(char **grid, char *word, int height, int width, int wordSize) {

    // allocating a copy of the grid
    char **aux = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        aux[i] = malloc(width * sizeof(char));
        for (int j = 0; j < width; j++) 
            aux[i][j] = grid[i][j];
    }

    // starting the search by every letter of the grid
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            // recopying grid to aux
            for (int k = 0; k < height; k++)
                for (int l = 0; l < width; l++) 
                    aux[k][l] = grid[k][l];

            // calling recursive search
            if (recursion(aux, word, i, j, 0, height, width, wordSize))
                return true;
                
        }
    }

    // deallocating aux
    for (int i = 0; i < height; i++)
        free(aux[i]);
    free(aux);

    return false;
}

int main() {

    // reading dimensions of the grid
    int height = 0;
    int width = 0;
    scanf(" %d %d\n", &height, &width);

    // reading grid
    char **grid = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        grid[i] =  malloc(width * sizeof(char));
        for (int j = 0; j < width; j++) 
            grid[i][j] = getchar();
        getchar();
    }

    // reading word
    int wordSize = 0;
    scanf(" %d\n", &wordSize);
    char *word = malloc(wordSize * sizeof(char));
    for (int i = 0; i < wordSize; i++) 
        word[i] = getchar();

    // searching for the word on the grid
    wordSearch(grid, word, height, width, wordSize) ? printf("Yes\n") : printf("No\n");

    // deallocating memory
    for (int i = 0; i < height; i++)
        free(grid[i]);
    free(grid);
    free(word);

    return 0;
}