#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

struct tupla {
	float a;
	int i;
};

bool menor(tupla i, tupla j) { return (i.a > j.a); }

float planificador(std::vector<float> &b, std::vector<int> &d, std::vector<int> &S) {
	std::vector<tupla> bp(b.size());
	float bTotal = 0;
	for (int i = 0; i < bp.size(); i++) {
		bp[i].a = b[i];
		bp[i].i = i;
	}
	std::sort(bp.begin(), bp.end(),menor);
	
	for (int i = 0, c = 0; c < S.size() && i<bp.size() ; i++) {
		int pos = d[bp[i].i]-1;
		while (pos >= 0) {
			if ((S[pos])) {
				pos--;
			}
			else {
				S[pos] = bp[i].i + 1;
				bTotal += b[bp[i].i];
				c++;
				break;
			}
		}
	}
	return bTotal;
}

int  main() {
	int T = 3;
	std::vector<int> S(T);
	std::vector<float> b = { 20, 15, 10, 7, 5, 3 };
	std::vector<int> d = { 3, 1, 1, 3, 1, 3 };
	float bTotal = planificador(b, d, S);
	std::cout << "Beneficio Total = " << bTotal << "\n";
	std::cout << "Orden de tareas escogidas: ";
	for (auto& it : S) {
		std::cout << it << " ";
	}

	return 0;
}