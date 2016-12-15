all: euler 1a.out h 2d3.out

euler: euler.c
	gcc -std=gnu99 -Wall -o euler euler.c -lm

1a.out: euler
	./euler > 1a.out

h: h.c
	gcc -std=gnu99 -Wall -o h h.c -lm

2d3.out: h
	./h > 2d3.out
