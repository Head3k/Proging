all: stock fixed

stock: lab1.c lab2.c lab3.c lab4.c
	gcc lab1.c -o build/lab1 -g3
	gcc lab2.c -o build/lab2 -g3
	gcc lab3.c -o build/lab3 -g3
	gcc lab4.c -o build/lab4 -g3

fixed: 1_lab1.c 1_lab2.c 1_lab3.c 1_lab4.c
	gcc 1_lab1.c -o build/1_lab1 -g3
	gcc 1_lab2.c -o build/1_lab2 -g3
	gcc 1_lab3.c -o build/1_lab3 -g3
	gcc 1_lab4.c -o build/1_lab4 -g3

strun1:
	./build/lab1
strun2:
	./build/lab2
strun3:
	./build/lab3
strun4:
	./build/lab4
fxrun1:
	./build/1_lab1
fxrun2:
	./build/1_lab2
fxrun3:
	./build/1_lab3
fxrun4:
	./build/1_lab4

clean:
	rm -rf build/lab1
	rm -rf build/lab2
	rm -rf build/lab3
	rm -rf build/lab4
	rm -rf build/1_lab1
	rm -rf build/1_lab2
	rm -rf build/1_lab3
	rm -rf build/1_lab4

