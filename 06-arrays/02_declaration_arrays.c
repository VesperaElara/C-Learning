/*
================================================================================
               C PROGRAMMING LECTURE NOTES: 1D ARRAY DECLARATION               
================================================================================

1. DECLARATION AND DEFINITION SYNTAX
--------------------------------------------------------------------------------
To use a one-dimensional (1D) array in C, you must first declare it so the 
compiler knows its data type and how much memory to allocate.

Syntax:
    data_type name_of_the_array[no_of_elements];

Example:
    int arr[5];

When the compiler processes the line above, it allocates a single, continuous 
(contiguous) block of memory. 

The total memory size allocated is calculated as:
    Total Size = number of elements * sizeof(data_type)
    Total Size = 5 * sizeof(int)

Memory Representation for 'int arr[5]':
+---------+---------+---------+---------+---------+
| Element | Element | Element | Element | Element |  <- Contiguous Memory
+---------+---------+---------+---------+---------+


2. RULES FOR SPECIFYING ARRAY LENGTH
--------------------------------------------------------------------------------
The size or length of an array (inside the square brackets `[]`) must always 
evaluate to a positive integer constant expression at compile time.

Valid Declarations:
    - int arr[5];         // Simple integer constant
    - int arr[5+5];       // Constant expression (evaluates to 10)
    - int arr[5*3];       // Constant expression (evaluates to 15)
    - int arr[a = 21/3];  // Evaluates to a positive integer expression (7)

Invalid Declarations:
    - int arr[-5];        // ERROR: Array size cannot be negative!


3. BEST PRACTICE: USING MACROS FOR ARRAY SIZE
--------------------------------------------------------------------------------
It is considered an excellent programming practice in C to define the size of 
an array using a macro definition (`#define`). 

Instead of hardcoding a number directly into the array brackets, you define a 
named constant at the top of your file.

Example Implementation:

    #define N 10   // This is a macro directive

    int arr[N];    // The compiler replaces 'N' with 10 during preprocessing

Why is this a best practice?
Using macros makes your code much cleaner and easier to maintain. If you need 
to change the size of your array later, you only have to modify the value in 
the `#define` directive once, rather than searching and updating every single 
loop or array boundary check throughout your entire codebase.

================================================================================
*/