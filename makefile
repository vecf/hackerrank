all: run0 run1
	
a.out: main.cpp solution.cpp makefile
	g++ main.cpp

run0: a.out
	cat input_0.txt | ./a.out | tee out_0.txt

run1: a.out
	cat input_1.txt | ./a.out | tee out_1.txt

test0: run0
	vimdiff out_0.txt expect_0.txt

test1: run1
	vimdiff out_1.txt expect_1.txt

testunlock1: a.out
	cat unlockeds/unlocked_input01.txt | ./a.out > unlockeds/unlocked_out1.txt
	vimdiff unlockeds/unlocked_expected01.txt unlockeds/unlocked_out1.txt

clean:
	rm -f out_0.txt out_1.txt out_2.txt unlockeds/unlocked_out1.txt a.out 
