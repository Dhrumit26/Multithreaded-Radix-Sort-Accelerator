# Multithreaded Radix Sort Accelerator

## Overview

This project implements a multithreaded radix sort algorithm to sort a large dataset of integers. The radix sort is parallelized using threads to enhance performance. The project includes scripts for generating data, sorting it using both a system sort and the custom radix sort, and comparing the results.

## Files

- **`generate.cpp`**: Generates a file of random integers based on the specified parameters.
- **`mysort.cpp`**: Implements the multithreaded radix sort algorithm.
- **`sortrace.sh`**: Shell script to automate data generation, sorting, and result comparison.

## Requirements

- C++ compiler (e.g., g++)
- Make
- POSIX threads library (for `pthread`)

## Building and Running

### 1. Compile the Code

To compile the source files, use the following commands:

```bash
g++ -o generate generate.cpp
g++ -o mysort mysort.cpp -pthread
```

### 2. Generate Random Numbers

Run the `generate` executable to create a file with random integers:

```bash
./generate <count> <min_value> <max_value>
```

**Example:**

```bash
./generate 1000000 100000 999999
```

This command generates `1,000,000` random integers between `100,000` and `999,999` and saves them in `numbers.dat`.

### 3. Sort the Data

Run the `sortrace.sh` script to perform the following:

- Generate random numbers
- Perform a system sort
- Perform the custom radix sort
- Compare the outputs

```bash
chmod +x sortrace.sh
./sortrace.sh
```

### 4. Check Results

After running the script, you can find the results in the following files:

- `systemsorg.out`: Output of the system sort
- `mysort.out`: Output of the custom radix sort
- `sortrace.log`: Log file with timing and comparison results

## Algorithm Details

- **Radix Sort**: Uses a counting sort approach to sort integers based on individual digits. The algorithm processes each digit in multiple passes.
- **Multithreading**: The dataset is divided into chunks, each processed in parallel using threads. After sorting, the sorted chunks are merged to produce the final sorted array.

## Author

- Dhrumit Savaliya
# Multithreaded-Radix-Sort-Accelerator-
