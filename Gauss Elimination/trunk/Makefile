all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: test1 test2 test3 test4
test1:
	bin/gauss test/test1/A test/test1/b > test/test1/output.txt
	cmp --silent test/test1/correct.txt test/test1/output.txt && echo 'Test1: Suksces' || echo 'Test1: Blad'
test2:
	bin/gauss test/test2/A test/test2/b > test/test2/output.txt
	cmp --silent test/test2/correct.txt test/test2/output.txt && echo 'Test2: Suksces' || echo 'Test2: Blad'
test3:
	bin/gauss test/test3/A test/test3/b > test/test3/output.txt
	cmp --silent test/test3/correct.txt test/test3/output.txt && echo 'Test3: Suksces' || echo 'Test3: Blad'
test4:
	bin/gauss test/test4/A test/test4/b > test/test4/output.txt
	cmp --silent test/test4/correct.txt test/test4/output.txt && echo 'Test4: Suksces' || echo 'Test4: Blad'
