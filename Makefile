CPP= g++
CFLAGS= -O3 #-fopenmp

all: 
	$(CPP) $(CFLAGS) *.cpp -o binp
        
clean:
	rm -f binp *.o
