all:
	@echo "compilando"
	gcc -c arvore.c -o arvore.o
	gcc main.c arvore.o -o main

run:
	./main

clean:
	rm *.o
	rm main
