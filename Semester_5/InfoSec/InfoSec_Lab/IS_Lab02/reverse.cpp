#include <iostream>
using namespace std;

string reverseCipher(string text) {
    string result = "";

    for (int i = text.length() - 1; i >= 0; i--) {
        result += text[i];
    }

    return result;
}

int main() {
    string text;

    cout << "Enter text: ";
    getline(cin, text);

    string cipher = reverseCipher(text);

    cout << "Encrypted: " << cipher << endl;
    cout << "Decrypted: " << reverseCipher(cipher);

    return 0;
}