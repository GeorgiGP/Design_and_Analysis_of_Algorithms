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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    set<char> vow;
    vow.insert('a');
    vow.insert('e');

    long len;
    cin >> len;

    for (int i = 1; i <= len; ++i) {
        long num;
        cin >> num;
        string s;
        for (int j = 0; j < num; ++j) {
            char ch;
            cin >> ch;
            s.push_back(ch);
            if (s.length() == 4) {
                if (vow.count(ch) == 1) {
                    cout << s.substr(0, 2) << ".";
                    s = std::move(s.substr(2, s.length() - 2));
                } else {
                    cout << s.substr(0, 3) << ".";
                    s = std::move(s.substr(3, s.length() - 3));
                }
            }
        }
        cout << s << endl;
    }
}
