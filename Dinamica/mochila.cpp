#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mochila(int k, int m, vector<vector<int>> &tabla, vector<int>& b, vector<int>& p) {
    if (m - p[k - 1] < 0) return tabla[k - 1][m];
    else return max(tabla[k - 1][m], b[k - 1] + tabla[k - 1][m - p[k - 1]]);
}

int mochilaD(int cTotal, vector<int>& b, vector<int>& p, vector<bool>& s, int&pTotal) {
    int bTotal = 0;
    pTotal = 0;

    vector<vector<int>> tabla(b.size() + 1, vector<int>(cTotal + 1));
    for (int i = 1; i < tabla.size(); i++) {
        for (int j = 1; j < tabla[0].size(); j++) {
            tabla[i][j] = mochila(i, j, tabla, b, p);
        }
    }
    for (int i = 0; i < tabla.size(); i++) {
        for (int j = 0; j < tabla[0].size(); j++) {
            cout << tabla[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int k = tabla.size() - 1;
    int m = tabla[0].size() - 1;
    bTotal = tabla[k][m];
    while (k) {
        if (tabla[k][m] == tabla[k - 1][m]) k--;
        else {
            s[--k] = 1;
            m -= p[k];
            pTotal+= p[k];
        }
    }
    return bTotal;
}

int main()
{
    int cTotal = 20;
    int pTotal;
    vector<int> beneficios = { 9,5,7,4,8,6,1,2,3 };
    vector<int> pesos = { 7,5,8,2,7,9,1,3,12 };
    vector<bool> solucion(beneficios.size());
    int bTotal = mochilaD(cTotal, beneficios, pesos, solucion, pTotal);
    cout << "Beneficio Total: " << bTotal << endl;
    cout << "Objetos a escoger: ";
    for (auto it : solucion)
        cout << it << " ";
}