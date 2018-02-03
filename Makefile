CXX=g++
CXXFLAGS=-g
make: main.o BankAccount.o Person.o List.o 
	$(CXX) $(CXXFLAGS) -o test main.o BankAccount.o Person.o List.o 

clean: 
	rm *.o 
	rm test