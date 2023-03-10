#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}


int64_t get_fibonacci_last_digit(int n) {
    if (n <= 1)
        return n;

    int64_t previous = 0;
    int64_t current  = 1;

    // std::cout << "0: " << previous << "\n";
    // std::cout << "1: " << current << "\n";

    for (int i = 0; i < n - 1; ++i) {
        int64_t tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;

        // std::cout << current << "\n";
    }

    return current;
}

int main() {
    int n;
    std::cin >> n;
    int64_t c = get_fibonacci_last_digit(n);
    std::cout << c << '\n';
}
