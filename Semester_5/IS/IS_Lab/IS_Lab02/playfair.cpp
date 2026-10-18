#include <iostream>
using namespace std;

char up(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

void buildMatrix(string key, char m[5][5]) {
    int used[26] = {0};
    used['J' - 'A'] = 1;
    string s = "";
    for (int i = 0; i < key.length(); i++) {
        char c = up(key[i]);
        if (c == 'J')
            c = 'I';
        if (c >= 'A' && c <= 'Z' && used[c - 'A'] == 0) {
            used[c - 'A'] = 1;
            s = s + c;
        }
    }
    for (char c = 'A'; c <= 'Z'; c++)
        if (used[c - 'A'] == 0)
            s = s + c;
    int k = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            m[i][j] = s[k++];
}

void findPos(char m[5][5], char c, int &r, int &col) {
    if (c == 'J')
        c = 'I';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (m[i][j] == c) {
                r = i;
                col = j;
                return;
            }
}

string prep(string t) {
    string r = "";
    for (int i = 0; i < t.length(); i++) {
        char c = up(t[i]);
        if (c == 'J')
            c = 'I';
        if (c >= 'A' && c <= 'Z')
            r = r + c;
    }
    return r;
}

string playfairEnc(string t, char m[5][5]) {
    string p = prep(t);
    string r = "";
    int i = 0;
    while (i < p.length()) {
        char a = p[i];
        char b = 'X';
        if (i + 1 < p.length())
            b = p[i + 1];
        if (a == b) {
            b = 'X';
            i = i + 1;
        } else {
            i = i + 2;
        }
        int r1, c1, r2, c2;
        findPos(m, a, r1, c1);
        findPos(m, b, r2, c2);
        if (r1 == r2) {
            r = r + m[r1][(c1 + 1) % 5];
            r = r + m[r2][(c2 + 1) % 5];
        } else if (c1 == c2) {
            r = r + m[(r1 + 1) % 5][c1];
            r = r + m[(r2 + 1) % 5][c2];
        } else {
            r = r + m[r1][c2];
            r = r + m[r2][c1];
        }
    }
    return r;
}

string playfairDec(string t, char m[5][5]) {
    string r = "";
    for (int i = 0; i < t.length(); i = i + 2) {
        char a = t[i];
        char b = t[i + 1];
        int r1, c1, r2, c2;
        findPos(m, a, r1, c1);
        findPos(m, b, r2, c2);
        if (r1 == r2) {
            r = r + m[r1][(c1 + 4) % 5];
            r = r + m[r2][(c2 + 4) % 5];
        } else if (c1 == c2) {
            r = r + m[(r1 + 4) % 5][c1];
            r = r + m[(r2 + 4) % 5][c2];
        } else {
            r = r + m[r1][c2];
            r = r + m[r2][c1];
        }
    }
    return r;
}

void printMatrix(char m[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
}

int main() {
    char m[5][5];
    buildMatrix("MONARCHY", m);
    printMatrix(m);
    string t = "CRYPTOGRAPHY";
    string c = playfairEnc(t, m);
    cout << "Plaintext:  " << t << endl;
    cout << "Encrypted:  " << c << endl;
    cout << "Decrypted:  " << playfairDec(c, m) << endl;
    return 0;
}