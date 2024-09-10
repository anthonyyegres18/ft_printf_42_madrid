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

int	number_length_int(int number)
{
	int	dozens;

	dozens = 1;
	if (number == 0)
		dozens *= 10;
	while (dozens <= number)
	{
		dozens *= 10;
	}
	return (dozens / 10);
}

int	ft_write_int(int number)
{
	char	print_number;
	int		counter;
	int		length;
	int		number_digit;

	counter = 0;
	if (number < 0)
	{
		counter += write(1, "-", 1);
		number *= -1;
	}
	length = number_length_int(number);
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
