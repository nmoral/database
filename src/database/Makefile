
.DEFAULT_GOAL: build read clean

run: build read clean


build: database_test.c database.c database.h
	gcc -o tests $^  -lcunit

read:
	./tests

clean:
	rm tests