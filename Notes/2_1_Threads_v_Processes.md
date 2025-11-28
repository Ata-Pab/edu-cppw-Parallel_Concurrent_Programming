# Thread vs. Processes

## Processes
- A process is an instance of a program executing on a computer
- It consists of the program's code, data, and state information
- Each process has its own independent address space in memory
- Computers can manage hundreds of active processes simultaneously

## Threads
- Threads are smaller, subelements that exist within a process
- They represent independent paths of execution through a program
- Threads are the basic units managed by the operating system for execution
- Multiple threads within a process share the same address space and resources

## Comparison of Processes and Threads
- Processes are isolated from each other, each with its own address space
- Threads within the same process can easily share resources and communicate
- Interprocess communication is possible but requires special mechanisms
- Threads are generally considered "lightweight" compared to processes
- Creating and terminating threads typically requires less overhead than - processes
- Switching between threads of the same process is usually faster than switching between different processes

## Analogy: Cooking in the Kitchen
- A process is likened to a kitchen (address space) where cooking occurs
- Threads are represented by cooks working on different tasks within the same kitchen
- Different processes are compared to separate kitchens working on distinct meals

## Choosing between Threads and Processes
- The choice depends on the specific task and operating environment
- Threads are generally recommended when possible due to their lightweight nature
- Implementing threads and processes can vary across operating systems and programming languages

# Concurrency versus Parallelism in Computing

Concurrency refers to the ability of a program to be broken into independent parts that can be executed out of order without affecting the final result. It focuses on how a program is structured and composed of independently executing processes. Concurrent execution does not necessarily mean parallel execution.

## Concurrent Execution
- Concurrent processes overlap in time but may not execute simultaneously on a single processor
- Rapid task-switching can create an illusion of simultaneous execution, but it's not true parallelism

## Parallel Execution
- Parallel execution requires parallel hardware, such as multiple processors or cores
- Parallel execution allows multiple tasks to be performed simultaneously, potentially speeding up the overall process

## Forms of Parallel Hardware
- Multicore processors in desktop computers and mobile devices
- Graphics processing units (GPUs) with numerous specialized cores
- Computer clusters that distribute processing across multiple systems

## Key Distinctions
- Concurrency is about program structure and dealing with multiple things at once
- Parallelism involves simultaneous execution and doing multiple things at once
- Concurrency enables potential parallel execution but doesn't guarantee it
## Use Cases
- Concurrent programming is beneficial for I/O-dependent tasks like graphical user interfaces
- Parallel processing is particularly useful for computation-intensive tasks, such as matrix multiplication

## Practical Applications
- Device drivers for I/O devices (mouse, keyboard, and hard drive) execute concurrently but may not benefit significantly from parallelism
- Graphical user interfaces use concurrency to maintain responsiveness during time-consuming operations
- Large mathematical operations can be divided into subparts for efficient parallel processing

# Operating System Scheduling in Concurrent Computing
Computers manage multiple processes and threads competing for limited processor resources. The operating system's scheduler controls when different threads and processes execute on the CPU.

## The Role of the Scheduler

### Process management
- The scheduler enables multiple programs to run concurrently on a single processor
- New processes are loaded into memory and placed in the "ready queue" when created
- The scheduler cycles through ready processes, allocating CPU time for each process to execute

### Multiprocessor handling
- For systems with multiple processors, the OS schedules processes across all available processors to maximize resource utilization

### Process execution states
- Processes may run until completion, get blocked waiting for I/O events, or be swapped out after using their allocated timeshare

## Context Switch
- Save the state of a currently running process and load the state of another process
- Allows multiple processes to share CPU time
- Context switches are not instantaneous and incur overhead
- Schedulers must balance switch frequency with performance impact

## Scheduling Algorithms
- Different operating systems use different scheduling algorithms based on their specific purposes and system requirements
- Some scheduling algorithms aim to maximize throughput, while others focus on minimizing latency for improved responsiveness
- Preemptive scheduling: Can interrupt low-priority processes for high-priority ones
- Non-preemptive scheduling: Allows processes to run for their full allotted time once started

### Key Takeaways
- Scheduling details are typically handled by the OS "under the hood"
- Programmers should not assume a specific execution order or equal time allocation for threads or processes
- Programs should be written to function correctly regardless of scheduling decisions

---
