// This file is distributed under the BSD License.
// See "license.txt" for details.
// Copyright 2014, Jason Turner (jason@emptycrate.com)

#include <iostream>

int main()
{
  std::cout << "Expect 2 errors, one in stderr and one on stdout" << std::endl;
  std::cerr << "src/main.cpp:" << __LINE__ << ": Odd Error" << std::endl;
  std::cout << "src/main.cpp:" << __LINE__ << ": Odd Error 2" << std::endl;
  return 'a';
}
