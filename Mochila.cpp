#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

struct tupla {
	float a;
	int i;
};

bool menor(tupla i, tupla j) { return (i.a > j.a); }

float mochila(float M, std::vector<float> &b, std::vector<float> &p, std::vector<float> &x) {
	std::vector<tupla> bp(b.size());
	float bTotal = 0;
	float pTotal = 0;
	for (int i = 0; i < bp.size(); i++) {
		bp[i].a = b[i] / p[i];
		bp[i].i = i;
	}
	/*for (auto& it : bp) {
		std::cout << it.a << " ";
	}*/
	std::sort(bp.begin(), bp.end(),menor);
	
	for (auto& it : bp) {
		if (pTotal + p[it.i] <= M) {
			pTotal += p[it.i];
			bTotal += b[it.i];
			x[it.i] = 1;
		}
		else {
			float aux = (M - pTotal) / p[it.i];
			pTotal = M;
			bTotal += b[it.i] * aux;
			x[it.i] = aux;
		}
	}
	return bTotal;
}

int  main() {
	float M = 20;
	std::vector<float> b = { 25,24,15 };
	std::vector<float> p = { 18,15,10 };
	std::vector<float> x(b.size());
	float bTotal = mochila(M, b, p, x);
	std::cout << "Beneficio Total = " << bTotal << "\n";
	std::cout << "Proporcion de elementos escogidos: ";
	for (auto& it : x) {
		std::cout << it << " ";
	}

	return 0;
}