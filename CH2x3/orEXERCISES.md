# Linux System Programming — Practice Exercises

## Ch. 2–3: Kernel/Library Overview & File I/O
- [ ] 1. Copy a file using raw `read()`/`write()` syscalls; benchmark against `fread()`/`fwrite()` at different buffer sizes.
- [ ] 2. Implement `cat` using only `open()`, `read()`, `write()`, `close()`.
- [ ] 3. Benchmark I/O performance across block sizes from 1 byte to 1MB.
- [ ] 4. Create a sparse file with `lseek()`; compare `du` vs `ls -l` output.
