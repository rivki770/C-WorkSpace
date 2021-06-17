#include "Calculator.h"

void Creat_number(Number *number, char typeNumber)
{
	double numCComplex, numCReal, numReal;
	switch (typeNumber)
	{
	case 'c':
		(*number).is_Real = F;

		printf("\nPlease enter the complex part (of complex number):\n");
		scanf_s("%lf", &numCComplex);
		(*number).number.is_complex.complexNumber = numCComplex;

		printf("\nPlease enter the real part (of complex number):\n");
		scanf_s("%lf", &numCReal);
		(*number).number.is_complex.realNumber = numCReal;
		(*number).number.is_real = numCReal;

		//the part of complex is 0.
		if ((*number).number.is_complex.complexNumber == 0)
		{
			(*number).is_Real = T;
			break;
		}

		printf("\nPlease enter the complex sign (between the number):\n");
		char sign;
		scanf_s(" %c", &sign);

		if (sign != '+' && sign != '-')
		{
			printf("\nWorng sign, the difault is +.\n");
			(*number).number.is_complex.signComplex = '+';
		}

		else if (sign == '-')
		{
			(*number).number.is_complex.realNumber = ((*number).number.is_complex.realNumber) * (-1);
			(*number).number.is_complex.signComplex = '+';
		}
		else
		{
			(*number).number.is_complex.signComplex = sign;
		}

		break;

	case 'r':
		(*number).is_Real = T;

		printf("\nPlese enter the real number:\n");
		scanf_s("%lf", &numReal);
		(*number).number.is_real = numReal;
		(*number).number.is_complex.realNumber = numReal;

		(*number).number.is_complex.complexNumber = 0;
		break;

	default:
		printf("\nWorng choice, the difault is 0 (real number)\n");
		(*number).is_Real = T;
		(*number).number.is_real = 0;
		(*number).number.is_complex.realNumber = 0;
		(*number).number.is_complex.complexNumber = 0;
		break;
	}
}

void Result(Number *n1, Number *n2, char sign, Number *result)
{
	switch (sign)
	{
	case '+':
		Add(n1, n2, result);
		break;

	case '-':
		Sub(n1, n2, result);
		break;

	case '*':
		Mul(n1, n2, result);
		break;

	case '/':
		Div(n1, n2, result);
		break;

	default:
		printf("\nWorng choice, the difault is +.\n");
		Add(n1, n2, result);
		break;
	}
}

void Add(Number *n1, Number *n2, Number *result)
{
	if ((*n1).is_Real == T && (*n2).is_Real == T)
	{
		(*result).is_Real = T;
		double res = (*n1).number.is_real + (*n2).number.is_real;

		(*result).number.is_real = res;

		(*result).number.is_complex.complexNumber = 0;
		(*result).number.is_complex.realNumber = res;
	}
	else if ((*n1).is_Real == F && (*n2).is_Real == F)
	{
		(*result).is_Real = F;
		double partReal = (*n1).number.is_complex.realNumber + (*n2).number.is_complex.realNumber;
		double partComplex = (*n1).number.is_complex.complexNumber + (*n2).number.is_complex.complexNumber;

		(*result).number.is_real = partReal;

		(*result).number.is_complex.complexNumber = partComplex;
		(*result).number.is_complex.realNumber = partReal;
	}
	else if ((*n1).is_Real == F && (*n2).is_Real == T)
	{
		(*result).is_Real = F;
		double partReal = (*n1).number.is_complex.realNumber + (*n2).number.is_real;
		double partComplex = (*n1).number.is_complex.complexNumber;

		(*result).number.is_real = partReal;

		(*result).number.is_complex.complexNumber = partComplex;
		(*result).number.is_complex.realNumber = partReal;
	}
	else
	{
		Add(n2, n1, result);
	}
}

void Sub(Number *n1, Number *n2, Number *result)
{
	if ((*n1).is_Real == T && (*n2).is_Real == T)
	{
		(*result).is_Real = T;
		double res = (*n1).number.is_real - (*n2).number.is_real;

		(*result).number.is_real = res;

		(*result).number.is_complex.complexNumber = 0;
		(*result).number.is_complex.realNumber = res;
	}
	else if ((*n1).is_Real == F && (*n2).is_Real == F)
	{
		(*result).is_Real = F;
		double partReal = (*n1).number.is_complex.realNumber - (*n2).number.is_complex.realNumber;
		double partComplex = (*n1).number.is_complex.complexNumber - (*n2).number.is_complex.complexNumber;

		(*result).number.is_real = partReal;

		(*result).number.is_complex.complexNumber = partComplex;
		(*result).number.is_complex.realNumber = partReal;
	}
	else if ((*n1).is_Real == F && (*n2).is_Real == T)
	{
		(*result).is_Real = F;
		double partReal = (*n1).number.is_complex.realNumber - (*n2).number.is_real;
		double partComplex = (*n1).number.is_complex.complexNumber;

		(*result).number.is_real = partReal;

		(*result).number.is_complex.complexNumber = partComplex;
		(*result).number.is_complex.realNumber = partReal;
	}
	else //((*n1).is_Real == T && (*n2).is_Real == F)
	{
		(*result).is_Real = F;
		double partReal = (*n1).number.is_real - (*n2).number.is_complex.realNumber;
		double partComplex = (*n2).number.is_complex.complexNumber;

		(*result).number.is_real = partReal;

		(*result).number.is_complex.complexNumber = partComplex;
		(*result).number.is_complex.realNumber = partReal;
	}
}

