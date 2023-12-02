#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

static int RED = 12;
static int GREEN = 13;
static int BLUE = 14;

int processLine(string str) {

  int colon = str.find(':');

  if (colon == string::npos) {
    return 0;
  }

  printf("> col pos : %d\n", colon);
  string day = str.substr(0, colon);

  size_t day_pos = day.find_first_of("0123456789");

  int num = stoi(day.substr(day_pos));

  printf("%s %s %d\n\n", str.c_str(), day.c_str(), num);

  return 0;
}

int main() {
  fstream file;

  // file.open("../input", ios::in);
  file.open("../test", ios::in);
  int sum = 0;
  string line;
  while (getline(file, line)) {
    sum = sum + processLine(line);
  }

  //  printf("sum: %d", processLine2("rsevenbqjfxh23rzdgcmdleightsixknpfs"));
  printf("sum: %d", sum);

  return 0;
}
