/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayegres- <ayegres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:47:05 by ayegres-          #+#    #+#             */
/*   Updated: 2024/04/18 16:40:41 by ayegres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	number_length_int(long number)
{
	long	dozens;

	dozens = 1;
	if (number == 0)
		dozens *= 10;
	while (dozens <= number)
		dozens *= 10;
	return (dozens / 10);
}

int	ft_write_int(int number)
{
	char	print_number;
	int		counter;
	int		length;
	int		number_digit;
	long	lnb;

	counter = 0;
	lnb = (long) number;
	if (lnb < 0)
	{
		counter += write(1, "-", 1);
		lnb *= -1;
	}
	length = number_length_int(lnb);
	while (length > 0)
	{
		number_digit = lnb / length;
		print_number = number_digit + '0';
		counter += write(1, &print_number, 1);
		lnb -= number_digit * length;
		length /= 10;
	}
	return (counter);
}
