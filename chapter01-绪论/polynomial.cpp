/*
参考资料: [数据结构-浙江大学](https://www.bilibili.com/video/av18586085?p=3)
*/
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

#define EXPONENT 1000
#define MAX_VAULE 4
#define EPOCH 1e7

// 暴力法
float polynomialV1(float a[], int x)
{
  float sum;
  int i;
  for(i=0;i<EXPONENT;i++)
  {
    sum+=a[i]*pow(x,i);
  }
  return sum;
}

// 提取公因子法
float polynomialV2(float a[], int x)
{
  float sum = a[EXPONENT-1];
  int i;
  for(i=EXPONENT-2;i>=0;i--)
  {
    sum = x*sum+a[i];
  }
  return sum;
}

int main() {
  int x;
  std::cin >> x;
  float a[EXPONENT];
  int i;
  for(i=0;i<EXPONENT;i++)
    a[i]=rand()/(float)MAX_VAULE+1;

  clock_t begin,end;
  double duration;

  begin = clock();
  for(i=0;i<EPOCH;i++)
    polynomialV1(a, x);
  end = clock();
  duration=double(end-begin)/CLOCKS_PER_SEC;
  std::cout << duration/EPOCH<<std::endl;

  begin = clock();
  for(i=0;i<EPOCH;i++)
    polynomialV1(a, x);
  end =clock();
  duration=double(end-begin)/CLOCKS_PER_SEC;
  std::cout << duration/EPOCH<<std::endl;

  return EXIT_SUCCESS;
}
