<div align="center">
    <h1>Simple Shell Project</h1>
</div>

## Description
This project is a basic recreation of the <a href="https://en.wikipedia.org/wiki/Unix_shell" target="_blank">Unix Shell</a> command interpreter that receives commands and communicates with multiple programs inside this repository to perform specific actions.

## Man Page
The man page is a file wich explains how our Shell works and the commands that can be executed. To see the detailed explanation, you can run our man page this way:

	$ man ./man_1_simple_shell


## Compilation 💻

To compile this Shell, the next command has to be executed:

	$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

After execution, the command to run our Shell and be able to enter action commands is:

	$ ./hsh

## Command list
The next list is a summarized chart of some the allowed commands that can be executed in our shell.
| Command  | Description |
| ------------- |:-------------:|
| ls      | Displays the names of files and directories contained within the current directory.    |
| pwd      | Prints the full path of the current working directory. |
| echo      | Writes its arguments separated by blanks and terminated by a new line on the standard output.    |
| env      | Set environment and execute command or print environment.    |
| exit      | The exit command causes normal process termination of the Shell.    |

## Usage

This shell can be executed two different ways, the first one is in the interactive mode, this means that after the shell is compiled, the user can call the commands directly in the executable file. Working as the following:

	$ ./hsh
	($) ls
	hsh main.c shell.c
	($)
	($) exit
	$

The second option is execute it in non-interactive mode, this means that after the compilation, the shell is going to be executed by entering commands using a pipe line. An example of this execution will be:

	$ echo "/bin/ls" | ./hsh
	hsh main.c shell.c test_ls_2
	$
	$ cat test_ls_2
	/bin/ls
	/bin/ls
	$
	$ cat test_ls_2 | ./hsh
	hsh main.c shell.c test_ls_2
	hsh main.c shell.c test_ls_2
	$



## Flow chart 📊
<img src="https://i.imgur.com/6SlivhO.jpeg" alt="flowchart">

## Authors 🖊
* Juan Esteban Duque <a href="https://github.com/Juanesduque1" rel="nofollow"><img align="center" alt="github" src="https://www.vectorlogo.zone/logos/github/github-tile.svg" height="24" /></a>
* Yurany Ulchur <a href="https://github.com/YuranyUlchur" rel="nofollow"><img align="center" alt="github" src="https://www.vectorlogo.zone/logos/github/github-tile.svg" height="24" /></a>
