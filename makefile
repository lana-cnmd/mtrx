# all, clean, test, s21_matrix_oop.a

FLAGS = -Wall -Wextra -Werror
FILES = s21_matrix_oop.cc
GTEST = -lgtest -lgtest_main


all: test

test: clean 
	g++ ${FLAGS} tests_s21_matrix.cc -c 
	g++ ${FLAGS} ${FILES} tests_s21_matrix.o -o test ${GTEST}
	./test

clean:
	rm -rf *.o test
