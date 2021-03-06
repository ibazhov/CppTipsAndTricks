//
// C++ Tips and Tricks
//
// Created by Ivan Bazhov on 18/07/2020.
//

#pragma once

#include <iostream>

namespace cpp_tips_and_tricks {
namespace powerful_auto {

/// "Auto" can be used as the return type in function declaration.
/// More powerfully, function may return a struct  declared
/// inside the function body (no forward declaration needed).
///
/// Version: since C++14
///
/// Sources:
/// https://en.cppreference.com/w/cpp/language/auto
/// https://github.com/CppCon/CppCon2019/blob/master/Presentations/back_to_basics_the_best_parts_of_cpp/back_to_basics_the_best_parts_of_cpp__jason_turner__cppcon_2019.pdf
/// https://youtu.be/iz5Qx18H6lg?t=1368

/// Example 1
auto doCalculation(double a, double b)
{
    return a * b;
}

/// Example 2
auto makeComplexNumber(double real, double imaginary)
{
    struct ComplexNumber
    {
        double real_part;
        double imaginary_part;
    };

    return ComplexNumber{real, imaginary};
}

/// Run examples
void doTrick()
{
    auto product = doCalculation(2, 5);
    assert(product == 10);

    auto complex_number = makeComplexNumber(2, 5);
    assert(complex_number.real_part == 2);
    assert(complex_number.imaginary_part == 5);

    std::cout << "Auto is powerful!" << std::endl;
}

} // namespace powerful_auto
} // namespace cpp_tips_and_tricks
