# <center>![page](https://github.com/matiassingers/awesome-readme/blob/master/icon.png?raw=true)


# <center>A simple rebuild of *sh*

## <center> Purpose

This project was assigned to us by Holberton School Tulsa. The mandatory goals/functionality/restrictions of this project for our *sh* (i.e. *hsh*) were as follows:
- Use the prototype: *int _printf(const char *format, ...);*
- written in vi, vim, or emacs
- have no memory leaks
- betty compliant
- **must have the exact same output** as `sh` (`/bin/sh`) as well as the exact same error output.
- The only difference is when printing an error, the name of the program must be equivalent to `argv[0]`
- compiled with the following `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## <center>How to Use (plus Examples)
The user of *hsh* will be able to utilize it in an interactive or non-interactive mode as desired. Running *./hsh* in terminal will open up a prompt that the user can call functions from. For example:

    ./hsh
    ($) cat "file"
    [prints contents of "file" to stdout]
    ($) exit
    

Either piping in commands or executing them with *./hsh* will executes the commands without opening the prompt and keeps you in your linux terminal. For example:

Both

    cat "file" | ./hsh

and

   `./hsh cat "file"` 

Will display the contents of "file" to stdout. 

## Contributors
This project exists because of the following contributors:<br />
<a href="https://github.com/wilstermanz"><img src="https://avatars.githubusercontent.com/u/100233764?v=4"></a> <a href="https://github.com/AaronManuel15"><img src="https://avatars.githubusercontent.com/u/100643249?v=4"></a>

> Written with [StackEdit](https://stackedit.io/).
