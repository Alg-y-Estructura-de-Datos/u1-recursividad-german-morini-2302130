#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_ordenado(const vector<string>& v) {
    for (int i = 0; i < v.size()-1; i++) {
        if (v[i] > v[i+1]) return false;
    }
    return true;
}

void ordenar_burbuja(vector<string>& mat, vector<string>& hor) {
    bool b = 1;
    string tmp1, tmp2;

    while(b) {
        b = 0;

        for(int i = 0; i < mat.size()-1; i++) {
            if(mat[i] > mat[i+1]) {
                tmp1 = mat[i];
                tmp2 = hor[i];
                
                mat[i] = mat[i+1];
                hor[i] = hor[i+1];

                mat[i+1] = tmp1;
                hor[i+1] = tmp2;
                
                b = 1;
            }
        }
    }
}

void ordenar_insercion(vector<string>& mat, vector<string>& hor) {
    for (int i = 1; i < mat.size(); i++) {
        string materia = mat[i];
        string horario = hor[i];

        int j = i - 1;

        while (j >= 0 and mat[j] > materia) {
            mat[j+1] = mat[j];
            hor[j+1] = hor[j];
            j--;
        }
        mat[j+1] = materia;
        hor[j+1] = horario;
    }
}

int encontrar_sec(string& busqueda, vector<string>& mat, int& comparaciones, int i = 0) {
    if (i < mat.size()) {
        comparaciones++;
        if (mat[i] == busqueda) {
            return i;
        } else {
            return encontrar_sec(busqueda, mat, comparaciones, i+1);
        }
    }

    return -1;
}

int encontrar_bin(string& busqueda, vector<string>& mat, int inicio, int fin, int& comparaciones) {
    if (inicio > fin) return -1;
    comparaciones++;

    int medio = inicio + (fin - inicio) / 2;
    if (mat[medio] == busqueda) {
        return medio;
    } else if (mat[medio] > busqueda) {
        return encontrar_bin(busqueda, mat, inicio, medio-1, comparaciones);
    } else {
        return encontrar_bin(busqueda, mat, medio+1, fin, comparaciones);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " CANTIDAD" << endl;
        return 1;
    }

    int n = atoi(argv[1]);
    int indx, comparaciones = 0;
    vector<string> materias(n), horarios(n);
    string busqueda;

    for (int i = 0; i < n; i++) {
        string mat, hor;

        cout << "--- MATERIA " << i+1 << " ---" << endl;
        cout << "\tMateria: "; cin >> mat;
        materias.push_back(mat);
        
        cout << "\tHorario: "; cin >> hor;
        horarios.push_back(hor);
    }
    
    if (not is_ordenado(materias)) {
        ordenar_burbuja(materias, horarios);
        // ordenar_insercion(materias, horarios);
        cout << "\n[WARN] los horarios han sido ordenados\n\n";
    }

    cout << "Ingrese la materia a buscar: "; cin >> busqueda;
    
    indx = encontrar_sec(busqueda, materias, comparaciones);
    // indx = encontrar_bin(busqueda, materias, 0, n-1, comparaciones);

    if (indx != -1) {
        cout << "La materia se encuentra en " << indx << " -> " << horarios[indx] << endl;
    } else {
        cout << "No se pudo encontrar la materia!" << endl;
    }
    cout << "Se han hecho " << comparaciones << " comparaciones" << endl;
}
