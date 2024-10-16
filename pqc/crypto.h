#include <stdint.h>
#define Q 3329

uint16_t mod3329 (uint16_t a, uint16_t b);

// No contracts here constraining range of a and b
uint16_t mod3329a (uint16_t a, uint16_t b);

// Now with contracts this time
uint16_t mod3329b (uint16_t a, uint16_t b)
__CPROVER_requires(a >= 0 && a < Q)
__CPROVER_requires(b >= 0 && b < Q);

// More contracts showing the range of the return value
uint16_t mod3329c (uint16_t a, uint16_t b)
__CPROVER_requires(a >= 0 && a < Q)
__CPROVER_requires(b >= 0 && b < Q)
__CPROVER_ensures(__CPROVER_return_value >= 0 && __CPROVER_return_value < Q);

// Montgomery reduction from the Kyber reference implementation
int16_t mr1(int32_t a)
__CPROVER_requires(a >= -32768 * Q)
__CPROVER_requires(a <= 32768 * Q - 1)
__CPROVER_ensures(__CPROVER_return_value >= (-Q) + 1)
__CPROVER_ensures(__CPROVER_return_value <= Q - 1)
__CPROVER_ensures(((__CPROVER_return_value * 65536) - a) % Q == 0);

// Montgomery reduction from the Kyber reference implementation
// Alternative implementation
int16_t mr2(int32_t a)
__CPROVER_requires(a >= -32768 * Q)
__CPROVER_requires(a <= 32768 * Q - 1)
__CPROVER_ensures(__CPROVER_return_value >= (-Q) + 1)
__CPROVER_ensures(__CPROVER_return_value <= Q - 1)
__CPROVER_ensures(((__CPROVER_return_value * 65536) - a) % Q == 0);
