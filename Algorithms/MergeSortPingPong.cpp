#include <bits/stdc++.h>
using namespace std;
#include <iostream>


void merge(vector<int>& arr, int l, int r, int mid, vector<int>& temp) {
    int resIdx = l, leftIdx = l, rightIdx = mid + 1;

    while(leftIdx <= mid && rightIdx <= r) {
        if (temp[leftIdx] <= temp[rightIdx]) {
            arr[resIdx++] = temp[leftIdx++];
        } else {
            arr[resIdx++] = temp[rightIdx++];
        }
    }

    while (leftIdx <= mid) {
        arr[resIdx++] = temp[leftIdx++];
    }

    while (rightIdx <= r) {
        arr[resIdx++] = temp[rightIdx++];
    }
}

void mergeSort(vector<int>& arr, int l, int r, vector<int>& buff) {
    if (l >= r) {
        return;
    }

    int mid = (r - l)/2 + l;
    mergeSort(buff, l, mid, arr);
    mergeSort(buff, mid + 1, r, arr);

    merge(arr, l, r, mid, buff);
}

void mergeSort(vector<int>& arr) {
    int l = 0;
    int r = arr.size() - 1;

    vector<int> buff(arr);
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
