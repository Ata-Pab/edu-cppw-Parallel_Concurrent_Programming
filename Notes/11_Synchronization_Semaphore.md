# Synchronization and Semaphores

## Limitations of Locks and Mutexes
- A lock or mutex restricts multiple threads from accessing a shared resource simultaneously; however, it doesn't provide a way for threads to signal each other or synchronize actions efficiently

## Condition Variables
- Condition variables serve as a `queue` for threads waiting for a specific condition to occur
- They work in conjunction with mutexes to implement a higher-level construct called a `monitor`

## Monitors
- Monitors protect critical sections of code with mutual exclusion and provide mechanisms for threads to wait and be `notified`
- Barron and Olivia describe the concept of monitors using a room analogy: the monitor is like a room containing protected procedures and shared data, the mutex acts as a lock on the door, and condition variables are like waiting rooms outside the monitor

## Condition Variable Operations
There are three main operations associated with condition variables:

- `Wait`: Releases the mutex lock and puts the thread to sleep in a queue
- `Signal` (or notify/wake): Wakes up a single thread from the waiting queue
- `Broadcast` (or notifyAll/wakeAll): Wakes up all threads in the waiting queue

## Practical Application
One common use case for condition variables is implementing a shared queue or buffer, which typically involves:

- A mutex to ensure exclusive access to the queue
- Two condition variables: one for `signaling` when the **buffer is not full** (for adding items) and another for `signaling` when the **buffer is not empty** (for removing items)

## Summary
- Condition variables enable efficient thread synchronization by allowing threads to wait for specific conditions and signal each other when those conditions are met
- This mechanism improves upon simple mutex-based solutions by reducing “busy-waiting” and enabling more sophisticated coordination between threads