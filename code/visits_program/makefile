
sources=main.cpp visits_menu.cpp writeInFile.cpp input.cpp gotoxy.cpp
src=src/main.cpp src/visits_menu.cpp src/writeInFile.cpp src/get_id.cpp ../src/input.cpp ../src/gotoxy.cpp ../src/text_with_timer.cpp
objects=$(src:.cpp=.o)
executble=visits_program.exe
lcovtest=$(executble:.exe=.info) 

all : $(src) $(executble)

$(executble) : $(objects)
	g++ $(objects) -g -o $@

.cpp.o :
	g++ -c $< -g -o $@

clean_o :
	rm -f src/*.o

clean :
	rm -f src/*.o *.exe

debug :
	gdb $(executble)

gcov :
	g++ $(src) --coverage -o $(executble)
	./$(executble)

lcov :
	lcov -t "program" -o $(lcovtest) -c -d .
	genhtml -o report $(lcovtest)
	rm -f *.gcda
	rm -f *.gcno
	rm -f $(lcovtest)
	rm -f $(executble) 
	firefox report/index.htm

clean_glcov :
	rm -f *.gcda
	rm -f *.gcno
	rm -f $(lcovtest)
	rm -rf report
	rm -f $(executble)

clean_gcda :
	rm -f *.gcda

clean_gcno :
	rm -f *.gcno
