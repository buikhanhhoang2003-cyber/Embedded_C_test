# Challenge: Pointer Arithmetic String Analyzer

**Objective:**

Write a C program that analyzes and modifies a string using pointer arithmetic only.

---

## Input Example
```c
char text[] = "Hello C Pointer";
```

---

## Requirements
Use pointers to:
- Print every character one by one
- Count total characters, not including '\0'
- Print the 4th character
- Print the last character
- Replace all spaces ' ' with underscores '_'
- Reverse the string in place
- Print the final string

---

## Rules
Do NOT use:
- strlen()
- strcpy()
- strcat()
- strcmp()
- strtok()

Try NOT to use:
- text[i]

Use:
- char *p;
- *p;
- p++;
- p--;
- p + n;

---

## Expected Example
Before:
```
Hello C Pointer
```
After replacing spaces:
```
Hello_C_Pointer
```
After reversing:
```
retnioP_C_olleH
```

---

## Skeleton
```c
#include <stdio.h>

int main(void)
{
    char text[] = "Hello C Pointer";
    char *p = text;
    /*
        TODO 1: Print each character using pointer
        TODO 2: Count string length using pointer
        TODO 3: Print 4th character using pointer arithmetic
        TODO 4: Print last character using pointer arithmetic
        TODO 5: Replace spaces with '_'
        TODO 6: Reverse string in place using two pointers
        TODO 7: Print final string
    */
    return 0;
}
```

---

## Hint
For reverse:
```c
char *left = text;
char *right = text;
/* move right to last character */
while (left < right) {
    char temp = *left;
    *left = *right;
    *right = temp;
    left++;
    right--;
}
```
