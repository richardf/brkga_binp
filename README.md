BRKGA for 1D bin packing problem
==========

Implementation of a Biased Random-Key Genetic Algorithm (BRKGA) for the one-dimensional bin packing problem.

The BRKGA framework utilized was developed by
_Toso, R. F., & Resende, M. G. (2012). A C++ application programming interface for biased random-key genetic algorithms. Technical report, AT&T Labs Research, Florham Park, NJ._

The files in 'instances' folder are from [OR-Library](http://people.brunel.ac.uk/~mastjjb/jeb/orlib/binpackinfo.html)


##### Usage
```bash
$ make
g++ -O3  *.cpp -o binp

$ ./binp
Usage:
        -i      Input file
        -p      Size of population (default: 1000)
        -e      Fraction of population to be elite (default: 0.2)
        -m      Fraction of population to be replaced by mutants (default: 0.1)
        -n      Probability that offspring inherit an allele from elite parent (default: 0.7)
        -k      Number of independent populations (default: 1)
        -s      Random seed (default: 0)
        -g      Number of generations (default: 100)
        -t      Number of threads (default: 1)
        
$ ./binp -i instances/t60_00 -p 100
21 2.37
```
