# standard compile options for the c++ executable
FLAGS = -fPIC

# the python interface through swig
PYTHONI = -I/usr/include/python3.8/
PYTHONL = -Xlinker -export-dynamic

# default super-target
all: 
	g++ -fPIC -c cpu.cpp -o cpu.o
	swig -c++ -python -o cpu_wrap.cxx cpu.i 
	g++ $(FLAGS) $(PYTHONI) -c cpu_wrap.cxx -o cpu_wrap.o
	g++ $(PYTHONL) $(LIBFLAGS) -shared cpu.o cpu_wrap.o -o _cpu.so
