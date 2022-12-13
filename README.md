<div id="header" align="center">
	<h1  class="page_title" align="center" width="50">Holberton Shell(FrankenShell)</h1>
	This Shell is a basic command-line interpreter, that takes some basic comands and tries to look like a bash shell.
	
</div>

---
<details>
<summary><h3>Project description</h3></summary>
This is the second group project, carried out by Holberton students.
The goal of this assignment is to recreate the basic simple shell.
 It also encourages group and team work with a randomly assigned partner.
 </details>
<details>
<summary><h3>Requirements</h3></summary>
 *Allowed editors: vi, vim, emac* s.
 
 *  You are not allowed to use global*  variables.
 
 *  No more than 5 functions per file* .
 
 *  it is not necessary to upload the test network to * your repository.
 
 *  The prototypes of all your functions should be included in your header file called main.h.
 
 *  Note that we will not provide the putchar function for this project.
</details>
<details>
<summary><h3>Files</h3></summary>
<h4>Index</h4>
1. [Interprete_line.c(#Interprete_line.c)

2. [ Linked_Lists.c](#Linked_Lists.c)
	
3. [Interprete_command.c](#Interprete_command.c)
	
4. [Memory_auxiliary_functions.c](#Memory_auxiliary_functions.c)
	
5. [Makefile ](#Makefile)

6. [main.h ](#main.h)

7. [man_1_simple_shell](#man_1_simple_shell)

8. [AUTHORS ](#AUTHORS)

<a name="main.h"></a>
<h2><a href="https://github.com/Sapitorico/holbertonschool-simple_shell/blob/main/main.h">main.h</a></h2>
<h4>Here we have Macros, Lybraries, Prototypes and Structures for the shell.</h4>

<a name="Interprete_line.c"></a>
<h2><a href="https://github.com/Sapitorico/holbertonschool-simple_shell/blob/master/Interprete_line.c">Interprete_line.c</a></h2>
<h4>Here we have the main functions for this shell</h4>
main - main function that executes the prompt

Read_Line - Read the input line and keep it in a buffer

Input_Tokenize - divide the input into multiple nodes


<a name="Interprete_command.c"></a>
<h2><a href="https://github.com/Sapitorico/holbertonschool-simple_shell/blob/master/Interprete_command.c">Interprete_command.c</a></h2>
<h4>Here we have a file that runs the command</h4>

Run_Command - This function runs the command

<a name="Linked_lists.c"></a>
<h2><a href="https://github.com/Sapitorico/holbertonschool-simple_shell/blob/master/Linked_lists.c">Linked_lists.c</a></h2>
<h4>Here we have files for the linked list</h4>

Add_Node - This function adds a new node

Add_Node_End - This function adds a node to the end of a list

Elements_Counter - Counts the number of elements in a list

Free_List - release the elements of a list

Free_Grid - Free a array of pointers

<a name="Get_path_command.c"></a>
<h2><a href="https://github.com/Sapitorico/holbertonschool-simple_shell/blob/master/Get_path_command.c">Get_path_command.c</a></h2>
<h4>Here we have function to obtain finale command</h4>

Concatenate_Command - This function obtains the direction of the command

Path_Tokenize - Divide directories into multiple elements

_getenv - This function obtains the value of an environment variable

<a name="Memory_auxiliary_functions.c"></a>
<h2><a href="https://github.com/Sapitorico/holbertonschool-simple_shell/blob/master/Memory_auxiliary_functions.c">Memory_auxiliary_functions.c</a></h2>
<h4>Here we have some auxiliary function for memory</h4>

_strdup - returns a pointer to a new string that is duplicated

_calloc - allocates memory for a data type

_memset - fills memory with a constant byte

<a name="Strings_auxiliary_functions.c"></a>
<h2><a href="https://github.com/Sapitorico/holbertonschool-simple_shell/blob/master/Strings_auxiliary_functions.c">Strings_auxiliary_functions.c</a></h2>



</details>
<details>
<summary><h3>Installation</h3></summary>
  ```
  // clones the repository
  
  $ git clone https://github.com/Sapitorico/holbertonschool-simple_shell.git
  
  $ cd holbertonschool-simple_shell
  ```
</details>
<details>
<summary> <h3>Compilation  and Testing</h3> </summary>

<h5>Your shell will be compiled this way:</h5>
  ```c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
  ```
  <h5>Testing</h5>

<h5>Your shell should work like this in interactive mode:</h5>
  
  ```c
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
<h5>But also in non-interactive mode:</h5>

```c
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
 ```
 <h5>Output</h5>
Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)
Example of error with sh:
 ```c
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
 ```
 <h5>Same error with your program hsh:</h5>
  ```c
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
 ```
  
</details>
<details>

<summary><h3>Authorized functions and macros</h3></summary>
  
* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* getpid (man 2 getpid)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* printf (man 3 printf)
* fprintf (man 3 fprintf)
* vfprintf (man 3 vfprintf)
* sprintf (man 3 sprintf)
* putchar (man 3 putchar)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)
</details>
</div>
---
<details>
  <summary><h3>Resources</h3></summary>
	
<a href="https://intranet.hbtn.io/concepts/900" title="" target="blank">Everything you need to know to start coding your own shell</a>
<a href="https://en.wikipedia.org/wiki/Ken_Thompson" target="blank">Ken Thompson<a>
<a href="https://en.wikipedia.org/wiki/Thompson_shell" target="blank">Thompson Shell</a>
<a href="https://en.wikipedia.org/wiki/Unix_shell" target="blank">Unix Shell</a>
</details>
<footer>
<p align="center"><h3>Authors:</h3><p>
<p align="center"><a href="https://github.com/Sapitorico" target="blank">Sapitorico</a></p>
<p align="center"><a href="https://github.com/CarolinaMolinaSosa" target="blank">CarolinaMolinaSosa</a></p>
</footer>01~
