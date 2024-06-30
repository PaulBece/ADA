#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
void merge(vector<T>& vec, int begin, int mid, int end, bool (*f) (T, T)) {
    vector<T> aux(vec.begin() + begin, vec.begin() + end);
    int left = 0, right = mid-begin;
    int i = begin;
    while (left + begin < mid && right + begin < end) {
        if (f(aux[left], aux[right])) {
            vec[i++] = aux[right];
            right++;
        }
        else {
            vec[i++] = aux[left];
            left++;
        }
    }
    while (begin + left < mid) {
        vec[i++] = aux[left++];
    }
    while (mid + right < end) {
        vec[i++] = aux[right++];
    }
}

template <class T>
void mergeSort(vector<T>& vec, int begin, int end, bool (*f) (T, T)) {
    if (begin + 1 >= end) return;
    int mid = (end - begin) / 2 + begin;
    mergeSort(vec, begin, mid, f);
    mergeSort(vec, mid, end, f);
    merge(vec, begin, mid, end, f);
}

int main()
{
    vector<int> vec = { 7,5,8,2,7,9,1,3,12 };
    mergeSort(vec, 0, vec.size(), isgreater);    
    for (auto it : vec)
        cout << it << " ";

    return 0;
}