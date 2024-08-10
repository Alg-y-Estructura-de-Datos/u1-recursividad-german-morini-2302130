#include <iostream>

using namespace std;

bool esta_en(int n, int d) {
    if (n > 0) return n%10 == d or esta_en(n/10, d);

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        cout << "Uso: " << argv[0] << " NUMERO DIGITO" << endl;
        return 1;
    }

    int num = atoi(argv[1]);
    int dig = atoi(argv[2]);

    esta_en(num, dig) ? cout << "Verdadero" << endl: cout << "Falso" << endl;
}
