#pragma once
#include <cstdint>

using Sum = unsigned __int128;
Sum sum_single(std::uint64_t n);
Sum sum_range(std::uint64_t first, std::uint64_t last);
Sum sum_threads(std::uint64_t n, unsigned thread_count);

void sum_worker(
    std::uint64_t first,
    std::uint64_t last,
    Sum& result
);

