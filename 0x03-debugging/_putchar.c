#include <unistd.h>
/**
 * _putchar inafanya ifuatayo
 * @c: inaipea kitu ya kuandika
 * Return: 1
 * ikikosea inarudisha -1
 */
int _putchar(char c)
{
        return(write(1, &c,1));
}
