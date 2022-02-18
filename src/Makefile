exec: tokenizer.o history.o uimain.o

	gcc -o exec tokenizer.o history.o uimain.o

tokenizer.o: tokenizer.h tokenizer.c

history.o: tokenizer.c history.h history.c

uimain.o: history.o uimain.c

clean:
	rm -f *.o exec
