#include "100-operations.h"

/**
 * add - Adds two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The sum of @a and @b.
 */
int add(int a, int b) {
    return a + b;
}

/**
 * sub - Subtracts two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The difference between @a and @b.
 */
int sub(int a, int b) {
    return a - b;
}

/**
 * mul - Multiplies two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The product of @a and @b.
 */
int mul(int a, int b) {
    return a * b;
}

/**
 * div - Divides two integers.
 * @a: The first integer.
 * @b: The second integer (non-zero).
 *
 * Return: The result of integer division of @a by @b.
 */
int div(int a, int b) {
    if (b == 0) {
        return 0;  // To avoid division by zero
    }
    return a / b;
}

/**
 * mod - Computes the remainder of division.
 * @a: The first integer.
 * @b: The second integer (non-zero).
 *
 * Return: The remainder of division of @a by @b.
 */
int mod(int a, int b) {
    if (b == 0) {
        return 0;  // To avoid modulo by zero
    }
    return a % b;
}
