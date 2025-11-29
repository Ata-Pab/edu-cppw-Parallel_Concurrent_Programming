#include <thread>
#include <chrono>
#include <iostream>
#include <mutex>

/*
 * main.cpp
 * This file is just for demonstration and test purposes.
 * Source code for the actual implementations are in /examples folder.
 *
 * Reference: https://www.linkedin.com/learning/complete-guide-to-parallel-and-concurrent-programming-with-c-plus-plus/
 */

void sequential_matrix_multiplication(long **matrix_A, size_t num_rows_a, size_t num_cols_a,
                                      long **matrix_B, size_t num_rows_b, size_t num_cols_b, long **matrix_result)
{
    for (size_t i = 0; i < num_rows_a; i++)
    {
        for (size_t j = 0; j < num_rows_b; j++)
        {
            matrix_result[i][j] = 0; // Initialize result cell

            for (size_t k = 0; k < num_rows_b; k++)
            {
                matrix_result[i][j] = matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }
}

void parallel_matrix_multiplication(long **matrix_A, size_t num_rows_a, size_t num_cols_a,
                                    long **matrix_B, size_t num_rows_b, size_t num_cols_b, long **matrix_result)
{
    size_t num_threads = std::thread::hardware_concurrency();
    size_t chunk_size = ceil((float)num_rows_a / num_threads);

    std::thread workers[num_threads];

    for (size_t t = 0; t < num_rows_a; t++)
    {
        size_t start_row_result = std::min(t * chunk_size, num_rows_a);
        size_t end_row_c = std::min((t + 1) * chunk_size, num_rows_a);

        workers[t] = std::thread(parallel_worker, matrix_A, num_rows_a, num_cols_a, matrix_B, num_rows_b, num_cols_b, matrix_result, start_row_result, end_row_c);
    }

    for (auto &w : workers)
    {
        w.join();
    }
}

void parallel_worker(long **matrix_A, size_t num_rows_a, size_t num_cols_a,
                     long **matrix_B, size_t num_rows_b, size_t num_cols_b, long **matrix_result, size_t start_row, size_t end_row)
{
    for (size_t i = start_row; i < end_row; i++)
    {
        for (size_t j = 0; j < num_rows_b; j++)
        {
            matrix_result[i][j] = 0; // Initialize result cell

            for (size_t k = 0; k < num_rows_b; k++)
            {
                matrix_result[i][j] = matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }
}

int main()
{
    const int NUM_EVAL_RUNS = 3;
    const size_t NUM_ROWS_A = 1000;
    const size_t NUM_COLS_A = 1000;
    const size_t NUM_ROWS_B = NUM_COLS_A;
    const size_t NUM_COLS_B = 1000;

    // intialize A and B with values in range 1 to 100
    long **A = (long **)malloc(NUM_ROWS_A * sizeof(long));
    long **B = (long **)malloc(NUM_ROWS_B * sizeof(long));
    if ((A == NULL) || (A == NULL))
    {
        exit(2);
    }
    for (size_t i = 0; i < NUM_ROWS_A; i++)
    {
        A[i] = (long *)malloc(NUM_COLS_A * sizeof(long));
        B[i] = (long *)malloc(NUM_COLS_B * sizeof(long));
        if ((A[i] == NULL) || (A[i] == NULL))
        {
            exit(2);
        }
        for (size_t j = 0; j < NUM_COLS_A; j++)
        {
            A[i][j] = rand() % 100 + 1;
            B[i][j] = rand() % 100 + 1;
        }
    }

    // allocate arrays for sequential and parallel results
    long **sequential_result = (long **)malloc(NUM_ROWS_A * sizeof(long));
    long **parallel_result = (long **)malloc(NUM_ROWS_A * sizeof(long));
    if ((sequential_result == NULL) || (parallel_result == NULL))
    {
        exit(2);
    }
    for (size_t i = 0; i < NUM_ROWS_A; i++)
    {
        sequential_result[i] = (long *)malloc(NUM_COLS_B * sizeof(long));
        parallel_result[i] = (long *)malloc(NUM_COLS_B * sizeof(long));
        if ((sequential_result[i] == NULL) || (parallel_result[i] == NULL))
        {
            exit(2);
        }
    }

    printf("Evaluating Sequential Implementation...\n");
    std::chrono::duration<double> sequential_time(0);
    sequential_matrix_multiplication(A, NUM_COLS_A, NUM_ROWS_A, B, NUM_COLS_B, NUM_ROWS_B, sequential_result); // "warm up"
    for (int i = 0; i < NUM_EVAL_RUNS; i++)
    {
        auto startTime = std::chrono::high_resolution_clock::now();
        sequential_matrix_multiplication(A, NUM_COLS_A, NUM_ROWS_A, B, NUM_COLS_B, NUM_ROWS_B, sequential_result);
        sequential_time += std::chrono::high_resolution_clock::now() - startTime;
    }
    sequential_time /= NUM_EVAL_RUNS;

    printf("Evaluating Parallel Implementation...\n");
    std::chrono::duration<double> parallel_time(0);
    parallel_matrix_multiplication(A, NUM_COLS_A, NUM_ROWS_A, B, NUM_COLS_B, NUM_ROWS_B, parallel_result); // "warm up"
    for (int i = 0; i < NUM_EVAL_RUNS; i++)
    {
        auto startTime = std::chrono::high_resolution_clock::now();
        parallel_matrix_multiplication(A, NUM_COLS_A, NUM_ROWS_A, B, NUM_COLS_B, NUM_ROWS_B, parallel_result);
        parallel_time += std::chrono::high_resolution_clock::now() - startTime;
    }
    parallel_time /= NUM_EVAL_RUNS;

    // verify sequential and parallel results
    for (size_t i = 0; i < NUM_ROWS_A; i++)
    {
        for (size_t j = 0; j < NUM_COLS_B; j++)
        {
            if (sequential_result[i][j] != parallel_result[i][j])
            {
                printf("ERROR: Result mismatch at row %ld, col %ld!\n", i, j);
            }
        }
    }
    printf("Average Sequential Time: %.2f ms\n", sequential_time.count() * 1000);
    printf("  Average Parallel Time: %.2f ms\n", parallel_time.count() * 1000);
    printf("Speedup: %.2f\n", sequential_time / parallel_time);
    printf("Efficiency %.2f%%\n", 100 * (sequential_time / parallel_time) / std::thread::hardware_concurrency());
}