// ============================================================================
//                       THE ULTIMATE GUIDE TO POINTERS
// ============================================================================
//
// CONCEPTS TO VISUALISE:
// 🏠 House (Variable)      : A physical place in memory holding real data.
// 📍 Address (&)            : The exact street number of that house.
// 📋 Note (Pointer Variable): A special piece of paper that holds an address.
// 🔑 Key (*)                : Used to unlock the door and change/read the data inside.
//
// ============================================================================

#include <stdio.h>

int main() {
    
    // ------------------------------------------------------------------------
    // STEP 1: Create a regular variable (The House)
    // ------------------------------------------------------------------------
    // This reserves a spot in your computer's RAM. 
    // The name of the house is 'my_house'. The content inside is 99.
    int my_house = 99; 

    
    // ------------------------------------------------------------------------
    // STEP 2: Create a pointer (The Note)
    // ------------------------------------------------------------------------
    // The '*' here tells the computer: "This variable does not hold normal numbers.
    // It is a pointer, designed ONLY to hold memory addresses of integers."
    int *my_note; 


    // ------------------------------------------------------------------------
    // STEP 3: Store the address (Writing on the Note)
    // ------------------------------------------------------------------------
    // The '&' operator means "Give me the memory address of this variable."
    // We take the street address of 'my_house' and write it onto 'my_note'.
    my_note = &my_house;

    printf("Actual address of variable using pointer:   %p\n", my_note);
    printf("Actual address of variable directly:        %p\n", &my_house);


    // ------------------------------------------------------------------------
    // STEP 4: Read data using the pointer (Looking through the Window)
    // ------------------------------------------------------------------------
    // When you use '*' BEFORE an already created pointer, it means "Go to the 
    // address written on this note, unlock the door, and show me what is inside."
    // This action is called 'Dereferencing'.
    printf("Reading directly:  %d\n", my_house); // Outputs: 99
    printf("Reading via note:  %d\n", *my_note);  // Outputs: 99


    // ------------------------------------------------------------------------
    // STEP 5: Change data using the pointer (Unlocking and Modifying)
    // ------------------------------------------------------------------------
    // We do NOT change 'my_note' (the address stays the same). 
    // Instead, we use the key '*' to go inside that address and replace 99 with 50.
    *my_note = 50; 


    // ------------------------------------------------------------------------
    // STEP 6: Verify the magic
    // ------------------------------------------------------------------------
    // Even though we never touched 'my_house' directly in Step 5, its content 
    // has changed because we used its address to modify it!
    printf("New value directly: %d\n", my_house); // Outputs: 50
    printf("New value via note: %d\n", *my_note);  // Outputs: 50

    /*_________________________________________________________________________*/
    /*_________________________________________________________________________*/
    /*_________________________________________________________________________*/
    
    // STEP 1: Create a normal integer variable.
    // Memory Status: A house named 'x' is built, and the number 10 is put inside.
    int x = 10;


    // STEP 2: Create a pointer variable.
    // Memory Status: A blank note named 'ptr1' is created. 
    // It can ONLY hold memory addresses of integers.
    int *ptr1;


    // STEP 3: Link them together (The Magic Step).
    // The '&' operator grabs the physical RAM address of 'x'.
    // Memory Status: The street address of 'x' is now written onto 'ptr1'.
    ptr1 = &x;


    // STEP 4: Change the value using the pointer.
    // The '*' here means "Go inside the address written on this note".
    // Memory Status: The computer follows 'ptr1' to the house 'x',
    // throws out the 10, and places a 30 inside.
    *ptr1 = 30;


    // STEP 5: Verify the results.
    // Even though we never wrote "x = 30;", x has still been changed!
    // Output will be: x = 30
    printf("x = %d\n", x);

    return 0;
}
