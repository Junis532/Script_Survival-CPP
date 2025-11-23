#pragma once

#include <stdio.h>
#include <stdint.h> // C99 표준 헤더

#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */

class MT19937
{
public:
	MT19937();
	~MT19937();

	void init_genrand(uint32_t s);
	uint32_t genrand_int32(void);
	double genrand_real1(void);

private:
	uint32_t mt[N];
	int mti;

};

extern MT19937 mt;