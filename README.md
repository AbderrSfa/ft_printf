# ft_printf
The aim of this project is pretty straight forward; recode printf. This project teaches the ins and outs of using variadic arguments.
The key to a successful ft_printf is well-structured and extensible code.
## Getting Started
Running `make` will produce a library called libftprintf.a. Use ft_printf() just as you would use printf(). When compiling your code use libftprintf.a.

`gcc main.c libftprintf.a`
## Functionality
Just like the real printf, ft_printf allows the following functionality:

`%[flags][width][.precision][length]type`

## Width
Specifies a minimum number of characters to output.
## Precision
Precision field specifies a maximum limit on the output. E.g: `ft_printf("%.2s", "xyz");` would output 'xy'.
## Flags
These flags are supported:
