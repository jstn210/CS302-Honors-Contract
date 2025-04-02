dictionary: driver.o 
	g++ driver.o -o dictionary

driver.o: driver.cpp arrayDictionary.h entry.h
	g++ -c driver.cpp

clean:
	rm *.o dictionary