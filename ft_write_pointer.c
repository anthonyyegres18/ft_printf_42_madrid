/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayegres- <ayegres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:47:05 by ayegres-          #+#    #+#             */
/*   Updated: 2024/04/18 16:40:41 by ayegres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	pointer_length(unsigned long long number)
{
	unsigned long long	length;

	length = 0x01;
	while (length <= number)
	{
		length *= 0x10;
	}
	return (length / 0x10);
}

static int	aux_function(unsigned long long print_digit)
{
	char	character;

	if (print_digit <= 9)
	{
		character = print_digit + '0';
		return (write(1, &character, 1));
	}
	else
	{
		print_digit = print_digit - 10;
		character = print_digit + 'a';
		return (write(1, &character, 1));
	}
}

int	ft_write_pointer(unsigned long long pointer)
{
	int					counter;
	unsigned long long	length;
	unsigned long long	number_digit;

	if (pointer == 0x0)
		return (write(1, "(nil)", 5));
	counter = 0;
	length = pointer_length(pointer);
	counter += write(1, "0x", 2);
	while (length > 0x0)
	{
		number_digit = pointer / length;
		counter += aux_function(number_digit);
		pointer -= number_digit * length;
		length /= 0x10;
	}
	return (counter);
}
