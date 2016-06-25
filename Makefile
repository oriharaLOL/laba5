INCLUDES = -I src/ -I thirdparty/
dirs = ./bin ./obj
test_obj = ./obj/main_test.o ./obj/roots.o  ./obj/test.o
main_obj = ./obj/main.o ./obj/roots.o 

all: ./bin/main ./bin/test testo

./bin/main: $(dirs) $(main_obj)
	gcc $(main_obj) -Wall -o ./bin/main -lm

./bin/test: $(dirs) $(test_obj)
	gcc $(test_obj) -Wall -o ./bin/test -lm

testo:
	./bin/test

$(dirs):
	mkdir obj
	mkdir bin

./obj/main.o: ./src/main.c
	gcc -c ./src/main.c -Wall -o ./obj/main.o $(INCLUDES)

./obj/roots.o: ./src/roots.c
	gcc -c ./src/roots.c -Wall -o ./obj/roots.o $(INCLUDES)

./obj/main_test.o: ./test/main.c
	gcc -c ./test/main.c -Wall -o ./obj/main_test.o $(INCLUDES)

./obj/test.o: ./test/test.c
	gcc -c ./test/test.c -Wall -o ./obj/test.o $(INCLUDES)

.PHONY: clean
clean:
	rm -rf bin/ obj/