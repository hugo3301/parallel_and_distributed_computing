#include "algorithms.hpp"

#include <functional>
#include <thread>
#include <vector>

Sum sum_range(std::uint64_t first, std::uint64_t last)
{
    Sum storage = 0;
    for (; first <= last; ++first)
    {
        storage += first;
    }
    return storage;
}

void sum_worker(std::uint64_t first, std::uint64_t last, Sum& result)
{
    result = sum_range(first, last);
}

Sum sum_threads(std::uint64_t n, unsigned thread_count)
{
    std::vector<Sum> partial(thread_count, 0);
    std::vector<std::thread> workers;
    workers.reserve(thread_count);

    const std::uint64_t base = n / thread_count;
    const std::uint64_t remainder = n % thread_count;
    std::uint64_t first = 1;

    for (unsigned i = 0; i < thread_count; ++i)
    {
        std::uint64_t count = base;
        if (i < remainder)
        {
            ++count;
        }
        if (count == 0)
        {
            continue;
        }

        std::uint64_t last = first + count - 1;
        workers.emplace_back(sum_worker, first, last, std::ref(partial[i]));
        first = last + 1;
    }

    for (std::thread& worker : workers)
    {
        worker.join();
    }

    Sum total = 0;
    for (Sum value : partial)
    {
        total += value;
    }
    return total;
}
