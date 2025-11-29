# Designing Parallel Programs

## Partitioning: Breaking Down the Problem
- Partitioning involves dividing the problem into discrete chunks of work for distribution among multiple tasks
- At this stage of the design process, the focus is on maximum decomposition without considering practical limitations like processor count
- Different decomposition methods may have varying advantages depending on the problem and hardware
- Domain decomposition and functional decomposition offer valuable perspectives on problem-solving in parallel computing

## Domain (data) decomposition
- Focuses on dividing the data associated with the problem into small, ideally equal-sized partitions
- Computations are then associated with the partitioned data
- Example from the video: Decorating a tray of cupcakes can be divided into blocks or cyclically

## Functional decomposition
- Begins by considering all computational work required by the program
- Divides the overall work into separate tasks performing different portions
- Data requirements for these tasks are a secondary consideration
- Example from the video: Breaking down the process of making cupcakes into individual tasks

## Complementary approaches
- Domain and functional decomposition are complementary and often used in combination
- Developers typically start with domain decomposition as it forms the foundation for many parallel algorithms
- Exploring both approaches can reveal optimization opportunities and potential issues that might be missed by considering data alone

# Communication between Parallel Tasks
After decomposing a problem into separate tasks, the next step is to establish **communication** between tasks. Communication involves coordinating execution and **sharing data**.

## Types of Task Communication

### 1. Independent tasks
Some problems can be decomposed into tasks that don't require data sharing. Example from the video: Frosting cupcakes independently, with no need for communication between tasks
### 2. Interdependent tasks
Tasks that require information from other tasks to complete their work. Example from the video: Decorating cupcakes in a rainbow pattern, where each task needs to know the colors of neighboring cupcakes

## Communication Structures

### 1. Point-to-point communication
- Direct links between neighboring tasks
- Suitable when each task communicates with a small number of other tasks
- Involves sender (**producer**) and receiver (**consumer**) roles

### 2. Collective communication
- Used when tasks need to communicate with a larger group
- Includes broadcasting (one-to-many) and scattering/gathering (distributing and collecting data)

### 3. Centralized management
- One task acts as a central coordinator for a group of distributed workers
- Can become a bottleneck as the number of workers increases
- Divide-and-conquer strategies can help distribute computation and communication load

## Communication Factors to Consider

### 1. Synchronous vs. asynchronous communication
- Synchronous (**blocking**): Tasks wait for communication to complete before continuing
- Asynchronous (**non-blocking**): Tasks can perform other work while communication is in progress
### 2. Performance considerations
- **Processing overhead**: Time spent on communication versus data processing
- **Latency**: Time for a message to travel from sender to receiver
- **Bandwidth**: Amount of data that can be communicated per unit of time

## Context-Specific Considerations
- For multithreaded programs on a single system, factors like latency and bandwidth may be less critical
- In distributed systems across multiple physical machines, intersystem communication factors significantly impact overall performance

## Agglomeration
The agglomeration stage of the parallel design process follows the initial partitioning of a problem into separate tasks and establishing communication between them.

## Granularity

### Fine-grained parallelism
- Breaks a program into a large number of small tasks
- Advantages: Allows for better load balancing across processors
- Disadvantages: Increases overhead for communication and synchronization, resulting in a low computation-to-communication ratio

### Coarse-grained parallelism
- Splits the program into a small number of large tasks
- Advantages: Has lower communication overhead, allowing more time for computation
- Disadvantages: May produce load imbalance, with some tasks processing more data while others remain idle

### Medium-grained parallelism
- Balances the trade-offs between fine and coarse-grained approaches
- Often the most efficient solution for general purpose computers

## Demonstration
Barron and Olivia illustrate the concept of agglomeration by frosting cupcakes:

- 12 cupcakes were divided into 12 separate tasks
- This approach initially required 34 communication events between tasks
- Tasks were combined through agglomeration to match the number of available processors (two)
- The program was restructured into two tasks, each responsible for six cupcakes
- This reduced communication events between tasks from 34 to two; however, each communication now involves sharing more information

## Recommendations
- Avoid hard-coded limits on the number of tasks
- Use compile-time or runtime parameters to control granularity
- Design programs to adapt to changes in the number of available processors

# Mapping in Parallel Design
Mapping is the fourth and final stage of our parallel design process. It involves specifying where each established task will be executed.

## Applicability
- Mapping is not applicable for single-processor systems or systems with automated task scheduling
- It becomes relevant in distributed systems or specialized hardware with multiple parallel processors
## Goals and strategies
The main goal of mapping is to minimize total execution time. Two key strategies are:

- **Increasing concurrency**: Place tasks capable of executing concurrently on different processors.
- **Improving locality**: Place frequently communicating tasks on the same processor to keep them close together.

## Challenges and considerations
- These strategies often conflict, requiring design trade-offs
- Dynamic workloads may necessitate periodic remapping using dynamic load-balancing techniques
- Mapping algorithm design depends heavily on program structure and hardware specifications
- Various load-balancing algorithms utilize domain decomposition and agglomeration techniques