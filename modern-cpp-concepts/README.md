# What is this repo anbout?

I hopped back on C++ after 2 years away from it and discovered that I didn't know about the Modern CPP concept.

Here I would go over some of the concepts and try to write simple programs demonstrating them. I will be using the latest C++20 standards (which includes C++11, 14, 17 standards)

I will start from pretty basic things from the old cpp and ramp up quickly as time progresses. 

## Topics Discussed
1. Abstract Base Class
2. Functors (Function Objects)
3. std::format module (WIP)
4. std::number module (I'll also talk about the <limits> module)


Note: 
Compiling C++20 is difficult and support for modules is experimental and stressful. 
For now GCC 11.0+ supports a lot of C++20 features but MSVC supports more features. I will expand on guide later on.


### Compiling C++20 code with MSVC
1. You need to install Visual studio 2022 and the C++ Desktop Development tool using the Visual Studio Installer. A lighter installation is to just install the MSVC Build Tools (msvc 14.31+)

2. In your code you can add this import statement to import all the core std modules.
```c++
 import std.core
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
1. You can use /std:latest 



## Influences and References

1. Beginning C++20 From Novice to Professional Sixth Edition by Ivor Horton and Peter Van Weert
2. Bjarne Stroustrop's The C++ Programming language
3. Javid9x (OneLoneCoder) videos
4. Learn Advanced C++ Programming - Advenced C (YouTube Channel)
5. Dmitry Nesteruk- Design Patterns and Modern CPP
6. Jason Turner YouTube Channel
7. Rainer Grimm
8. CopperSpice YouTube Channel
9. The Cherno YouTube Channel

