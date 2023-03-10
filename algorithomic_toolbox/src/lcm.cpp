#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd(int a, int b){
  if(b == 0){
    return a;
  }

  int rem = a % b;
  a = b;
  b = rem;

  return gcd(a, b);
}

long long lcm(int a, int b){
  return (long long)a * b / gcd(a, b);
}

void test(){
  while(true){
    int a = rand() % 10000;
    int b = rand() % 10000;


    long long res1 = lcm(a, b);
    long long res2 = lcm_naive(a, b);

    if(res1 != res2){
      std::cout << a << " " << b << "\n";
      std::cout << "Wrong Answer: " << res1 << " " << res2 << "\n";
      break;
    }else{
      std::cout << "OK\n";
    }
  }
}

int main() {
  // test();

  int a, b;
  std::cin >> a >> b;

  // std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm(a, b) << std::endl;

  return 0;
}
