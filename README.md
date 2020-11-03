# ft_printf
The aim of this project is pretty straight forward; recode printf. This project teaches the ins and outs of using variadic arguments.
The key to a successful ft_printf is well-structured and extensible code.
## Getting Started
Running `make` will produce a library called libftprintf.a. Use ft_printf() just as you would use printf(). When compiling your code use ft_printf.a.

`gcc main.c ft_printf.a`
## Functionality
Just like the real printf, ft_printf allows the following functionality:

`%[flags][width][.precision]type`

### Width
Specifies a minimum number of characters to output.

'\*' : If '\*' is used width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.
### Precision
Precision field specifies a maximum limit on the output. E.g: `ft_printf("%.2s", "xyz");` would output 'xy'.
### Flags
These flags are supported:
- '0' (zero) - if the 'width' option is specified, add zeros to the beginning for numeric types.

- '-' (minus) - Left-align the output of this placeholder.

## Type
These conversion characters are managed:

- %c (character)
- %s (string)
- %p (address)
- %d (digit)
- %i (integer)
- %u (unsigned integer)
- %x (hexadecimal in lowercase)
- %X (hexadecimal in upper case)
