# VG101: Introduction to Computer and Programming
## Week7 Checklist
### Farewell MATLAB, Hello C
#### C
- A Lower-level higher-level language.
- A procedure-oriented programming language.
- Good for system programming.

#### C and C++
- C++ is based on C.
- C++ is An object-oreiented programming language.
- C++ integrates many modern programming ideas.

### Before we start
- Be prepare to get rid of bad programming habits.
- Submitting program on JOJ that result to an error = Submitting nothing.
- Warning = Error on JOJ.
- Start early. JOJ has maximum submission limits per day.
- [Visual Studio guide](https://www.cnblogs.com/shawnxie/p/7887787.html)

### Features of C
What is C different with MATLAB?
- Filename: end with .c
- Include header files (libraries)
- A main function with return value
- ; at the end of each line
- "{}" instead of "end"
- Different comment style

```C
/* Filename: helloWorld.c */
#include <stdio.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
```

#### Header files
- What is program files (.c) and header files (.h)? 
- Definition vs. Implementation.
- include: link multiple files.
```C
#include <stdio.h>
#include <math.h>
#include "myFunctions.h"
```
- Library: function definitions written by frofessional programers.
- Common libraries: 
```C
#include <stdio.h>   // For standard input and output.
#include <math.h>    // For basic mathematic operations like sqrt, sin, pow.
#include <stdlib.h>  // For random number generation and dynamic memory allocation.
#include <string.h>  // For efficient string manipulation.
#include <time.h>    // For recording program running time.
```
- Header files: functions definitions witten by you.
- Difference between <> and ""

#### Main function
- Main function is where a program starts executing.
- A program only contains **one** main function.
- Main function not callable. (No recursion for main function)
- Return type and return value: **strongly recommended**
```C
int main() // Return type: a integer
{
	// Write your code here
	return 0; // Return value: 0
}
```
- Your program will fail on JOJ if you don't add return type and return value.
- **Please** don't write everything in the main function.

### Variable
- A variable need a name, a data type, a value
- Variable name rules similar to MATLAB
- Requires define before use
```C
int main() // Define different types of variables
{
	int a;
	float b;
	unsigned int c;
	char d;
	long e;
	return 0;
}
```

#### Data types
- char: 8 bits ASCII code representing a character
- int: -2147483648 ~ 2147483647 
- unsigned int
- long 
- float & double (both floating point)
- No bool type (logical type) in C. Number 0 = False. Number not 0 = True.

#### Data type conversion
- C will automatically convert data type.
```C
int main()
{
	int a = 1 + 1.5;      // What is a?
	double b = 3/2;       // What is b?
	double c = 3/2.0;     // What is c?
	int d = a + b + c;    // What is d?
	return 0;
}
```
- You can manually convert data type.
```C
int main()
{
	double pi = 3.1415926;
	int integerPi = (int)pi; // Convert double into int
	return 0;
}
```
- Keep using same data type in an expression to avoid trouble.

#### Constant variable
- Same as MATLAB, C allows constant variables.
- Require initial value assigned, or the variable is meaningless.
- Changing the value of constant variable causes error.
- Why constant variable? 
Sometimes we want to garantee we will not mistakely change variable that should remain constant.
```C
int main()
{
	const int a = 1; // Constant variable must has initial value assigned
	a = 2;           // Wrong! Causing an error.
	return 0;
}
```

### Input / Output
- You must include <stdio.h>.
- Output function: printf
- Input function: scanf

#### printf
- Similar to MATLAB function fprintf.
- Only print to standard output stream (command line).
- Use C function fprintf for file output.
```C
#include <stdio.h>
int main()
{
	printf("Hello world!\n");                           // string uses double quotation mark
	int a = 0; float b = 1; double c = 2; char d = 'd'; // char uses single quotation mark
	printf("a=%d\tb=%f\tc=%lf\td=%c.\n", a, b, c, d);   // \t for tab, \n for new line
	return 0;
}
```

#### scanf
- Similar to MATLAB function fscanf.
- Only scan from standard inpt stream (command line input).
- Use C function fscanf for file input.
- Visual studio may require you use scanf_s
```C
#include <stdio.h>
int main()
{
	int a; float b; double c; char d;
	printf("Please input a, b, c, d:\n");				// scanf does not support output
	scanf("%d, %f, %lf, %c", &a, &b, &c, &d);			// don't forget &
	//scanf("%d %f %lf %c", &a, &b, &c, &d); 			// Whats the difference?
	printf("a=%d\tb=%f\tc=%lf\td=%c.\n", a, b, c, d);
	return 0;
}
```

#### other ways of I/O
- getchar(): seldom used.
- Some Visual studio user use getchar() to avoid quit after program terminates. Don't do that! Program like this 100% fail on JOJ. Follow above visual studio guide to setup, or [follow this link to fix](https://jingyan.baidu.com/article/cdddd41c8e2e4153cb00e13d.html).

### Operators
- Assignment operator: =
- Arithmatic: +, -, \*, /
- Remainder: %
- No ^ , use pow()

#### ~~To be lazy~~
- ++ increment, -- decrement
- (i++) vs. (++i)
```C
#include <stdio.h>
int main()
{
	int i=0;
	printf("%d\n", i++); // Print out 0
	return 0;
}
```
- Shorthand assignment operators
	- a += b &hArr; a = a + b
	- a -= b &hArr; a = a - b
	- a \*= b &hArr; a = a \* b
	- a /= b &hArr; a = a / b

#### Logical operators
| operator | operation |
| :----------: | :-------------: |
| && | And |
| \|\| | Or |
| ! | Not|
| == | Equal to|
| != | Not equal to|

### Control statements
- if, switch, while, for. Similar to MATLAB.
- blocks {}: enclose multiple statesments
- Variable scope: inside block.
```C
#include <stdio.h>
int main()
{
	if (1) // An if statement they will always excute
	{
		int a = 1;
	}
	printf("a = %d", a); // Wrong! variable a no longer exists!
	return 0;
}
```
- block {} can be omitted if it only enclose one statement.
- Again, **Indent is useful!**

#### If
- No major difference with MATLAB
- No elseif, use else if

#### Switch
- Fast way to deal with multiple situations.
- break is important. What will happen without break?
```C
#include <stdio.h>
int main()
{
	int n;
	printf("What is the rank of the card (1-13)? ");
	scanf("%d", &n);
	switch (n)
	{
		case 1: printf("Ace\n"); break; // break is important
		case 11: printf("Jack\n"); break;
		default: printf("%d\n", n); break;
	}
	return 0;
}
```

#### While
- No major difference with MATLAB
- Do-while: another version of while loog.
- while(1) for infinite loop.
- break & continue: same as MATLAB

#### For
- Most common loop statement
- How to use?
```C
#include <stdio.h>
int main()
{
	int i;
	for (i=0; i<10; i++) //Initial value; ending condition; step
		printf("%d\n", i);
	return 0;
}
```
- The above code equals code below:
```C
#include <stdio.h>
int main()
{
	int i=0;
	while (i<10)
	{
		printf("%d\n", i);
		i++;
	}
	return 0;
}
```
- What is the variable scope if we do this?
```C
for (int i=0; i<10; i++)
```


### Function
- Allow code written outside main function
- Syntax:
```C
int add(int a, int b)   // returnType functionName (parameterType parameter, ...)
{						// block enclose function content
	return (a + b);		// return value (must consistent with returnType)
}
```
- parameter passed by value
- same variable name can be used in different function (they do not share value)
- Use void function if function return nothing.
- Use void parameter if function needs no input parameters.
```C
void helloWorld(void)			// No input parameter, no return value.
{
	printf("Hello world\n"); 	// Only do something.
}
```

#### Use function in main
- Function prototype (definition) should appear above where it is used.
- Function implementation can appear after main function.
```C
#include <stdio.h>
int add(int a, int b);			// Function prototype, ; required

int main()
{
	int a, b, c;
	scanf("%d, %d", &a, &b);
	c = add(a, b);				// Call the function, return value stored into c
	printf("a+b=%d\n", c);
	return 0;
}

int add(int a, int b)			// Function implementation
	return (a + b);				// block {} omitted since only single statement
```
- Put prototype and implentation together:
```C
#include <stdio.h>
int add(int a, int b)			// Function prototype + implementation, ; not required
	return (a + b);

int main()
{
	int a, b, c;
	scanf("%d, %d", &a, &b);
	c = add(a, b);				// Call the function, return value stored into c
	printf("a+b=%d\n", c);
	return 0;
}
```
- Both is OK. ~~Just be lazy and use the latter.~~
- Sometimes you have to use the former
	- Using function in other .c files: prototype written in a .h file.
	- Two functions calling each other. (recursion)





