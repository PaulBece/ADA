#include <iostream>
#include <vector>
using namespace std;

template <class T>
bool solucion(int &nivel, vector<bool>& soa, T &voa, T &pact, T& bact, T &M) {
    return nivel == soa.size() - 1 && pact <= M && bact>=voa;
}

template <class T>
bool criterio(int& nivel, vector<bool>& soa, T& voa, T& pact, T& M) {
    return nivel < soa.size() - 1 && pact <= M;
}

bool masHermanos(int& nivel, vector<bool>& soa) {
    return !soa[nivel];
}

template <class T>
T mochila(vector<T>& b, vector<T>& p, vector<bool>& s, T &M) {
    int nivel = 0;
    T voa = INT_MIN;
    vector<bool> soa = s;
    T pact = 0, bact = 0;
    while (nivel>=0) {
        pact += p[nivel] * soa[nivel];
        bact += b[nivel] * soa[nivel];
        if (solucion(nivel, soa, voa, pact, bact, M)) {
            voa = bact;
            s = soa;
        }
        if (criterio(nivel, soa, voa, pact, M)) {
            nivel++;
        }
        else {
            while (nivel >= 0) {
                if (masHermanos(nivel, soa)) {
                    soa[nivel] = 1;
                    break;
                }
                else {
                    pact -= p[nivel] * soa[nivel];
                    bact -= b[nivel] * soa[nivel];
                    soa[nivel] = 0;
                    nivel--;
                }
            }
        }
    }
    return voa;
}

int main()
{
    int n = 4;
    int M = 7;
    vector<int> b = { 2,3,4,5 };
    vector<int> p = { 1,2,3,4 };
    vector<bool> s (b.size());
    cout << mochila(b, p, s, M) << endl;
    for (auto it : s) {
        cout << it << " ";
    }

    return 0;
}