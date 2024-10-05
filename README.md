Just a small shell like tool which is supposed to give some low level features too. first u give the command, then the options, then the arguments for the options then it runs and thats it. the syntax is a bit rigid but the tool itself is supposed to flexible in its function. The tool itself is far from finished and most of my commits are just small commits it self so yeah.If you wonna join then i would be more than happy to make u join this project. file of modes consist of the names of each option and those names are separated using &. and the syntax for giving the command is :
command1_argv1&command1_argv2&and so one| command2_argv1&command2_argv2& and so on.

then u give the options which has the same syntax which is :
command1_option1&command1_option2&and so one| command2_option1&command2_option2& and so on.
then u give arguments which is the same.


FIRST ARGUMENT IS FOR OPTION 2 while the SECOND ARGUMENT IS FOR OPTION 3.

ARGUMENTS FOR EACH PROGRAM IS OBVIOUSLY DIVIDED BY THE SAME |

 ARGUMENTS MAY FURTHUR PROCESS AND INPUT BASED ON A SPECIFIC ENCOUNTER OF A STRING OR A CHARACTOR.
example:
enter ur command:$  ls&ls&|grep&grep&a&|
enter the options:
B&A&|C&A&|
enter the arguments for the options YOU chose:
B&|&B&|
a.out
program_handler.c

enter ur command:$

so here whats happening is that the commands are ls and grep. in the options input i give B&A, C&A. B is for storing a pipe that takes data from stdout. C is for recieving data from that pipe. A is for running ls and grep. in the arguments input I give B&| for process one and the reason for that is that the option 'B' takes a input which is at position one. the B in the arguments input is the pipename. the second process grep write &B&| because it recieves the pipe and the position for 'C' option is second. so in this example ls gives output from stdout to a pipe. grep takes data from that pipe. u can change the option names and used RUN_COMMAND instead of the option name 'A'. u can do that by changing them in file_of_modes file. I hope its understandable.



