
.PHONY: all
all: pldconf

run: pldconf
	cat tests/test.pldconf | ./pldconf

pldconf: pldconf.tab.c lex.yy.c
	gcc pldconf.tab.c lex.yy.c -lfl -o $@

pldconf.tab.c: bison
yacc: bison
bison: pldconf.y
	bison -d $^

lex.yy.c: flex
lex: flex
flex: pldconf.l
	flex $^

.PHONY: clean
clean:
	rm -f pldconf.tab.c pldconf.tab.h lex.yy.c a.out pldconf
