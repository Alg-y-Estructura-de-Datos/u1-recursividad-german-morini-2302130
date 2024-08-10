#include <cstring>
#include <iostream>

using namespace std;

int contar(int n, int i) {
    if (n > 0) {
        return ((n%10)%2 == 0 and i%2 != 0) + contar(n/10, i-1);
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " NUMERO" << endl;
        return 1;
    }

    unsigned int num = atoi(argv[1]);
    int i = strlen(argv[1]);
    
    cout << num << " -> " << contar(num, i) << endl;
}
