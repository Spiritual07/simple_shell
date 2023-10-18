![image](https://github.com/Spiritual07/simple_shell/assets/138759673/3362459e-e755-432d-b6e4-b8736bdd04a4)

Simple Shell  Project

Simple shell is a simplified version of a Unix-like shell program, providing a command-line interface to interact with your system. It offers a variety of built-in commands and supports both interactive and non-interactive modes. Simple shell is an excellent tool for those seeking to understand the fundamentals of shell programming.

Features

Simple shell provides numerous functionalities, including:

Command lines with arguments: Enter any command followed by its arguments, and Simple shell will execute it for you.

PATH handling: Simple shell understands the PATH environment variable, allowing you to run programs without specifying their full paths.

env built-in: Use the env command to print the current environment variables.

Exit and Exit with arguments: The exit command can be used with optional numeric arguments to return a status to the parent process.

cd command: Change the current directory using the cd command followed by the directory path.

Command separator (;): Execute multiple commands at once by separating them with a semicolon (;).

Variable replacement: Simple shell supports variable replacement, allowing you to use the value of a variable within commands.

Special Variables ($? and $$): Simple shell handles the $? variable, which returns the exit status of the last executed command, and the $$ variable, which returns the process ID of the shell.

Comments (#): Any line or part of a line preceded by a # is treated as a comment and ignored during execution.

Installation

Clone this repository to your local machine and compile the source code:

hsh
Copy
git clone https://github.com/yourusername/simple_shell.git
cd simple_shell

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Usage
To start the shell in interactive mode:

hsh
Copy
./hsh

To start the shell in non-interactive mode, pipe commands into the shell:

hsh
Copy
echo "ls -l" | ./hsh

Contact
Feel free to reach out if you have any questions. You can contact us at 
kelvin.igbineweka@yahoo.com
Negrosmartins@gmail.com
