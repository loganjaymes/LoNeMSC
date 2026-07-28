# Linux System Programming — Practice Exercises

## Ch. 2–3: Kernel/Library Overview & File I/O
- [ ] 1. Copy a file using raw `read()`/`write()` syscalls; benchmark against `fread()`/`fwrite()` at different buffer sizes.
- [ ] 2. Implement `cat` using only `open()`, `read()`, `write()`, `close()`.
- [ ] 3. Benchmark I/O performance across block sizes from 1 byte to 1MB.
- [ ] 4. Create a sparse file with `lseek()`; compare `du` vs `ls -l` output.

## Ch. 4: Advanced File I/O
- [ ] 5. Use `mmap()` to modify a file in place; compare speed to read/write.
- [ ] 6. Implement file locking with `fcntl()` between two cooperating processes.
- [ ] 7. Use `readv()`/`writev()` to write a struct with mixed fields in one syscall.
- [ ] 8. Experiment with `O_DIRECT` and explain why alignment matters.

## Ch. 5: Process Management
- [ ] 9. Fork a child, exec a different program, and wait for its exit status.
- [ ] 10. Build a minimal shell that forks/execs commands and supports pipelines (`|`).
- [ ] 11. Demonstrate zombie and orphan processes; fix the zombie with `wait()`/`waitpid()`.
- [ ] 12. Use `vfork()` and explain its pitfalls versus `fork()`.

## Ch. 6: Advanced Process Management
- [ ] 13. Set/get process priorities with `nice()`/`setpriority()`; observe scheduling under load.
- [ ] 14. Explore `sched_setscheduler()` with `SCHED_FIFO` for a real-time task.
- [ ] 15. Use `prctl()` to set a process name and inspect it via `/proc`.

## Ch. 7: Threading (Pthreads)
- [ ] 16. Write a multithreaded shared counter; show the race condition, then fix with a mutex.
- [ ] 17. Implement a producer-consumer queue using condition variables.
- [ ] 18. Compare thread creation overhead vs. process (`fork`) creation overhead.
- [ ] 19. Use `pthread_once()` to implement lazy singleton initialization.

## Ch. 8: File and Directory Management
- [ ] 20. Write a recursive directory walker with `opendir()`/`readdir()` (mini `find`).
- [ ] 21. Implement `mv` handling cross-filesystem moves (fallback to copy+unlink).
- [ ] 22. Use `stat()`/`lstat()` to print permissions like `ls -l`, distinguishing symlinks.
- [ ] 23. Create a hard link and a symlink; show the difference when the original is deleted.

## Ch. 9: Memory Management
- [ ] 24. Write a simple `malloc`/`free` using `sbrk()` or `mmap()`.
- [ ] 25. Demonstrate a memory leak, then find it with Valgrind.
- [ ] 26. Use `mlock()` to lock a page in memory; explain when this matters (e.g., crypto keys).
- [ ] 27. Trigger and handle `SIGSEGV` from a null pointer dereference with a signal handler.

## Ch. 10: Signals
- [ ] 28. Install a `SIGINT` handler to clean up before exit instead of terminating abruptly.
- [ ] 29. Use `sigprocmask()` to block a signal during a critical section, then unblock it.
- [ ] 30. Implement a self-pipe trick to safely handle signals in an event loop.
