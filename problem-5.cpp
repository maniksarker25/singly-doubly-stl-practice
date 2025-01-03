#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> list;
    int q;
    cin >> q;

    while (q--) {
        int x, v;
        cin >> x >> v;

        if (x == 0) {
            list.push_front(v);
        } 
        else if (x == 1) {
            list.push_back(v);
        } 
        else if (x == 2) {
            if (v >= 0 && v < list.size()) {
                auto it = list.begin();
                for (int i = 0; i < v; i++) {
                    ++it;
                }
                list.erase(it);
            }
        }

        cout << "l -> ";
        for (auto it = list.begin(); it != list.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;

        cout << "r -> ";
        if (!list.empty()) {
            auto it = list.end();
            --it;
            while (it != list.begin()) {
                cout << *it << " ";
                --it;
            }
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}
