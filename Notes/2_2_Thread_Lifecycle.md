# Thread Lifecycle and States
- A new process begins with a single "main thread" that can spawn additional child threads
- Child threads execute independently within the same process and can spawn their own children
- Threads notify their parent upon completion, with the main thread usually finishing last

## Thread States
Threads transition through four main states during their lifecycle:

### NEW
- The NEW thread has been created but is not yet running
- It doesn't consume CPU resources at this stage
- The thread is assigned a function to execute
### RUNNABLE
- The operating system can schedule the RUNNABLE thread to execute on a processor
- It may be swapped with other threads through context switches
### BLOCKED
- The thread enters the BLOCKED state when waiting for an event or resource
- It doesn't use CPU resources while blocked
- The thread returns to the RUNNABLE state when the required condition is met
### TERMINATED
- The thread enters the TERMINATED state upon completing execution or being abnormally aborted
- It notifies its parent thread before termination
### Key Concepts
- Threads can create child threads to perform parallel tasks
- The join() method allows a parent thread to wait for a child thread to complete
- Different programming languages may use varying terminology for thread states
- Efficient thread management is crucial for concurrent and parallel computing

# Background Tasks
Threads are often created to provide services or perform periodic tasks in support of the main program. A common example of such a service is garbage collection, which runs in the background to manage memory automatically.

## Garbage Collection
- Garbage collection is an automatic memory management technique that reclaims memory that is no longer in use by the program
- Many programming languages include garbage collection as part of their runtime environment

## Independent Execution of Threads
- The garbage collection thread executes independently of the main thread
- This allows the main program to continue its tasks while garbage collection occurs concurrently

## Normal Child Threads
- When spawned as a normal child thread, the garbage collection thread prevents the main program from exiting
- This is because the main thread must wait for all of its non-daemon child threads to terminate before it can exit
- Continuous background tasks like garbage collection may run indefinitely, causing the program to never terminate

## Daemon Threads
- A daemon thread is a background thread that does not prevent the program from exiting when it's still running
- By default, new threads are spawned as non-daemon (normal) threads and must be explicitly set as daemon threads

## Benefits of Daemon Threads
- Daemon threads allow the main program to exit even if the daemon threads are still running
- When the main thread finishes and no non-daemon threads are left, the process can terminate

## Cautions When Daemon Threads Terminate
- Daemon threads are abruptly terminated when the process exits, so they do not have the opportunity to gracefully shut down
- Abrupt termination is generally safe for tasks like garbage collection; however, for I/O operations (for example, writing to a file), abrupt termination may lead to data corruption
- When detaching a thread to run as a daemon background task, consider the potential negative side effects of it being abruptly terminated

---
