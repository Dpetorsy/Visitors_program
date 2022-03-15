
sources=main.cpp start_menu.cpp sign_in.cpp sign_up.cpp home.cpp my_profile.cpp my_visits.cpp edit_profile.cpp input.cpp gotoxy.cpp random_number.cpp captcha.cpp text_with_timer.cpp determine_gender.cpp confirm_change.cpp
src=$(sources:%.cpp=src/%.cpp)
objects=$(src:.cpp=.o)
executble=program.exe
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
	firefox report/index.html

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
