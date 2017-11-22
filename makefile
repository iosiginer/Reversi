# Iosi Ginerman
# 332494830

a.out: compileAll
	g++ *.o 
	rm -f *.o

compileAll: *.h *.cpp
	g++ -c *.cpp
