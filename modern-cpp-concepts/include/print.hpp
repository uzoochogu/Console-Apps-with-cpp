#ifndef PRINT_HPP
#define PRINT_HPP

#include <format>
#include <string>
#include <string_view>
#include <cstdio>

template<typename... Args>
void print(const std::string_view fmt_str, Args&&... args)
{
    auto fmt_args{ std::make_format_args(args...) };
    std::string outstr{ vformat(fmt_str, fmt_args) };
    fputs(outstr.c_str(), stdout);
}

#endif