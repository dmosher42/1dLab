
CCC = g++
CCFLAGS = -ansi

1dlife: container.o common.o universe.o 1dlife.o 
	$(CCC) -o 1dlife container.o common.o universe.o 1dlife.o 

1dlife.o: container.h entry.h universe.h

common.o: common.h

container.o: container.h listnode.h listnode_inl.h entry.h common.h

universe.o: container.h entry.h universe.h

arraycontainer:
	rm -f container.h container.cc
	ln -s Container/Array/container.h .
	ln -s Container/Array/container.cc .
	touch container.cc container.h

listcontainer:
	rm -f container.h container.cc
	ln -s Container/List/container.h .
	ln -s Container/List/container.cc .
	touch container.cc container.h

version1 : 
	rm universe.cc
	ln -s universe_v1.cc universe.cc
	touch universe.cc

version2 : 
	rm universe.cc
	ln -s universe_v2.cc universe.cc
	touch universe.cc

version3 : 
	rm universe.cc
	ln -s universe_v3.cc universe.cc
	touch universe.cc

version4 : 
	rm universe.cc
	ln -s universe_v4.cc universe.cc
	touch universe.cc

clean:
	rm -f *.o

real_clean: clean
	rm -f 1dlife
