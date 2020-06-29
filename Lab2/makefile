all:main

main: src/main.c src/IntVector.c
	gcc -o main -I src src/main.c src/IntVector.c
	tree

test: src/main.c src/IntVector.c
	gcc -o main -I src src/main.c src/IntVector.c
	tree
	./main
	rm -rf main
	tree

run: src/main.c src/IntVector.c
	gcc -Wall -o main -I src src/main.c src/IntVector.c
	tree
	./main

clean:
	rm -rf main
	tree
