#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>

#include "algorithms.hpp"

std::string to_decimal(Sum value)
{
    if (value == 0)
    {
        return "0";
    }

    std::string text;
    while (value > 0)
    {
        text.push_back(static_cast<char>('0' + value % 10));
        value /= 10;
    }

    std::reverse(text.begin(), text.end());
    return text;
}

int main()
{
    long long input_num;
    std::cin >> input_num;
    /*if (input_num < 0)
    {
        std::cout << "Invalid input\n";
        return 1;
    }*/

    const std::uint64_t n = static_cast<std::uint64_t>(input_num);
    const unsigned thread_count = 6;
    const unsigned repetitions = 10;

    for (unsigned run = 1; run <= repetitions; ++run)
    {
        auto start = std::chrono::steady_clock::now();
        Sum result = sum_single(n);
        auto finish = std::chrono::steady_clock::now();
        double seconds = std::chrono::duration<double>(finish - start).count();

        std::cout << "Single " << run << ": sum = " << to_decimal(result)
                  << ", time = " << seconds << " s" << std::endl;
    }

    for (unsigned run = 1; run <= repetitions; ++run)
    {
        auto start = std::chrono::steady_clock::now();
        Sum result = sum_threads(n, thread_count);
        auto finish = std::chrono::steady_clock::now();
        double seconds = std::chrono::duration<double>(finish - start).count();

        std::cout << "Multi " << run << ": sum = " << to_decimal(result)
                  << ", time = " << seconds << " s" << std::endl;
    }

    return 0;
}
