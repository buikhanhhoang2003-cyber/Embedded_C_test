# String Pointer Exercises

## Exercise 1 — Reverse a String Using Pointers

**Objective:**

Reverse a string in place using only pointers.

### Requirements
- Do NOT use array indexing ([])
- Use `char *`
- Modify the original string
- Use pointer arithmetic only

#### Example
Input: `hello`
Output: `olleh`

#### Function Prototype
```c
void reverse_string(char *str);
```

#### Hint
- Use one pointer at the beginning
- Use one pointer at the end
- Swap characters until they meet

---

## Exercise 2 — Count Words Using Pointers

**Objective:**

Count how many words exist in a string using only pointers.

### Requirements
- A word is separated by space `' '`, tab `'\t'`, or newline `'\n'`
- Use pointers only (no array indexing)
- Handle multiple spaces, leading/trailing spaces

#### Example
Input: `"Hello world from C"`
Output: `4`

#### Function Prototype
```c
int count_words(const char *str);
```

#### Extra Challenge
- Count sentences too (., !, ?)
- Example: `"   Hello   world   "` should return `2`
