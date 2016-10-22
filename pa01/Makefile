pa01.pdf: pa01.tex secantE.c secantE.out secantM.c secantM.out fpoint.c fpoint.out newtonE.c newtonE.out newtonM.c newtonM.out
	xelatex pa01.tex

newtonE: newtonE.c
	gcc -o newtonE newtonE.c -Wall

newtonE.out: newtonE
	./newtonE > newtonE.out

newtonM: newtonM.c
	gcc -o newtonM newtonM.c -Wall

newtonM.out: newtonM
	./newtonM > newtonM.out

secantE: secantE.c
	gcc -o secantE secantE.c -Wall -lm

secantE.out: secantE
	./secantE > secantE.out

secantM: secantM.c
	gcc -o secantM secantM.c -Wall -lm

secantM.out: secantM
	./secantM > secantM.out

fpoint: fpoint.c
	gcc -o fpoint fpoint.c -Wall

fpoint.out: fpoint
	./fpoint > fpoint.out
