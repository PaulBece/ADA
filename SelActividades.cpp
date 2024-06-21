#include <iostream>
#include <vector>
#include <algorithm>

struct actividad {
    char name;
    int inicio, fin;
    actividad(int i, int f,char n) {
        inicio = i; fin = f; name = n;
    }
};

struct tupla {
    int v;
    int i;
};

bool mayor(actividad *a, actividad *b) { return (a->fin < b->fin); }

void selAct(int T, std::vector<actividad>& act, std::vector<actividad>& S) {
    std::vector<actividad*> fAsc(act.size());
    for (int i = 0; i < act.size(); i++) {
        fAsc[i] = &act[i];
    }
    std::sort(fAsc.begin(), fAsc.end(), mayor);

    int i = 0;
    for (int t = 0; t < T; t++) {
        for (; i < fAsc.size(); i++) {
            if (fAsc[i]->inicio >= t) {
                S.push_back(*fAsc[i]);
                t = fAsc[i]->fin;
                t--;
                break;
            }
        }
    }
}

int main()
{
    int T = 11;
    actividad A(0, 6, 'A');
    actividad B(1, 4, 'B');
    actividad C(3, 5, 'C');
    actividad D(3, 8, 'D');
    actividad E(4, 7, 'E');
    actividad F(5, 9, 'F');
    actividad G(6, 10, 'G');
    actividad H(8, 11, 'H');
    std::vector<actividad> act = { A,B,C,D,E,F,G,H };
    std::vector<actividad> S;
    selAct(T, act, S);
    for (int i = 0; i < S.size(); i++) {
        std::cout << S[i].name << " ";
    }

    return 0;
}