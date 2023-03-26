#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int fibonacci_sum_squares(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    // std::cout << previous << "\n";
    // std::cout << current << "\n";

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
        
        // std::cout << current << "\n";
        
        sum += (current * current)%10;
    }

    return sum%10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares(n);
}

// cd src; g++ -pipe -O2 -std=c++11 fibonacci_sum_squares.cpp -o ../bin/fibonacci_sum_squares; cd ../bin/; ./fibonacci_sum_squares; cd ..
