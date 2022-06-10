cmake_minimum_required(VERSION 3.10)

project("Modern CPP Concepts" VERSION 1.0 DESCRIPTION "Description of some Modern CPP concepts")


# set compiler and flags
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)





#executables
add_executable(1_abstract_base_class 1_abstract_base_class.cpp)
if (MSVC)
    target_compile_options(1_abstract_base_class PRIVATE /experimental:module /EHsc /MD)
endif()

add_executable(constexpr_keyword constexpr_keyword.cpp)
if (MSVC)
    target_compile_options(constexpr_keyword PRIVATE /experimental:module /EHsc /MD)
endif()

add_executable(modern_memory_mgmt modern_memory_mgmt.cpp)
if (MSVC)
    target_compile_options(modern_memory_mgmt PRIVATE /experimental:module /EHsc /MD)
endif()

add_executable(the_std_format the_std_format.cpp)
if (MSVC)
    target_compile_options(the_std_format PRIVATE /experimental:module /EHsc /MD)
endif()

add_executable(the_std_number the_std_number.cpp)
if (MSVC)
    target_compile_options(the_std_number PRIVATE /experimental:module /EHsc /MD)
endif()

add_executable(bitwise_operators bitwise_operators.cpp)
if (MSVC)
    target_compile_options(bitwise_operators PRIVATE /experimental:module /EHsc /MD)
endif()



