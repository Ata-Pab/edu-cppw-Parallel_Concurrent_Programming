# Asynchronous Tasks

## Computational Graphs

- Computational graphs model relationships between program steps
- Graphs visualize which steps can be executed in parallel to help coordinate parallel execution and identify dependencies

## Directed acyclic graphs (DAGs)
- Nodes represent tasks or units of work
- Directed edges indicate progression and dependencies between tasks

Barron illustrates the concept of a computational graph using a salad-making process, which involves chopping lettuce, chopping tomatoes, mixing the ingredients, and adding salad dressing. 
- Chopping lettuce and tomatoes can occur asynchronously
- "Spawn" node represents the start of parallel execution
- "Sync" node ensures both chopping tasks complete before mixing

## Key Terminology
- `Spawn`/`fork`: Initiates parallel execution paths
- `Sync`/`join`: Synchronizes completion of parallel tasks
- `Asynchronous`: Tasks that can occur in any order relative to each other
- `Critical path`: Longest sequence of dependent operations in the graph

## Analyzing Parallel Potential
- Work: Total execution time on a single processor (sum of all task times)
- Span: Shortest possible execution time with maximum parallelization (sum of critical path times)
- Ideal parallelism: Ratio of work to span, indicating maximum speed improvement

# Challenges with Creating Many Threads
Barron and Olivia introduce the concept of running asynchronous tasks in parallel using a cooking analogy where they each represent independent threads (or processes) chopping different vegetables representing parallel tasks.

- As more tasks (vegetables) are added, they can spawn a new thread for each one
- Creating a new thread for each task can lead to inefficiencies because thread creation incurs overhead in terms of processor time and memory usage

## Thread Pools
- Thread pools can be a more efficient alternative to creating individual threads for each task
- Thread pools maintain a small collection of worker threads that can be reused to execute multiple tasks
- Submitting tasks to a thread pool is analogous to adding items to a to-do list for worker threads

[C++ Boost Thread Pool Library](https://www.boost.org/doc/libs/latest/doc/html/boost_asio/reference/thread_pool.html)

## Benefits of thread pools
- Reusing threads from a pool overcomes the overhead of creating new threads for each task
- Thread pools are especially advantageous when the task execution time is less than thread creation time
- Using preexisting threads in a pool can make programs more responsive by eliminating the delay of thread creation

# Futures
- Asynchronous tasks allow multiple operations to be accomplished simultaneously
- Futures are a mechanism for handling the results of asynchronous operations
- It acts as a **placeholder** for a result that will be available at a later time
- A future is like an "I owe you" note for the result of an asynchronous task

Barron and Olivia demonstrate a future in action using an analogy in the kitchen:

- Barron asks Olivia to count vegetables in the pantry, representing an asynchronous task
- Olivia provides an "I owe you" note (future) before leaving to complete the task
- Barron continues with other work while holding onto the future
- Olivia eventually returns with the result (zero vegetables), fulfilling the promise
- The resolved future allows Barron to make a decision (to go to the store)

## Working with Futures
- Futures are `read-only` and may not have an immediate result
- A thread might need to wait for the future to be resolved
- `Resolving` or `Fulfilling` a future means writing the result value to it