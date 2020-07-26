%module cpu

%{
    #include "include/cpu.h"
%}

%include <std_string.i>
%include <stdint.i>
%include <std_vector.i>
%include "include/cpu.h"

%typedef unsigned char uint8_t;
%template(VectorUChar) std::vector<uint8_t>;
