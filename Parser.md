# Hardest Challenge — Mini String Parser Using Pointers

**Objective:**

Write a C program that parses a command string into arguments, like a tiny shell parser, using only char pointers and pointer arithmetic.

---

## Input Example
```c
char input[] = "run -f \"hello world.txt\" --count 10";
```

## Expected Output
```
argc = 5
argv[0] = run
argv[1] = -f
argv[2] = hello world.txt
argv[3] = --count
argv[4] = 10
```

---

## Requirements
- Implement:
  ```c
  int parse_args(char *input, char **argv, int max_args);
  ```
- Split words by spaces
- Keep quoted strings together
- Remove the quote characters `"`
- Modify the original string in place
- Do NOT use `strtok`
- Do NOT use array indexing like `input[i]`
- Use pointers only
- Return number of arguments found

---

## Skeleton
```c
#include <stdio.h>

int parse_args(char *input, char **argv, int max_args)
{
    // TODO
}

int main(void)
{
    char input[] = "run -f \"hello world.txt\" --count 10";
    char *argv[10];

    int argc = parse_args(input, argv, 10);

    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    return 0;
}
```

---

## Extra Hard Rules
- Also handle:
  ```c
  char input[] = "copy \"my file.txt\" \"backup folder\"";
  // Expected:
  // argc = 3
  // argv[0] = copy
  // argv[1] = my file.txt
  // argv[2] = backup folder
  ```
- And:
  ```c
  char input[] = "  build   --target   \"arm cortex\"   ";
  // Expected:
  // argc = 3
  // argv[0] = build
  // argv[1] = --target
  // argv[2] = arm cortex
  ```
- Bonus: detect error if a quote is not closed.
