#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <locale.h>
using namespace std;

const int NUM_FILEIRAS = 15;
const int POLTRONAS_POR_FILEIRA = 40;
const double PRECO_FILEIRAS[] = {50.00, 50.00, 50.00, 50.00, 50.00, 30.00, 30.00, 30.00, 30.00, 30.00, 15.00, 15.00, 15.00, 15.00, 15.00};

char mapaOcupacao[NUM_FILEIRAS][POLTRONAS_POR_FILEIRA];

void inicializarMapa() {
    for (int i = 0; i < NUM_FILEIRAS; ++i) {
        for (int j = 0; j < POLTRONAS_POR_FILEIRA; ++j) {
            mapaOcupacao[i][j] = '.';
        }
    }
}

void reservarPoltrona() {
    int fileira, poltrona;
    cout << "Informe a fileira (1 a 15): ";
    cin >> fileira;
    cout << "Informe o número da poltrona (1 a 40): ";
    cin >> poltrona;

    if (fileira < 1 || fileira > NUM_FILEIRAS || poltrona < 1 || poltrona > POLTRONAS_POR_FILEIRA) {
        cout << "Dados inválidos. Tente novamente.\n";
        return;
    }

    if (mapaOcupacao[fileira - 1][poltrona - 1] == '#') {
        cout << "Poltrona já está ocupada.\n";
    } else {
        mapaOcupacao[fileira - 1][poltrona - 1] = '#';
        cout << "Reserva efetuada com sucesso!\n";
    }
}

void mostrarMapaOcupacao() {
    cout << "Mapa de ocupação do teatro:\n";
    for (int i = 0; i < NUM_FILEIRAS; ++i) {
        for (int j = 0; j < POLTRONAS_POR_FILEIRA; ++j) {
            cout << mapaOcupacao[i][j] << " ";
        }
        cout << endl;
    }
}

void mostrarFaturamento() {
    int lugaresOcupados = 0;
    double valorTotal = 0.0;

    for (int i = 0; i < NUM_FILEIRAS; ++i) {
        for (int j = 0; j < POLTRONAS_POR_FILEIRA; ++j) {
            if (mapaOcupacao[i][j] == '#') {
                lugaresOcupados++;
                valorTotal += PRECO_FILEIRAS[i];
            }
        }
    }

    cout << "Quantidade de lugares ocupados: " << lugaresOcupados << endl;
    cout << fixed << setprecision(2);
    cout << "Valor da bilheteria: R$ " << valorTotal << endl;
}

int main() {
	setlocale (LC_ALL, "portuguese");
    inicializarMapa();

    int opcao;
    do {
        cout << "\nSelecione uma opção:\n";
        cout << "0. Finalizar\n";
        cout << "1. Reservar poltrona\n";
        cout << "2. Mapa de ocupação\n";
        cout << "3. Faturamento\n";
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Finalizando o programa...\n";
                break;
            case 1:
                reservarPoltrona();
                break;
            case 2:
                mostrarMapaOcupacao();
                break;
            case 3:
                mostrarFaturamento();
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 0);

    return 0;
}
