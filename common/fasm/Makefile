
.PHONY: all
all: fasm

run: fasm
	cat tests/test1.asc | ./fasm

fasm: fasm.tab.c lex.yy.c
	gcc lex.yy.c -lfl -o $@

fasm.tab.c: fasm.y
	bison -d $^

lex.yy.c: fasm.l
	flex $^

.PHONY: clean
clean:
	rm -f fasm.tab.c fasm.tab.h lex.yy.c a.out fasm
