cmake_minimum_required(VERSION 3.14)
project(ed1_linked_list_list08_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_SANITIZERS "Compila com AddressSanitizer e UBSan" OFF)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
    if(ENABLE_SANITIZERS)
        add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
        add_link_options(-fsanitize=address,undefined)
    endif()
endif()

set(EXERCISES
    Exer01_MiddleNode
    Exer02_PalindromeList
    Exer03_RemoveDuplicates
    Exer04_OddEvenList
    Exer05_AddTwoNumbers
)

foreach(exe ${EXERCISES})
    add_executable(${exe} src/${exe}.cpp)
    target_include_directories(${exe} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
endforeach()
