# Harder Exercise: Modify a Pointer Inside a Function

> **Objective:**
>
> Practice using a double pointer to change where a pointer points, safely.

---

## Task

Write a C program that manages two integers:

```c
int a = 10;
int b = 99;
```

You must create a function:

```c
void switch_pointer(int **p, int *target);
```

The function should make the pointer in main() point to target.

---

## Requirements

In main():
- Create `int a = 10;`
- Create `int b = 99;`
- Create `int *ptr = &a;`
- Print the value pointed to by `ptr`
- Call `switch_pointer(&ptr, &b);`
- Print the value pointed to by `ptr` again
- Change `b` to 500
- Print `*ptr` again to prove `ptr` is really pointing to `b`

---

## Starter Code

```c
#include <stdio.h>

void switch_pointer(int **p, int *target);

int main() {
    int a = 10;
    int b = 99;

    int *ptr = &a;

    printf("Before switch: *ptr = %d\n", ________);

    switch_pointer(__________, __________);

    printf("After switch : *ptr = %d\n", ________);

    b = 500;

    printf("After b change: *ptr = %d\n", ________);

    return 0;
}

void switch_pointer(int **p, int *target) {
    // TODO:
    // Make the original pointer point to target
}
```

---

## Expected Output

```
Before switch: *ptr = 10
After switch : *ptr = 99
After b change: *ptr = 500
```

---

## Challenge Level 2

Add another function:

```c
void set_value_through_pointer(int **p, int new_value);
```

This function should change the value that the pointer points to.

Example:

```c
set_value_through_pointer(&ptr, 777);
```

After this call, `b` should become 777.

**Expected extra output:**

```
After set_value_through_pointer: b = 777
```

**Key Rule**

Use a double pointer when the function needs to change the original pointer itself:

```c
*p = target;
```
