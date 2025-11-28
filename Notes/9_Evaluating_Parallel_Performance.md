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
