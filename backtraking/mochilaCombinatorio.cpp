#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
T mochilaCombinatoria(T cTotal, vector<T>& p, vector<T>& b, vector<bool>& s, T& pTotal) {
    vector<bool> soa(s.size());
    pTotal = 0;
    T voa = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        soa[i] = 1;
        do {
            T bact = 0, pact = 0;
            for (int j = 0; j < s.size(); j++) {
                if (soa[j]) {
                    pact += p[j];
                    if (pact > cTotal) break;
                    bact += b[j];
                }
            }
            if (pact <= cTotal && bact >= voa) {
                s = soa;
                pTotal = pact;
                voa = bact;
            }
        } while (next_permutation(soa.begin(), soa.end()));
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
    float bTotal = mochilaCombinatoria(cTotal, pesos, beneficios, solucion, pTotal);

    cout << "Beneficio total: " << bTotal << endl;
    cout << "Peso total: " << pTotal << endl;
    cout << "Objetos a escoger: ";
    for (auto it : solucion)
        cout << it << " ";
    cout << endl;

    return 0;
}