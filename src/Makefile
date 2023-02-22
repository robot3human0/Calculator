CFLAGS=-std=c11 -Wall -Werror -Wshadow -Wextra

ifeq ($(shell uname), Linux)
	CHKFLAGS=-pthread -lcheck_pic -pthread -lrt -lm -lsubunit
else
	CHKFLAGS=-lcheck
endif

all: clean run

install:
	mkdir -p build
	qmake front/calcuta.pro -o build/
	cd build; make
	cd ../
	mkdir -p app
	cp -r build/calcuta.app app/

run: install
	./app/calcuta.app/Contents/MacOS/calcuta

uninstall:
	@rm -rf app

test:
	gcc $(CFLAGS) --coverage calc_test.c back/polka.c back/stack.c $(CHKFLAGS) 
	./a.out

dvi: 
	open documentation.html

gcov_report:
	gcc $(CFLAGS) --coverage back/polka.c -c -o polka_coverage.o
	gcc $(CFLAGS) --coverage back/stack.c -c -o stack_coverage.o
	gcc $(CFLAGS) --coverage calc_test.c -c -o test_coverage.o
	gcc $(CFLAGS) polka_coverage.o stack_coverage.o test_coverage.o -o $@ $(CHKFLAGS)  -lgcov
	./$@
	gcovr --html --html-details -o report.html
	open report.html

dist:
	mkdir -p Smartcalc
	cp -r back Smartcalc
	cp -r front Smartcalc
	cp Makefile Smartcalc
	cp calc_test.c Smartcalc
	cp documentation.html Smartcalc
	tar -czf Smartcalc.tar Smartcalc
	rm -rf Smartcalc

clean:
	@rm -rf *.a *.o *.out tests gcov_report *.gcda *.gcno *.tar Smartcalc
	@rm -rf report.css report.calc_test.* report.functions.html report.html report.polka.c.* report.stack.c.*
	@rm -rf build

style:
	clang-format -style=google -i back/*.c
	clang-format -style=google -i back/*.h
	clang-format -style=google -n back/*.c
	clang-format -style=google -n back/*.h
	clang-format -style=google -i front/*.cpp
	clang-format -style=google -i front/*.h
