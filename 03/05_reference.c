int add(int a, int b)
{
    return (a + b);
}

/*
========================================================================
FUNCTION SCOPE & PRIVACY IN C
========================================================================
1. GLOBAL BY DEFAULT:
   * In C, all functions are global by default. Any other file in the 
     project can call this 'add' function simply by declaring its prototype.

2. ENFORCING PRIVACY WITH 'static':
   * To restrict this function so that it can ONLY be used within this specific 
     file, add the 'static' prefix:
     
     static int add(int a, int b)
     {
         return (a + b);
     }
     
   * Making a function static hides it from the linker, preventing other 
     files from accessing it and avoiding naming conflicts across large projects.
========================================================================
*/