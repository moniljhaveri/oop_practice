CXX=g++
make: main.o BankAccount.o  
	$(CXX) -o BankAccount main.o BankAccount.o

clean: 
	rm *.o 
	rm  BankAccount