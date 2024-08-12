#include <iostream>
#include <vector>

using namespace std;

string contar1(vector<string>& tareas, int& iter) {
    string max = tareas[0];

    for (int i = 0; i < tareas.size(); i++) {
        if (max.length() < tareas[i].length()) max = tareas[i];
        iter++;
    }

    return max;
}

void contar2(vector<string>& tareas, string& max, int& iter, int i) {
    if (i >= tareas.size()) {
        return;
    }

    if (max.length() < tareas[i].length()) {
        max = tareas[i];
    }

    iter++;
    contar2(tareas, max, iter, i+1);
}

int main(int argc, char **argv) {
    if (argc == 1) {
        cout << "Uso: " << argv[0] << " TAREAS..." << endl;
        return 1;
    }

    vector<string> tareas(argc-1);
    for (int i = 1; i < argc; i++) {
        tareas[i-1] = argv[i];
    }

    string max = tareas[0];
    int iter1 = 0;
    int iter2 = 0;

    cout << "--- METODO ITERATIVO ---" << endl;
    cout << "Palabra maxima: " << contar1(tareas, iter1) << endl;
    cout << "Iteraciones: " << iter1 << endl << endl;

    cout << "--- METODO RECURSIVO ---" << endl;
    contar2(tareas, max, iter2, 0);
    cout << "Palabra maxima: " << max << endl;
    cout << "Iteraciones: " << iter2 << endl << endl;
    
}
