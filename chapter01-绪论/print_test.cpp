/*
参考资料: [数据结构-浙江大学](https://www.bilibili.com/video/av18586085?p=2)
*/
#include <cstdlib>
#include <iostream>
#include <string>

#if 0           // 递归
void print_test(int n)
{
  if(n)
  {
    print_test(n-1);
    std::cout << n << std::endl;
  }
}
#else           // 循环
void print_test(int n)
{
  for(int i = 0; i < n; i++)
    std::cout << i << std::endl;
}
#endif

int main() {
  int n;
  std::cin >> n;
  print_test(n);
  return EXIT_SUCCESS;
}
