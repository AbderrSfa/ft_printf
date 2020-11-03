/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_divider.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:38:34 by asfaihi           #+#    #+#             */
/*   Updated: 2020/11/01 13:28:59 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	percent_d_rest(t_set *group, int arg)
{
	if (group->left_field)
	{
		specifier_printer(group->specifier, arg, group);
		space_printer(group->width, group->specifier, arg, group);
	}
	else
	{
		if (group->zeroes && !group->left_field)
			zeroes_printer(group->width, group->specifier, arg, group);
		else
			space_printer(group->width, group->specifier, arg, group);
		specifier_printer(group->specifier, arg, group);
	}
}

void	percent_d(t_set *group, va_list list)
{
	int		arg;

	arg = va_arg(list, int);
	star_converter(group);
	if (group->precision < 0)
		group->pre_toggle = 0;
	if (group->pre_toggle)
		precision(group, arg);
	else if (arg < 0 && !group->left_field && group->zeroes)
	{
		ft_putchar('-', group);
		zeroes_printer(group->width, group->specifier, arg, group);
		ft_special_putnbr(arg, group);
	}
	else
		percent_d_rest(group, arg);
}

void	percent_c(t_set *group, va_list list)
{
	int		arg;

	arg = 0;
	if (group->specifier != '%')
		arg = va_arg(list, int);
	star_converter(group);
	if (group->left_field)
	{
		specifier_printer(group->specifier, arg, group);
		space_printer(group->width, group->specifier, arg, group);
	}
	else
	{
		if (group->zeroes && !group->left_field)
			zeroes_printer(group->width, group->specifier, arg, group);
		else
			space_printer(group->width, group->specifier, arg, group);
		specifier_printer(group->specifier, arg, group);
	}
}

void	percent_u_x(t_set *group, va_list list)
{
	int		arg;

	arg = va_arg(list, int);
	star_converter(group);
	if (group->precision < 0)
		group->pre_toggle = 0;
	if (group->pre_toggle)
		precision(group, arg);
	else if (group->left_field)
	{
		specifier_printer(group->specifier, arg, group);
		space_printer(group->width, group->specifier, arg, group);
	}
	else
	{
		if (group->zeroes && !group->left_field)
			zeroes_printer(group->width, group->specifier, arg, group);
		else
			space_printer(group->width, group->specifier, arg, group);
		specifier_printer(group->specifier, arg, group);
	}
}
