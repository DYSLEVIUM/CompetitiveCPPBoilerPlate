# CompetitiveCppBoilerplate

This is a simple boilerplate code that I use in my competitive programming.


# How to use?
1. Setup the compiler path in **tasks.json** to the directory of your compiler. (Make sure your environment variable is set, if you want to use it with your terminal.)
2. Copy the folder under library(including the hidden folder .vscode) and start solving problems in the solve method.

# How to use?

Compile using the command -  

**`g++ -std=c++17 -Wshadow -Wall main.cpp -o a.exe -Ofast -Wno-unused-result -DONLINE_JUDGE`**
  
Build using the command -  

**`g++ -g -std=c++17 -Wshadow -Wall main.cpp -o a.exe -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -DLOCAL_PROJECT`**

**NOTE :-** Make sure you have the inputs in another file named **"input.txt"**.

# FAQs

1. If you get the error - **cannot open source file "bits/stdc++.h"**, make sure that the compiler you used contains the **bits** folder from MinGW if using any other compiler like MSVC. Or you can modify VSCode settings ' "C_Cpp.default.includePath" : "**YOUR PATH**" ' manually or use a "c_cpp_properties.json" config file in **.vscode** folder. 
</br></br>(Preferably don't use non - standard header files supported only by GCC, if you are using a template beforehand. Also, a point to note is that the compile time of the program increases; boils down to personal preference **¯\\_(ツ)_/¯**)</br></br>
2. To get output in the Command Line, pass the **"-DLOCAL_PROJECT"** flag.
