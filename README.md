# rshell
CS100 Assignment 

Created by:
Antonius Panggabean and
Randy Yamanaka

~

This program simulates a shell by taking string input and 
parsing the string into multiple components that are either words
or symbols. They will be used to initialize a command
class. When a connector is read in, the program will consider 
its next instruction based on the connector type.



Specifications:
- inputted commands/flags/connectors must be spaced out seperately
- will be able to run commands with connectors
- runs indefinitely unless the input is "exit"

Bugs:
- does not work if there is no space between connectors
- will not exit if input is not "exit"