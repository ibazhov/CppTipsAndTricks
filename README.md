# C++ Tips and Tricks

A compilation of various features of C++ language:

 - Powerful Auto

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
