/*
================================================================================
                    C PROGRAMMING: ARRAYS AND POINTERS
================================================================================

1. THE CORE RELATIONSHIP
--------------------------------------------------------------------------------
In C, the name of an array acts as a pointer to its very first element. 
Specifically, the array name evaluates to the "base address" (the memory 
location of index 0).

Example:
    int a[5];

Here, 'a' represents the address of a[0]. 
Because of this, we can use pointer dereferencing (*) directly on the array name.

    *a = 10;   => This is exactly equivalent to writing: a[0] = 10;


2. POINTER ARITHMETIC AND ELEMENT ACCESS
--------------------------------------------------------------------------------
When you add an integer 'i' to an array name 'a', C does not just add 'i' bytes. 
It shifts the address by 'i' elements based on the data type's size.

Formula applied by the compiler:
    Address of element = Base Address + (i * size of data type)

If an integer takes 4 bytes and the base address of array 'a' is 1000:
    a + 1  => 1000 + (1 * 4) = 1004 (Address of the second element)

Therefore, the following relationship always holds true:
    *(a + i) == a[i]

Examples:
    *(a + 0) = 10;  => Sets a[0] to 10
    *(a + 1) = 20;  => Sets a[1] to 20
    *(a + 2) = 30;  => Sets a[2] to 30


3. ACCESSING VS. ASSIGNING (THE CRITICAL DIFFERENCE)
--------------------------------------------------------------------------------
While an array name behaves like a pointer, it is NOT a variable pointer. It is 
a constant pointer. You can look up addresses relative to it, but you cannot 
modify the base address itself.

Case A: Illegal Operation (Modifying the Array Name)
    int a[] = {11, 22, 36, 5, 2};
    printf("%p", a++); // ERROR!

    Why it fails: 
    'a++' implies 'a = a + 1'. You are trying to permanently change the base 
    address of the array 'a' from 1000 to 1004. C does not allow this.

Case B: Legal Operation (Accessing relative addresses)
    int a[] = {11, 22, 36, 5, 2};
    printf("%p", a + 1); // LEGAL.

    Why it works:
    You are simply calculating the address of the second element (1004) to print 
    it. You are not trying to save that new address back into 'a'.


4. USING A MODIFIABLE POINTER VARIABLE
--------------------------------------------------------------------------------
If you need to move a pointer across an array using operations like '++', you 
must create a dedicated pointer variable and point it to the array.

Example Code:
    int a[] = {11, 22, 36, 5, 2};
    int *p = a; // 'p' now stores the address 1000 (points to 11)

    printf("%d", *(++p)); 

Visualizing Execution:
    1. Memory layout of array 'a':
       Index:      [0]     [1]     [2]     [3]     [4]
       Value:    |  11  |  22  |  36  |   5  |   2  |
       Address:   1000    1004    1008    1012    1016

    2. '++p' is a pre-increment operation. It changes 'p' from 1000 to 1004 
       before anything else happens. 'p' now points to index [1].
    3. '*(++p)' dereferences the new address (1004).
    4. Output: 22

================================================================================
*/