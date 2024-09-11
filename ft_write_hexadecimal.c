/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayegres- <ayegres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:47:05 by ayegres-          #+#    #+#             */
/*   Updated: 2024/04/18 16:40:41 by ayegres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	number_length_hexa(unsigned int nb)
{
	unsigned long	hex;
	unsigned int	holder;

	hex = 0x01;
	if (nb == 0x00)
		hex *= 0x10;
	while (nb >= 0x01)
	{
		holder = nb / 0x10;
		nb = holder;
		hex *= 0x10;
	}
	return (hex / 0x10);
}

int	aux_function(unsigned int print_digit, char string)
{
	char	character;

	if (print_digit <= 9)
	{
		character = print_digit + '0';
		return (write(1, &character, 1));
	}
	else
	{
		print_digit -= 10;
		if (string == 'X')
			character = print_digit + 'A';
		else
			character = print_digit + 'a';
		return (write(1, &character, 1));
	}
}

int	ft_write_hexadecimal(unsigned int number, char string)
{
	int				counter;
	unsigned int	length;
	unsigned int	number_digit;

	counter = 0;
	length = number_length_hexa(number);
	while (length > 0x0)
	{
		number_digit = number / length;
		counter += aux_function(number_digit, string);
		number -= number_digit * length;
		length /= 0x10;
	}
	return (counter);
}
