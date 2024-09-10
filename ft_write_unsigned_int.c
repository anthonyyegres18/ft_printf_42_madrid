/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayegres- <ayegres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:47:05 by ayegres-          #+#    #+#             */
/*   Updated: 2024/04/18 16:40:41 by ayegres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	number_length(unsigned int number)
{
	unsigned long	dozens;

	dozens = 1;
	if (number == 0)
		dozens *= 10;
	while (dozens <= number)
	{
		dozens *= 10;
	}
	return (dozens / 10);
}

int	ft_write_unsigned_int(unsigned int number)
{
	unsigned char		print_number;
	unsigned long		number_digit;
	unsigned int		length;
	int					counter;

	counter = 0;
	length = number_length(number);
	while (length > 0)
	{
		number_digit = number / length;
		print_number = number_digit + '0';
		counter += write(1, &print_number, 1);
		number -= number_digit * length;
		length /= 10;
	}
	return (counter);
}
