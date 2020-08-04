# Rules about how I should style and organise
# my code
# Only stray from these rules if there is a very good reason

# Naming

MyType (includes structs, enums, unions)
all_variables ;; Much easier to read than camelCase
all_functions ;; Functions can be variables, so keep them the same
MY_ENUM_VALUE
MY_DEFINE
MY_MACRO()

Don't use global variables
Rarely use macros
Rarely use defines

Prefer shorter variable names, but they must always be
sufficiently descriptive.
Local variables should be short, especially if it is
clear what they are doing.

## Common variable names

Use the same names for common types of things:
- i, j, k - indexes
- begin, iter, end - iteration using pointers
- size - Length of arrays, strings

## Enums

Always prefix an enum value with the enum name in upper case
eg:
typedef enum {
    HITBOX_CIRCLE,
    HITBOX_RECT,
    HITBOX_POLY,
    HITBOX_COUNT ;; If it makes sense, put a ..._COUNT value at
} Hitbox;        ;; the end, so you can get the number of enum values

## Globals, defines, macros

They should be used rarely, if at all.

## Hierarchical function names

For functions which are related, give them the same prefix
This is especially applicable for functions operating on types
eg:
Vector vectorAdd(Vector a, Vector b);
Vector vectorProductDot(Vector a, Vector b);
Vector vectorProductCross(Vector a, Vector b);
Vector vectorMagnitude(Vector a);

As you add words, the function should become more precise as what it does
This also helps with autocomplete, as opposed to:
addVector         ;; Can't tab complete to see all the vector
dotProductVector  ;; related functions
...
Also, the above breaks alignment, so is less readable.

## Pointer names

A lot of the time, pointers are the method by which you access the object
The only difference is that you use -> instead of .
Therefore, it is better to name pointers the same way you would name a
normal object.

If you have a pointer which isn't being used to handle an object,
but is actually just a pointer (eg: iterating with a pointer), it
might make more sense to use variable names like "ptr", "struct_ptr", etc.


# Defining data types

## Pointers

Yes: int *p;
No:  int* p;
Why?
"int* p" is interpreted as "int (*p)"
The "*" is associated with the "p", indicating that an int is being
created, but p is to be assigned a pointer to an int.
'int* a, b, c'   is acutually   'int (*a), b, c'
Therefore, put the * with the variable, since that is what the association is.

Also, never typedef pointers, it should clearly be a pointer.

## Structs

Use typedef with an unamed struct
typedef struct {
    int x;
    int y;
} Point;

If the struct is self-referential, then name the
struct so you can use it, but this should only
be used if necessary


# Sizeof

If you have an expression you are allocating memory to,
use sizeof on the expression itself
int* a;
a = malloc((sizeof a)); ;; Also, always put brackets around (typeof var)

This means you don't need to worry about typing the correct variable
type, and allows you to change the variable type without re-writing
the malloc line.


# Comments

Comments should be there to describe WHAT the code does, not HOW.
The code should explain itself.
Rarely, code may require some ugly hack, or unintuitive operation
which is justified. In this case, add a brief comment justifying it
and explaining where it comes from (not necessarily explaining in detail)

Except for trivial functions, put comments before each function
explaining what they do, of the form:
/* Start here
 * some stuff
 * end here
 */
void functionHere(int a, char c) ...

Don't repeat information in comments which is clear from the code.
It is unecessary, and needs to be updated when you change the code
Incorrect comments are worse than no comments at all

;; Importantly:
For function comments, don't write the function name, arguments, return value
That is clear from just reading the function declaration.
Instead, just briefly say what it is doing


# Braces and spacing

## Braces

For most blocks, put the first brace
on the same line as the statement.
if (condition) {
    do stuff
}

However, for functions, put the first brace on
the line following the statement
void myFunction(int x)
{
    // Function body
}

For simple blocks, still use braces:
ie: Don't do this:
if (condition)
    do stuff
else
    do other stuff
Instead:
if (condition) {
    do stuff
}else{
    do other stuff
}
Therefore, everything is consistent, and if
something needs to be added, you don't need to
add braces around it.

The exception is for one-line if statements, without an else clause
if (condition) do_stuff;
- This can be more readable

## Spacing with braces, parentheses, expressions

