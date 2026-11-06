#include <iostream>
using namespace std;

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
    for (int key = 0; key < 26; key++)
        cout << "Key " << key << " : " << caesarDecrypt(cipher, key) << endl;
    return 0;
}
