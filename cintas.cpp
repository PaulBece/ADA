#include <iostream>
#include <vector>
#include <algorithm>

struct tupla {
    int v;
    int i;
};

bool mayor(tupla a, tupla b) { return (a.v < b.v); }

int cintas(std::vector<int>& l, std::vector<int>& S) {
    int total = 0;
    std::vector<tupla> lAsc(l.size());
    for (int i = 0; i < l.size(); i++) {
        lAsc[i].v = l[i];
        lAsc[i].i = i;
    }
    std::sort(lAsc.begin(), lAsc.end(), mayor);

    for (int i = 0; i < S.size(); i++) {
        S[i] = (lAsc[i].i + 1);
        for (int j = 0; j <= i; j++) {
            total += lAsc[j].v;
        }
    }
    return total;
}

int main()
{
    int n = 3;
    std::vector<int> l = { 5,10,3 };
    std::vector<int> S(n);
    std::cout << cintas(l, S) << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << S[i] << " ";
    }

    return 0;
}