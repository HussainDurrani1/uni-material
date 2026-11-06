#include <iostream>
using namespace std;

int idx(char c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A';
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    return -1;
}

int main() {
    string text;
    cout << "Enter text: ";
    getline(cin, text);
    int f[26] = {0};
    int total = 0;
    for (int i = 0; i < text.length(); i++) {
        int k = idx(text[i]);
        if (k >= 0) {
            f[k]++;
            total++;
        }
    }
    for (int i = 0; i < 26; i++)
        if (f[i] > 0)
            cout << char('A' + i) << " : " << f[i] << " : " << f[i] * 100.0 / total << "%" << endl;
 
   return 0;
}
