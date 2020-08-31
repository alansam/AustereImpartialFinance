/*
 *  Branchless Programming from "YouTube" channel:
 *  ;C  What's a Creel?
 *  Practical x64 Assembly and C++ Tutorials.
 */

#include <iostream>
#include <cstring>

int Smaller(int a, int b);
int Smaller_Branchless(int a, int b);
void ToUpperCPP(char * d, int count);
void ToUpper_Branchless(char * d, int count);
void ToUpper_Branchless2(char * d, int count);

int main() {
  std::cout << "Hello World!\n";
  std::cout << Smaller(1, 2) << std::endl;
  std::cout << Smaller_Branchless(2, 1) << std::endl;

  char const * foxy = "The Quick Brown Fox Jumps Over A Lazy Dog.";
  size_t foxy_l = strlen(foxy);
  char fox[50] { '\0', };

  strncpy(fox, foxy, foxy_l);
  std::cout << fox << std::endl;
  ToUpperCPP(fox, foxy_l);
  std::cout << fox << std::endl;

  strncpy(fox, foxy, foxy_l);
  std::cout << fox << std::endl;
  ToUpper_Branchless(fox, foxy_l);
  std::cout << fox << std::endl;

  strncpy(fox, foxy, foxy_l);
  std::cout << fox << std::endl;
  ToUpper_Branchless2(fox, foxy_l);
  std::cout << fox << std::endl;
  return 0;
}

int Smaller(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}

int Smaller_Branchless(int a, int b) {
  return a * (a < b)
       + b * (b <= a);
}

void ToUpperCPP(char * d, int count) {
  for (int i = 0; i < count; i++) {
    if (d[i] >= 'a' && d[i] <= 'z')
      d[i] -= 32;
  }
}

void ToUpper_Branchless(char * d, int count) {
  for (int i = 0; i < count; i++) {
    d[i] = (d[i] * !(d[i] >= 'a' && d[i] <= 'z')) +
      (d[i] - 32) * (d[i] >= 'a' && d[i] <= 'z');
  }
}

void ToUpper_Branchless2(char * d, int count) {
  for (int i = 0; i < count; i++) {
    d[i] -= 32 * (d[i] >= 'a' && d[i] <= 'z');
  }
}