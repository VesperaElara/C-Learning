/*
================================================================================
                    C PROGRAMMING NOTES: POINTER COMPARISON
================================================================================

1. CORE CONCEPT: RELATIONAL AND EQUALITY OPERATORS WITH POINTERS
--------------------------------------------------------------------------------
Pointers store memory addresses. You can use relational operators (<, >, <=, >=) 
and equality operators (==, !=) to compare these addresses.

* Rule of Thumb: Pointer comparison is only meaningful and valid when both 
  pointers point to elements within the SAME array.
* Behavior: The comparison outcome depends strictly on the relative positions 
  (indices) of the elements in memory. An element with a higher index has a 
  higher memory address.

--------------------------------------------------------------------------------
2. PRACTICAL EXAMPLE
--------------------------------------------------------------------------------
Consider the following array and pointers:
int a[] = {1, 2, 3, 4, 5, 6};
int *p = &a[3]; // p points to the 4th element (value 4)
int *q = &a[5]; // q points to the 6th element (value 6)

* Expression: p <= q
  - Analysis: Since index 3 is less than or equal to index 5, the address in p 
    is less than or equal to the address in q.
  - Output: 1 (True)

* Expression: p >= q
  - Analysis: Index 3 is not greater than or equal to index 5.
  - Output: 0 (False)

* Operation: q = &a[3];
  - Analysis: Now both p and q point to the same element (index 3).
  - Expression: p == q
  - Output: 1 (True)

--------------------------------------------------------------------------------
3. PRACTICE PROBLEM WALKTHROUGH
--------------------------------------------------------------------------------
Given Code:
int a[] = {5, 16, 7, 89, 45, 32, 23, 10};
int *p = &a[1]; // points to 16 (index 1)
int *q = &a[5]; // points to 32 (index 5)

Let's evaluate each printf statement sequentially:

Line 1: printf("%d ", *(p + 3));
  - p + 3 moves the pointer 3 positions forward from index 1 to index 4.
  - a[4] contains the value 45.
  - Dereferencing gives: 45

Line 2: printf("%d ", *(q - 3));
  - q - 3 moves the pointer 3 positions backward from index 5 to index 2.
  - a[2] contains the value 7.
  - Dereferencing gives: 7

Line 3: printf("%d ", q - p);
  - Pointer subtraction finds the distance (number of elements) between them.
  - Calculation: Index 5 - Index 1 = 4.
  - Output: 4

Line 4: printf("%d ", p < q);
  - This compares the memory addresses (relative positions).
  - Since p (index 1) comes before q (index 5) in the array, p < q is true.
  - Output: 1

Line 5: printf("%d", *p < *q);
  - This compares the actual values stored at those addresses because of the 
    dereference (*) operator.
  - Value at p is 16. Value at q is 32.
  - Since 16 < 32 is true.
  - Output: 1

Final Program Output Sequence: 45 7 4 1 1
================================================================================
*/