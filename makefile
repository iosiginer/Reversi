# Josef Ginerman 332494830
# Barak Talmor 308146240

a.out: compileAll
	g++ *.o 
	rm -f *.o

compileAll: *.h *.cpp
	g++ -c *.cpp
