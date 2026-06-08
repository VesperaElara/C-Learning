/*
================================================================================
TOPIC: INITIALIZING 1D ARRAYS IN C
================================================================================

1. COMMON INITIALIZATION METHODS
--------------------------------
There are several ways to initialize a 1D array in C:

    // Method 1: Static initialization with defined size
    int arr[5] = {1, 2, 5, 67, 32};

    // Method 2: Static initialization with implicit size (compiler counts elements)
    int arr[] = {1, 2, 5, 67, 32};

    // Method 3: Manual assignment (not recommended as primary initialization)
    int arr[5];
    arr[0] = 1; arr[1] = 2; ... // Tedious for large arrays

    // Method 4: Dynamic input via loop (preferred for runtime data)
    int arr[5];
    for(int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

2. PARTIAL INITIALIZATION AND DEFAULTS
--------------------------------------
If you provide fewer values than the declared array size, C automatically 
fills the remaining memory locations with the value 0.

    // Example: int arr[10] = {45, 6, 2, 78, 5, 6};
    // Result: The array will contain {45, 6, 2, 78, 5, 6, 0, 0, 0, 0}

3. TRICK: INITIALIZING ALL ELEMENTS TO ZERO
-------------------------------------------
Instead of manually looping through an array to set all values to zero, 
you can use this shorthand:

    int arr[10] = {0}; 
    // This explicitly sets the first element to 0, and the compiler 
    // applies the partial initialization rule to the rest.

4. IMPORTANT RESTRICTIONS (DO NOT DO THIS)
------------------------------------------
When initializing an array, there are two common mistakes that will cause errors:

    * DO NOT use empty brackets:
        int arr[10] = {}; // ILLEGAL: You must provide at least one element.

    * DO NOT exceed the array size:
        int arr[5] = {1, 2, 3, 4, 5, 6}; // ILLEGAL: Too many elements for size 5.

================================================================================
*/