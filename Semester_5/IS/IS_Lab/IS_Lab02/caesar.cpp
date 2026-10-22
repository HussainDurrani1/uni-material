#include <iostream>
using namespace std;

string encrypt(string text, int key) {
    string result = "";
    key = (key % 26 + 26) % 26;

    for (int i = 0; i < static_cast<int>(text.length()); ++i) {
        char c = text[i];

        if (c >= 'A' && c <= 'Z')
            c = 'A' + (c - 'A' + key) % 26;
        else if (c >= 'a' && c <= 'z')
            c = 'a' + (c - 'a' + key) % 26;

        result += c;
    }
    return result;
}

string decrypt(string text, int key) {
    return encrypt(text, -key);
}

int main() {
    string text;
    int key;

    cout << "Enter plain text: ";
    getline(cin, text);
    cout << "Enter key: ";
    cin >> key;

    string cipher = encrypt(text, key);

    cout << "Encrypted: " << cipher << endl;
    cout << "Decrypted: " << decrypt(cipher, key )<< endl;

    return 0;
}