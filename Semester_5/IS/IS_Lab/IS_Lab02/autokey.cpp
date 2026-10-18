#include <iostream>
using namespace std;

int val(char c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A';
    return c - 'a';
}

char encChar(char c, int k) {
    if (c >= 'A' && c <= 'Z')
        return 'A' + (c - 'A' + k) % 26;
    return 'a' + (c - 'a' + k) % 26;
}

char decChar(char c, int k) {
    if (c >= 'A' && c <= 'Z')
        return 'A' + (c - 'A' - k + 26) % 26;
    return 'a' + (c - 'a' - k + 26) % 26;
}

int isLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

string autoEnc(string t, string primer) {
    string r = "";
    string key = primer;
    int j = 0;
    for (int i = 0; i < t.length(); i++) {
        if (isLetter(t[i])) {
            r = r + encChar(t[i], val(key[j]));
            key = key + t[i];
            j++;
        } else {
            r = r + t[i];
        }
    }
    return r;
}

string autoDec(string t, string primer) {
    string r = "";
    string key = primer;
    int j = 0;
    for (int i = 0; i < t.length(); i++) {
        if (isLetter(t[i])) {
            char p = decChar(t[i], val(key[j]));
            r = r + p;
            key = key + p;
            j++;
        } else {
            r = r + t[i];
        }
    }
    return r;
}

int main() {
    string t = "CRYPTOGRAPHY";
    string primer = "KEY";
    string c = autoEnc(t, primer);
    cout << "Plaintext:  " << t << endl;
    cout << "Encrypted:  " << c << endl;
    cout << "Decrypted:  " << autoDec(c, primer) << endl;
    return 0;
}