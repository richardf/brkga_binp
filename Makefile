# Macros:
CPP= g++
CFLAGS= -O3 #-fopenmp

# Targets:
all: 
	$(CPP) $(CFLAGS) *.cpp -o binp
        
# Remove:
clean:
	rm -f binp *.o
