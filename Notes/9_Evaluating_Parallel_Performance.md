# Evaluating Parallel Performance

## Weak Scaling vs. Strong Scaling

### Weak scaling: Increase the problem size

- Weak scaling allows us to tackle larger problems in the same amount of time by adding more processors while keeping the workload per processor constant
- For example, one person can decorate 10 cupcakes in an hour, while two people working in parallel can decorate 20 cupcakes in the same time

### Strong scaling: Accomplish tasks faster

- Strong scaling involves breaking down a fixed-size problem across multiple processors to execute it faster
- For example, decorating 10 cupcakes takes one person an hour, but two people working together can complete the task in about 30 minutes

## Key Metrics in Parallel Computing

### Throughput

- Throughput measures the **number of tasks** completed in a given time period
- Adding more processors increases overall throughput, for example, from 10 cupcakes/hour with one worker to 30 cupcakes/hour with three workers

### Latency

- Latency is the time taken to execute a single task from start to finish
- It remains constant per task even when multiple processors are used (for example, six minutes to decorate one cupcake)

### Speedup

- Speedup is calculated as the ratio of sequential execution time to parallel execution time
- For example, if one worker takes 60 minutes and two workers take 30 minutes, the speedup is 2

## Limitations of Parallelization

- Real-world programs often have both parallelizable and sequential components
- Sequential parts of a program (for example, packing cupcakes into a shared container) limit the maximum achievable speedup, which leads to diminishing returns as more processors are added

# Amdahl's Law

Amdahl's Law is an equation used to estimate the potential speedup of a parallel program

- It helps determine the effectiveness of parallelizing a program based on its parallelizable portion

## The Equation

Equation for Amdhel's Law.

<img src="./assets/images/Amdahls_Law.png" alt="Amdahl's Law Equation" width="300"/>

Where:

- `P` represents the portion of the program that can be parallelized
- `S` represents the speedup for the parallelized part running on multiple processors

Barron uses a program with 95% parallelizable code as an example:

- With two processors, the overall speedup is about 1.9
- Increasing to three processors yields a speedup of 2.7, and four processors result in 3.5
- However, even with 1000 processors, the maximum speedup is only around 19.6
- Increasing to a million processors barely improves the speedup to just under 20
- The non-parallelizable 5% of the program creates an upper limit on achievable speedup

## Limitations on the Effectiveness of Parallelization

- The degree of parallelization significantly impacts potential speedup
- Programs with 90% parallelizable code have a maximum speedup of 10
- 75% parallelizable programs are limited to a speedup of 4
- 50% parallelizable programs can achieve a maximum speedup of only 2

## Decision-Making in Parallel Programming

- Amdahl's Law helps determine whether parallelizing a program is worthwhile
- It illustrates why parallel computing is most beneficial for highly parallelizable programs
- The costs and overhead of parallelization should be weighed against potential benefits
- Parallelizing everything is not always the best approach, despite the availability of multicore processors

# Measuring Speedup and Efficiency
Amdahl's Law estimates potential speedup from parallelization. Empirical measurement provides actual performance data

## Calculating Speedup

`Speedup = Time for sequential execution / Time for parallel execution`

- Speedup measures the benefit of parallel problem-solving
- Any speedup greater than 1 indicates improvement from parallelization
- Speedup less than 1 suggests that a sequential algorithm is preferable

Barron and Olivia demonstrate this by measuring how long it takes them to add up shopping receipts

- Sequential task: Adding receipts alone took 25 seconds
- Parallel task: Adding receipts together took 17 seconds
- Calculated speedup: 25/17 = 1.47 (almost 1.5 times faster)

## Calculating Efficiency
`Efficiency = Speedup / Number of processors`

- Efficiency describes how well processors are utilized
- For example, with two processors: if the speedup is 1.47, then the efficiency is 73.5%
- With 8 processors: if the speedup is 2.2, then the efficiency is 27.5%

## Benchmarking Best Practices
- Limit other running programs to avoid resource competition
- Average multiple independent runs to account for execution variability
- Allow for "warm-up" in environments with just-in-time compilation
- Run the algorithm once before measurement to ensure a consistent cache state
