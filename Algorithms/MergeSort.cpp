#include <bits/stdc++.h>
using namespace std;
#include <iostream>


void merge(vector<int>& arr, int l, int r, int mid, vector<int>& temp) {
    for (int i = l; i <= mid; ++i) {
        temp[i] = arr[i];
    }

    int resIdx = l, leftIdx = l, rightIdx = mid + 1;

    while(leftIdx <= mid && rightIdx <= r) {
        if (temp[leftIdx] <= arr[rightIdx]) {
            arr[resIdx++] = temp[leftIdx++];
        } else {
            arr[resIdx++] = arr[rightIdx++];
        }
    }

    while (leftIdx <= mid) {
        arr[resIdx++] = temp[leftIdx++];
    }
}

void mergeSort(vector<int>& arr, int l, int r, vector<int>& buff) {
    if (l >= r) {
        return;
    }

    int mid = (r - l)/2 + l;
    mergeSort(arr, l, mid, buff);
    mergeSort(arr, mid + 1, r, buff);

    merge(arr, l, r, mid, buff);
}

void mergeSort(vector<int>& arr) {
    int l = 0;
    int r = arr.size() - 1;
    vector<int> buff(arr.size());
    mergeSort(arr, l, r, buff);
}

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0 ;i < N; ++i) {
        cin >> v[i];
    }
    mergeSort(v);
    for (int el : v) {
        cout << el << " ";
    }
}
