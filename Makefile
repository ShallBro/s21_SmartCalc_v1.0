CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 -g -c
CTESTFLAGS=-lcheck -lm -lpthread
GCOV_FLAGS=--coverage -Wall -Wextra -Werror
CFILES=$(wildcard calculator/*.c)
OBJ = $(CFILES:.c=.o)
# $(wildcard tests/*.c)
# tests/test_calculate.c
TESTS_CFILES = $(wildcard tests/*.c)
TESTS_OBJ = $(TESTS_CFILES:.c=.o)
LIBRARY = s21_SmartCalculator.a
EXECUTABLE = s21_calc


ifeq ($(shell uname -s),Linux)
	CTESTFLAGS += -lrt
endif

#-lsubunit

all: $(LIBRARY) clean

$(LIBRARY) : $(OBJ)
	ar -rc $(LIBRARY) $(OBJ)
	ranlib $(LIBRARY)

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

install:
	cd SmarCalcv1 && qmake && make && make clean
	cp -r SmarCalcv1/SmarCalcv1.app ~/Desktop

uninstall:
	rm -rf SmarCalcv1/SmarCalcv1.app 
	rm -rf ~/Desktop/SmarCalcv1.app
	rm -rf SmarCalcv1/Makefile

dvi:
	open README.md

test: $(TESTS_OBJ) $(LIBRARY)
	$(CC) $^ -o test $(CTESTFLAGS)
	./test

gcov_report: $(TESTS_OBJ)
	$(CC) $(GCOV_FLAGS) $(CTESTFLAGS) $(TESTS_OBJ) $(CFILES) -o test
	./test
	lcov --exclude '/usr/include/math.h' -t "s21_SmartCalculator" -o s21_SmartCalculator.info -c -d .
	genhtml -o report s21_SmartCalculator.info
	open report/index.html

dist: install
	mkdir archiv
	cp -r *.h calculator/*.c Makefile SmarCalcv1/ archiv
	tar -cvzf SmarCalcv1.tar.gz archiv
	rm -rf archiv

checkstyle:
	clang-format -style=google -n tests/*.c
	clang-format -style=google -n tests/*.h
	clang-format -style=google -n calculator/*.c
	clang-format -style=google -n *.h
	clang-format -style=google -n SmarCalcv1/*.cpp
	clang-format -style=google -n SmarCalcv1/*.h
	clang-format -style=google -n SmarCalcv1/build/*.cpp
	clang-format -style=google -n SmarCalcv1/build/*.h

clean:
	rm -rf $(OBJ) $(LIBRARY) $(TESTS_OBJ) test $(EXECUTABLE) *.gcov *.gcno *.gcda *.info report

# test_create:
# 	checkmk tests/calculate.check > tests/test_calculate.c
# 	checkmk clean_mode=1 tests/calculate.check > tests/test_calculate.c


# $(EXECUTABLE) : $(OBJ)
# 	$(CC) $^ -o $@
# 	./$(EXECUTABLE)


# $(filter-out $<,$^)