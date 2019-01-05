sort : main.o Sort.o 
	clang++ main.o Sort.o -o sort

main.o : main.cpp Sort.h 
	clang++ -c main.cpp 

Sort.o : Sort.cpp Sort.h
	clang++ -c Sort.cpp 

clean : 
	rm -f *.o sort