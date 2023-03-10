#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<long long>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            long long prod = numbers[first] * numbers[second];

            if(prod > max_product){
                max_product = prod;
            }
        }
    }

    return max_product;
}

long long MaxPairWiseProductFast(const std::vector<long long>& numbers){
    long long max_product = 0;
    int n = numbers.size();

    long long max=-1, sec_max=-1;
    int max_i, sec_max_i;

    for(int i=0; i<n; i++){
        if(numbers[i] > max){
            max = numbers[i];
            max_i = i;
        }
    }

    for(int i=0; i<n; i++){
        if(i != max_i && numbers[i] > sec_max){
            sec_max = numbers[i];
            sec_max_i = i;
        }
    }

    return max * sec_max;
}

int main() {
    // stress test
    // while(true){
    //     int n = rand() % 200000 + 2;

    //     std::cout << n << "\n";

    //     std::vector<long long> a;

    //     for(int i=0; i<n; i++){
    //         a.push_back(rand() % 100000);
    //     }

    //     for(int i=0; i<n; i++){
    //         std::cout << a[i] << " ";
    //     }

    //     std::cout << "\n";

    //     long long result1 = MaxPairwiseProduct(a);
    //     long long result2 = MaxPairWiseProductFast(a);

    //     if(result1 != result2){
    //         std::cout << "Wrong Answer: " << result1 << " " << result2 << "\n";
    //         break;
    //     }else{
    //         std::cout << "Ok\n";
    //     }
    // }


    int n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairWiseProductFast(numbers) << "\n";
    return 0;
}
