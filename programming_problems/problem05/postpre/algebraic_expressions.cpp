#include <string>
using std::string;

#include <iostream>

#include <cctype> // for isalpha

#include "algebraic_expressions.hpp"

bool isoperator(char ch) {
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(string s, int last) {
  int first = 0;

  if ((first > last)) {
    return -1;
  }

  char ch = s[last];
  if (isalpha(ch)) {
    return last;
  } else {
    if (isoperator(ch)) {
      int lastEnd = endPost(s, last - 1);
      if (lastEnd > -1) {
        return endPost(s, lastEnd - 1);
      } else {
        return -1;
      }
    } else {
      return -1;
    }
  }
}

bool isPost(string s) {
  int firstChar = endPost(s, s.size() - 1);

  return (firstChar == 0);
}

void convert(string &postfix, string &prefix) {

  int postLength = postfix.length();
  char ch = postfix[postLength - 1];
  
  if(ch >= 'a' && ch <= 'z') {
    prefix += ch;
  } else if (isoperator(ch)) {
    int endLast = endPost(postfix, postLength-1);
    string postfix1 = postfix.substr(endLast, postLength-2);
    string postfix2 = postfix.substr(0, endLast-1);
    prefix += ch;
    convert(postfix1, prefix);
    convert(postfix2, prefix);
  }
}
