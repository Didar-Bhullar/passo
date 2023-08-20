build:
	gcc -o main main.c rules.c -Wall -Wextra

run:
	./main

clean:
	rm -rf main 