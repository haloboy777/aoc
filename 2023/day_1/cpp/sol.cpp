#include <cstdio>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
unordered_map<string, string> digitMap = {

    {"one", "o1e"},  {"two", "t2o"}, {"three", "t3e"}, {"four", "f4r"},
    {"five", "f5e"}, {"six", "s6x"}, {"seven", "s7n"}, {"eight", "e8t"},
    {"nine", "n9e"}

};

int processLine2(string str) {
  int len = str.size();
  vector<int> digits;
  //  for (int i = 0; i < len; i++) {
  //    if (str[i] > 47 && str[i] < 58) {
  //      str[i] = '_';
  //    }
  //  }

  for (auto const &[key, value] : digitMap) {
    // hello
    // printf("> %s\n", key.c_str());
    size_t pos = str.find(key);
    while (pos != string::npos) {
      str.replace(pos, key.length(), value);
      pos = str.find(key, pos + value.length());
    }
  }
  for (int i = 0; i < len; i++) {
    if (str[i] > 47 && str[i] < 58) {
      digits.push_back((str[i] - 48));
    }
  }
  int num =
      digits.size() > 0 ? (digits[0] * 10) + digits[digits.size() - 1] : 0;
  // printf("%d\t:\t%s\n", num, str.c_str());
  return num;
}

int processLine(string str) {
  int len = str.size();
  vector<int> digits;
  for (int i = 0; i < len; i++) {
    if (str[i] > 47 && str[i] < 58) {
      digits.push_back((str[i] - 48));
    }
  }
  int num = (digits[0] * 10) + digits[digits.size() - 1];
  printf("%d\t:\t%s\n", num, str.c_str());
  return num;
}

int main() {

  fstream file;

  file.open("../input", ios::in);
  // file.open("test", ios::in);
  int sum = 0;
  string line;
  while (getline(file, line)) {
    sum = sum + processLine2(line);
  }

  //  printf("sum: %d", processLine2("rsevenbqjfxh23rzdgcmdleightsixknpfs"));
  printf("sum: %d", sum);

  return 0;
}
