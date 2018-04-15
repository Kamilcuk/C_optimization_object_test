B=Build
all:
%:
	cmake -H. -B$B
	$(MAKE) -C$B $@
test: all
	memusage $B/num1
	memusage $B/num2
	wc -l $B/num1.asm $B/num2.asm
