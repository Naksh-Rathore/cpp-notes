# Secmantic Errors

A semantic error is an error in meaning. These occur when a statement is syntactically valid, but either violates other rules of the language, or does not do what the programmer intended.

Some kind of semantic errors can be caught by the compiler. Common examples include using an undeclared variable, type mismatches (when we use an object with the wrong type somewhere), and more

# Debugging Process

When there are errors in your program, fixing it is hard. Here is a step-by-step process you can use to debug programs:

* Find the root cause of the problem (usually the line of code that’s not working).
* Ensure you understand why the issue is occurring.
* Determine how you’ll fix the issue.
* Repair the issue causing the problem.
* Retest to ensure the problem has been fixed.
* Retest to ensure no new problems have emerged.

# Debugging Tools

Here are some tools and strategies you can use for debugging programs in C++.

* Inspect the line of code that the error happened in and investigate
* Investigate in GDB
* Print variables and debug statements that you think may be involved
* Look at the red squiggly lines in your editor
* Reproduce the bug and "reverse engineer" the problem
* Take the buggy code into another debug program and play around with it
* Look for unusual code
* Look for typos (common error)
* Look for deferencing invalid pointers (common error too)
* Comment out and add extra lines of code to find the weak link
* Ask AI to catch errors (not complicated ones and **don't rely on it**)
