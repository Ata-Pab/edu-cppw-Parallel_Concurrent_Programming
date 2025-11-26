# Data Races in Concurrent Programming

A data race occurs when two or more threads concurrently access the same memory location AND at least one of those threads is writing to that location to modify its value.

## Anatomy of a data race
Even simple operations, like incrementing a numeric value, consist of multiple operations:

1. Reading: A thread reads the existing value from the shared resource
2. Modifying: The thread performs calculations or modifications based on the value
3. Writing: The thread writes the new value back to the shared resource

To demonstrate a data race Barron and Olivia represent two concurrent threads performing different tasks that modify a shared resource: their shopping list. Initially, the list has one clove of garlic. Barron wants to add two cloves, while Olivia wants to add five. Due to thread scheduling and timing issues, the final result is incorrectly three cloves instead of the expected eight.

## Challenge of data races
Data races can be difficult to debug because:

- They depend on the unpredictable timing of thread scheduling
- They may occur intermittently, making the problem inconsistent and hard to reproduce

## Key Takeaways
- Data races are a significant concern in concurrent programming
- They occur when multiple threads access and modify shared resources without proper synchronization
- Recognizing potential data races is crucial for developing reliable concurrent programs
- The unpredictable nature of thread scheduling contributes to the complexity of identifying and resolving data races

# Concurrent Access and Critical Sections
When multiple threads concurrently read and write to a shared resource, that can lead to incorrect behavior, such as a data race. This issue can be mitigated by identifying and protecting critical sections of code.

## Critical sections
- A critical section is a part of a program that accesses a shared resource (for example, a data structure in memory)
- The program may not function correctly if multiple threads access the critical section simultaneously
- Critical sections need protection to ensure only one thread or process can execute that code section at a time
- Barron and Olivia demonstrate a critical section with their shared shopping list, where incrementing a value is a three-step process: read, modify, and write back; those three steps form a critical section that needs to be executed by each thread as an uninterrupted action

## Mutex (mutual exclusion)
- A mutex, also known as a lock, is a mechanism to prevent simultaneous access to shared resources
- Only one thread can possess the mutex at a time, forcing threads to take turns accessing the shared resource
- The process involves acquiring the lock, executing the critical section, and then releasing the lock

## Atomic operations
- Acquiring a lock is an atomic operation, meaning it executes as a single, indivisible action
- Atomic operations appear instantaneous to the rest of the system and are uninterruptible

## Thread blocking
- Threads attempting to acquire a lock that's already held by another thread will block (wait) until it becomes available

## Best Practices
- It's crucial to keep the code protected by a mutex as short as possible to prevent threads from getting stuck waiting
- Operations that don't require the shared resource should be performed outside the critical section to improve efficiency

[See Examples](../example/CH03/)