
.DEFAULT_GOAL: build read clean

run: build read clean

build: write_test.c write.c write.h
	gcc -o tests $^  -lcunit

read:
	./tests

clean:
	rm tests