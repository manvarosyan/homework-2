# Homework 2

This repository contains solutions to the assignments on **fork** and **exec** system calls.  

---
[GitHub Repository: manvarosyan/homework-2](https://github.com/manvarosyan/homework-2)

---

### Assignment 0: Multiple Fork Calls
**Source Code:** [`Assignment 0`](multi_fork_seq.c)

**Analysis:**
- Three sequential `fork()` calls create `2^3 = 8` processes.
- Each `fork()` duplicates the current process.  
  - **Return values:**  
    - `0` → child process.  
    - `>0` → parent process (child’s PID).  
    - `<0` → error.  
- Hierarchy: each process becomes a parent to its child.  
- The `printf` output shows `PID` and `PPID`, demonstrating relationships.

---

### Assignment 1: Simple Fork and Exec
**Source Code:** [`Assignment 1`](simple_fork_exec.c)

**Analysis:**
- Parent calls `fork()`.  
- Child executes `/bin/ls` using `execl()`.  
- Parent waits for the child (`wait(NULL)`) and prints `"Parent process done"`.  
- Flow:  
  1. `fork()` → 2 processes.  
  2. Child: `execl("ls")`.  
  3. Parent: waits → prints message.

---

### Assignment 2: Multiple Forks and Execs
**Source Code:** [`Assignment 2`](multiple_forks_execs.c)

**Analysis:**
- First `fork()` creates child → runs `ls`.  
- Second `fork()` creates another child → runs `date`.  
- Parent calls `waitpid()` for both children, then prints `"Parent process done"`.  
- Hierarchy:  
  - Parent has two children.  
  - Each child is independent.  
- Execution order: usually `ls` first, then `date`, but exact order can vary depending on scheduling.

---

### Assignment 3: Fork and Exec with Arguments
**Source Code:** [`Assignment 3`](fork_exec_with_argumanets.c)

**Analysis:**
- `fork()` → 2 processes.  
- Child executes `/bin/echo` with argument `"Hello from the child process"`.  
- Parent waits and prints `"Parent process done"`.  
- Demonstrates passing **command-line arguments** to `execl`.

---

### Assignment 4: Fork and Exec with Command-Line Arguments
**Source Code:** [`Assignment 4`](fork_exec_command_line.c)  
**Test File:** [`test.txt`](test.txt)

**Analysis:**
- `fork()` creates a child.  
- Child executes `/usr/bin/grep "main" test.txt`.  
- Parent waits, then prints `"Parent process completed"`.  
- Flow:  
  1. Parent forks.  
  2. Child runs `grep`.  
  3. Parent waits → prints message.  
- Shows how multiple arguments are passed to `execl` (`grep`, search term, file name).

---

