all: run0 run1
	
a.out: main.cpp solution.cpp makefile
	g++ main.cpp

run0: a.out
	cat input_0.txt | ./a.out | tee out_0.txt

run1: a.out
	cat input_1.txt | ./a.out | tee out_1.txt

run2: a.out
	cat input_2.txt | ./a.out | tee out_2.txt

test0: run0
	vimdiff out_0.txt expect_0.txt

test1: run1
	vimdiff out_1.txt expect_1.txt

clean:
	rm -f out_0.txt out_1.txt out_2.txt a.out 
