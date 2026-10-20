#include "algorithms.hpp"

Sum sum_single(std::uint64_t n)
{
    Sum storage = 0;
    sum_worker(1, n, storage);
    return storage;
}
