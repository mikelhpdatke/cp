#include <bits/stdc++.h>
using namespace std;

string s;
stack<string> st;

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

void init() {
    while (s.find(' ') != string::npos) s.erase(s.find(' '),1);
    int i = 0;
    while (i < s.size())
        if (!isDigit(s[i])) {
            s.insert(i," ");
            s.insert(i+2," ");
            i = i + 3;
        } else i++;
    s += " ";
    while (s.find("  ") != string::npos) s.erase(s.find("  "),1);
    while (s[0] == ' ') s.erase(0,1);
}

string calc(string a, string t, string b) {
    int x = atoi(a.c_str());
    int y = atoi(b.c_str());
    int z;
    if (t == "+") z = x + y;
    if (t == "-") z = x - y;
    if (t == "*") z = x * y;
    if (t == "/") z = x / y;
    char temp[100];
    itoa(z,temp,10);
    return string(temp);
}

void run() {
    while (!s.empty()) {
        string p = s.substr(0,s.find(' '));
        if (p[0] == ')') {
            string a, t, b;
            b = st.top();
            st.pop();
            t = st.top();
            st.pop();
            a = st.top();
            st.pop();
            st.push(calc(a,t,b));
        } else if (p[0] != '(') st.push(p);
        s.erase(0,s.find(' ')+1);
    }
}

int main() {
    cout << "Nhap bieu thuc: ";
    getline(cin,s);
    init();
    run();
    cout << "Ket qua = " << st.top();
}
