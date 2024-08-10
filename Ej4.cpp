#include <cstdlib>
#include <iostream>

using namespace std;

void encontrar_mayor(int arr[10], int i, int &mayor) {
    if(i > 0) {
        arr[i] > mayor ? mayor = arr[i] : mayor = mayor;
        encontrar_mayor(arr, i-1, mayor);
    }
}

int main() {
    srand(time(NULL));
    
    int arr[10];
    int *mayor = new int;

    for (int i = 0; i < 10; i++) {
        arr[i] = rand()%200 - 100;
    }
    *mayor = arr[9];

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    encontrar_mayor(arr, 9, *mayor);
    cout << " [" << *mayor << "]" << endl;
}
