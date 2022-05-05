

DRIVER_NAME = main
SUBMIT_NAME = submit



a.out: $(DRIVER_NAME).o numbers.o
	g++ -std=c++11 $(DRIVER_NAME).o numbers.o
  
$(DRIVER_NAME).o: $(DRIVER_NAME).cpp $(DRIVER_NAME).h numbers.h
	g++ -std=c++11 -c $(DRIVER_NAME).cpp

numbers.o: numbers.cpp numbers.h
	g++ -std=c++11 -c numbers.cpp 


.PHONY: submit clean

submit:
	rm -f $(SUBMIT_NAME).zip
	zip $(SUBMIT_NAME).zip Makefile $(DRIVER_NAME).cpp $(DRIVER_NAME).h numbers.cpp numbers.h

clean:
	rm -f a.out *.o