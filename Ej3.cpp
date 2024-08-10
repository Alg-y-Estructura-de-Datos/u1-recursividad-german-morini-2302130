#include <cstdlib>
#include <iostream>

using namespace std;

void invert(int n, int &inv) {
    if (n > 0) {
        inv = inv*10 + n%10;
        invert(n/10, inv);
    }

    return;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " NUMERO" << endl;
        return 1;
    }

    int n = atoi(argv[1]);
    int inv = 0;

    invert(n, inv);

    cout << n << " <- " << inv << endl;
}
