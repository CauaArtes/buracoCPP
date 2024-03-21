#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int NUM_JOGADORES = 4;
const int NUM_CARTAS = 52 * 2;
const int NUM_CARTAS_MAO = 11;

// Função para inicializar o baralho
vector<string> inicializarBaralho() {
    vector<string> baralho;
    for (int b = 1; b <= 2; ++b) {
        for (int n = 1; n <= 4; ++n) {
            for (int c = 1; c <= 13; ++c) {
                string naipe;
                switch (n) {
                    case 1:
                        naipe = "Copas";
                        break;
                    case 2:
                        naipe = "Paus";
                        break;
                    case 3:
                        naipe = "Ouro";
                        break;
                    case 4:
                        naipe = "Espada";
                        break;
                }
                string carta = to_string(n) + "-" + (c < 10 ? "0" : "") + to_string(c) + "-" + to_string(b) + " (" + naipe + ")";
                baralho.push_back(carta);
            }
        }
    }
    return baralho;
}

// Função para embaralhar o baralho
void embaralharBaralho(vector<string> &baralho) {
    srand(time(NULL));
    random_shuffle(baralho.begin(), baralho.end());
}

// Função para distribuir cartas aos jogadores
void distribuirCartas(const vector<string> &baralho, vector<string> mao[]) {
    int cartaIndex = 0;
    for (int j = 0; j < NUM_JOGADORES; ++j) {
        for (int c = 0; c < NUM_CARTAS_MAO; ++c) {
            mao[j].push_back(baralho[cartaIndex++]);
        }
    }
}

// Função para exibir as mãos dos jogadores
void exibirMaos(const vector<string> mao[]) {
    for (int j = 0; j < NUM_JOGADORES; ++j) {
        cout << "Mão do Jogador " << j + 1 << ":" << endl;
        for (const string &carta : mao[j]) {
            cout << carta << endl;
        }
        cout << endl;
    }
}

int main() {
    vector<string> baralho = inicializarBaralho();
    embaralharBaralho(baralho);

    vector<string> mao[NUM_JOGADORES];
    distribuirCartas(baralho, mao);
    
    exibirMaos(mao);

    return 0;
}
