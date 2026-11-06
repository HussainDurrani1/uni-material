#include <iostream>
using namespace std;

string encrypt(string text, string key) {
    int cols = key.length();

    while (text.length() % cols != 0)
        text += 'X';

    int rows = text.length() / cols;
    string result = "";

    for (int k = 1; k <= cols; k++) {
        for (int j = 0; j < cols; j++) {
            if (key[j] - '0' == k) {
                for (int i = 0; i < rows; i++)
                    result += text[i * cols + j];
            }
        }
    }
    return result;
}

string decrypt(string text, string key) {
    int cols = key.length();
    int rows = text.length() / cols;

    string result = text;
    int index = 0;

    for (int k = 1; k <= cols; k++) {
        for (int j = 0; j < cols; j++) {
            if (key[j] - '0' == k) {
                for (int i = 0; i < rows; i++)
                    result[i * cols + j] = text[index++];
            }
        }
    }
    return result;
}

int main() {
    string text, key;

    cout << "Enter text (no spaces): ";
    cin >> text;
    cout << "Enter numeric key: ";
    cin >> key;

    string cipher = encrypt(text, key);

    cout << "Encrypted: " << cipher << endl;
    cout << "Decrypted: " << decrypt(cipher, key);

    return 0;
}
