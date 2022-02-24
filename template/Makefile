cpp_version = c++20
src_file = main.cc
executable = main.exe
watch_executable = file_watcher.exe

watch: $(watch_executable)
	./$(watch_executable) 

$(watch_executable): dyslevium.h.gch file_watcher.cc
	g++ -std=$(cpp_version) -H file_watcher.cc -o $(watch_executable) 

run: $(executable)
	./$(executable) < input.in > output.out 2> error.err

$(executable): dyslevium.h.gch $(src_file)
	g++ -std=$(cpp_version) -Wshadow -Wall -H $(src_file) -D DYSLEVIUM -o $(executable) -Wno-unused-result

#	precompiling all required headers in custom header
dyslevium.h.gch: dyslevium.h
	g++ -std=$(cpp_version) -H -x c++-header -o dyslevium.h.gch -c dyslevium.h

format: $(src_file)
	cp $(src_file) $(src_file).bak
	clang-format $(src_file).bak > $(src_file)
	rm $(src_file).bak

clean:
	rm $(watch_executable) $(executable) output.out error.err dyslevium.h.gch
