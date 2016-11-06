=============================================================
|  _ \                | |             | (_)     | |
| |_) | ___  _ __ ___ | |__   __ _  __| |_ _ __ | |__   ___
|  _ < / _ \| '_ ` _ \| '_ \ / _` |/ _` | | '_ \| '_ \ / _ \
| |_) | (_) | | | | | | |_) | (_| | (_| | | | | | | | | (_) |
|____/ \___/|_| |_| |_|_.__/ \__,_|\__,_|_|_| |_|_| |_|\___/
=============================================================
                By João Estrela (DCC/FCUP)

Bombadinho is a Mathlab/GNU Octave Syntax Analyser (for now...)

Syntax Analyser files included:
   - scanner.flex : the lexical analyser (scanner) in flex
   - parser.bison: the parser in bison
   - ast.h, ast.c: AST declarations & constructor implementations
   - interpreter.c: the interpreter routines including main
   - Makefile: makefile to build the interpreter.

There are a few mathlab-examples included aswell so you can test that Bombadinho actually does what he says he does !

The Makefile has several routines to help you out using this powerfull tool!
How to use it:
  make all - compiles everying it needs to compile to run !
  make clean - cleans any residual files created by a previous compilation
  make test - tests Bombadinho with the mathlab-examples provided
