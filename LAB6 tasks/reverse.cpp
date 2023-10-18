#include <iostream>
#include <stack>

using namespace std;

string reverseStringUsingStack(string str) {
  stack<char> s;
  for (int i = 0; i < str.length(); i++) {
    s.push(str[i]);
  }

  string reversedString = "";
  while (!s.empty()) {
    reversedString += s.top();
    s.pop();
  }

  return reversedString;
}

int main() {
  string str1;
  cout << "Enter a string: ";
  getline(cin, str1); // Use getline to read the whole line

  string reversedString = reverseStringUsingStack(str1);

  cout << "The reversed string is: " << reversedString << endl;

  return 0;
}

