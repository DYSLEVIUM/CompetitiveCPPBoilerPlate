# # CompetitiveCppBoilerplate

This is a simple boilerplate code that I use in my competitive programming.

# # How to use?

Copy the file under library and start solving problems in the solve method.

# # How to use?

Compile using the command -
**`g++ -std=c++17 -Wshadow -Wall main.cpp -o a.exe -O2 -Wno-unused-result -DLOCAL_PROJECT`**

Build using the command -
**`g++ -g -std=c++17 -Wshadow -Wall main.cpp -o a.exe -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -DLOCAL_PROJECT`**

NOTE :- Make sure you have the inputs in another file named **"input.txt"**.

# # FAQs

1. If you get the error - **cannot open source file "bits/stdc++.h" **, make sure that your IDE's include path contains the **bits** folder from MinGW.

2. To get output in the **"output.txt"** file, pass the **"-DONLINE_JUDGE"** flag.
