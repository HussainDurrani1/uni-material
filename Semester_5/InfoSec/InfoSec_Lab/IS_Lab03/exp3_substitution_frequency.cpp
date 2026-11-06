#include <iostream>
using namespace std;

string engOrder = "ETAOINSHRDLU";

int idx(char c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A';
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    return -1;
}

char up(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

int main() {
    string c = "ZOLSS AOL JHU KPFF TVYF AOHA AOPZ PZ H ZLTWSL JYPWALY";
    int f[26] = {0};
    for (int i = 0; i < c.length(); i++) {
        int k = idx(c[i]);
        if (k >= 0)
            f[k]++;
    }
    int o[26];
    int n = 0;
    for (int i = 0; i < 26; i++)
        if (f[i] > 0)
            o[n++] = i;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (f[o[j]] > f[o[i]]) {
                int t = o[i];
                o[i] = o[j];
                o[j] = t;
            }
    char mp[26];
    for (int i = 0; i < 26; i++)
        mp[i] = '_';
    for (int i = 0; i < n && i < engOrder.length(); i++)
        mp[o[i]] = engOrder[i];
    for (int i = 0; i < n; i++)
        cout << char('A' + o[i]) << " -> " << mp[o[i]] << endl;
    string r = "";
    for (int i = 0; i < c.length(); i++) {
        int k = idx(c[i]);
        if (k >= 0)
            r = r + mp[k];
        else
            r = r + c[i];
    }
    cout << r << endl;
    return 0;
}
