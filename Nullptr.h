//
// C++ Tips and Tricks
//
// Created by Ivan Bazhov on 31/07/2020.
//

#pragma once

namespace cpp_tips_and_tricks {
namespace dereferencing_nullptr {

/// There are some case in C++ when dereferencing of null pointer is valid
/// and does not cause undefined behaviour.
///
/// We give a number of examples:
///  - Examples 1, 2, and 3 should not produce undefined behaviour
///    according ot the Standard and we can compile them.
///  - Examples 4 and 5 are more controversial: it is difficult to
///    say what the Standard says about these cases and some
///    compiler can compile the examples.
///  - Examples 6, 7, and 8 produce undefined behaviour.
///
/// To test that an example produces an undefined behaviour
/// we put it inside a constexp function. Since constexpr does not
/// allow undefined behaviour, we would caught UD at compile time.
///
/// Source: https://dev.to/promwad_team/null-pointers-in-c-what-you-can-and-can-t-do-25ic


/// Prerequisite: Structure with data and function members
struct HandsomeStruct
{
    int some_integer;
    constexpr static void some_static_member_function() {};
    constexpr void some_non_static_member_function() {};
};

/// Prerequisite: Function consuming int
constexpr void foo(int) {}

/// Function with examples
///
/// return marked as constexpr. Since constexpr does not
/// allow undefined behaviour, we would caught UD at compile time.
constexpr int testTrick()
{
    HandsomeStruct* handsomeStruct_ptr{nullptr};

    // Example - 1
    // Compile because the result is not used and discarded.
    //
    *handsomeStruct_ptr;

    // Example - 2
    // This is valid example
    //
    handsomeStruct_ptr->some_static_member_function();

    // Example - 3
    // Same explanation as in Example 1
    //
    foo((*handsomeStruct_ptr, 5));

    // Example - 4
    // This is a controversial example.
    // As tested in the reference, works GCC but not with Clang ot MSVC
    // The explanation can be as follows:
    // again, as in examples 1 and 3 the result is not used and discarded.
    // handsomeStruct_ptr->some_integer;

    // Example - 5
    // According to the Standard (see Reference)
    // the line below should cause Undefined behaviour
    //
    // Despite that, example compiles with GCC and MSVC
    // handsomeStruct_ptr->some_non_static_member_function();

    // Example - 6
    // It doesn't compile because struct should be initialized
    // with something.
    //
    // HandsomeStruct handsomeStruct{*handsomeStruct_ptr};

    // Example - 7
    // Again, doesn't compile because int b should be initialized
    // with something
    //
    // int b{handsomeStruct_ptr->some_integer};

    return 0;
}

/// Run example
void doTrick()
{
    constexpr auto testTrick_result = testTrick();
    if (testTrick_result == 0)
    {
        std::cout << "I dereferenced nullptr and I am still alive!" << std::endl;
    }
}

}
}
