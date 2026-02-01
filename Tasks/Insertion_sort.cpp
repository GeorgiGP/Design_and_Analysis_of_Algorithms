#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>
#include <utility>
#include <iomanip>
#include <bitset>
#include <tuple>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
#define endl '\n'

void insertion_sort(vector<long>& arr) {
    for(int i = 0; i < arr.size(); ++i) {
        int j = i;
        long cur = arr[i];
        while (j > 0 && arr[j - 1] > cur) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = cur;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long len;
    cin >> len;

    vector<long> arr(len, 0);
    for(int i = 0; i < len; ++i) {
        cin >> arr[i];
    }
    insertion_sort(arr);
    for(long el : arr) {
        cout << el << " ";
    }
    cout << endl;
}
