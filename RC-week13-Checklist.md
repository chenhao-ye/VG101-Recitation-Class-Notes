# VG101: Introduction to Computer and Programming
## Week12 Checklist
### C++ Dynamic Memory Allocation
- `new` and `delete`: dynamic memory allocation in C++
- example
```C++
// Allocate single integer
int *pInt = new int;
delete pInt;

// Allocate an integer array of length = 5
int size = 5;
int *pArr = new int[size];
delete[] pArr;   // note the [] here
```
- Don't mix with `malloc` and `free`
- Advantage of `new` over `malloc`
    - `new` is an C++ keyword (no library requirement), `malloc` is a library function
    - `new` will call the constructor, `malloc` will not
    - `new` will return appropreiate pointer type

### Reference
#### Reference Variable
- A reference variable is an alias for another variable. Any changes made through the reference variable are actually performed on the original variable.
    - Must be initialized and cannot be `NULL`
    - Cannot change the variable the reference variable refers to
```C++
int a;
int &ra = a;    // any change to ra will affect the value of a
```

#### Reference Variable in Function
- A very useful techniuque to share variable during function calling
- Use reference variable as function parameter
- Similar to pointer
```C++
void swap(int &a, int &b)     // function parameters are reference variable
{                             // change of a, b will be kept
    int temp = a;             // similar to using pointer, but more clear
    a = b;
    b = temp;
}

int main()
{
    int a = 1, b = 2;
    swap(a, b);               // directly use variable instead of using address
    cout << "a = " << a << ", b = " << b << endl; // result: a = 2, b = 1
    return 0;
}
```

- Counterpart program using pointer 
```C++
void swap(int *a, int *b)     // function parameters are pointer
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 1, b = 2;
    swap(&a, &b);             // pass the address 
    cout << "a = " << a << ", b = " << b << endl; // result: a = 2, b = 1
    return 0;
}
```

- Distinguish between reference variable and variable address
    - reference variable is left value
    - variable address is right value

- Another advantage of reference: a way to pass by address rather than pass by value
    - In C++, function parameter need to be class object, usually big in size
    - Pass by value require copy the big class object, very inefficient
    - Pass by address can instantly finish the passing

### Destructor
- Destructor is called automatically by the compiler when the object goes out of scope.
    - Constructor is called automatically by the compiler when the object is created.
- Syntax similar to constructor 
```C++
public:
    MyClass();        // constructor of MyClass
    ~MyClass();       // destructor of MyClass
```

### Default Argument
- A default argument is a value given in the declaration that the compiler automatically inserts if you don’t provide a value in the function call.
- If function has several argument and some are default, default arguments are always put at the end
```C++
int add(int a, int b = 1) // a is not default arguemnt, but b is
{                         // b should be put behind a
    return a+b;           // valid call: add(1), add(1, 3)
}
```

### STL (Standard Template Library)
#### Template
- We want a class to support different variable types (int, char ... even class object)
- We can use template
- For example: a list of any variable type
```C++
MyList <T>                // <T> is called template  
{                         // You can regard it as place holder for variable type
public:
    T * list;
};

MyList<int> intList;        // Using the class, we specity the variable type
MyList<string> stringList;  // It can even be class object
```

#### STL container classes 
- STL container classes that you should know
    - string
    - vector
- Other STL container classes
    - deque
    - list
    - priority_queue
    - unordered_map
    - set
- After C++11 STL implementation becomes very efficient
- Use STL when possible, it helps a lot

#### string
- 


#### vector
- 
