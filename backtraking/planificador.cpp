#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct tupla {
    int persona, actividad;
};


int solucion(int &voa, vector< vector<int> >& tabla, vector<tupla> &soa) {
    int b = 0;
    for (int i = 0; i < soa.size(); i++) {
        b += tabla[soa[i].persona][soa[i].actividad];
    }
    return b;
}


int planificador(vector< vector<int> > &tabla, vector<tupla> &s) {
    int voa = 0;
    vector<tupla> soa(tabla.size());
    vector<int> awa(tabla.size());
    for (int i = 0; i < awa.size();i++) {
        awa[i] = i;
    }
    do {
            for (int j = 0; j < awa.size(); j++) {
                soa[j].persona = j;
                soa[j].actividad = awa[j];
                //cout << soa[j].persona << "-" << soa[j].actividad<<" ";
                
            }
            int b = (solucion(voa, tabla, soa));
            if (b>=voa) {
                s = soa;
                voa = b;
            }
            //cout << endl;
    } while (next_permutation(awa.begin(), awa.end()));
    return voa;
}

int main()
{
    int n = 3;
    /*vector<int> awa(n);
    for (int i = 0; i < n; i++) {
        awa[i] = i;
    }
    do {
        for (int j = 0; j < n; j++) {
            cout << awa[j] << " ";
        }
        cout << endl;
    } while (next_permutation(awa.begin(), awa.end()));*/

    vector< vector<int> > tabla(n);
    tabla = { {4,9,1},{7,2,3},{6,3,5} };
    vector<tupla> s(n);
    cout<<planificador(tabla,s);
    cout << endl;
    //vector<int> b = { 2,3,4,5 };
    //vector<int> p = { 1,2,3,4 };
    //vector<bool> s (b.size());
    //cout << mochila(b, p, s, M) << endl;
    for (auto it : s) {
        cout << it.persona << "-" << it.actividad << " ";
    }

    return 0;
}