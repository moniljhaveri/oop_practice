CXX=g++
make: main.o BankAccount.o Person.o
	$(CXX) -o test main.o BankAccount.o Person.o

clean: 
	rm *.o 
	rm test