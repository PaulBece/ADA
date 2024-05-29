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
	/*for (auto& it : bp) {
		std::cout << it.a << " ";
	}*/
	std::sort(bp.begin(), bp.end(),menor);
	
	int c = 0;
	for (int i = 0; i < S.size()+c; i++) {
		int aux = 0;
		while (1) {
			if (&(S[bp[i].i - aux]) < &S[0]) {
				c++;
				break;
			}
			if ((S[bp[i].i - aux])) {
				aux++;
			}
			else {
				S[bp[i].i - aux] = bp[i].i + 1;
				bTotal += b[bp[i].i];
			}
		}
	}
	
	return bTotal;
}

int  main() {
	int T = 3;
	std::vector<float> b = { 20, 15, 10, 7, 5, 3 };
	std::vector<int> d = { 3, 1, 1, 3, 1, 3 };
	std::vector<int> S(T);
	float bTotal = planificador(b, d, S);
	std::cout << "Beneficio Total = " << bTotal << "\n";
	std::cout << "Proporcion de elementos escogidos: ";
	for (auto& it : S) {
		std::cout << it << " ";
	}

	return 0;
}