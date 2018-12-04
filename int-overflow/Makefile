all:
	gcc -o int-overflow int-overflow.c
	gcc -o int-overflow-fix int-overflow-fix.c
test:
	cvc4 int-overflow.smt2
	cvc4 int-overflow-fix.smt2
clean:
	rm int-overflow
	rm int-overflow-fix
