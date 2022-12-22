<div align="center">
    <h1>Simple Shell Project</h1>
</div>

## Description
This project is a basic recreation of the <a href="https://en.wikipedia.org/wiki/Unix_shell" target="_blank">Unix Shell</a> command interpreter that receives commands and communicates with multiple programs inside this repository to perform specific actions.

## Man Page
The man page is a file wich explains how our Shell works and the commands that can be executed. To see the detailed explanation, you can run our man page this way:

	$ man ./man_1_simple_shell

## Flow chart 📊
<img src="https://i.imgur.com/6SlivhO.jpeg" alt="flowchart">


## Compilation 💻

To compile this Shell, the next command has to be executed:

	$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

After execution, the command to run our Shell and be able to enter action commands is:

	$ ./hsh

## Usage

This shell can be executed two different ways, the first one is in the interactive mode, this means that after the shell is compiled, the user can call the commands directly in the executable file. Working as the following:

	$ ./hsh
	($) 

Executing the shell will show the prompt `$` shown previously and is going to wait until the user enters a command, so an example will be:

	$ ./hsh
	($) ls
	File1.c File2.c Header.h


The second option is execute it in non-interactive mode, this means that after the compilation, the shell is going to be executed by entering commands using a pipe line. An example of this execution will be:

	$ echo "/bin/ls" | ./hsh
	hsh main.c shell.c test_ls_2

## Files list
The following list will tell us what files are necessary to run the shell successfully:
| File  | Description |
| ------------- |:-------------:|
| `auxiliar_functions.c` | Has functions that will divide the string (input) and check if it's valid. |
| `main.c` | Main function that will execute the shell. |
| `str_functions.c` | Has recreated functions to modify and manipulate strings, such as strcpy, strlen, etc. |
| `shell.h` | Has header declarations, such as libraries, global variables and prototypes.|

## Command list
The next list is a summarized chart of some the allowed commands that can be executed in our shell.
| Command  | Description |
| ------------- |:-------------:|
| `ls`      | Displays the names of files and directories contained within the current directory.    |
| `pwd`      | Prints the full path of the current working directory. |
| `echo`      | Writes its arguments separated by blanks and terminated by a new line on the standard output.    |
| `env`      | Execute command and print environment.    |
| `exit`      | The exit command causes normal process termination of the Shell.    |


## Authors 🖊
* Juan Esteban Duque <a href="https://github.com/Juanesduque1" rel="nofollow"><img align="center" alt="github" src="https://www.vectorlogo.zone/logos/github/github-tile.svg" height="24" /></a>
* Yurany Ulchur <a href="https://github.com/YuranyUlchur" rel="nofollow"><img align="center" alt="github" src="https://www.vectorlogo.zone/logos/github/github-tile.svg" height="24" /></a>

> This project was made for [Holberton School's](https://www.holbertonschool.com/) software development program.