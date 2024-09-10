/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayegres- <ayegres-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:47:05 by ayegres-          #+#    #+#             */
/*   Updated: 2024/04/18 16:40:41 by ayegres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mapper_function(va_list args, char const *string, int *length)
{
	char	data_type;

	data_type = *string;
	if (data_type == 'd' || data_type == 'i')
		*length += ft_write_int(va_arg(args, int));
	else if (data_type == 'c')
		*length += ft_write_char(va_arg(args, int));
	else if (data_type == 's')
		*length += ft_write_string(va_arg(args, char *));
	else if (data_type == 'x' || data_type == 'X')
		*length += ft_write_hexadecimal(va_arg(args, unsigned int), data_type);
	else if (data_type == 'p')
		*length += ft_write_pointer(va_arg(args, unsigned long long));
	else if (data_type == 'u')
		*length += ft_write_unsigned_int(va_arg(args, unsigned int));
	else if (data_type == '%')
		*length += write(1, &data_type, 1);
	else
		return ;
	return ;
}

int	ft_printf(char const *string, ...)
{
	int		length;
	size_t	j;
	va_list	args;

	va_start(args, string);
	length = 0;
	j = 0;
	while (string[j] != '\0')
	{
		if (string[j] == '%' && string[j + 1] != '\0')
		{
			j++;
			mapper_function(args, &string[j], &length);
		}
		else
		{
			write(1, &string[j], 1);
			length++;
		}
		j++;
	}
	va_end(args);
	return (length);
}
