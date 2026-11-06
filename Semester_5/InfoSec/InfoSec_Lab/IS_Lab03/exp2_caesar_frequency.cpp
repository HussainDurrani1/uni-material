#include <iostream>
using namespace std;

int idx(char c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A';
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    return -1;
}

char shiftChar(char c, int k) {
    if (c >= 'A' && c <= 'Z')
        return 'A' + (c - 'A' + k + 26) % 26;
    if (c >= 'a' && c <= 'z')
        return 'a' + (c - 'a' + k + 26) % 26;
    return c;
}

string applyShift(string t, int k) {
    string r = "";
    for (int i = 0; i < t.length(); i++)
        r = r + shiftChar(t[i], k);
    return r;
}

int main() {
    string c = "SOJZKXS KDGS OY ZUU KGYE";
    int f[26] = {0};
    int total = 0;
    for (int i = 0; i < c.length(); i++) {
        int k = idx(c[i]);
        if (k >= 0) {
            f[k]++;
            total++;
        }
    }
    for (int i = 0; i < 26; i++)
        if (f[i] > 0)
            cout << char('A' + i) << " : " << f[i] << " : " << f[i] * 100.0 / total << "%" << endl;
    int mx = 0;
    for (int i = 0; i < 26; i++)
        if (f[i] > mx)
            mx = f[i];
    for (int i = 0; i < 26; i++)
        if (f[i] == mx) {
            int key = (i - 4 + 26) % 26;
            cout << "Top letter " << char('A' + i) << " -> key " << key << " : " << applyShift(c, 26 - key) << endl;
        }
    return 0;
}
