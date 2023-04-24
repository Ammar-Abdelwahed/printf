#include "main.h"
/**
*print_unsigned - Prints an unsigned number
*@types: List a of arguments
*@buffer: Buffer array to handle print
*@flags: Calculates active flags
*@width: get width
*@precision: Precision specification
*@size: Size specifier
*Return: Number of chars printed.
*/
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = 1024 - 2;
unsigned long int number = va_arg(types, unsigned long int);
number = convert_size_unsgnd(number, size);
if (number == 0)
buffer[i--] = '0';
buffer[1024 - 1] = '\0';
while (number > 0)
{
buffer[i--] = (number % 10) + '0';
number /= 10;
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
*print_octal - Prints an unsigned number in octal notation
*@types: Lista of arguments
*@buffer: Buffer array to handle print
*@flags: Calculates active flags
*@width: get width
*@precision: Precision specification
*@size: Size specifier
*Return: Number of chars printed
*/
int print_octal(va_list types, char buffer[],
int flags, int __attribute__((__unused__)) width, int precision, int size)
{
int i = 1024 - 2;
unsigned long int number = va_arg(types, unsigned long int);
unsigned long int temp = number;
number = convert_size_unsgnd(number, size);
if (number == 0)
buffer[i--] = '0';
buffer[1024
 - 1] = '\0';
while (number > 0)
{
buffer[i--] = (number % 8) + '0';
number /= 8;
}
if (flags & F_HASH && temp != 0)
buffer[i--] = '0';
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
*print_hexadecimal - Prints an unsigned number in hexadecimal notation
*@types: Lista of arguments
*@buffer: Buffer array to handle print
*@flags: Calculates active flags
*@width: get width
*@precision: Precision specification
*@size: Size specifier
*Return: Number of chars printed
*/
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}
/**
*print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
*@types: Lista of arguments
*@buffer: Buffer array to handle print
*@flags: Calculates active flags
*@width: get width
*@precision: Precision specification
*@size: Size specifier
*Return: Number of chars printed
*/
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}
/**
*print_hexa - Prints a hexadecimal number in lower or upper
*@types: lista of arguments
*@map_to: array of values to map the number to
*@buffer: cuffer array to handle print
*@flags: calculates active flags
*@flag_ch: calculates active flags
*@width: get width
*@precision: precision specification
*@size: size specifier
*@size: size specification
*Return: number of chars printed
*/
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int __attribute__((__unused__)) width, int precision, int size)
{
int i = 1024 - 2;
unsigned long int number = va_arg(types, unsigned long int);
unsigned long int temp= number;
number = convert_size_unsgnd(number, size);
if (number == 0)
buffer[i--] = '0';
buffer[1024 - 1] = '\0';
while (number > 0)
{
buffer[i--] = map_to[number % 16];
number /= 16;
}
if (flags & F_HASH && temp != 0)
{
buffer[i--] = flag_ch;
buffer[i--] = '0';
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
