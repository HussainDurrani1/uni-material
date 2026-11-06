#include <iostream>
using namespace std;

int val(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    return c - 'a';
}

string encrypt(string text, string key) {
    string result = "";
    int j = 0;

    for (int i = 0; i < static_cast<int>(text.length()); i++) {
        char c = text[i];

        if (c >= 'A' && c <= 'Z') {
            result += char('A' + (c - 'A' + val(key[j % key.length()])) % 26);
            j++;
        }
        else if (c >= 'a' && c <= 'z') {
            result += char('a' + (c - 'a' + val(key[j % key.length()])) % 26);
            j++;
        }
        else
            result += c;
    }
    return result;
}

string decrypt(string text, string key) {
    string result = "";
    int j = 0;

    for (int i = 0; i < static_cast<int>(text.length()); i++) {
        char c = text[i];
        int k = val(key[j % key.length()]);

        if (c >= 'A' && c <= 'Z') {
            result += char('A' + (c - 'A' - k + 26) % 26);
            j++;
        }
        else if (c >= 'a' && c <= 'z') {
            result += char('a' + (c - 'a' - k + 26) % 26);
            j++;
        }
        else
            result += c;
    }
    return result;
}

int main() {
    string text, key;

    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter keyword: ";
    cin >> key;

    string cipher = encrypt(text, key);

    cout << "Encrypted: " << cipher << endl;
    cout << "Decrypted: " << decrypt(cipher, key);

    return 0;
}