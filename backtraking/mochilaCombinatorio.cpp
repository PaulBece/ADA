#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
bool solucion(T &voa, T &pact, T& bact, T &M) {
    return pact <= M && bact>=voa;
}

template <class T>
T mochila(vector<T>& b, vector<T>& p, vector<bool>& s, T &M) {
    T voa = 0;
    vector<bool> soa = s;
    for (int i = 1; i < s.size()+1;i++) {
        soa[soa.size() - i] = 1;        
        do {
            T pact = 0, bact = 0;
            for (int j = 0; j < s.size(); j++) {
                pact += p[j] * soa[j];
                bact += b[j] * soa[j];
            }
            if (solucion(voa, pact, bact, M)) {
                voa = bact;
                s = soa;
            }
        } while (next_permutation(soa.begin(), soa.end()));
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