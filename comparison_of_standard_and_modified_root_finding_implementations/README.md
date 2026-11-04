# Advanced Root-Finding Optimization & Convergence Benchmark

A C++ optimization sandbox designed to pit standard Newton-Cotes root-finding implementations against higher-order variations—including **Interval Trisection**, **Householder’s 3rd-Order Method**, and **Inverse Quadratic Interpolation (Müller's Variant)**.

---

## Algorithms Profile Matrix

| Standard Method | Advanced Variant Implemented | Core Advantage | Mathematical Dependency |
| :--- | :--- | :--- | :--- |
| **Bisection** | `ModifiedBisection` (Trisection) | Scans 3 sub-panels simultaneously | $f(x)$ |
| **Newton-Raphson** | `ModifiedNewtonRaphson` (Householder) | 3rd-Order cubic convergence rate | $f(x), f'(x), f''(x)$ |
| **Secant** | `ModifiedSecant` (Müller's/IQI) | Parabolic curve fitting over 3 nodes | $f(x)$ |

---

## Features
* **Multi-Derivative Trigonometric Profiling**: Employs exact analytical algebraic evaluations for $f(x)$, $f'(x)$, and $f''(x)$ to avoid numerical differentiation errors.
* **Automated Stress Testing**: Features 300 automated comparison blocks leveraging `<random>` pseudo-random generation engines (`std::mt19937`).
* **Efficiency Analysis**: Streams iteration recursion loops directly to standard console displays for instant performance checks.

---

## Prerequisites
* A standard compiler matching **C++11** specifications or newer.
* Core headers: `<iostream>`, `<cmath>`, `<iomanip>`, and `<random>`.

---

## Compilation & Execution

Compile the source configuration file via your standard command line interface:
```bash
g++ -std=c++11 main.cpp -o optimization_benchmark
```

Run the binary package to execute the full benchmarking suite:
```bash
./optimization_benchmark
```

### Deciphering the Console Output Stream
The terminal outputs blocks separated by delimiter bars (`------` and `//////`). In each comparison sub-block, two numbers are printed sequentially:
1. The recursion steps required by the **Modified/Advanced** variation.
2. The recursion steps taken by the **Standard** algorithm baseline.
Lower numbers indicate faster convergence rates and superior structural efficiency.
