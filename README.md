# C++ Tips and Tricks

A compilation of various features of C++ language:

 - Dereferening `nullptr`
 - Powerful Auto

## Dereferencing `nullptr`

There are some cases in C++ when dereferencing of null pointer is valid
and does not cause undefined behaviour. These two examples work
perfectly:

```cpp
struct NotVerySophisticatedStruct
{
    int some_data;
    constexpr static void a_static_member_function() {};
    constexpr void a_non_static_member_function() {};
};

NotVerySophisticatedStruct* ptr{nullptr};

// Example - 1
*ptr;

// Example - 2
ptr->a_static_member_function();
 ```

The first example compiles because the result is not used and discarded.
The second examples is just a valid example.

Some of the following examples are valid, some produce 
undefined behaviour, some are controversial (compilers disagree on
whether there is an undefined behaviour or not). You can try to guess which one
is which or check them in [file with examples](DereferencingNullptr.h).

```cpp
// Example - 3
constexpr void foo(int) {}
foo((*ptr, 5));

// Example - 4
ptr->some_data;

// Example - 5
ptr->a_non_static_member_function();

// Example - 6
NotVerySophisticatedStruct not_very_sophisticated_one{*ptr};

// Example - 7
int b{handsomeStruct_ptr->some_data};
```

To check whether a compiler sees an undefined behaviour in an example,
one can do the following trick: put the example inside `constexp`. Since
`constexp` does not allow undefined behaviour, one would caught UD at 
compile time.

File with examples: [DereferencingNullptr.h](DereferencingNullptr.h)

Source: [post on dev.to](https://dev.to/promwad_team/null-pointers-in-c-what-you-can-and-can-t-do-25ic)


## Powerful auto

Specifier `auto` can be used for return type in function declaration. 
 
 ```cpp
auto doCalculation(double a, double b)
{
    return a * b;
}
 ```
More powerfully, function may return a struct declared
only inside the function body (no forward declaration needed).

 ```cpp
auto makeComplexNumber(double real, double imaginary)
{
    struct ComplexNumber
    {
        double real_part;
        double imaginary_part;
    };

    return ComplexNumber{real, imaginary};
}
 ```

File: [PowerfulAuto.h](PowerfulAuto.h)

Available: since C++14

References:
[Cpp reference](https://en.cppreference.com/w/cpp/language/auto) /
[CppCon2019 - Slides](https://github.com/CppCon/CppCon2019/blob/master/Presentations/back_to_basics_the_best_parts_of_cpp/back_to_basics_the_best_parts_of_cpp__jason_turner__cppcon_2019.pdf) /
[CppCon2019 - YouTube](https://youtu.be/iz5Qx18H6lg?t=1368)
