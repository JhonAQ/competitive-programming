#include <bits/stdc++.h>
using namespace std;

stack<string> s;
unordered_map<string, string> op = {{")", "("},{"]", "["},{"}", "{"},{">", "<"},{"*)", "(*"}};
unordered_map<string, string> cl = {{"(", ")"},{"[", "]"},{"{", "}"},{"<", ">"},{"(*", "*)"}};

bool producesAnError(string c) {
  if ((op.find(c) != op.end()) && (s.empty() || s.top() != op[c])) return true; // En caso de que sea de cierre y no haya nada en stack, o sea cierre y el top sea distinto
  if (cl.find(c) != cl.end())
    s.push(c);
  else
    s.pop();
  return false;
}
string nextChar(string &str) {
  int sl = str.size(), len;
  if (sl == 0) return "ef";
  len = (sl >= 2 && (str.substr(0, 2) == "(*" || str.substr(0, 2) == "*)")) ? 2 : 1;
  string res = str.substr(0, len);
  str = str.substr(len);
  return res;
}

int main() {
  string line;
  int count = 0;
  while (getline(cin, line)) {
    while (!s.empty()) s.pop();
    count = 0;
    string actual = nextChar(line);
    bool error = false;
    while (actual != "ef") { // itera sobre cada caracter de la string
      count++;
      // cout << "Count: " << count << "\tactual = " << actual << endl;
      bool isBracket = ((op.find(actual) != op.end()) || (cl.find(actual) != cl.end()));
      if ( isBracket && producesAnError(actual)) {
        error = true;
        while(!s.empty()) s.pop();
        break; // error detectado, salida del buble inmediata
      }
      actual = nextChar(line);
    } // Luego de iterar, comprobamos los casos de salida
    if (!s.empty())
      count++;
    if (error || !s.empty())
      cout << "NO " << count << endl;
    else
      cout << "YES" << endl;
  }
}