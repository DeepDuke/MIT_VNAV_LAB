# Answers for C++ Warm-up Exercises
## Operators

1.What are the values of i and j after running the following code?
```c++
int i = 0, j;
j = ++i;
j = i++;
```
The values are: `i=2, j=1`


2.What does the following code print?
```c++
int i = 42;
std::string output = (i < 42) ? "a" : "b";
std::cout << output << std::endl;
```
The result is `b`

## References and Pointers

1.What does the following code print?
```c++
int i;
int& ri = i;
i = 5;
ri = 10;
std::cout << i << " " << ri << std::endl;
```
The result is `10 10`.

2.What does the following code print?
```cpp
int i = 42;
int* j = &i;
*j = *j**j;
std::cout << *j << std::endl;
```
The result is `1764`.

3.What does the following code print?
```cpp
int i[4] = {42,24,42,24};
*(i+2) = *(i+1)-i[3];
std::cout << *(i+2) << std::endl;
```
The result is `0`.

4.What does the following code print?
```cpp
void reset(int &i) {
    i = 0;
}

int j = 42;
reset(j);
std::cout << j << std::endl;
```
The result is `0`.

## Numbers

1.What are the differences between int, long, long long, and short?

Different size length.

2.What are the differences between a float and double? What is the value of i after running the following code snippet?
```cpp
int i;
i = 3.14;
```

`Double` is more precise than `float`. `i=3`

3.What are the differences between an unsigned and signed type? What is the value of c in the following code snippet assuming chars are 8-bit?

The term "unsigned" in computer programming indicates a variable that can hold only positive numbers. The term "signed" in computer code indicates that a variable can hold negative and positive values.
`c=255`

4.What will the value of i be after running the following code snippet?
```cpp
int i = 42;
if (i) {
 i = 0;
} else {
 i = 43;
}
```
The result is `i=0`

