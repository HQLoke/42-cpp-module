#include "../include/Fixed.hpp"
#include <stdlib.h>
#include <stdio.h>

#define RESET		"\033[0m"
#define RED 		"\033[31m"  
#define BOLD_RED	"\033[1m\033[31m"

void	print_KO(void)
{
	printf(BOLD_RED "KO.........\n"RESET);
}

void	test_int_constructor(void)
{
	std::cout << "Testing int constructor\n";
	int i_val[] = {-999, -1, 0, 1, 9, 199, 999, 10000, 30000, 80000, 999999, 8333333};
	for (size_t i = 0; i < sizeof(i_val)/sizeof(i_val[0]); i += 1)
	{
		Fixed a(i_val[i]);
		if (a.toInt() == i_val[i])
			printf("OK!\n");
		else
		{
			print_KO();
			std::cout << "Test: " << i_val[i] << std::endl;
			std::cout << "Mine: " << a.toInt() << std::endl;
 		}
	}
}
void	test_float_constructor(void)
{
	std::cout << "Testing float constructor\n";
	float f_val[] = {-1.234f, 0.0f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512};
	for (size_t i = 0; i < sizeof(f_val)/sizeof(f_val[0]); i += 1)
	{
		Fixed a(f_val[i]);
		if (a.toFloat() - f_val[i] < 1 / pow(2, 8))
			printf("OK!\n");
		else
		{
			print_KO();
			std::cout << "Test: " << f_val[i] << std::endl;
			std::cout << "Mine: " << a.toFloat() << std::endl;
 		}
	}
}
void	test_copy_constructor(void)
{
	std::cout << "Testing copy constructor\n";

	int i_val[] = {-1, 0, 1, 9, 199, 999, 10000, 30000, 80000, 999999, 20000000};
	for (size_t i = 0; i < sizeof(i_val)/sizeof(i_val[0]); i += 1)
	{
		Fixed a(i_val[i]);
		Fixed b(a);

		if (a.getRawBits() == b.getRawBits())
			printf("OK!\n");
		else
			print_KO();
	}

	float f_val[] = {-1.234f, 0.0f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512};
	for (size_t i = 0; i < sizeof(f_val)/sizeof(f_val[0]); i += 1)
	{
		Fixed c(f_val[i]);
		Fixed d(c);

		if (c.getRawBits() == d.getRawBits())
			printf("OK!\n");
		else
			print_KO();
	}
}
void	test_copy_assignment(void)
{
	std::cout << "Testing copy assignment\n";

	int i_val[] = {-1, 0, 1, 9, 199, 999, 10000, 30000, 80000, 999999, 20000000};
	for (size_t i = 0; i < sizeof(i_val)/sizeof(i_val[0]); i += 1)
	{
		Fixed a(i_val[i]);
		Fixed b = a;

		if (a.getRawBits() == b.getRawBits())
			printf("OK!\n");
		else
			print_KO();
	}

	float f_val[] = {-1.234f, 0.0f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512};
	for (size_t i = 0; i < sizeof(f_val)/sizeof(f_val[0]); i += 1)
	{
		Fixed c(f_val[i]);
		Fixed d = c;

		if (c.getRawBits() == d.getRawBits())
			printf("OK!\n");
		else
			print_KO();
	}
}
void	test_more(void)
{
	std::cout << "Testing more than\n";
	int i_val1[] = {0, 1, 2, 10, 200, 1000, 10001, 30001, 80001, 1000000, 8333334};
	int i_val2[] = {-1, 0, 1, 9, 199, 999, 10000, 30000, 80000, 999999, 8333333};

	for (size_t i = 0; i < sizeof(i_val1)/sizeof(i_val1[0]); i += 1)
	{
		Fixed a(i_val1[i]);
		Fixed b(i_val2[i]);

		if (a > b)
			printf("OK!\n");
		else	
			print_KO();
	}

	float f_val1[] = {-9.614f, -1.232f, 0.1f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512};
	float f_val2[] = {-9.615f, -1.233f, 0.0f, 1.233f, 9.875f, 199.122f, 999.9122f, 9999.512, 99999.3511};
	for (size_t i = 0; i < sizeof(f_val1)/sizeof(f_val1[0]); i += 1)
	{
		Fixed a(f_val1[i]);
		Fixed b(f_val2[i]);
		if (a > b)
			printf("OK!\n");
		else
		{
			printf(BOLD_RED"KO.........\n");
			printf("Ori A is %f, ori B is %f\n", f_val1[i], f_val2[i]);
			printf("    A is %f,     B is %f\n" RESET, a.toFloat(), b.toFloat());
		}
	}
}
void	test_less(void)
{
	std::cout << "Testing less\n";
	int i_val1[] = {-1, 0, 1, 9, 199, 999, 10000, 30000, 80000, 999999, 8333333};
	int i_val2[] = {0, 1, 2, 10, 200, 1000, 10001, 30001, 80001, 1000000, 8333334};

	for (size_t i = 0; i < sizeof(i_val1)/sizeof(i_val1[0]); i += 1)
	{
		Fixed a(i_val1[i]);
		Fixed b(i_val2[i]);

		if (a < b)
			printf("OK!\n");
		else	
		{
			printf(BOLD_RED"KO.........\n");
			printf("Ori A is %i, ori B is %i\n", i_val1[i], i_val2[i]);
			printf("    A is %i,     B is %i\n" RESET, a.toInt(), b.toInt());
		}
	}

	float f_val1[] = {-9.615f, -1.233f, 0.0f, 1.233f, 9.875f, 199.122f, 999.9122f, 9999.512, 99999.3511};
	float f_val2[] = {-9.614f, -1.232f, 0.1f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512};
	for (size_t i = 0; i < sizeof(f_val1)/sizeof(f_val1[0]); i += 1)
	{
		Fixed a(f_val1[i]);
		Fixed b(f_val2[i]);
		if (a < b)
			printf("OK!\n");
		else
		{
			printf(BOLD_RED"KO.........\n");
			printf("Ori A is %f, ori B is %f\n", f_val1[i], f_val2[i]);
			printf("    A is %f,     B is %f\n" RESET, a.toFloat(), b.toFloat());
		}
	}
}
void	test_more_equal(void)
{
	std::cout << "Testing more equal\n";
	int i_val1[] = {0, 1, 2, 10, 200, 1000, 10001, 30001, 80001, 1000000, 8333334};
	int i_val2[] = {0, 1, 2, 10, 200, 1000, 10001, 30001, 80001, 1000000, 8333334};

	for (size_t i = 0; i < sizeof(i_val1)/sizeof(i_val1[0]); i += 1)
	{
		Fixed a(i_val1[i]);
		Fixed b(i_val2[i]);

		if (a >= b)
			printf("OK!\n");
		else	
			print_KO();
	}

	float f_val1[] = {-9.614f, -1.232f, 0.1f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512};
	float f_val2[] = {-9.614f, -1.232f, 0.1f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512};
	for (size_t i = 0; i < sizeof(f_val1)/sizeof(f_val1[0]); i += 1)
	{
		Fixed a(f_val1[i]);
		Fixed b(f_val2[i]);
		if (a >= b)
			printf("OK!\n");
		else
		{
			printf(BOLD_RED"KO.........\n");
			printf("Ori A is %f, ori B is %f\n", f_val1[i], f_val2[i]);
			printf("    A is %f,     B is %f\n" RESET, a.toFloat(), b.toFloat());
		}
	}
}
void	test_less_equal(void)
{
	std::cout << "Testing less equal\n";
	int i_val1[] = {0, 1, 2, 10, 200, 1000, 10001, 30001, 80001, 1000000, 8333334};
	int i_val2[] = {0, 1, 2, 10, 200, 1000, 10001, 30001, 80001, 1000000, 8333334};

	for (size_t i = 0; i < sizeof(i_val1)/sizeof(i_val1[0]); i += 1)
	{
		Fixed a(i_val1[i]);
		Fixed b(i_val2[i]);

		if (a <= b)
			printf("OK!\n");
		else	
			print_KO();
	}

	float f_val1[] = {-9.614f, -1.232f, 0.1f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512};
	float f_val2[] = {-9.614f, -1.232f, 0.1f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512};
	for (size_t i = 0; i < sizeof(f_val1)/sizeof(f_val1[0]); i += 1)
	{
		Fixed a(f_val1[i]);
		Fixed b(f_val2[i]);
		if (a <= b)
			printf("OK!\n");
		else
		{
			printf(BOLD_RED"KO.........\n");
			printf("Ori A is %f, ori B is %f\n", f_val1[i], f_val2[i]);
			printf("    A is %f,     B is %f\n" RESET, a.toFloat(), b.toFloat());
		}
	}
}
void	test_equal_to(void)
{
	std::cout << "Testing equal to\n";
	int i_val1[] = {0, 1, 2, 10, 200, 1000, 10001, 30001, 80001, 1000000, 8333334};
	int i_val2[] = {0, 1, 2, 10, 200, 1000, 10001, 30001, 80001, 1000000, 8333334};

	for (size_t i = 0; i < sizeof(i_val1)/sizeof(i_val1[0]); i += 1)
	{
		Fixed a(i_val1[i]);
		Fixed b(i_val2[i]);

		if (a == b)
			printf("OK!\n");
		else	
			print_KO();
	}

	float f_val1[] = {-9.614f, -1.232f, 0.1f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512};
	float f_val2[] = {-9.614f, -1.232f, 0.1f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512};
	for (size_t i = 0; i < sizeof(f_val1)/sizeof(f_val1[0]); i += 1)
	{
		Fixed a(f_val1[i]);
		Fixed b(f_val2[i]);
		if (a == b)
			printf("OK!\n");
		else
		{
			printf(BOLD_RED"KO.........\n");
			printf("Ori A is %f, ori B is %f\n", f_val1[i], f_val2[i]);
			printf("    A is %f,     B is %f\n" RESET, a.toFloat(), b.toFloat());
		}
	}
}
void	test_not_equal_to(void)
{
	std::cout << "Testing not equal to\n";
	int i_val1[] = {0, 1, 2, 10, 200, 1000, 10001, 30001, 80001, 1000000, 8333334};
	int i_val2[] = {1, 2, 10, 200, 1000, 10001, 30001, 80001, 1000000, 8333334, 0};

	for (size_t i = 0; i < sizeof(i_val1)/sizeof(i_val1[0]); i += 1)
	{
		Fixed a(i_val1[i]);
		Fixed b(i_val2[i]);

		if (a != b)
			printf("OK!\n");
		else	
			print_KO();
	}

	float f_val1[] = {-9.614f, -1.232f, 0.1f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512};
	float f_val2[] = {-1.232f, 0.1f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512, -9.614f};
	for (size_t i = 0; i < sizeof(f_val1)/sizeof(f_val1[0]); i += 1)
	{
		Fixed a(f_val1[i]);
		Fixed b(f_val2[i]);
		if (a != b)
			printf("OK!\n");
		else
		{
			printf(BOLD_RED"KO.........\n");
			printf("Ori A is %f, ori B is %f\n", f_val1[i], f_val2[i]);
			printf("    A is %f,     B is %f\n" RESET, a.toFloat(), b.toFloat());
		}
	}
}
void	test_plus(void)
{
	std::cout << "Testing plus\n";
	int i_val1[] = {-98765, -1, 3, 99, 99999, 999999};
	int i_val2[] = {-56789, 1, 4, 199, 199999, 1999999};

	for (size_t i = 0; i < sizeof(i_val1)/sizeof(i_val1[0]); i += 1)
	{
		Fixed a(i_val1[i]);
		Fixed b(i_val2[i]);
		a = a + b;
		if (a.toInt() == i_val1[i] + i_val2[i])
			printf("OK!\n");
		else	
			print_KO();
	}

	float f_val1[] = {-9.614f, -1.232f, 0.1f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512};
	float f_val2[] = {-1.232f, 0.1f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512, -9.614f};
	
	for (size_t i = 0; i < sizeof(f_val1)/sizeof(f_val1[0]); i += 1)
	{
		Fixed a(f_val1[i]);
		Fixed b(f_val2[i]);
		a = a + b;
		if (abs(a.toFloat() - (f_val1[i] + f_val2[i])) <= (2 / pow(2, 8)))
			printf("OK!\n");
		else
		{
			printf(BOLD_RED"KO.........\n");
			printf("Test sum is %f, my sum is %f\n" RESET, f_val1[i] + f_val2[i], a.toFloat());
		}
	}
}
void	test_minus(void)
{
	std::cout << "Testing minus\n";
	int i_val1[] = {-98765, -1, 3, 99, 99999, 999999};
	int i_val2[] = {-56789, 1, 4, 199, 199999, 1999999};

	for (size_t i = 0; i < sizeof(i_val1)/sizeof(i_val1[0]); i += 1)
	{
		Fixed a(i_val1[i]);
		Fixed b(i_val2[i]);
		a = a - b;
		if (a.toInt() == i_val1[i] - i_val2[i])
			printf("OK!\n");
		else	
			print_KO();
	}

	float f_val1[] = {-9.614f, -1.232f, 0.1f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512};
	float f_val2[] = {-1.232f, 0.1f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512, -9.614f};
	
	for (size_t i = 0; i < sizeof(f_val1)/sizeof(f_val1[0]); i += 1)
	{
		Fixed a(f_val1[i]);
		Fixed b(f_val2[i]);
		a = a - b;
		if (abs(a.toFloat() - (f_val1[i] - f_val2[i])) <= (2 / pow(2, 8)))
			printf("OK!\n");
		else
		{
			printf(BOLD_RED"KO.........\n");
			printf("Test sum is %f, my sum is %f\n" RESET, f_val1[i] + f_val2[i], a.toFloat());
		}
	}
}
void	test_multiply(void)
{
	std::cout << "Test multiply\n";
	int i_val1[] = {-987, -25, -3, 0, 1234, 5432};
	int i_val2[] = {-789, -52, 0, 99, 4321, 1234};

	for (size_t i = 0; i < sizeof(i_val1) / sizeof(i_val1[0]); i += 1)
	{
		Fixed a(i_val1[i]);
		Fixed b(i_val2[i]);

		a = a * b;
		if (a.toInt() == (i_val1[i] * i_val2[i]))
			printf("OK!\n");
		else
		{
			print_KO();
			printf("Original 1st value: %i, 2nd value: %i\n", i_val1[i], i_val2[i]);
			printf("Test is %i, mine is %i\n", i_val1[i] * i_val2[i], a.toInt());
		}
	}
}
void	test_divide(void)
{
	std::cout << "Test divide\n";
	float i_val1[] = {-987, -25, -3, 0, 1234, 5432};
	float i_val2[] = {-789, -52, 3, 99, 4321, 1234};

	for (size_t i = 0; i < sizeof(i_val1) / sizeof(i_val1[0]); i += 1)
	{
		Fixed a(i_val1[i]);
		Fixed b(i_val2[i]);

		a = a / b;
		if ( abs(a.toFloat() - (i_val1[i] / i_val2[i])) < (1 / pow(2, 8)) )
			printf("OK!\n");
		else
		{
			print_KO();
			printf("Original 1st value: %f, 2nd value: %f\n", i_val1[i], i_val2[i]);
			printf("Test is %f, mine is %f\n", i_val1[i] / i_val2[i], a.toFloat());
		}
	}
}
void	test_pre_increment(void)
{
	std::cout << "Testing pre increment\n";
	int		i_val[] = {999, 0, 999, 1234567};
	float	f_val[] = {-1.234f, 0.0f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512};
	double	incre = 1 / pow(2, 8);

	for (size_t i = 0; i < sizeof(i_val)/sizeof(i_val[0]); i += 1)
	{
		Fixed a(i_val[i]);
		++a;
		if (abs(a.toFloat() - ((float)i_val[i] + incre)) <= incre)
			printf("OK!\n");
		else
		{
			print_KO();
			printf("Test sum is %f, my sum is %f\n" RESET, (float)i_val[i] + incre, a.toFloat());
		}
	}

	for (size_t i = 0; i < sizeof(f_val)/sizeof(f_val[0]); i += 1)
	{
		Fixed b(f_val[i]);
		++b;
		if (abs(b.toFloat() - (f_val[i] + incre)) <= incre)
			printf("OK!\n");
		else
		{
			print_KO();
			printf("Test sum is %f, my sum is %f\n" RESET, (float)f_val[i] + incre, b.toFloat());
		}
	}
}
void	test_post_increment(void)
{
	std::cout << "Testing post increment\n";
	int		i_val[] = {999, 0, 999, 1234567};
	float	f_val[] = {-1.234f, 0.0f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512};
	double	incre = 1 / pow(2, 8);

	for (size_t i = 0; i < sizeof(i_val)/sizeof(i_val[0]); i += 1)
	{
		Fixed a(i_val[i]);
		a++;
		if (abs(a.toFloat() - ((float)i_val[i] + incre)) <= incre)
			printf("OK!\n");
		else
		{
			print_KO();
			printf("Test sum is %f, my sum is %f\n" RESET, (float)i_val[i] + incre, a.toFloat());
		}
	}

	for (size_t i = 0; i < sizeof(f_val)/sizeof(f_val[0]); i += 1)
	{
		Fixed b(f_val[i]);
		b++;
		if (abs(b.toFloat() - (f_val[i] + incre)) <= incre)
			printf("OK!\n");
		else
		{
			print_KO();
			printf("Test sum is %f, my sum is %f\n" RESET, (float)f_val[i] + incre, b.toFloat());
		}
	}
}
void	test_pre_decrement(void)
{
	std::cout << "Testing pre decrement\n";
	int		i_val[] = {999, 0, 999, 1234567};
	float	f_val[] = {-1.234f, 0.0f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512};
	double	decre = 1 / pow(2, 8);

	for (size_t i = 0; i < sizeof(i_val)/sizeof(i_val[0]); i += 1)
	{
		Fixed a(i_val[i]);
		--a;
		if (abs(a.toFloat() - ((float)i_val[i] - decre)) <= decre)
			printf("OK!\n");
		else
		{
			print_KO();
			printf("Test sum is %f, my sum is %f\n" RESET, (float)i_val[i] - decre, a.toFloat());
		}
	}

	for (size_t i = 0; i < sizeof(f_val)/sizeof(f_val[0]); i += 1)
	{
		Fixed b(f_val[i]);
		--b;
		if (abs(b.toFloat() - (f_val[i] - decre)) <= decre)
			printf("OK!\n");
		else
		{
			print_KO();
			printf("Test sum is %f, my sum is %f\n" RESET, (float)f_val[i] - decre, b.toFloat());
		}
	}
}
void	test_post_decrement(void)
{
	std::cout << "Testing post decrement\n";
	int		i_val[] = {999, 0, 999, 1234567};
	float	f_val[] = {-1.234f, 0.0f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512};
	double	decre = 1 / pow(2, 8);

	for (size_t i = 0; i < sizeof(i_val)/sizeof(i_val[0]); i += 1)
	{
		Fixed a(i_val[i]);
		a--;
		if (abs(a.toFloat() - ((float)i_val[i] - decre)) <= decre)
			printf("OK!\n");
		else
		{
			print_KO();
			printf("Test sum is %f, my sum is %f\n" RESET, (float)i_val[i] - decre, a.toFloat());
		}
	}

	for (size_t i = 0; i < sizeof(f_val)/sizeof(f_val[0]); i += 1)
	{
		Fixed b(f_val[i]);
		b--;
		if (abs(b.toFloat() - (f_val[i] - decre)) <= decre)
			printf("OK!\n");
		else
		{
			print_KO();
			printf("Test sum is %f, my sum is %f\n" RESET, (float)f_val[i] - decre, b.toFloat());
		}
	}
}
void	test_min(void)
{
	std::cout << "Test min\n";
	int i_val1[] = {0, 1, 2, 10, 200, 1000, 10001, 30001, 80001, 1000000, 8333334};
	int i_val2[] = {-1, 0, 1, 9, 199, 999, 10000, 30000, 80000, 999999, 8333333};

	float f_val1[] = {-9.614f, -1.232f, 0.1f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512};
	float f_val2[] = {-9.615f, -1.233f, 0.0f, 1.233f, 9.875f, 199.122f, 999.9122f, 9999.512, 99999.3511};

	for (size_t i = 0; i < sizeof(i_val1)/sizeof(i_val1[0]); i += 1)
	{
		Fixed a(i_val1[i]);
		Fixed b(i_val2[i]);

		if (Fixed::min(a, b).toInt() == b.toInt())
			printf("OK!\n");
		else
			print_KO();
	}

	for (size_t i = 0; i < sizeof(f_val1)/sizeof(f_val1[0]); i += 1)
	{
		Fixed a(f_val1[i]);
		Fixed b(f_val2[i]);

		if (Fixed::min(a, b).toFloat() == b.toFloat())
			printf("OK!\n");
		else
			print_KO();
	}
}
void	test_max(void)
{
	std::cout << "Test max\n";
	int i_val1[] = {0, 1, 2, 10, 200, 1000, 10001, 30001, 80001, 1000000, 8333334};
	int i_val2[] = {-1, 0, 1, 9, 199, 999, 10000, 30000, 80000, 999999, 8333333};

	float f_val1[] = {-9.614f, -1.232f, 0.1f, 1.234f, 9.876f, 199.123f, 999.9123f, 9999.513, 99999.3512};
	float f_val2[] = {-9.615f, -1.233f, 0.0f, 1.233f, 9.875f, 199.122f, 999.9122f, 9999.512, 99999.3511};

	for (size_t i = 0; i < sizeof(i_val1)/sizeof(i_val1[0]); i += 1)
	{
		Fixed a(i_val1[i]);
		Fixed b(i_val2[i]);

		if (Fixed::max(a, b).toInt() == a.toInt())
			printf("OK!\n");
		else
			print_KO();
	}

	for (size_t i = 0; i < sizeof(f_val1)/sizeof(f_val1[0]); i += 1)
	{
		Fixed a(f_val1[i]);
		Fixed b(f_val2[i]);

		if (Fixed::max(a, b).toFloat() == a.toFloat())
			printf("OK!\n");
		else
			print_KO();
	}
}

int main(void)
{
	// test_int_constructor();
	// test_float_constructor();
	// test_copy_constructor();
	// test_copy_assignment();
	// test_more();
	// test_less();
	// test_more_equal();
	// test_less_equal();
	// test_equal_to();
	// test_not_equal_to();
	// test_plus();
	// test_minus();
	// test_multiply();
	// test_divide();
	// test_pre_increment();
	// test_post_increment();
	// test_pre_decrement();
	// test_post_decrement();
	// test_min();
	// test_max();

	return (0);
}
