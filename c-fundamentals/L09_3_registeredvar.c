/* 
Register modifier
Syntax = register data_type variable_name
*/
int main()
{
    register int var;
    return 0;
}

// Access time for variables stored in registered memory is greatly reduced. 
// Usually, frequently-used variables are registered.
// It is upto the compiler whether it chooses to put the variable in its registered memory.
