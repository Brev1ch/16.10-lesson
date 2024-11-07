#include "table.hpp"
int main(){
  int long long m = 0, n = 0;
  std::cin >> m >> n;
  if (m < 1 || n < 1)
  {
    std::cout << "Input error!\n"
  }
  if (std::cin.fail())
  {
    std::cerr << "Input error!\n";
  }
  try
  {
    Matrix mtx(m, n);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Create error\n";
    return 1;
  }
  try
  {
    mtx.input(std::cin);
  }
  catch (const std::logic_error & e)
  {
    std::cerr << "Insufficient data\n";
    return 1;
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Invalid argument\n";
    return 1;
  }
  Matrix mtx2(mtx);
  mtx.print(std::cout);
  mtx2.print(std::cout);
  return 0;
}