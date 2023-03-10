#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
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

void test(){
  while(true){
    int a = rand() % 10000;
    int b = rand() % 10000;


    int res1 = gcd(a, b);
    int res2 = gcd_naive(a, b);

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

  
  // std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd(a, b) << std::endl;

  return 0;
}
