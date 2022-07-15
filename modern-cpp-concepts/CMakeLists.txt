cmake_minimum_required(VERSION 3.10)

project("Modern CPP Concepts" VERSION 1.0 DESCRIPTION "Description of some Modern CPP concepts")


# set compiler and flags
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



#source files
set(source_files "1_abstract_base_class" "constexpr_keyword" 
                 "modern_memory_mgmt"    "the_std_format" 
                 "the_std_number"        "bitwise_operators"
                 "stl_algorithms_demo"
    )

#executables
foreach(File IN LISTS source_files)
    add_executable("${File}" ${File}.cpp)
    if (MSVC)
        target_compile_options("${File}" PRIVATE /experimental:module /EHsc /MD)
    endif()
endforeach()
    

 







