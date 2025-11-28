# Data Races vs. Race Conditions

## Data races

- Data races occur when two or more threads concurrently access the **same memory location**, with at least one thread **writing** to or changing that memory value
- This can lead to threads **overwriting** each other or reading **incorrect values**
- Data races can be detected using automated tools and prevented by ensuring mutual exclusion for shared resources

## Race conditions
- Race conditions are flaws in the **timing** or order of a program's execution that cause **incorrect behavior**
- They are often more difficult to detect and prevent than data races

## Important distinctions
- Data races and race co6nditions are different problems that are often confused due to their similar names
- It's possible to have data races without race conditions and vice versa
- Many race conditions are caused by data races, and many data races lead to race conditions, but they are not dependent on each other

## Challenges in detecting race conditions
- Race conditions can be difficult to discover during testing, as they may only manifest under specific timing conditions
- They are often classified as "heisenbugs": bugs that seem to disappear or change behavior when studied

## Potential detection methods
- Inserting `sleep` statements at different points in the code can sometimes help uncover race conditions by altering thread execution order

- However, attempts to study race conditions may inadvertently prevent them from occurring, making them challenging to reproduce and debug

# Preventing Race Conditions with Barriers

## Barriers
- A barrier is a **synchronization mechanism** for thread coordination
- It serves as a **stopping point** for a group of threads, preventing them from proceeding until all (or a sufficient number of) threads have reached the barrier

Barron relates the concept of a barrier to a sports team huddle:
- Players finish individual activities before joining the huddle
- Team members wait in the huddle until everyone arrives
- Once all are present, they break the huddle and resume their activities

## Applying barriers to solve race conditions
Barron and Olivia demonstrate how barriers can be used to solve a race condition using their shopping list scenario:

- Olivia adds three bags of chips to the list before reaching the barrier
- Barron waits at the barrier until Olivia completes her task
- After both reach the barrier, they `break` (analogous to leaving the huddle)
- Barron then doubles the number of chips on the list

### There are two possible execution scenarios:

1. Olivia executes first, adds her chips, and then both meet at the barrier so Barron can continue to double the chips
2. Barron executes first but waits at the barrier for Olivia to complete her task before continuing to double the chips

In both cases, the final result is correct: eight bags of chips on the shopping list.

### Benefits of using barriers
Barriers ensure the correct order of operations regardless of thread scheduling:

- The order in which threads are scheduled to execute becomes less critical
- Synchronization is guaranteed by the barrier mechanism
- Consistent results are achieved even with varying execution orders

Barriers provide a reliable method for synchronizing threads in concurrent programming, ensuring correct execution order and preventing race conditions.

## Latch

Latches are similar to barriers but are typically used for one-time synchronization. Once the latch condition is met (e.g., a certain number of threads have reached it), it cannot be reused. Latches are often used to ensure that a set of threads complete their tasks before allowing another thread to proceed

- `latch` (value): Initialize count value 
- `wait(latch)`: Decrement count; if count > 0, block until count reaches 0
- `countdown(latch)`: Decrement count; if count == 0, unblock all

**Barriers** release all waiting threads each time they are reached, while **latches** release threads only once when the count reaches `zero`. Latches are generally initialized with a specific count value and are used to block threads until that count reaches zero. Barriers, on the other hand, are reusable synchronization points that allow threads to wait for each other multiple times during execution.

- Latch -> Initialize count to 1 : A simple ON/OFF gate
- Latch -> Initialize count to N : Wait N threads to complete some action

### References

- [Boost C++ Libraries - Barrier](https://www.boost.org/doc/libs/1_81_0/doc/html/thread/synchronization.html#thread.synchronization.barriers)
---
