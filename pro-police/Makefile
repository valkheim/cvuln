all: with without

with:
	gcc -g -fstack-protector -o with simple.c 

without:
	gcc -g -o without simple.c 

clean:
	rm with without
