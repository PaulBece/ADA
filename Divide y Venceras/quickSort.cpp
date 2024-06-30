#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
int partition(vector<T>& vec, int begin, int end, bool (*f) (T, T)) {
    int pivot = vec[begin];
    int c = 0;
    for (int i = begin+1; i <= end; i++) {
        if (f(pivot, vec[i])) {
            c++;
        }
    }
    int pindex = begin + c;
    swap(vec[begin], vec[pindex]);
    while (begin < pindex && end > pindex) {
        while (f(pivot, vec[begin])) {
            begin++;
        }
        while (!f(pivot, vec[end])) {
            end--;
        }
        if (begin < pindex && end > pindex) {
            swap(vec[begin++], vec[end--]);
        }
    }
    return pindex;
}

template <class T>
void quickSort(vector<T>& vec, int begin, int end, bool (*f) (T, T)) {
    if (begin >= end) return;
    int p = partition(vec, begin, end, f);
    quickSort(vec, begin, p - 1, f);
    quickSort(vec, p + 1, end, f);
}

int main()
{
    vector<int> vec = { 7,5,8,2,7,9,1,3,12 };
    quickSort(vec, 0, vec.size()-1, isgreater);
    for (auto it : vec)
        cout << it << " ";

    return 0;
}