#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX_RANDOM_VALUE 100
#define MIN_RANDOM_VALUE -100

/**
 * 
 * 暴力解法
 * 算法复杂度为O(n^3)
 **/
int maxSubseqV1(int a[], int K)
{
    int i,j,k;
    int sum;
    int maxSum=0;

    for(i=0;i<K;i++){
        for(j=i;j<K;j++){
            sum=0;
            for(k=i;k<=j;k++){
                sum += a[k];
                if(sum>maxSum)
                    maxSum=sum;
            }
        }
    }
    return maxSum;
}

/**
 * 
 * 累加解法
 * 算法复杂度为O(n^2)
 **/
int maxSubseqV2(int a[], int K)
{
    int i,j,k;
    int sum;
    int maxSum=0;

    for(i=0;i<K;i++){
        sum=0;
        for(j=i;j<K;j++){
            sum += a[j];
            if(sum>maxSum)
                maxSum=sum;
        }
    }
    return maxSum;
}

/**
 * 
 * 分而治之法
 * 算法复杂度为O(nlogn)
 **/
int maxInTwoValue(int left, int right)
{
   return std::max(std::max(left,right),left+right);
}
int maxInArray(int a[], int left, int right)
{
   return std::max(std::max(std::max(a[left],a[right]),a[left]+a[right]),0);
}

int maxSubseqV3(int a[], int left, int right, int K)
{
    int leftMax,rightMax;
    if(K>2){
       leftMax=maxSubseqV3(a,left, left+K/2-1,K/2);
       rightMax=maxSubseqV3(a,left+K/2, right,K/2);
       return maxInTwoValue(leftMax,rightMax);
    }
    else
        return maxInArray(a,left,right);
}


/**
 * 
 * 在线法
 * 算法复杂度为O(n)
 **/
int maxSubseqV4(int a[], int K)
{
    int i;
    int sum=0;
    int maxSum=0;

    for(i=0;i<K;i++){
        sum=sum+a[i];
        if(sum>maxSum)
            maxSum = sum;
        if(sum<0)
            sum=0;          
    }
    return maxSum;
}

// 参考资料: [C/C++ 生成随机数](https://blog.csdn.net/YF_Li123/article/details/75220786)
void generateRandomNumber(int a[], int K){
    std::srand(std::time(nullptr)); // 以当前时间为随机生成器的种子
 
    for (int n = 0; n != K; ++n) {
        a[n] = std::rand() % (MAX_RANDOM_VALUE-MIN_RANDOM_VALUE+1)+MIN_RANDOM_VALUE;
        // std::cout << a[n]<<std::endl;
    }
}

int main()
{
#if 0
  int K;
  std::cout << "Please input array's length:";
  std::cin >> K;
  int* a=(int*)malloc(K*sizeof(int));
  generateRandomNumber(a,K);
#else
  int K;
  std::cin>>K;
  int* a=(int*)malloc(sizeof(int)*K);
  for(int k=0;k<K;k++)
  { std::cin>>a[k];
    std::cout<<" ";
  }
#endif
  std::cout << "V1:The maximun sub sequential's value is:";
  std::cout << maxSubseqV1(a,K) << std::endl;
  std::cout << "V2:The maximun sub sequential's value is:";
  std::cout << maxSubseqV2(a,K) << std::endl;
  std::cout << "V3:The maximun sub sequential's value is:";
  std::cout << maxSubseqV3(a,0, K-1, K) << std::endl;
  std::cout << "V4:The maximun sub sequential's value is:";
  std::cout << maxSubseqV4(a,K) << std::endl;

  return 0;
}