# NOTES FOR GLORIOUS C LANGUAGE

Already a little ways in lets just write down anything that looks important
as it comes up. Declaration, definition and initialization is always an 
important difference to beat into ones head. 

Types 

char - 1 byte
int - default size for host
float - single precision floating point
double - double precision floating point

short and long modifiers, used on int and float when abbreviated and used by
themselves assumed to stand for short int (short) and long int (long). Again
exact byte length is machine defined but ints are usually 16 or 32 bits (2-4 bytes)
short is usually 16 bits and long is 32 bits. Language definition is just that 
long must be at least as long as int.... lets check if any of this has been standardized
in newer c. 

Nope only addition is long long int in c99 which must be longer than long int
(is usually 64 bit vs 32 bit for long and 16 bit for int)

Signed vs unsigned. There are signed and unsigned variants for all of the datatypes
and with the exception of char they all default to the signed type if its not specified.
So short is signed, and unsigned long long is unsigned. char is apparently implementation
dependent whether its signed or not by default but seems like its usually not?

<limits.h> has the platform specific limits for all of these types

C constants

Supports a few different styles of contant values.
long - 1234567L  (long integer)
unsigned anything - 123u (unsigned int), 1234567uL (unsigned long)
float - 123.5f (float), 

octal - leading o

o37 - 011 111

or 

\ooo (\007 bell character)

hexadecimal - leading 0x

x0A - 0000 1000 

or 

\x7 (bell character)



