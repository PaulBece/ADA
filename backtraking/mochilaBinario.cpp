#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
bool solution(T cTotal, T pact, int n, vector<bool> &soa) {
    return n == soa.size() - 1 && pact <= cTotal;
}

template <class T>
bool criterio(T cTotal, T pact, int n, vector<bool>& soa) {
    return n < soa.size() - 1 && pact <= cTotal;
}

bool hermano(int n, vector<bool>& soa) {
    return soa[n];
}

template <class T>
T mochilaBinario(T cTotal, vector<T>& p, vector<T>& b, vector<bool>& s, T &pTotal) {
    vector<bool> soa(s.size());
    T pact = 0, bact = 0;
    T voa = 0;
    int n = 0;
    while (n >= 0) {
        soa[n] = !soa[n];
        pact += p[n] * soa[n];
        bact += b[n] * soa[n];
        if (solution(cTotal,pact,n,soa)) {
            if (bact >= voa) {
                voa = bact;
                s = soa;
                pTotal = pact;
            }
        }
        if (criterio(cTotal, pact, n, soa)) {
            n++;
        }
        else {
            while (n>=0 && !hermano(n, soa)) {
                n--;
            }
            if (n >= 0) {
                pact -= p[n];
                bact -= b[n];
            }
        }
    }
    return voa;
}

int main()
{
    float cTotal = 20;
    float pTotal;
    vector<float> pesos = { 7,5,8,2,7,9,1,3,12 };
    vector<float> beneficios = { 9,5,7,4,8,6,1,2,3 };
    vector<bool> solucion(pesos.size());
    float bTotal = mochilaBinario(cTotal, pesos, beneficios, solucion, pTotal);
    cout << "Beneficio total: " << bTotal << endl;
    cout << "Peso total: " << pTotal << endl;
    cout << "Objetos a escoger: ";
    for (auto it : solucion)
        cout << it << " ";
    cout << endl;

    return 0;
}