# mysh
## Table of Contents
1. [General Info](#general-info)
2. [Technologies](#technologies)
3. [Installation](#installation)
4. [Overview](#Overview)

### General Info
***
A Unix command interpreter. This is one of the first step to be able to do 42sh project.

## Technologies
***
A list of technologies used within the project:
* [execve]: Execute binaries
* [fork]: Duplicate the calling process

## Installation
***
A little intro about the installation. 
```
$ git clone git@github.com:EpitechPromo2027/B-PSU-200-BDX-2-1-minishell1-romain.giraud.git
$ cd B-PSU-200-2-1-minishell1-romain.giraud
$ make
$ ./mysh
```

## Overview
***
Some examples of what the program should return, and all the differents interractions
```
∼/B-PSU-101> ./mysh
$> ./my_ls .
dir my_ls ‘#test#’ test
```

```
∼/B-PSU-101> ./mysh
$> pwd
/tmp
$> cd test
$> pwd
/tmp/test
```

```
∼/B-PSU-101> ./mysh
$> ls /
/tmp
$> cd test
$> pwd
/tmp/test
```

```
∼/B-PSU-101> echo “ls” | ./mysh
tata
∼/B-PSU-101> echo $?
0
∼/B-PSU-101> echo “ls nofile” | ./mysh
∼/B-PSU-101> echo $?
2
```