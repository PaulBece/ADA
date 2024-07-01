#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct duo {
    int persona, actividad;
};

template <class T>
T planificador(vector<vector<T>>& t, vector<duo>& s) {
    T voa = 0;
    vector<int> combinaciones(t.size());
    for (int i = 0; i < s.size(); i++) {
        s[i].persona = i;
        combinaciones[i] = i;
    }
    do {
        T bact = 0;
        for (int i = 0; i < s.size(); i++) {
            bact += t[i][combinaciones[i]];
        }
        if (bact >= voa) {
            voa = bact;
            for (int i = 0; i < s.size(); i++) {
                s[i].actividad = combinaciones[i];
            }
        }
    } while (next_permutation(combinaciones.begin(), combinaciones.end()));
    return voa;
}

int main()
{
    int n = 3;
    vector< vector<int> > tabla(n);
    tabla = {   {4,9,1},
                {7,2,3},
                {6,3,5} };
    vector<duo> s(n);
    int bTotal = planificador(tabla, s);
    cout << "Beneficio total: " << bTotal;
    cout << endl;
    for (auto it : s) {
        cout << "Persona: " << it.persona << " realiza la actividad: " << it.actividad << "\n";
    }
    return 0;
}