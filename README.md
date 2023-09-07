# Philosophers
## Introduction
The "Philosophers" project is a practical exercise in C programming that explores the concepts of multithreading and mutexes. 
It involves simulating a scenario with philosophers seated around a dining table, making decisions about eating, thinking, and sleeping.

In this project, we will create a program that simulates philosophers' interactions and ensures they follow specific rules to 
prevent starvation and conflicts while sharing forks.

## Overview
The project's core elements are as follows:
- Philosophers at a Round Table: We'll simulate philosophers sitting at a round table, each having a specific number.
- Actions: Philosophers will alternate between eating, thinking, and sleeping. Each of these actions comes with its own time duration.
- Forks: There will be as many forks as there are philosophers. Philosophers need forks to eat. To eat, a philosopher must hold both the fork on their left and the one on their right.
- Starvation: The simulation stops when a philosopher dies of starvation. Our program must ensure that all philosophers get a fair chance to eat to avoid this situation.

## Understanding Threads
In this project, we'll leverage threads as a means to represent the philosophers. Threads are like independent workers in our program, 
capable of executing tasks concurrently.
- Threads for Philosophers: Each philosopher will be implemented as a separate thread.
- Concurrent Execution: Threads enable our program to perform multiple tasks simultaneously, just like the philosophers at the dining table.

## Understanding Mutexes
To maintain order and avoid conflicts when philosophers access shared resources (forks), we'll use mutexes (short for mutual exclusion).
- Mutex as Reservation Signs: Mutexes serve as "reservation signs" for resources, ensuring exclusive access.
- Resource Protection: Only one philosopher can hold a fork (lock) at a time. If a philosopher wants to use a fork, they must check if it's available; if not, they wait.
- Safety Assurance: Mutexes play a crucial role in preventing data races and guaranteeing the safe use of shared resources.

## Data Races
Data races can be problematic when multiple threads access shared data without proper synchronization. In our project:
- Data Races Implications: Data races could lead to issues such as multiple philosophers trying to grab the same fork simultaneously.
- Synchronization with Mutexes: We will employ mutexes to ensure proper synchronization, preventing data races and maintaining the integrity of shared resources.

## Conclusion
This project provides a hands-on opportunity to implement multithreading and mutex concepts in C, allowing us to create a simulation that adheres to the rules of philosophers at a dining table. By understanding threads, mutexes, and the importance of preventing data races, we aim to create a program that ensures the safety and fairness of our simulated philosophers.
