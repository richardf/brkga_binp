# Macros:
CPP= g++
CFLAGS= -O3 #-fopenmp

# Targets:
all: 
	$(CPP) $(CFLAGS) SampleDecoder.cpp samplecode.cpp -o samplecode
        
# Remove:
clean:
	rm -f samplecode SampleDecoder.o
