cpp_version = c++20
src_file = main.cc
executable = main.exe

run: $(executable)
	./$(executable) < input.in > output.out 2> error.err

$(executable): dyslevium.h.gch $(src_file)
	g++ -std=$(cpp_version) -g -Wshadow -Wall -H $(src_file) -D DYSLEVIUM -o $(executable) -Ofast -Wno-unused-result

#	precompiling all required headers in custom header
dyslevium.h.gch: 
	g++ -std=$(cpp_version) -H -x c++-header -o dyslevium.h.gch -c dyslevium.h

format: $(src_file)
	cp $(src_file) $(src_file).bak
	clang-format $(src_file).bak > $(src_file)
	rm $(src_file).bak

clean:
	rm $(executable) dyslevium.h.gch
