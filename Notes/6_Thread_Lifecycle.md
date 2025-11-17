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

