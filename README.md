#### Implementation of the [MIT 6.1810 Operating System Engineering](https://pdos.csail.mit.edu/6.828/2025/schedule.html) labs on xv6 (RISC-V)

This repository contains my work on the xv6 (RISC-V) kernel labs, focusing on low-level systems programming, kernel architecture, and syscall internals.

## Overview

These labs explore how a real operating system works internally by modifying and extending the kernel itself.

The labs progressively extend the kernel with features such as:
- System call plumbing
- Process management
- Virtual memory
- Concurrency & locking
- File systems
- Scheduling
- Security-oriented syscall interposition (sandbox)

All work is implemented directly inside the kernel source.

---

#### Build & Run:
```bash
make qemu
```
