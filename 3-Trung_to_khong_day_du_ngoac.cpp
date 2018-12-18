#include <bits/stdc++.h>
using namespace std;

string s;
stack<string> num, op;

int isDigit(char c){
    return (c >= '0' && c <='9');
}

int isOp(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void init(){
    while (s.find(' ') != string::npos) s.erase(s.find(' '),1);
    int i = 0;
    while (i < s.size())
    if (!isDigit(s[i])){
        s.insert(i," ");
        s.insert(i+2," ");
        i = i + 3;
    } else i++;
    s += " ";
    while (s.find("  ") != string::npos) s.erase(s.find("  "),1);
    while (s[0] == ' ') s.erase(0,1);
}

int UT(char c){
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void calc(){
    string a, t, b, c;
    b = num.top();
    num.pop();
    a = num.top();
    num.pop();
    t = op.top();
    op.pop();
    int x = atoi(a.c_str());
    int y = atoi(b.c_str());
    int r;
    if (t == "+") r = x+y;
    if (t == "-") r = x-y;
    if (t == "*") r = x*y;
    if (t == "/") r = x/y;
    char temp[100];
    itoa(r,temp,10);
    string tem = string(temp);
    num.push(tem);
}

void run(){
    while (!s.empty()){
        string p = s.substr(0,s.find(' '));
        if (isDigit(p[0])) num.push(p);
        if (p[0] == '(') op.push(p);
        if (isOp(p[0])){
            while (!op.empty() && UT(op.top()[0]) >= UT(p[0])) calc();
            op.push(p);
        }
        if (p[0] == ')')
        {
            while (op.top() != "(") calc();
            op.pop();
        }
        s.erase(0,s.find(' ')+1);
    }
    while (!op.empty()) calc();
}

int main()
{
    cout << "Nhap bieu thuc: ";
    getline(cin, s);
    init();
    run();
    cout << "Ket qua bang = " << num.top();
}
