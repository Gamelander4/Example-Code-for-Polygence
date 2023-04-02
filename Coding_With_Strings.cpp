#include <bits/stdc++.h>
using namespace std;

struct Members
{
    int game;
    string name;
    int change;
};
bool compare(Members a, Members b) {
    if (a.game < b.game) {
        return 1;
    }
    else {
        return 0;
    }
}
int main() {
    int n, m_points = 7, e_points = 7, b_points = 7, lead_change = 0;
    string cleader = "", pleader = "";
    cin >> n;
    Members p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i].game >> p[i].name >> p[i].change;
    }
    sort(p, p+n, compare);
    for (int i = 0; i < n; i++) {
        if (p[i].name == "Mildred") {
            m_points += p[i].change;
        }
        if (p[i].name == "Elsie") {
            e_points += p[i].change;
        }
        if (p[i].name == "Bessie") {
            b_points += p[i].change;
        }
        if (m_points > e_points && m_points > b_points) {
            pleader = cleader;
            cleader = "Mildred";
        } else if (e_points > m_points && e_points > b_points) {
            pleader = cleader;
            cleader = "Elsie";
        } else if (b_points > m_points && b_points > e_points) {
            pleader = cleader;
            cleader = "Bessie";
        } else if (m_points == e_points && m_points > b_points) {
            pleader = cleader;
            cleader = "Mildred and Elsie";
        } else if (e_points == b_points && e_points > m_points) {
            pleader = cleader;
            cleader = "Elsie and Bessie";
        } else if (b_points == m_points && b_points > e_points) {
            pleader = cleader;
            cleader = "Bessie and Mildred";
        } else if (m_points == e_points && m_points == b_points && e_points == b_points) {
            pleader = cleader;
            cleader = "Tied";
        }
        if (pleader != cleader) {
            lead_change++;
        } 
    }
    cout << lead_change;
}