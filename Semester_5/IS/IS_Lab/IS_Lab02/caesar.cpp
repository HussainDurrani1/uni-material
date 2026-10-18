#include <iostream>
using namespace std;

char shiftChar(char c, int k) {
    if (c >= 'A' && c <= 'Z')
        return 'A' + (c - 'A' + k + 26) % 26;
    if (c >= 'a' && c <= 'z')
        return 'a' + (c - 'a' + k + 26) % 26;
    return c;
}

string caesarEnc(string t, int k) {
    string r = "";
    for (int i = 0; i < t.length(); i++)
        r = r + shiftChar(t[i], k);
    return r;
}

string caesarDec(string t, int k) {
    return caesarEnc(t, 26 - k % 26);
}

int main() {
    string name = "Hussain Durrani";
    int k = 3;
    string c = caesarEnc(name, k);
    cout << "Plaintext:  " << name << endl;
    cout << "Encrypted:  " << c << endl;
    cout << "Decrypted:  " << caesarDec(c, k) << endl;
    return 0;
}