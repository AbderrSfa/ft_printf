/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:32:56 by asfaihi           #+#    #+#             */
/*   Updated: 2020/11/01 13:56:56 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	pre_sp_print_p(int width, unsigned long arg, t_set *group)
{
	if (arg)
	{
		width -= 2;
		if (group->precision < hexa_counter_p(arg))
			width -= hexa_counter_p(arg);
		else
			width -= group->precision;
	}
	else
		width -= group->precision;
	if (!arg)
		width -= 2;
	while (width-- > 0)
		ft_putchar(' ', group);
}

int		hexa_counter_p(unsigned long n)
{
	int		i;
	int		temp;
	char	buffer[20];

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
		n = n + 4294967296;
	while (n)
	{
		temp = n % 16;
		if (temp < 10)
			buffer[i++] = temp + 48;
		else
			buffer[i++] = temp + 55;
		n = n / 16;
	}
	return (i);
}

void	deci_to_hexa_lower_p(unsigned long n, t_set *group)
{
	int		i;
	int		temp;
	char	buffer[20];

	i = 0;
	if (n == 0)
		ft_putchar('0', group);
	if (n < 0)
		n = n + 4294967296;
	while (n)
	{
		temp = n % 16;
		if (temp < 10)
			buffer[i++] = temp + 48;
		else
			buffer[i++] = temp + 87;
		n = n / 16;
	}
	while (i)
		ft_putchar(buffer[--i], group);
}

void	percent_p_precision(unsigned long arg, t_set *group)
{
	if (group->width && !group->left_field)
		pre_sp_print_p(group->width, arg, group);
	zeroes_printer(group->precision, group->specifier, arg, group);
	specifier_printer(group->specifier, arg, group);
	if (group->width && group->left_field)
		pre_sp_print_p(group->width, arg, group);
}

void	percent_p(t_set *group, va_list list)
{
	long	arg;

	arg = va_arg(list, unsigned long);
	star_converter(group);
	if (group->precision < 0)
		group->pre_toggle = 0;
	if (group->pre_toggle)
		percent_p_precision(arg, group);
	else if (group->left_field)
	{
		ft_putstr("0x", group);
		specifier_printer(group->specifier, arg, group);
		space_printer(group->width, group->specifier, arg, group);
	}
	else
	{
		if (group->zeroes && !group->left_field)
			zeroes_printer(group->width, group->specifier, arg, group);
		else
			space_printer(group->width, group->specifier, arg, group);
		if (!group->zeroes)
			ft_putstr("0x", group);
		specifier_printer(group->specifier, arg, group);
	}
}