void Mul(Number *n1, Number *n2, Number *result)
{
	if ((*n1).is_Real == T && (*n2).is_Real == T)
	{
		(*result).is_Real = T;
		double res = (*n1).number.is_real * (*n2).number.is_real;

		(*result).number.is_real = res;

		(*result).number.is_complex.complexNumber = 0;
		(*result).number.is_complex.realNumber = res;
	}
	else if ((*n1).is_Real == F && (*n2).is_Real == F)
	{
		(*result).is_Real = F;
		double partReal = ((*n1).number.is_complex.realNumber) * ((*n2).number.is_complex.realNumber);
		partReal += (((*n1).number.is_complex.complexNumber) * ((*n2).number.is_complex.complexNumber)) * (-1);
		double partComplex = ((*n1).number.is_complex.realNumber) * ((*n2).number.is_complex.complexNumber);
		partComplex += ((*n1).number.is_complex.complexNumber) * ((*n2).number.is_complex.realNumber);

		(*result).number.is_real = partReal;

		(*result).number.is_complex.complexNumber = partComplex;
		(*result).number.is_complex.realNumber = partReal;
	}
	else if ((*n1).is_Real == F && (*n2).is_Real == T)
	{
		(*result).is_Real = F;
		double partReal = (*n1).number.is_complex.realNumber * (*n2).number.is_real;
		double partComplex = (*n1).number.is_complex.complexNumber * (*n2).number.is_real;

		(*result).number.is_real = partReal;

		(*result).number.is_complex.complexNumber = partComplex;
		(*result).number.is_complex.realNumber = partReal;
	}
	else
	{
		Mul(n2, n1, result);
	}
}

void Div(Number *n1, Number *n2, Number *result)
{
	if ((*n1).is_Real == T && (*n2).is_Real == T)
	{
		if ((*n2).number.is_real == 0)
		{
			printf("\nCannot divide by 0, done + instead.\n");
			Add(n1, n2, result);
			return;
		}

		(*result).is_Real = T;

		double res = (*n1).number.is_real / (*n2).number.is_real;

		(*result).number.is_real = res;

		(*result).number.is_complex.complexNumber = 0;
		(*result).number.is_complex.realNumber = res;
	}
	else if ((*n1).is_Real == F && (*n2).is_Real == F)
	{
		Number tzamudNumber;
		Create_tzamud(n2, &tzamudNumber);

		Number mechane, mone;
		Mul(n1, &tzamudNumber, &mone);
		Mul(n2, &tzamudNumber, &mechane);

		mechane.is_Real = T;

		Div(&mone, &mechane, result);
	}
	else if ((*n1).is_Real == F && (*n2).is_Real == T)
	{
		if ((*n2).number.is_real == 0)
		{
			printf("\nCannot divide by 0, done + instead.\n");
			Add(n1, n2, result);
			return;
		}

		(*result).is_Real = F;

		double partReal = (*n1).number.is_complex.realNumber / (*n2).number.is_real;
		double partComplex = (*n1).number.is_complex.complexNumber / (*n2).number.is_real;

		(*result).number.is_real = partReal;

		(*result).number.is_complex.complexNumber = partComplex;
		(*result).number.is_complex.realNumber = partReal;
	}
	else //((*n1).is_Real == T && (*n2).is_Real == F)
	{
		Number tzamudNumber;
		Create_tzamud(n2, &tzamudNumber);

		Number mechane, mone;
		Mul(n1, &tzamudNumber, &mone); //real*tzamudComplex = complex
		Mul(n2, &tzamudNumber, &mechane); //complex*tzamudComplex = real

		mechane.is_Real = T;

		Div(&mone, &mechane, result);
	}
}

void Create_tzamud(Number *number, Number *tzamudNumber)
{
	(*tzamudNumber).is_Real = F;
	(*tzamudNumber).number.is_complex.complexNumber = ((*number).number.is_complex.complexNumber * (-1));
	(*tzamudNumber).number.is_complex.realNumber = (*number).number.is_complex.realNumber;

	(*tzamudNumber).number.is_real = (*number).number.is_real;
}

void PrintFormat(Number *n1, Number *n2, char signn, Number *result)
{
	printf("The result is:\n( ");
	NumberToString(n1);
	printf(" )  %c  ( ", signn);
	NumberToString(n2);
	printf(" )  =  ( ");
	NumberToString(result);
	printf(" )\n\n");
}

void NumberToString(Number *number)
{
	if ((*number).is_Real == F)
	{
		double complex = (*number).number.is_complex.complexNumber;
		double real = (*number).number.is_complex.realNumber;
		char sign = (*number).number.is_complex.signComplex;
		if (real < 0)
		{
			real *= (-1);
			printf("%f i - %f", complex, real);
		}
		else
		{
			printf("%f i + %f", complex, real);
		}
		return;
	}
	double num = (*number).number.is_real;
	printf("%f", num);
}