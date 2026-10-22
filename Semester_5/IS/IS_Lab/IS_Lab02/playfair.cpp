#include <iostream>
using namespace std;

char grid[5][5];

string clean(string s) {
    string r = "";
    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';
        }
        
        if (c >= 'A' && c <= 'Z') {
            if (c == 'J') c = 'I';
            r += c;
        }
    }
    return r;
}

void makeGrid(string key) {
    string letters = clean(key) + "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    string used = "";

    for (char c : letters) {
        if (used.find(c) == string::npos) used += c;
    }

    for (int i = 0; i < 25; i++) { grid[i / 5][i % 5] = used[i]; }
}

void position(char c, int &r, int &col) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (grid[i][j] == c) {
                r = i;
                col = j;
                return;
            }
}

string prepare(string text) {
    text = clean(text);
    string result = "";

    for (int i = 0; i < static_cast<int>(text.length());) {
        char a = text[i];
        char b = 'X';

        if (i + 1 < static_cast<int>(text.length()) && text[i + 1] != a) {
            b = text[i + 1];
            i += 2;
        }
        else {
            b = (a == 'X') ? 'Q' : 'X';
            i++;
        }

        result += a;
        result += b;
    }
    return result;
}

string convert(string text, int shift) {
    string result = "";

    for (int i = 0; i < static_cast<int>(text.length()); i += 2) {
        int r1, c1, r2, c2;

        position(text[i], r1, c1);
        position(text[i + 1], r2, c2);

        if (r1 == r2) {
            c1 = (c1 + shift + 5) % 5;
            c2 = (c2 + shift + 5) % 5;
        }
        else if (c1 == c2) {
            r1 = (r1 + shift + 5) % 5;
            r2 = (r2 + shift + 5) % 5;
        }
        else {
            int temp = c1;
            c1 = c2;
            c2 = temp;
        }

        result += grid[r1][c1];
        result += grid[r2][c2];
    }
    return result;
}

int main() {
    string text, key;

    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter keyword: ";
    cin >> key;

    makeGrid(key);

    string cipher = convert(prepare(text), 1);

    cout << "Encrypted: " << cipher << endl;
    cout << "Decrypted: " << convert(cipher, -1);

    return 0;
}