.PHONY: all run clean
all: clean demo

lex.yy.c: demo.l
	flex $<

demo.tab.h demo.tab.c: demo.y
	bison -d $<
	#bison --debug --verbose -d $<

demo: lex.yy.c demo.tab.c
	gcc $^ -o $@

run: demo
	@./$< < input

clean:
	$(RM) demo demo.tab.* demo.output lex.yy.c
