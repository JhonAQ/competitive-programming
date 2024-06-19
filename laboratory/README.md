## C++ Live Toolkit

> **Note** This is a POC (proof of concept) for more advenced tools.

**CLT** *(C++ Live Toolkit)* is subset of tools that are very light in<br> size, and maintained to help programmers in compiling and<br> executing C++ code in the fly.

### List of tools

Here are listed tools that are inside toolkit.<br>
*If you have idea related to this project, we will be happy if you contribute a new tool.*

- **C++ Live Compile Repl (C++ LCP)**:<br><br>
    Cpp fast and light in size repl program that helps to compile ideas<br> in the file without creating useless files.
    <br>
- **C++ Liver**:<br><br>
    Live is a program that monitor changes on your files and compiles <br> them and runs automatically, without any interaction.
    <br>

### C++ LCP 

To use repl compile `src/toolkit/repl.cpp`.<br>
After that, run it, you will get something like this:
```
CLT C++ LRC Live Repl Compiler

cpp >> std::cout << "Hi!" << "\n";
Hi!

cpp >> // thats how it works
```

There are two directives included by deafult: 
- `#include<iostream>`
- `#include<cmath>`


Type C++ code and it will be compiled live fast and output file will be<br> automatically executed.

**Avaible commands**

- **.help**<br>
    Standard help message
- **.quit**<br>
    Quit the repl
- **.clear**<br>
    Clears up the code cached in the variable.
- **.include `every_directive`**<br>
    You can add by it every directive what you need
- **.run**<br>
    Runs constructed c++ code

### C++ Liver

You need to compile: `src/toolkit/live.cpp` in order to use it<br>
Syntax of the **C++ Liver** program is: `./liver name_of_file.cpp`<br>

It will listen on changes in the file/files.<br>
Liver will compile and run your code on every edit.<br>

You can also include more files!<br>
`./liver name_of_file_1.cpp name_of_file_2.cpp name_of_file_3.cpp name_of_file_4.cpp ... name_of_file_n.cpp`

**Dependenices**
- [libsfwatch]()

### Compilation Notes

In order to compile checkout commands included in the `compile.txt`.<br>
Every line of this file represents diffrent command subset for every tool.