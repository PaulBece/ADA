#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
struct duo {
    T valor;
    int pos;
    void print() {
        cout << valor << "-" << pos << " ";
    }
};

template <class T>
bool mayor(duo<T> a, duo<T> b) {
    return a.valor > b.valor;
}

template <class T>
bool menor(duo<T> a, duo<T> b) {
    return a.valor < b.valor;
}

template <class T>
int maxContenedores(T cTotal, vector<T>& pesos, vector<bool>& solucion, T &sPeso) {
    int nConenedores = 0;
    sPeso = 0;
    T pact = 0;
    vector<duo<T>> vecOrd(pesos.size());
    for (int i = 0; i < vecOrd.size(); i++) {
        vecOrd[i].valor = pesos[i];
        vecOrd[i].pos = i;
    }
    sort(vecOrd.begin(), vecOrd.end(),menor<T>);
    for (int i = 0; i < vecOrd.size(); i++) {
        cTotal -= vecOrd[i].valor;
        if (cTotal >= 0) {
            solucion[vecOrd[i].pos] = 1;
            nConenedores++;
            sPeso += vecOrd[i].valor;
        }
        else
            break;
    }

    return nConenedores;
}

template <class T>
int maxPeso(T cTotal, vector<T>& pesos, vector<bool>& solucion, T& sPeso) {
    int nConenedores = 0;
    sPeso = 0;
    T pact = 0;
    vector<duo<T>> vecOrd(pesos.size());
    for (int i = 0; i < vecOrd.size(); i++) {
        vecOrd[i].valor = pesos[i];
        vecOrd[i].pos = i;
    }
    sort(vecOrd.begin(), vecOrd.end(), mayor<T>);
    for (int i = 0; i < vecOrd.size(); i++) {
        if (cTotal - vecOrd[i].valor >= 0) {
            solucion[vecOrd[i].pos] = 1;
            nConenedores++;
            sPeso += vecOrd[i].valor;
            cTotal -= vecOrd[i].valor;
        }
    }

    return nConenedores;
}

int main()
{
    float cTotal = 20;
    float sPeso;
    float sPeso2;
    vector<float> pesos = { 7,5,8,2,7,9,1,3,12 };
    vector<bool> solucion(pesos.size());
    vector<bool> solucion2(pesos.size());
    int nContenedores = maxContenedores(cTotal, pesos, solucion, sPeso);
    int nContenedores2 = maxPeso(cTotal, pesos, solucion2, sPeso2);

    cout << "Maximizando numero de contenedores: "<< endl;
    cout << "Numero de contenedores: " << nContenedores << endl;
    cout << "Peso cargado: " << sPeso << endl;
    cout << "Contenedores a escoger: ";
    for (auto it : solucion)
        cout << it << " ";
    cout << endl;
    cout << endl;
    cout << "Maximizando peso cargado"<< endl;
    cout << "Numero de contenedores: " << nContenedores2 << endl;
    cout << "Peso cargado: " << sPeso2 << endl;
    cout << "Contenedores a escoger: ";
    for (auto it : solucion2)
        cout << it << " ";
    cout << endl;

    return 0;
}