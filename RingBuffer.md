# Exercise 15: Circular Queue / Ring Buffer (LeetCode Style)

## Level
- Intermediate

## Overview
This exercise implements a fixed-size FIFO (First In First Out) circular queue, also known as a ring buffer.

The goal is to practice:
- Queue data structures
- Circular indexing
- Modulo arithmetic
- Memory management in C
- Embedded-system style buffering

## Problem Statement
Design and implement a circular queue with fixed capacity.

The queue should support:
- Enqueue
- Dequeue
- Peek front/rear
- Empty/full checks

All operations must run in O(1) time.

## API Specification
```c
typedef struct {
    int *data;
    int capacity;
    int head;
    int tail;
    int count;
} MyCircularQueue;
```

### Required Functions
```c
MyCircularQueue* myCircularQueueCreate(int k);
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);
bool myCircularQueueDeQueue(MyCircularQueue* obj);
int myCircularQueueFront(MyCircularQueue* obj);
int myCircularQueueRear(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);
void myCircularQueueFree(MyCircularQueue* obj);
```

## Return Rules
- `myCircularQueueEnQueue`
  - `true`: success
  - `false`: queue full
- `myCircularQueueDeQueue`
  - `true`: success
  - `false`: queue empty
- `myCircularQueueFront`
  - front value if not empty
  - `-1` if empty
- `myCircularQueueRear`
  - rear value if not empty
  - `-1` if empty

## Example
Input sequence:
1. create(3)
2. enQueue(1)
3. enQueue(2)
4. enQueue(3)
5. enQueue(4)
6. Rear()
7. isFull()
8. deQueue()
9. enQueue(4)
10. Rear()

Expected output:
```text
true
true
true
false

3

true

true

true

4
```

## Circular Buffer Visualization
Capacity = 3

Initial:
```text
[ _ | _ | _ ]
head = 0, tail = 0, count = 0
```

After enqueue(1):
```text
[ 1 | _ | _ ]
head = 0, tail = 1, count = 1
```

After enqueue(2):
```text
[ 1 | 2 | _ ]
head = 0, tail = 2, count = 2
```

After enqueue(3):
```text
[ 1 | 2 | 3 ]
head = 0, tail = 0, count = 3
```

After dequeue():
```text
[ _ | 2 | 3 ]
head = 1, tail = 0, count = 2
```

After enqueue(4):
```text
[ 4 | 2 | 3 ]
head = 1, tail = 1, count = 3
```

## Key Concept: Wrap Around
```c
tail = (tail + 1) % capacity;
head = (head + 1) % capacity;
```

This reuses array space without shifting elements.

## Constraints
- `1 <= k <= 1000`
- `0 <= value <= 1000`

## Complexity
- Enqueue: O(1)
- Dequeue: O(1)
- Front: O(1)
- Rear: O(1)
- Space: O(k)

## Real-World Use Cases
- UART RX/TX FIFOs
- Audio streaming
- Ethernet packet queues
- Camera frame pipelines
- AI accelerator descriptor queues
- Linux kernel logging
- DMA descriptor rings
- NVMe submission/completion queues

## Follow-Up (Harder)
Implement the queue WITHOUT using `count`.

Use effective capacity `k + 1` and these conditions:
```text
empty: head == tail
full:  (tail + 1) % capacity == head
```

## Suggested File Structure
```text
.
├── README.md
├── circular_queue.c
├── circular_queue.h
├── main.c
└── Makefile
```

## Build
```bash
make
```

## Run
```bash
./ringbuffer
```

## Validation
- Build with strict flags.
- Verify expected output sequence.
- Optionally run valgrind for leak checks.
