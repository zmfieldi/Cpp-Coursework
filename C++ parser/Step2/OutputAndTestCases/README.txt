This directory contains output from the parser (ParserOutput10_08_22), the vm from executing programs (VMOutput10_08_22), the test cases as of 10/08/2022 (TesetCases10_08_22), and the bash scripts I used to execute the parser on all of the non-error (good files) and error producing files, and to run the vm on all of the good files .out files.

10/22/22 update: the ParserOutput10_22_22 files contains updated operands for GoSubLable statements.

10/08/22 update: The testcase 20HardArray declared A as a scalar in a malformed declaration.  It should have been declared as an array.

9/22 update: The only updated test case from what was posted earlier is 20HardArray, which was missing an exit statement and causing my VM to segfault, because the exit statement is what causes the vm to stop executing and incrementing the pc.

10/08/22 update: 20HardArray was updated to declare A as an array with four elements. The previous program declared it as a scalar with four elements, which is a malformed statement.

10/08/22A update: The .pout file for 20HardArray was wrong. Start should have an argument of 4, not 1. The previous incorrect .pout file was for the bad version of 20HardArray when A was declared as a scalar.
