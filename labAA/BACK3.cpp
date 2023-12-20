#include <bits/stdc++.h>

using namespace std;

const int MAX = 51;
int L, C, res = INT_MAX;
vector<vector<int>> campo(MAX, vector<int>(MAX));
vector<vector<bool>> visitado(MAX, vector<bool>(MAX));

void backtrack(int i, int j, int passos) {

    if (passos > res || i < 0 || j < 0 || i >= L || j >= C || campo[i][j] == 0 || visitado[i][j])
        return;

    if (j == C - 1) {  // chegou na borda direita
        if (res == -1 || passos < res)
            res = passos;
        return;
    }

    visitado[i][j] = true;
    backtrack(i - 1, j, passos + 1);
    backtrack(i, j + 1, passos + 1);
    backtrack(i + 1, j, passos + 1);
    backtrack(i, j - 1, passos + 1);
    visitado[i][j] = false;
}

void pre_processamento() {

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            if (campo[i][j] == 0 && visitado[i][j] == true) {
                if (j != 0)
                    campo[i][j - 1] = 0; // esquerdo
                if (j != C - 1)
                    campo[i][j + 1] = 0; // direita
                if (i != 0)
                    campo[i - 1][j] = 0; // cima
                if (i != L - 1)
                    campo[i + 1][j] = 0; // baixo
            }
        }
    }

}

int main() {

    cin >> L >> C;

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            cin >> campo[i][j];
            if (campo[i][j] == 0)
                visitado[i][j] = true;
            else
                visitado[i][j] = false;
        }
    }

    pre_processamento();

    for (int i = 0; i < L; i++) {
        if (campo[i][0] == 1) {
            backtrack(i, 0, 0);
        }
    }

    if (res == INT_MAX) {
        cout << "Nao ha caminho valido" << endl;
    } else {
        cout << "Comprimento da rota = " << res << endl;
    }

    return 0;
}
