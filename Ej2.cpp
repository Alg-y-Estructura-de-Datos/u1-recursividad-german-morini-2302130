#include <cstdlib>
#include <iostream>

using namespace std;

unsigned long mult(unsigned long n1, unsigned long n2) {
    if (n2 > 0) return n1 + mult(n1, n2-1);

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        cout << "Uso: " << argv[0] << " NUM1 NUM2" << endl;
        return 1;
    }
    
    long n1 = atol(argv[1]);
    long n2 = atoi(argv[2]);

    cout << n1 << " * " << n2 << " = " << mult(n1, n2) << endl;

    return 0;
}
