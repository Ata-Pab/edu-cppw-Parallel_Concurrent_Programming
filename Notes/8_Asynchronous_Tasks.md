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
