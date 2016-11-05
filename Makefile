
OBJS=scanner.o parser.o ast.o interpreter.o
INTERM=scanner.c parser.c parser.h
PROGRAM=./interpreter
CFLAGS=-g
MATHLAB_EXAMPLES_FOLDER=mathlab-examples

all: $(PROGRAM)

scanner.c: scanner.flex parser.h
	flex -o scanner.c scanner.flex

parser.c parser.h: parser.bison
	bison --defines=parser.h -o parser.c parser.bison

$(PROGRAM): $(OBJS)
	$(CC) -o $(PROGRAM) $(OBJS)
clean:
	rm -f $(PROGRAM) $(OBJS) $(INTERM)

test: $(PROGRAM)
	$(PROGRAM) $(MATHLAB_EXAMPLES_FOLDER)/arithmeticOperators.m
	$(PROGRAM) $(MATHLAB_EXAMPLES_FOLDER)/arithmeticOperators2.m
	$(PROGRAM) $(MATHLAB_EXAMPLES_FOLDER)/fibonacci.m
	$(PROGRAM) $(MATHLAB_EXAMPLES_FOLDER)/forExample.m
	$(PROGRAM) $(MATHLAB_EXAMPLES_FOLDER)/forExample2.m
	$(PROGRAM) $(MATHLAB_EXAMPLES_FOLDER)/ifExample.m
	$(PROGRAM) $(MATHLAB_EXAMPLES_FOLDER)/ifExample2.m
	$(PROGRAM) $(MATHLAB_EXAMPLES_FOLDER)/ifExample3.m
	$(PROGRAM) $(MATHLAB_EXAMPLES_FOLDER)/ifExample4.m
	$(PROGRAM) $(MATHLAB_EXAMPLES_FOLDER)/inputExample.m
	$(PROGRAM) $(MATHLAB_EXAMPLES_FOLDER)/isPerfectSquare.m
	$(PROGRAM) $(MATHLAB_EXAMPLES_FOLDER)/relationalOperators.m
	$(PROGRAM) $(MATHLAB_EXAMPLES_FOLDER)/whileExample.m
	$(PROGRAM) $(MATHLAB_EXAMPLES_FOLDER)/whileExample2.m
