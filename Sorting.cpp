#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, ns, in, min = 0, posf, index = 0, posi = 0, ab;
    cin >> t >> ns;
    vector <int> n, a;
    for (int i = 0; i < ns; i++) {
        cin >> in;
        n.push_back(in);
    }
    sort(n.begin(), n.end());
    for (int i = 0; i < ns; i++) {
        a.push_back(abs(n[i]));
    }
    sort(a.begin(), a.end());
    while (min < t) {
        if (count(n.begin(), n.end(), a[index]) == 0) {
            posf = a[index] * -1;
        } else {
            posf = a[index];
        }
        min += abs(posf - posi);
        posi = posf;
        index++;
    }
    cout << index-1;
}