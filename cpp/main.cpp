#include "zyggy-begin.h"
#include <iostream>
#include "zyggy-end.h"

int main(int argc, char *argv[]) try
{
  std::cout << "Hello world!" << std::endl;
  for (auto i = 0; i < argc; ++i) {
    std::cout << argv[i] << std::endl;
  }
  return 0;
}
catch (const std::runtime_error& exception) {
  std::cerr << "Exception caught: " << exception.what() << std::endl;
  return 1;
}
