# What is this repo for?

I hopped back on C++ after 2 years away from it and discovered a similar, yet different and beautiful language called Modern C++.

Here I would go over some of the Modern C++ concepts and try to write simple programs demonstrating them. I will be using the latest C++20 standards (which includes C++11, 14, 17 standards). 

I will start from pretty basic things from the old cpp and ramp up quickly as time progresses. Note that the codes are heavily commented on (which may not be a good practice but serves a pedagogic purpose).

## Topics Discussed
1. Abstract Base Class
2. Functors (Function Objects)
3. `std::format` module 
4. `std::number` module (I'll also talk about the `<limits>` module)
5. Using Aliases
6. Constexpr variables and functions.
7. STL Algorithms
8. C++ Iterators


Note: 
Compiling C++20 is difficult and support for modules is experimental and stressful. 
For now GCC 11.0+ supports a lot of C++20 features but MSVC supports more features. MSVC is currently the only compiler with support for Modules in C++, due to this, I would use it here. (Updated: Sept 18, 22).
I will expand on guide later on.


### Compiling C++20 code with MSVC
1. You need to install Visual studio 2022 and the C++ Desktop Development tool using the Visual Studio Installer. A lighter installation is to just install the MSVC Build Tools (msvc 14.31+)

2. In your code you can add this import statement to import all the core std modules.
```c++
 import std.core;
 ```

3. Open "Developer Command Prompt for VS 2022" or "Developer Powershell for VS 2022" from the start menu
or see this [link](https://docs.microsoft.com/en-us/cpp/build/building-on-the-command-line?view=msvc-170) for more information and for example, using it within your own command line instance. 
 
```powershell
cd "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build"`
```
Then you enter this command: vcvarsall.bat [architecture] [platform_type] [winsdk_version] [-vcvars_ver=vcversion] [spectre_mode]
(Check [here](https://docs.microsoft.com/en-us/cpp/build/building-on-the-command-line?view=msvc-170) for the default values and other options)

For example
```powershell
.\vcvarsall.bat x86
```

4. Use the following flags (replace the name of file as needed)
```powershell
cl /std:c++20 /experimental:module /EHsc /MD the_std_format.cpp
```
*Notes*
1. You can use `/std:latest` flag.
2. To consume the Microsoft Standard Library modules, compile your program with `/EHsc` and `/MD` options.
3. For VS Code fans, two very useful articles (actualy the same article) for using "Developer Command Prompt for VS 2022" as the integrated terminal are:
- [Configure VS Code for Microsoft C++](https://code.visualstudio.com/docs/cpp/config-msvc) 
- [Run VS Code outside the Developer Command Prompt](https://code.visualstudio.com/docs/cpp/config-msvc#_run-vs-code-outside-the-developer-command-prompt) - This configures the VS Code tasks.json file.
4. For a guide on using modules in C++ check this Microsoft documentation - [An Overview of Modules in C++](https://docs.microsoft.com/en-us/cpp/cpp/modules-cpp?view=msvc-170)
5. Cmake currently (Sept 18, 2022) does not support generating modules directly within the build system so you have to add the files manually to the Visual Studio project and solution. The settings in the CMakeLists.txt file is enough though.

<p>
The simplest method which is discussed in the first part of the article is to run "Developer Command Prompt for VS 2022" program from the start menu then navigate to your project directory and run `code` command to open VS code in that working directory using the correct environment variables. You can test this terminal by runing `cl` command to check if exists in that environment.
</p>


## Alternative:
Run CMake and configure a solution file for yourself. The previous Visual studio requirements still hold. As other compilers support C++20, I would add support for them.

### Generating a Solution File
Run the Following:
```powershell
mkdir build
cd build
cmake ..
```
```powershell
cmake --build .
```

## Excerpt on Importing Modules in MSVC from [Microsoft Docs](https://docs.microsoft.com/en-us/cpp/cpp/modules-cpp?view=msvc-170)
> Although not specified by the C++20 standard, Microsoft makes its implementation of the C++ Standard Library importable as modules. By importing the C++ Standard Library as modules rather than including it through header files, you can potentially speed up compilation times depending on the size of your project. The library is split into the following named modules:
> - `std.regex` provides the content of header `<regex>`
> - `std.filesystem` provides the content of header `<filesystem>`
> - `std.memory` provides the content of header `<memory>`
> - `std.threading` provides the contents of headers `<atomic>`, `<condition_variable>`, `<future>`, `<mutex>`, `<shared_mutex>`, and `<thread>`
> - `std.core` provides everything else in the C++ Standard Library



## Influences and References

1. Beginning C++20 From Novice to Professional Sixth Edition by Ivor Horton and Peter Van Weert
2. Bjarne Stroustrop's The C++ Programming language
3. [Javidx9 (OneLoneCoder) videos](https://www.youtube.com/c/javidx9)
4. Learn Advanced C++ Programming - [Advenced C (YouTube Channel)](https://www.youtube.com/channel/UCkcrsZxo0eTpPhBG7Rugs-Q)
5. [Dmitry Nesteruk- Design Patterns and Modern CPP](https://www.youtube.com/watch?v=j9arNRRoPe8)
6. [Cpp Weekly with Jason Turner](https://www.youtube.com/c/lefticus1)
7. Rainer Grimm
8. [CopperSpice YouTube Channel](https://www.youtube.com/c/CopperSpice)
9. [The Cherno YouTube Channel](https://www.youtube.com/c/TheChernoProject)
10. Microsoft Docs (C++)
 - [Visual Studio and C++](https://docs.microsoft.com/en-us/cpp/overview/visual-cpp-in-visual-studio?view=msvc-170)
 - [C++ Language Documentation](https://docs.microsoft.com/en-us/cpp/cpp/?view=msvc-170)
 - [Overview of modules in C++](https://docs.microsoft.com/en-us/cpp/cpp/modules-cpp?view=msvc-170)

11. C++ Design Patterns: Creational- LinkedIn Learning Tutorial by Olivia Chiu Stone.
12. [code_report YouTube Channel](https://www.youtube.com/c/codereport)

