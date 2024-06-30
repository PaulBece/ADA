#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void cambio(vector<int> &monedas, vector<int> &sol, int resto) {
    int act = 0;
    int i = 0;
    for (int i = 0; i < monedas.size(); i++) {
         sol[i] = resto / monedas[i];
         resto = resto % monedas[i];
         act += sol[i] * monedas[i];
    }
    if (resto) {
        cout << "No existe solucion. Falta devolver " << resto << "\n";
    }
}



int main()
{
    vector<int> monedas = { 200,100,50,20,10,5,2 };
    vector<int> sol(monedas.size());
    cambio(monedas,sol,389);
    for (auto it : sol)
        cout << it << " ";

    return 0;
}