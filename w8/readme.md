# Workshop #8: Virtual functions and Abstract base classes

In this workshop, you will create a hierarchy of classes to practice and understand the role of virtual functions in inheritance. 
The workshop consists of 4 classes:  
- `Shape`: encapsulates a shape that can be drawn on the screen<br />
(An interface, that is an abstract base class with only pure virtual functions)
- `LblShape`: encapsulates a shape that can be labelled <br />
(An abstract base class that represents a labelled shape) 
- `Line`: encapsulates a horizontal line on a screen with the label <br />
(this concrete class draws a labelled line)
- `Rectangle`: encapsulates a rectangle on the screen that can be labelled <br />
(this concrete class draws a rectangle with a label inside).


## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- define pure virtual functions
- create abstract base classes
- implement behaviour using virtual functions
- explain the difference between an abstract base class and a concrete class
- describe what you have learned in completing this workshop


## Submission Policy


The workshop is divided into one coding part and one non-coding part:

- Part 1 (**LAB**): A step-by-step guided workshop, worth 100% of the workshop's total mark
> Please note that the part 1 section is **not to be started in your first session of the week**. You should start it on your own before the day of your class and join the first session of the week to ask for help and correct your mistakes (if there are any).
- Part 2 (reflection): non-coding part. The reflection doesn't have marks associated with it but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

## Due Dates

The Due dates depend on your section. Please choose the "-due" option of the submitter program to see the exact due date of your section:

```bash
~profname.proflastname/submit 200/w8/p1_sss -due<ENTER>
```
- Replace **sss** with the section: [`naa, nbb`]

## Late penalties
You are allowed to submit your work up to 2 days after the due date with a 30% penalty for each day. After that, the submission will be closed and the mark will be zero.

## Citation

Every file that you submit must contain (as a comment) at the top:<br />
**your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

### For work that is done entirely by you (ONLY YOU)

If the file contains only your work or the work provided to you by your professor, add the following message as a comment at the top of the file:

> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

### For work that is done partially by you.

If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which part of the assignment is given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrongdoing.

> - Add the citation to the file in which you have the borrowed code
> - In the 'reflect.txt` submission of part 2 (DIY), add exactly what is added to which file and from where (or whom).

