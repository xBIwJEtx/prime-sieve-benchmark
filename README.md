# Prime Sieve

Implementations of the Sieve of Eratosthenes in C++,
optimized progressively from naive to parallel.

## Build
g++ -O3 -march=native -fopenmp -std=c++17 src/segmented_sieve.cpp -o sieve
echo "1000000000" | ./sieve

## Results
| Version         | Time   | Speedup |
|-----------------|--------|---------|
| Naive           | 8051ms | 1x      |
| Segmented       | 1294ms | 6.2x    |
| + OpenMP        | 127ms  | 63x     |

## What I learned
- Cache hierarchy: segmented sieve fits working set in L1
- OpenMP: parallel for, reduction, schedule(dynamic) vs static
- Profiling: I/O cost 4500ms — measure before optimizing
- Wheel factorization: skip even numbers in inner loop
