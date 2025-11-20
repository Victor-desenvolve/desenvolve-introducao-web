#include <iostream>
#include <fstream>
using namespace std;

struct Animal {
    char sexo;
    float peso;
    int tipo; 
};

int main() {
    int qtd = 3;

    Animal* animais = new Animal[qtd];

    // Variáveis para somar os pesos e contar quantos cães e gatos existem, permitindo calcular as médias
    float somaCaes = 0, somaGatos = 0;
    int totalCaes = 0, totalGatos = 0;

    for (int i = 0; i < qtd; i++) {
        cout << "Animal " << i + 1 << ":\n";

        cout << "Sexo (M/F): ";
        cin >> animais[i].sexo;

        cout << "Peso: ";
        cin >> animais[i].peso;

        cout << "Tipo (1 = cao, 2 = gato): ";
        cin >> animais[i].tipo;
        cout << "\n";

        if (animais[i].tipo == 1) {
            somaCaes += animais[i].peso;
            totalCaes++;
        } else if (animais[i].tipo == 2) {
            somaGatos += animais[i].peso;
            totalGatos++;
        }
    }

    float mediaCaes = (totalCaes > 0 ? somaCaes / totalCaes : 0);
    float mediaGatos = (totalGatos > 0 ? somaGatos / totalGatos : 0);

    cout << "Media de peso dos caes: " << mediaCaes << "\n";
    cout << "Media de peso dos gatos: " << mediaGatos << "\n";

    ofstream arquivo("medias.txt");
    arquivo << "Media de peso dos caes: " << mediaCaes << "\n";
    arquivo << "Media de peso dos gatos: " << mediaGatos << "\n";
    arquivo.close();

    delete[] animais;

    return 0;
}
