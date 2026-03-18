
.PHONY: all
all: fasm

run: fasm
	cat tests/test.fasm | ./fasm

fasm: fasm.tab.c lex.yy.c
	gcc fasm.tab.c lex.yy.c -lfl -o $@

fasm.tab.c: bison
yacc: bison
bison: fasm.y
	bison -d $^

lex.yy.c: flex
lex: flex
flex: fasm.l
	flex $^

.PHONY: clean
clean:
	rm -f fasm.tab.c fasm.tab.h lex.yy.c a.out fasm
