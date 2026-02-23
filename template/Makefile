.PHONY: run format clean

cpp_version = c++20
src_file = main.cc
executable = main
includes = /opt/homebrew/Cellar/gcc/12.2.0/include/c++/12

OS := $(shell uname)
ifeq ($(OS),Darwin)
includes_apple = /opt/homebrew/Cellar/gcc/12.2.0/include/c++/12/aarch64-apple-darwin22
else
includes_apple = 
endif

run: $(executable)
	timeout 2s ./$(executable) < input.in > output.out 2> error.err

$(executable): $(src_file) dyslevium.h.gch
	g++ -I $(includes) -I $(includes_apple) -std=$(cpp_version) -Wshadow -Wall -H -include dyslevium.h -D DYSLEVIUM -o $(executable) -Wno-unused-result $(src_file)

#	precompiling all required headers in custom header
dyslevium.h.gch: dyslevium.h
	g++ -I $(includes) -I $(includes_apple) -std=$(cpp_version) -H -x c++-header -o dyslevium.h.gch -c dyslevium.h

format: $(src_file)
	cp $(src_file) $(src_file).bak
	clang-format $(src_file).bak > $(src_file)
	rm $(src_file).bak

clean:
	rm -f $(executable) output.out error.err dyslevium.h.gch
