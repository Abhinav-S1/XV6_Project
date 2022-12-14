# Implementing Lazy Allocation for XV6 Kernal

xv6 is a re-implementation of Dennis Ritchie's and Ken Thompson's Unix Version 6 (v6).  xv6 loosely follows the structure and style of v6, but is implemented for a modern x86-based multiprocessor using ANSI C.

In XV6 a page table is logically an array of 2^20 (1,048,576) page table entries (PTEs). Each PTE contains a 20-bit physical page number (PPN) and some flags. Page table is stored in physical memory as a two-level tree. The root of the tree is 4096-byte page directory that contains 1024 PTE-like references to page table pages. Each page table page is an array of 1024 32-bit PTEs. The paging hardware uses the top 10 bits of a virtual address to select a page directory entry. If the page directory entry is present, the paging hardware uses the next 10 bits of the virtual address to select a PTE from the page table page that the page directory entry refers to. The remaining bits contain flags such as PTE_W, PTE_U and PTE_P. sbrk() is the system call for a process to shrink or grow its memory. The system call is implemented by the function growproc(). XV6 natively doesn’t support demand pagingand lazily allocated pages. Modern Operating systems have much efficient allocation techniques which use a combination of segmentation and paging methods along with other optimisation algorithms.

This project implements the following for the native xv6 kernal :
1) Lazy allocation along with fault handling procedures.
2) a system call to print saved state of any process.
3) a system call to print number of physical and virtual pages allocated to a process.
4) a system call to count number of page faults.

"**ps**" system call can be used to display the process states."**displayinfo pid**" system call is used to display the numberof physical and virtual pages allocated to a process with processid as pid."**totalpagefault**" system call is used to display the total number of page faults that have occured till that instance.

A test program "**dprog.c**" is created to test these system calls. This program creates a child process which  initialises 25 pages worth of memory using the malloc() function. Only virtual pages are created for this memory but not physical pages. Each time a page is accessed, a page fault is created, and the kernel resolves it by allocating a physical page associated with that virtual page.
