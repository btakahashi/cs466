pa01.pdf: pa01.tex newton.c newton.out secant.c secant.out fpoint.c fpoint.out
	xelatex pa01.tex

newton: newton.c
	gcc -o newton newton.c -Wall

newton.out: newton
	./newton > newton.out

secant: secant.c
	gcc -o secant secant.c -Wall -lm

secant.out: secant
	./secant > secant.out

fpoint: fpoint.c
	gcc -o fpoint fpoint.c -Wall

fpoint.out: fpoint
	./fpoint > fpoint.out
