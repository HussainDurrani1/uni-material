#include <iostream>
using namespace std;

string beaufort(string text, int key) {
    string result = "";
    key = (key % 26 + 26) % 26;

    for (int i = 0; i < static_cast<int>(text.length()); i++) {
        char c = text[i];

        if (c >= 'A' && c <= 'Z')
            c = 'A' + (key - (c - 'A') + 26) % 26;
        else if (c >= 'a' && c <= 'z')
            c = 'a' + (key - (c - 'a') + 26) % 26;

        result += c;
    }
    return result;
}

int main() {
    string text;
    int key;

    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter key (0-25): ";
    cin >> key;

    string cipher = beaufort(text, key);

    cout << "Encrypted: " << cipher << endl;
    cout << "Decrypted: " << beaufort(cipher, key);

    return 0;
}