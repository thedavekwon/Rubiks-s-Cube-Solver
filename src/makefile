.PHONY: clean debug run

rubsolver.exe: main.cpp Cube.hpp Solver.hpp
	g++ -std=c++11 -o rubsolver.exe main.cpp Cube.hpp Solver.hpp

debug:
	g++ -std=c++11 -g -o rubsolver.exe main.cpp

clean:
	rm -f *.exe *.o *.stackdump *~

backup:
	test -d backups || mkdir backups
	cp *.cpp backups
	cp *.hpp backups