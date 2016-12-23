diff: diff.o
	gcc -o diff diff.o
diff.o: diff.c
	gcc -c diff.c
