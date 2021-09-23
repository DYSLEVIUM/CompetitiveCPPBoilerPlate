tempObjects = input.in output.out error.err
cppVersion = c++17

run: reqFiles a.exe
	./a.exe

a.exe: dyslevium.h.gch main.cc
	g++ -std=$(cppVersion) -g -Wshadow -Wall main.cc -D DYSLEVIUM -o a.exe -Ofast -Wno-unused-result

#	precompiling all required headers in custom header
dyslevium.h.gch: dyslevium.h
	g++ -std=$(cppVersion) dyslevium.h

reqFiles:
	touch $(tempObjects)

clean:
	rm a.exe dyslevium.h.gch $(tempObjects)
