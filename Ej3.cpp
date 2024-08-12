#include <iostream>

using namespace std;

void invert(unsigned int n, unsigned int &inv) {
    if (n > 0) {
        inv = inv*10 + n%10;
        invert(n/10, inv);
    }
}

void invert2(unsigned int n, unsigned int &inv) {
    if (n <= 0) {
        return;
    } else {
        inv = inv*10 + n%10;
        invert(n/10, inv);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " NUMERO" << endl;
        return 1;
    }

    unsigned int n = atoi(argv[1]);
    unsigned int inv = 0;

    if (n < 0) {
        cout << "No se deben ingresar numeros negativos" << endl;
        return 2;
    }

    invert(n, inv);

    cout << n << " <- " << inv << endl;
}
