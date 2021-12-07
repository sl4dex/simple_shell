# Simple Shell

### What is a shell program and why would you use it?

The shell is a computer program that serves as an intermediary between  
the operating system and the human user or other programs. In general,
operating  system shells use either a command-line interface (CLI) or
graphical user  interface (GUI).
It is named Shell because it is the outermost layer around the operating   
system. In this case, our shell is only used through the Command-line
interface (CLI)

### Compilation
To compile the current files to generate a functioning executable, you'll need
the files:
- shell.c
- get_path.c
- tokensAndfree.c
- execution.c

joining them together with the gcc program and its respective warnings

`gcc -g -Wall -Werror -Wextra -pedantic -std=gnu89 -o excutableName`
### Commands
Command-line shells require the user to be familiar with commands and  
their calling syntax and to understand concepts about the shell-specific  
scripting language (for example, bash).

To use the Command-line, simply start the shell executable and type in the
command that you want to use, for example:
``` 
root@9500cff7c6d4:~/shell# ./execName
-> ls 
ATHORS debug execution.c get_path.c README.md main.h ...
->
```
to exit interactive mode, just type exit, or ctrl + D
``` 
root@9500cff7c6d4:~/shell# ./execName
-> exit
root@9500cff7c6d4:~/shell#
```
You can use the non-interactive mode also, using the shell without entering
the terminal:
````
root@9500cff7c6d4:~/shell# echo "ls" | ./execName
ATHORS debug execution.c get_path.c README.md main.h ...
root@9500cff7c6d4:~/shell#
````
**Authors © Joaquin Victoria, Salvador Diaz.**
