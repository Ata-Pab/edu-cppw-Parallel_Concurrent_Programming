# Liveness and Deadlock

## The Dining Philosophers Problem
Barron and Olivia illustrate synchronization issues in concurrent programming using the Dining Philosophers problem:

- Two philosophers (representing threads) alternate between thinking and eating sushi from a shared plate
- Chopsticks are used as mutexes to protect the critical section (taking sushi from the plate)
- Each philosopher attempts to acquire two locks (chopsticks) before entering the critical section
- A deadlock occurs when both philosophers acquire one chopstick each and wait indefinitely for the other
- This scenario demonstrates how competing for multiple locks can lead to a lack of progress in concurrent programs

## Deadlock and Liveness
- Deadlock is a situation where each member of a group is waiting for another member to take action, resulting in no progress
- Liveness is the property of a program that ensures concurrent programs make progress, even if threads must take turns in critical sections

## Real-World Application
- One example of a real-world scenario with the potential for deadlock is a banking application, where transferring funds between accounts requires acquiring locks for both the sender and receiver accounts
- Multiple threads making concurrent transfers could potentially lead to deadlock situations
## Solution to Deadlock
Barron and Olivia demonstrate one possible solution to prevent deadlock with the Dining Philosophers problem:

- The philosophers implement a lock prioritization strategy to avoid deadlock
- By agreeing to acquire the same chopstick first, they prevent the circular wait condition that causes deadlock
- This solution ensures that one philosopher can always complete the critical section, allowing the other to proceed afterward






## Abandoned Lock: A New Form of Deadlock
An abandoned lock occurs when a thread acquires a lock on a shared resource and exits before releasing its lock on that resource, leaving other threads trying to acquire the lock to wait indefinitely. When a thread or process acquires a lock and then terminates unexpectedly, it may not release the lock automatically.
- Barron and Olivia demonstrate an abandoned lock as two dining philosophers sharing a chopstick when one philosopher (Barron) abruptly leaves with one chopstick, resulting in a deadlock scenario; other tasks (represented by Olivia) become stuck, waiting indefinitely for a lock that will never be released
- Deadlocks can occur not only through resource competition but also through unexpected thread termination

## Starvation
Starvation occurs when a process or thread is perpetually denied access to the resources it needs, preventing it from progressing. 
- Ideally, threads will take turns accessing shared resources, but this is not guaranteed due to how operating systems schedule thread execution
- A "greedy" thread frequently holding a lock on a shared resource can lead to other threads being starved out of being able to make progress
- In simple scenarios with a few equally prioritized threads, starvation is less likely to be a concern; however, thread priorities can significantly impact the likelihood of starvation: higher-priority threads are generally scheduled to execute more often, and lower-priority threads may struggle to gain access to resources

### Implications
Starvation can significantly impact system performance and fairness in resource allocation
- Designers of concurrent systems need to consider thread priorities and the number of concurrent threads to prevent starvation
- While occasional delays in resource access may be tolerable, persistent starvation can severely hamper the functionality of affected threads

## Livelock
Livelock is a situation in concurrent computing where two or more threads block each other from making progress
- Barron and Olivia illustrate a livelock scenario as two overly polite threads that continue to offer the last piece of sushi to the other thread out of politeness, creating a situation where neither can progress 
- Unlike deadlock, threads in livelock are actively trying to resolve the problem but fail to make progress

### Characteristics of Livelock
- Threads respond to each other's actions, creating a cycle of mutual interference
- All threads are busy, but their combined efforts prevent any actual accomplishment
- The program never reaches its end state or terminates

### Causes and Prevention
- Livelocks often result from algorithms designed to detect and recover from deadlocks
- They occur when multiple processes simultaneously attempt to resolve a deadlock
- To prevent livelock, ensure only one process takes action to resolve conflicts
- Use mechanisms like priority systems or random selection to choose which process acts
