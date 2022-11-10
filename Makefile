CC = g++ -std=c++17
COMPILE = -Wall -Wextra -pedantic -static
QMAKE_PATH = qmake
TEST_FLAGS = -lgtest -pthread -lgtest_main

all: install run

install: clean
	mkdir ../install
	cp -r Resources/* ../install
	cp settings.conf ~/
	qmake obj_loader.pro -o ../install/Makefile
	make -C ../install/

run:
ifeq ("$(shell test -e ../install/obj_loader.app && echo yes)","yes")
	open ../install/./obj_loader*
else
	make install
	open ../install/./obj_loader*
endif

uninstall:
	rm -rf ../install

clean:
	rm -rf gcov_test
	rm -rf test/exec*
	rm -rf ../install
	rm -rf *.tgz
	rm -rf *.gcno *.gcda *.info check_res
	rm -rf finish

dvi:
	open docs/dvi.pdf

dist:
	tar cvzf ./SmartCalc.tgz ../src/

tests:
	$(CC) model.cpp test.cc $(TEST_FLAGS) -o test
	./test

lint:
	cp ../materials/linters/.clang-format ./
	clang-format -i *.cpp *.h
	clang-format -n *.cpp *.h
	rm -rf .clang-format


.PHONY: all install run uninstall clean dvi dist gcov_report
