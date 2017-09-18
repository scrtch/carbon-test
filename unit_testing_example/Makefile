APP := programm
CFLAGS_EXTRA := -Wall -Wextra -Wpedantic -D APP=\"$(APP)\" -I$(PWD)
objects := func.o
LFLAGS := -Llibs -lfunc -lcmocka

all: build tests
clean:
	rm -f *.o libs/libfunc.a tests/func_test tests/*.o
build: $(objects)
	mkdir -p libs
	ar rcs libs/libfunc.a $(objects)
	$(CC) $(CFLAGS_EXTRA) main.c $(LFLAGS) -o $(APP)
tests: $(objects) libs/libfunc.a
	$(CC) $(CFLAGS_EXTRA) tests/func_test.c $(LFLAGS) -o tests/func_test
