# rshell
CS100 Assignment 

Created by:
Antonius Panggabean and
Randy Yamanaka

~

This program simulates a shell by taking string input and 
parsing the string into multiple components that are either words
or symbols. They will be used to initialize a command
class. The design is mostly a strategy pattern that uses different 
types of commands to execute. When a connector is read in, the program will 
consider its next instruction based on the connector type.



Specifications:
- inputted commands/flags/connectors must be spaced out seperately
- will be able to run commands (except cd) and the test command
- can use test command with "[]"
- runs indefinitely unless the input is "exit"
- creates commands and a command tree to execute


Bugs:
- does not work if there is no space between connectors
- will not exit if input is not "exit"
- echo's will include ""
- precedence does not work yet