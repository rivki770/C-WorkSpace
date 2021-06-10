#ifndef _CALCULATOR
#define _CALCULATOR

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef unsigned int size_t;

typedef enum { F, T } boolean;

typedef struct NumberComplex_t {
    double realNumber; //for the alone number
    double complexNumber; //for the i number
    char signComplex;
} NumberComplex;

typedef union NumberData_t {
    double is_real;
    NumberComplex is_complex;
} NumberData;

typedef struct Number_t {
    NumberData number;
    boolean is_Real;
} Number;


void Creat_number(Number *number, char typeNumber);

void Result(Number *n1, Number *n2, char sign, Number *result);

void Add(Number *n1, Number *n2, Number *result);

void Sub(Number *n1, Number *n2, Number *result);

void Mul(Number *n1, Number *n2, Number *result);

void Div(Number *n1, Number *n2, Number *result);

void Create_tzamud(Number *number, Number *tzamudNumber);

void PrintFormat(Number *n1, Number *n2, char signn, Number *result);

void NumberToString(Number *number);

#endif // !_CALCULATOR
