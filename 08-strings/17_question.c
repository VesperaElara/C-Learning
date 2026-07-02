#include <stdio.h>

void fun1(char *s1, char *s2) 
{
    char *tmp;
    tmp = s1;
    s1 = s2;
    s2 = tmp;
}

void fun2(char **s1, char **s2) 
{
    char *tmp;
    tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

int main() 
{
    char *str1 = "Hi", *str2 = "Bye";
    
    fun1(str1, str2);
    printf("%s %s ", str1, str2);
    
    fun2(&str1, &str2);
    printf("%s %s", str1, str2);
    
    putchar('\n');
    return 0;
}

/*
================================================================================
POINTER MUTATION AND PASS-BY-VALUE VS. PASS-BY-REFERENCE IN C
================================================================================

This program illustrates a foundational concept in systems programming: the 
difference between modifying local pointer copies versus modifying actual values 
in the calling scope using double pointers (indirection).

---
1. THE MAIN FUNCTION INITIALIZATION
---
Inside the main function, two character pointers are defined:
- 'str1' points to the string literal "Hi"
- 'str2' points to the string literal "Bye"

Think of 'str1' and 'str2' as variables containing the memory addresses where 
these string literals reside.

---
2. ANALYSIS OF fun1 (PASS-BY-VALUE WITH SINGLE POINTERS)
---
When 'fun1(str1, str2)' is invoked, C handles arguments using pass-by-value:

* Mechanism:
  - Local pointer variables 's1' and 's2' are created in the stack frame of fun1.
  - The address stored in 'str1' is copied into 's1'.
  - The address stored in 'str2' is copied into 's2'.

* Swapping Operation:
  - The function swaps the values of 's1' and 's2' using a temporary variable.
  - After swapping, 's1' now points to "Bye" and 's2' points to "Hi".

* Side Effects:
  - Crucially, this operation only reorganizes the local copies within the stack 
    frame of fun1. It has zero impact on the original 'str1' and 'str2' variables 
    defined in main.

Therefore, the first printf statement outputs:
Hi Bye

---
3. ANALYSIS OF fun2 (PASS-BY-REFERENCE WITH DOUBLE POINTERS)
---
When 'fun2(&str1, &str2)' is invoked, the program passes the actual memory 
addresses of the pointers themselves (pointers to pointers):

* Mechanism:
  - Local double-pointer variables 's1' and 's2' are created in fun2's frame.
  - 's1' points directly to the variable 'str1' in main.
  - 's2' points directly to the variable 'str2' in main.

* Swapping Operation:
  - '*s1' evaluates to the value stored inside 'str1' (the address of "Hi").
  - '*s2' evaluates to the value stored inside 'str2' (the address of "Bye").
  - 'tmp = *s1;' saves the address of "Hi".
  - '*s1 = *s2;' writes the address of "Bye" directly into 'str1' in main.
  - '*s2 = tmp;' writes the saved address of "Hi" directly into 'str2' in main.

* Side Effects:
  - Because dereferencing allows direct manipulation of main's memory space, the 
    actual variables 'str1' and 'str2' are successfully swapped.

Therefore, the second printf statement outputs:
Bye Hi

---
4. CONCLUSION AND SUMMARY
---
Combining the outputs from both stages sequentially results in:
Hi Bye Bye Hi

This behavior matches option (a) from the standard problem set.
*/