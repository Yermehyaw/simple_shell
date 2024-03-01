C - SIMPLE SHELL


Collaborators:
1. Jeremiah Akor (https://github.com/yermehyaw)


Description:
This is the Readme for a custom shell.


Characteristics/Properties:
The created custom shell will possess the following capabilities/properties:
1. Execute commands passed to it
2. Execute commands with arguments
3. Use PATH variable to find/locate commabds directory
4. Handle an exit command with an exit code
5. Handle env command to print shell environment
6. Use a custom strtok(), getline(), stenv(), unsetemv()
7. Handle the cd command
8. Handle the commamd seperator(;)
9. Handle the && and || shell logical operators


Desription, Explanation and Workflow
shell.c is  a basic shell that performs only the basic yet sophisticated
duties of a shell. It is basically a copy of the sh shell and emulates
almost all its  behaviours including error handling, builtins, signal handling
amongst others.

The control flow works thus:
(See the flowchart for an clear, simple and visual explanation)


main(): The code begins with a main.c which calls the shell() in shell.c
infinitely except the return vlaue of shell() is 0.

shell(): shell() prints a prompt, calls a getline() function to receive
user input. Then takes tge input and checks if:
• cmd_sep(): a command seperator e.g && is present
• check_string(): it has a '/' char in its first word
• cmd_checker(): it the first word matches the the name of any of the shell
buitin commands e.g exit
• program_path(): its a single command with or without  arguments e.g ls -al


Returings Flow:
Case 1: A command path with ot without argumemts
shell() returns an int to main(). If 0 main exits 0.