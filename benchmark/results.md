# Benchmark Results

## Environment
- CPU: AMD RYZEN 7 6800HS
- Cores: 8 core
- OS: Windows 11
- Compiler: g++ 14.2.0, flags: -O3 -march=native -fopenmp -std=c++17

## Results (n = 10^9)

| Version              | Time    | Speedup | Notes                    |
|----------------------|---------|---------|--------------------------|
| Naive sieve          | 8051ms  | 1x      | baseline                 |
| Segmented sieve      | 1294ms  | 6.2x    | cache locality           |
| + Wheel mod 2        | 1222ms  | 6.6x    | skip even numbers        |
| + OpenMP (N threads) | 127ms   | 63x     | parallel segments        |

## Observations
- cache locality alone gave 6-6.5 speedup
- OpenMP schedule(dyanmic) beat schedule(static) by 30-70ms
