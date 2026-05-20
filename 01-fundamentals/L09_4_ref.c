#include <stdio.h>

int count; //global variables are by default initiliazed to zero.

int increment()
{
    count += 1;
    return count;
}

/*
========================================================================
THE TWO FACES OF THE 'static' KEYWORD IN C
========================================================================

1. STATIC GLOBAL VARIABLES (File-Level Scope / Privacy)
------------------------------------------------------------------------
* By default, global variables are visible to the entire project (via 'extern').
* Adding 'static' before a global variable restricts its scope strictly to 
  the file it is declared in. No other file can link to or access it.
  
  Example:
  static int count; // Private to this file; hidden from other files.


2. STATIC LOCAL VARIABLES (Function-Level Scope / Persistence)
------------------------------------------------------------------------
* Declared INSIDE a function. Unlike normal (automatic) local variables 
  that are destroyed when a function finishes, a static local variable 
  remains in memory for the entire duration of the program.
* It retains its value across multiple function calls.


3. KEY RULES FOR ALL STATIC VARIABLES
------------------------------------------------------------------------
* Initialization: Unlike normal local variables (which contain unpredictable 
  "garbage values" if uninitialized), all static variables are automatically 
  initialized to zero by default.
* Constant Assignment: You can only initialize a static variable using a 
  constant literal (e.g., static int x = 5;). You cannot initialize it using 
  the value of another variable or a function call.
========================================================================
*/