Put spaces around control statements
like if, case, switch, while
Yes:  while (condition) { ...
No:   while(condition){ ...

For things inside parentheses, don't pad it
with spaces on the outside.
Yes: if (x == 1) {
No:  if ( x == 1 ) {

Use space around any binary or ternary operator:
Yes: x += y
     z = x + y
     result = (z == zExpected)
     a = condition ? ifTrue : ifFalse;

Don't put space after unary operators, or
the increment operators
Yes: ptr = &x
     value = *ptr
     inv = !result
     x++
     --i
No:  i --
     y ++
etc

And of course, no space around . and ->

## Blank lines

Put a single blank line between functions, more is unecessary.

Within functions, use blank lines to seperate out logically distint
parts. Use judgement to decide what is clearer.


# Formatting functions

Unlike control statements, don't put spaces around the parentheses.
Yes:  void myFunction(int x);
No:   void myFunction (int x);

The thing "myFunction(int x)" should be treated as a single entity,
so don't break it up with a space.

Put the first brace of a function on the next line:
void myFunction(int x)
{
    < function body >
}

This is different to control stuctres, because the use of ()
with functions is fundamentally different to control statements.

## Prototypes

Include variables names within the prototype definition, so that someone
can see what the arguments are, just from the header.


# Working with pointers

When assigning null pointers, use NULL, not 0, to make it
clearer what you are doing.

When testing for NULL pointers, use:
if (ptr)
if (!ptr) ;; More consice, and it is clear what it means
NOT
if (ptr != NULL)
if (ptr == NULL)

Prefer pointers for iteration where applicable.
When you do my_array[i], this is the same as *(my_array + i).
Therefore when iterating through the array, you are looking at:
*(my_array)
*(my_array + 1)
*(my_array + 2)
...
ie: You have to increment i, and add this to my_array, each iteration,
as opposed to if you are using a pointer, just increment the pointer
each iteration.

Prefer iteration to be done in for loops, of the form:
for (int *iter = start; iter != end; iter++) {

}
If multiple statements are required in different sections of the for
loop such as below, then put it in a while loop instead.
for (Node *iter = start, *prev = NULL; iter; prev = iter; iter = iter->next){
    Do stuff    ;; This is too verbose
}
Instead, just use a while loop:
Node *iter = start, *prev = NULL;
while (iter) {
    Do stuff
    prev = iter;
    iter = iter->next;
}

# Line length, indentation, trailing whitespace

## Line length

Don't exceed 80 characters
Have added a bar in vim at the 80th character

Should rarely get close to the limit

## Indentation

Tab four characters, and automatically convert to spaces.
Relevant vim settings:
set tabstop=4
set softtabstop=4
set shirtwidth=4
set expandtab
set autoindent

Don't manually press space for indentation,
use the tab key to do this

## Trailing whitespace

Don't leave white space at the end of a blank line.
On vim, trailing white space is marked like so:       
Why?
It is picked up by diffs in version control, so just adds junk.
Additionally, be careful to not do this:
    Indented here
    
    See that there is whitespace up to the tabstop
    Make sure you delete it

    Also, this makes vim skip over the blank line when
    moving between paragraphs, instead of stopping at it


# Header files

Header files should contain the bare minimum necessary.
Especially make sure that memory isn't allocated in headers.

Therefore, headers should only really contain:
- function prototypes
- structs, enums, unions (with typedefs)
- any necessary defines or macros
- any necessary global variables, with extern keyword
;; Debateable whether the last two are necessary

## Including other header files

Only include the necessary header files, where a data type is used
and memory needs to be allocated.

;;!If only a pointer is used, always use a forward declaration instead.
(Otherwise you are going to end up with cyclic dependencies)

## Header guards

Always use header guards of the form:
<PROJECT>_<PATH>_<FILE>_H_
eg: foo/src/bar/baz.h
FOO_BAR_BAZ_H_

You need to be able to guarantee that header guards won't repeat
names, so only including the header name itself is insufficient

## Self-contained headers

Headers should be self-contained.
ie: They should be able to compile on their own
To ensure this, in their .c implementation, put them at the top

# Includes in source files

`#include <...> ;; Used for external header files, from external libraries
`#include "..." ;; Used for internal header files, within your project

Order of indcludes
* foo/src
* "interface header" ;; ie: Header for the functions implemented in this .c

* <external include 1> ;; In alphabetical order
* ...
* <external include n>

* "internal include 1" ;; In alphabetical order
* ...
* "internal include m"


# File names

Use lower_case_with_underscores


# Project layout

todo (write this as I work out how I want to do things)