> :warning: This [Submission Policy](#submission-policy) only applies to the workshops. All other assessments in this subject have their own submission policies.

### If you have helped someone with your code

If you have helped someone with your code. Let them know of these regulations and in your 'reflect.txt' of part 2 (DIY), write exactly which part of your code was copied and who was the recipient of this code.<br />By doing this you will be clear of any wrongdoing if the recipient of the code does not honour these regulations.

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ws
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> Note: All the code written in workshops and the project must be implemented in the **sdds** namespace, unless instructed otherwise.


# PART 1 (100%)

Implement four modules for the following classes; **Shape, LblShape, Line** and **Rectangle**

![Classes](images/classes.png)


## 1- The `Shape` interface

### Create the following two [Pure virtual functions](https://ict.senecacollege.ca/~oop244/pages/content/abstr.html#pur):
> a [pure virtual function](https://ict.senecacollege.ca/~oop244/pages/content/abstr.html#pur) is a virtual function that has no implementation.  To indicate that the pure virtual function does not have implementation set its prototype to zero (```= 0;```) in the class declaration.

#### draw  
Does not return anything and receives a reference to **ostream** as an argument.  This pure virtual function can not modify the current object.

#### getSpecs
Does not return anything and receives a reference to **istream** as an argument. 

### `destructor`
Create a virtual empty destructor for the shape interface. 
> this guarantees that any dynamically allocated derived class from the shape interface pointed by a base class pointer will be removed properly from memory when deleted.

### `Shape` helper functions
Overload the insertion and extraction operators (using `draw` and `getSpecs` functions) so any shape object can be written or read using `ostream` and `istream`.


## 2- The `LblShape` abstract Class (the Labeled Shape class)
Create an abstract class called `LblShape` by inheriting the `Shape` interface.  This class adds a label to a `Shape`.

This class will implement the pure virtual function **getSpecs** but will not implement the `draw` function; therefore it remains abstract.

### Private Member variable
Add a character pointer member variable called **m_label** and initialize it to `nullptr`.  This member variable will be used to hold the dynamically allocated label for the `Shape`.


### Protected members 
#### ``` label() ```
Add a query called **label** that returns the unmodifiable value of `m_label` member variable. 

### public members
#### Default (no argument) constructor
Sets the label pointer to `nullptr`. (You don't need to do this if the **m_label** is already initialized to `nullptr` in its declaration in the class definition)
#### One argument constructor
Receives C-style null-terminated string as unmodifiable parameter, allocates memory large enough to hold the received string and makes **m_label** point to it. Finally, copies the received string to the allocated memory.
#### Destructor
Deletes the memory pointed to by **m_label** member variable.
#### deleted actions
The copy constructor and assignment operator are to be deleted to prevent copying or assignment of instances of this class.
#### getSpecs
Reads a comma-delimited C-style null-terminated string form `istream`: <br /> 
Override the **Shape::getSpecs** pure virtual function to receive a C-style string (a label) from **istream** up to the **','** character (and then extract and ignore the **comma**).  Afterward, follow the same logic as was done in the one argument constructor; allocate memory large enough to hold the string and copy the string into the allocated memory. 

## 3- The `Line` concrete class
Line inherits the structure of **LblShape** class to create a horizontal line with a label.

### Private Member variable
Create a member variable called **m_length** to hold the length of the **Line**, i.e., number of characters in a line. 

#### Default (no argument) constructor
Sets the **m_length** member variable to zero, and invokes the default constructor of the base class. 
#### Two argument constructor
Receives a C-style null-terminated string and a value for the length of the line (number of characters to be printed as line). Passes the string to the constructor of the base class and sets the **m_length** member variable to the value received through second parameter.

#### Destructor
This class has no destructor implemented.

#### getSpecs
Reads comma-separated specs of the **Line** from `istream`.<br />
This function overrides the **getSpecs** function of the base class as follows.<br />
First, it will call the **getSpecs** function of the base class to read the string, then it will read the value of the `m_length` attribute from the `istream` argument, and then it will ignore the rest of the characters up to and including the newline character **'\n'**.

#### draw
This function overrides the draw function of the base class.<br />
If the **m_length** member variable is greater than zero and the **label()** is not `nullptr`, this function will first print the **label()** and then go to the new line.  Afterwards it keeps printing the **'='** (assignment character) for the number of times equal to value carried by **m_length**.<br />
Otherwise, it will take no action.

For example, if the C-style string returned by the `label` query is `"Separator"` and the length is `40`, the `draw` function should insert the following into `ostream`:

```Text
Separator
========================================
```
## 3- The `Rectangle` concrete class
The `Rectangle` class inherits the the structure of **LblShape** class to create a rectangular frame with a label inside.

### Private Member variable
Create two member variables called **m_width** and **m_height** to hold the width and the height of a rectangular frame (as number of characters).

#### Default (no argument) constructor
Sets the width and height member variables to zero.  It will also invoke the default constructor of the base class.

#### Three argument constructor
Receives a C-style null-terminated string for the label, and two values for the width and height of the **Rectangle** through its arguments.  Passes the the string to the constructor of the base class and sets the **m_width** and **m_height** member variables to the corresponding values received from the argument list.
However if the **m_height** is less than 3 or **m_width** is less the length of the **label() + 2** it will set the `Rectangle` object to an empty state.

#### Destructor
This class has no destructor implemented.

#### getSpecs
Reads comma-separated specs of the **Rectangle** from `istream`.<br />
This function overrides the **getSpecs** function of the base class as follows.<br />
First, it will call the **getSpecs** function of the base class, then it will read two comma-separated values from `istream` for **m_width** and **m_length** and then ignores the rest of the characters up to and including the newline character (**'\n'**).

#### draw
This function overrides the draw function of the base class.<br />
If the `Rectangle` is not in an empty state, this function will draw a rectangle with a label inside as follows, otherwise, it will do nothing:

First line:<br />
prints '+', then prints the '-' character (m_width - 2) times and then prints '+' and goes to newline.

Second line:<br />
prints '|', then in (m_width-2) spaces it prints the **label()** left justified and then prints '|' and goes to new line.

In next (m_height - 3) lines:<br />
prints '|', (m_width-2) spaces then prints '|' and goes to new line.

Last line: <b />
exactly like first line.

For example, if the string returned by the label query is `"Container"`, the width is `30` and the height is `5`, this function should insert the following into `ostream`:

```Text
+----------------------------+
|Container                   |
|                            |
|                            |
+----------------------------+
```



## `main` Module (supplied)

**Do not modify this module!**  Walk through the code and make sure you understand it.

### Sample Output

```Text
Nothing should be printed between these two lines
------------------------------------
------------------------------------
Separator
==================================================
+----------------------------+
|Container                   |
|                            |
|                            |
+----------------------------+
Enter the following:
>Line two,40<ETNER>
>Line two,40
The following outputs should be the same
The correct output:
Line two
========================================
Your output:
Line two
========================================
Enter the following:
>A 50 by 4 frame to be printed on screen,50,4<ETNER>
>A 50 by 4 frame to be printed on screen,50,4
The following outputs should be the same
The correct output:
+------------------------------------------------+
| A 50 by 4 frame to be printed on screen        |
|                                                |
+------------------------------------------------+
Your output:
+------------------------------------------------+
|A 50 by 4 frame to be printed on screen         |
|                                                |
+------------------------------------------------+
printing Line and Rectangle using Shape pointers:
Line two
========================================
+------------------------------------------------+
|A 50 by 4 frame to be printed on screen         |
|                                                |
+------------------------------------------------+
Reading the data from a file
line one
==========
line two
==============================
line three
==================================================
line four
======================================================================
+-------------+
|Step four    |
|             |
+-------------+
+-----------------------+
|Step three             |
|                       |
+-----------------------+
+---------------------------------+
|Step two                         |
|                                 |
+---------------------------------+
+-------------------------------------------+
|Step one                                   |
|                                           |
+-------------------------------------------+

```




## PART 1 Submission 
### Files to submit
```Text
Shape.h
Shape.cpp
LblShape.h
LblShape.cpp
Line.h
Line.cpp
Rectangle.h
Rectangle.cpp
w08p1_tester.cpp
```
### Submission Process:

Upload the files listed above to your `matrix` account. Compile and run your code using the `g++` compiler as shown in [Compiling and Testing Your Program](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 200/w8/p1_sss  <ENTER>
```
- Replace **sss** with the section: [`naa, nbb`]

and follow the instructions.


> **Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty

# Part 2: Reflection

Study your final solutions for each deliverable of the workshop **and the most recent milestones of the project**, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.  **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this workshop and **the project milestones** and mention any issues that caused you difficulty.


### Submission Process:

Upload the files listed above to your `matrix` account. 

Then, run the following command from your matrix account

```bash
~profname.proflastname/submit 200/w8/reflect_sss  <ENTER>
```
- Replace **sss** with the section: [`naa, nbb`]

and follow the instructions.
> **⚠️Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
