# Double Pointer Challenges

## Exercise 1 — Swap Two Pointers

**Objective:**

Learn to modify multiple pointers using double pointers.

### Task

Create two integers:
```c
int a = 10;
int b = 20;
```

Create two pointers:
```c
int *p1 = &a;
int *p2 = &b;
```

Write a function:
```c
void swap_pointers(int **x, int **y);
```

After swapping:
- *p1 = 20
- *p2 = 10

#### Starter Code
```c
#include <stdio.h>

void swap_pointers(int **x, int **y);

int main() {
    int a = 10;
    int b = 20;
    int *p1 = &a;
    int *p2 = &b;
    printf("Before swap:\n");
    printf("*p1 = %d\n", *p1);
    printf("*p2 = %d\n", *p2);
    swap_pointers(__________, __________);
    printf("After swap:\n");
    printf("*p1 = %d\n", *p1);
    printf("*p2 = %d\n", *p2);
    return 0;
}
```

---

## Exercise 2 — Dynamic Memory Allocation

**Objective:**

Use double pointers with malloc().

### Task

Write:
```c
void allocate_number(int **p, int value);
```

#### Requirements:
- Allocate memory using malloc
- Store value
- Return the allocated pointer through double pointer

#### Expected Output
```
Allocated value = 500
```

### Concepts
- malloc
- Heap memory
- Double pointer for returning allocated memory
