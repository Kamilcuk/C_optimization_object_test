
all:
%:
	cmake -H. -BBuild 
	$(MAKE) -CBuild $@
	