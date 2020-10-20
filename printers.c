/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:38:37 by asfaihi           #+#    #+#             */
/*   Updated: 2020/10/20 09:30:28 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pre_space_print(int width, char c, long arg, t_set *group)
{
	if ((c == 'x' || c == 'X' || c == 'p') && arg)
	{
		if (c == 'p')
			width -= 2;
		if (group->precision < hexa_counter(arg))
			width -= hexa_counter(arg);
		else
			width -= group->precision;
	}
	else if (c == 'u' && arg < 0 && (group->precision < how_long(arg + M_UI)))
		width -= how_long(arg + M_UI);
	else
	{
		if (group->precision < how_long(arg) && arg)
			width -= how_long(arg);
		else
			width -= group->precision;
	}
	if ((c == 'd' || c == 'i') && arg < 0 && group->precision >= how_long(arg))
		width--;
	if (c == 'p' && !arg)
		width -= 2;
	while (width-- > 0)
		ft_putchar(' ', group);
}

void	zeroes_printer(int i, char c, long arg, t_set *group)
{
	if (c == 'c' || c == '%')
		i--;
	else if (c == 'd' || c == 'i')
		i -= how_long(arg);
	else if (c == 'x' || c == 'X')
		i -= hexa_counter(arg);
	else if (c == 'p')
	{
		ft_putstr("0x", group);
		if (i > hexa_counter(arg) && group->pre_toggle)
			i -= hexa_counter(arg);
		else
			i -= hexa_counter(arg) + 2;
	}
	else if (c == 'u')
	{
		if (arg >= 0)
			i -= how_long(arg);
		else
			i -= how_long(arg + M_UI);
	}
	while (i-- > 0)
		ft_putchar('0', group);
}

void	space_printer(int i, char c, long arg, t_set *group)
{
	if (c == 'c' || c == '%')
		i--;
	else if (c == 'd' || c == 'i')
		i -= how_long(arg);
	else if (c == 'x' || c == 'X')
		i -= hexa_counter(arg);
	else if (c == 'p')
		i -= hexa_counter(arg) + 2;
	else if (c == 'u')
	{
		if (arg >= 0)
			i -= how_long(arg);
		else
			i -= how_long(arg + M_UI);
	}
	while (i-- > 0)
		ft_putchar(' ', group);
}

void	specifier_printer(char c, long arg, t_set *group)
{
	if (c != '%' && c != 'c' && group->pre_toggle && !group->precision && !arg)
		return ;
	if (c == 'c')
		ft_putchar(arg, group);
	else if (c == 'd' || c == 'i')
		ft_putnbr(arg, group);
	else if (c == 'u')
	{
		if (arg > 0 || arg == 0)
			ft_putnbr(arg, group);
		else
			ft_putnbr(arg + M_UI, group);
	}
	else if (c == 'p')
	{
		deci_to_hexa_lower(arg, group);
	}
	else if (c == '%')
		ft_putchar('%', group);
	else if (c == 'x')
		deci_to_hexa_lower(arg, group);
	else if (c == 'X')
		deci_to_hexa_upper(arg, group);
}

void	executer(t_set *group, va_list list)
{
	if (group->specifier == 'c' || group->specifier == '%')
		percent_c(group, list);
	if (group->specifier == 's')
		percent_s(group, list);
	if (group->specifier == 'p')
		percent_p(group, list);
	if (group->specifier == 'd' || group->specifier == 'i')
		percent_d(group, list);
	if (group->specifier == 'X' || group->specifier == 'x' ||
			group->specifier == 'u')
		percent_u_x(group, list);
}
