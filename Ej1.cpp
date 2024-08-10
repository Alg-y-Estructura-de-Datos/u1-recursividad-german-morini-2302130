#include <cstdlib>
#include <iostream>

using namespace std;

double mult(double base, int exp) {
    if (exp > 0) return base * mult(base, exp-1);

    return 1;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        cout << "Uso: " << argv[0] << " BASE EXPONENTE" << endl;
        return 1;
    }
    
    double base = atof(argv[1]);
    int exp = atoi(argv[2]);

    cout << base << " ^ " << exp << " = " << mult(base, exp) << endl;

    return 0;
}
