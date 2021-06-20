tempObjects = input.in output.out error.err
cppVersion = c++17

run: reqFiles a
	./a

a: dyslevium.h.gch main.cc
	g++ -std=$(cppVersion) -g -Wshadow -Wall main.cc -D DYSLEVIUM -o a -Ofast -Wno-unused-result

dyslevium.h.gch: dyslevium.h
	g++ -std=$(cppVersion) dyslevium.h

reqFiles:
	touch $(tempObjects)

clean:
	rm a dyslevium.h.gch $(tempObjects)
