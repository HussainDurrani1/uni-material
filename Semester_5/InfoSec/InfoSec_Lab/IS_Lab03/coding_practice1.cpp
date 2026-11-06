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

string caesarDecrypt(string t, int key) {
    string r = "";
    for (int i = 0; i < t.length(); i++)
        r = r + shiftChar(t[i], 26 - key);
    return r;
}

int main() {
    string cipher;
    cout << "Enter ciphertext: ";
    getline(cin, cipher);
    int counts[26] = {0};
    int total = 0;
    for (int i = 0; i < cipher.length(); i++) {
        int k = idx(cipher[i]);
        if (k >= 0) {
            counts[k]++;
            total++;
        }
    }
    for (int i = 0; i < 26; i++)
        if (counts[i] > 0)
            cout << char('A' + i) << " : " << counts[i] << " : " << counts[i] * 100.0 / total << "%" << endl;
    int mx = 0;
    for (int i = 0; i < 26; i++)
        if (counts[i] > mx)
            mx = counts[i];
    for (int i = 0; i < 26; i++)
        if (counts[i] == mx) {
            int key = (i - 4 + 26) % 26;
            cout << "Top letter " << char('A' + i) << " -> key " << key << " : " << caesarDecrypt(cipher, key) << endl;
        }
    for (int key = 0; key < 26; key++)
        cout << "Key " << key << " : " << caesarDecrypt(cipher, key) << endl;
    return 0;
}
