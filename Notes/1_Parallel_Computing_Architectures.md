# Flynn’s Taxonomy

## Four Classes of Computer Architecture

Parallel computing requires parallel hardware with multiple processors. Flynn's taxonomy classifies one of four multi-processor architectures based on its instruction streams and data streams:

### 1. Single Instruction, Single Data (SISD)
- Sequential computer with a single processor unit
- Executes one series of instructions on one data element at a time

### 2. Single Instruction, Multiple Data (SIMD)
- Parallel computer with multiple processing units
- All processors execute the same instruction simultaneously on different data elements
- Well-suited for applications performing repetitive operations on large datasets (for example, image processing)
- Modern GPUs often use SIMD instructions

### 3. Multiple Instruction, Single Data (MISD)
- Each processing unit executes its own series of instructions on the same data stream
- Not a commonly used architecture due to limited practical applications

### 4. Multiple Instruction, Multiple Data (MIMD)
- Each processing unit can execute different instructions on different datasets
- Most commonly used architecture found in multicore PCs, networked clusters, and supercomputers
- MIMD Subdivisions

### Single Program, Multiple Data (SPMD)
- Multiple processing units execute copies of the same program simultaneously
- Processors can run asynchronously and execute different program parts based on conditional logic
- The most common style of parallel programming

### Multiple Program, Multiple Data (MPMD)
- Processors execute different, independent programs simultaneously on different data
- Often uses a "host" or "manager" node to distribute work to other nodes and then collect results
- Less common than SPMD but useful for certain applications

# Shared vs. Distributed Memory
Memory organization and access are crucial factors in parallel computing performance. Even with numerous processors, inefficient memory access can negate potential gains because computer memory typically operates slower than processors, creating potential bottlenecks.

Shared memory and distributed memory are the two main memory architectures that support different use cases for parallel computing.

## Shared Memory Architecture
All processors access a global memory address space, and changes made by one processor to that memory are visible to all others.

### Types of shared memory systems

#### 1. Uniform memory access (UMA)

- Processors have equal access speed to memory
- Symmetric multiprocessing (SMP) is a common UMA architecture
- Modern multicore processors use SMP architecture

#### 2. Non-uniform memory access (NUMA)

- Often created by connecting multiple SMP systems
- Processors have varying access speeds to different memory parts
- All processors can still access all memory

### Caches in shared memory systems
- Each core typically has its own fast, local cache
- Cache coherency becomes a challenge when updating shared memory
- Hardware handles cache coherency in multicore processors

### Advantages and disadvantages
- Easier for programming due to simple data sharing
- May not scale well due to increased bus traffic and synchronization needs

## Distributed Memory Architecture
Each processor has its own local memory and address space; no global address space exists, and processors are connected through a network.

### Key characteristics
- Changes in one processor's memory are not automatically reflected in others
- Programmers must explicitly define data communication between nodes

### Advantages and disadvantages
- Highly scalable: adding processors increases both processing power and memory
- Cost-effective using commodity hardware
- Communication between nodes can be challenging to program

---
