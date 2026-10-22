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
            result += char('A' + (c - 'A' + val(key[j])) % 26);
            key += c;
            j++;
        }
        else if (c >= 'a' && c <= 'z') {
            result += char('a' + (c - 'a' + val(key[j])) % 26);
            key += c;
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

        if ((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z')) {

            char base = (c >= 'A' && c <= 'Z') ? 'A' : 'a';

            char p = base + (c - base - val(key[j]) + 26) % 26;

            result += p;
            key += p;
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
    cout << "Enter primer: ";
    cin >> key;
    cin.ignore(); // Ignore the newline character left in the buffer
    string cipher = encrypt(text, key);

    cout << "Encrypted: " << cipher << endl;
    cout << "Decrypted: " << decrypt(cipher, key);

    return 0;
}