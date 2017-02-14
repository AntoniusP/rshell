# rshell
CS100 Assignment 

Created by:
Antonius Panggabean 
Randy Yamanaka

~

This program simulates a shell by taking string input and 
parsing the string into multiple components that are either words
or symbols. These components will be separated into different types. 
The first word tokened from the group will be a "executable", while 
following keywords will be inserted into a "ArgList" until the 
input comes across a "connector". When a connector is read in, the 
program will consider its next instruction based on the connector 
type. 

Main.cpp:
- handles input output and contains a command list to execute.
- will be able to run class functions 
- runs indefinitely unless the input is exit