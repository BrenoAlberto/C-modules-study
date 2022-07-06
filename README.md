# Modules

---

## Modularizing Programs

* Downsides to single file programs:
  * Single namespace for static global identifiers (such as variable / function names)
    * Static global identifiers have file-level namespaces (hidden from other files)
  * Recompiling large projects can be slow, even though changes are small.
    * Incremental compilation on a per-file bases should help avoid this downside.
  * Sharing code between multiple programs requires duplication of code.
    * Duplication of code is generally best avoided!
  * Long files are more diffult to reason through separate of concerns.

---

## "Modules" in "C

* There are not formal modules in the C language, but the combination of a header and source file offer benefits of a module

* Header file (.h) contains function and type declarations

* Source file (.c) contains function definitions

* Header file provides the interface to a module.
  * The contents of a well-defined module should treat the source file as a black box.

---

## Defining a Header File

* Header filenames end in .h

* The filename conventionally matches its corresponding c file
  * Ex: Point.h / Point.c

* Header files are surrounded in macro "includes guards"

* Declarations of functions, structs, and shared global variables are made inside the include guard.

* Documentation for end users of a module is written in the header files.
  * This should be the only file a programmer needs to look at in order to make use of a mdoule!

* When the C preprocessor reaches an #include macro, it literraly replaces the include line with the contents of the file.

* If many C files include the same header file, the declarations of the header files would be repeated which is invalid C

* To address this, include guards are a pattern of macro if-then statements.

* Convetion: name the macro symbol the same as the file name with underscores replacing non-alphanumerics: ALL_CAPS_H

* Effect: the first time a file includes a heder file, its declarations are loaded. Subsequent times it is skipped over. This makes including a heder file idempotent.

* The \<header.h\> syntax tells the compiler to look in system include paths

* To include a header file from a module in your project, you surround it with " instead

---

## Compiling a "Module" into an Object Code file

* C compilers have facilities to build single modules at a time

* A compiled C module is called an Object Code file (.o extension)

* An Object Code file contains machine code and a symbol table

* Symbols are global identifiers like function names and variables
  * Symbols defined in the module are mapped to their locations in the obj file
  * External symbols (imported into the module) are undefined

* Object files are not executable on their own. They must be linked with the other object files they depend on in order to be executable.

---

## Incremental Compilation

* Adding the -c flag to the compiler flags produces object code files

* Ex: gcc -Wextra -Wall -std=c11 -g -c Point.c
  * This produces the object code file Point.o

* To link object code files together into an executable file, exactly one of the object code files must have a main function symbol defined

* Ex: gcc Point.o main.o
  * This produces the executable

* Notice that changing one file means recompiling only its module and relinking. You can use Make build tool to automate these steps.
